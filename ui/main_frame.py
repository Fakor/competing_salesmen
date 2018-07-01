import wx

from wx.lib.colourdb import getColourList

from client import Client
from map_panel import MapPanel
from status_display import StatusDisplay
from salesman import Salesman
from map_generator_settings import MapGeneratorSettings

colors = [
    wx.RED,
    wx.GREEN
]

class MainFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None)
        self.panel = wx.Panel(self, id=wx.ID_ANY)

        self.colors = colors
        self.SetClientSize((700,500))
        self.Center()

        self.map_generator_settings_frame = MapGeneratorSettings(self)

        self.salesmen = []

        self.generate_map_button = wx.Button(self.panel,wx.ID_ANY,"Generate map")
        self.perform_turn_button = wx.Button(self.panel, wx.ID_ANY,"Perform turn")
        self.map_generator_settings_button = wx.Button(self.panel,wx.ID_ANY,"Map settings")
        self.exit_button = wx.Button(self.panel, wx.ID_ANY, "EXIT")

        self.generate_map_button.Bind(wx.EVT_BUTTON,self.GenerateMap)
        self.perform_turn_button.Bind(wx.EVT_BUTTON,self.PerformTurn)
        self.map_generator_settings_button.Bind(wx.EVT_BUTTON,self.MapGeneratorSettings)
        self.exit_button.Bind(wx.EVT_BUTTON,self.ExitButtonClicked)

        self.map_panel = MapPanel(self.panel, (200,200), (3,3), self.salesmen)
        self.status_display = StatusDisplay(self.panel, (20,200), [])

        top_sizer = wx.BoxSizer(wx.HORIZONTAL)
        button_sizer = wx.BoxSizer(wx.VERTICAL)
        map_sizer = wx.BoxSizer(wx.VERTICAL)
        status_display_sizer = wx.BoxSizer(wx.VERTICAL)

        map_sizer.Add(self.map_panel, 0, wx.ALIGN_TOP|wx.FIXED_MINSIZE)
        status_display_sizer.Add(self.status_display, 0, wx.ALL)

        button_sizer.Add(self.generate_map_button, 0, wx.ALL)
        button_sizer.Add(self.perform_turn_button, 0, wx.ALL)
        button_sizer.Add(self.map_generator_settings_button, 0, wx.ALL)
        button_sizer.Add(self.exit_button, 0, wx.ALL)

        top_sizer.Add(button_sizer, 0, wx.LEFT)
        top_sizer.Add(map_sizer, 0, wx.ALIGN_TOP)
        top_sizer.Add(status_display_sizer, 0, wx.CENTRE)

        self.panel.SetSizer(top_sizer)
        top_sizer.Fit(self)
        self.command=None
        self.client=Client()
        self.Show()

    def GenerateMap(self, event):
        command = []
        if not self.map_generator_settings_frame.settings_used:
            self.map_generator_settings_frame.settings_used = True
            command.append(map_generator_settings_frame.get_settings_command)
        command.append({"generate_map": {}})
        server_response = self.client.transceive(command)
        self.handle_response(server_response)

    def PerformTurn(self, event):
        server_response = self.client.transceive([{"perform_turn":{}}])
        self.handle_response(server_response)

    def MapGeneratorSettings(self, event):
        self.map_generator_settings_frame.Show()
        
    def ExitButtonClicked(self, event):
        print("Exit program")
        self.Close()

    def InitSalesmen(self, salesmen):
        self.salesmen = []
        index = 0
        for salesman in salesmen:
            self.salesmen.append(Salesman([salesman["x"], salesman["y"]], self.colors[index]))
            index = index + 1

        self.map_panel.salesmen = self.salesmen

    def UpdateSalesmen(self, data):
        for salesman, salesman_data in zip(self.salesmen, data):
            salesman.update_status(salesman_data["x"], salesman_data["y"], salesman_data["score"])

    def handle_response(self, response):
        for label, data in response.items():
            if label == "new_map":
                self.InitSalesmen(data["map"]["salesmen"])
                self.status_display.setup_scoreboard(self.salesmen)
                self.map_panel.set_map(data["map"])
            elif label == "turn_performed":
                self.UpdateSalesmen(data["salesmen"])
                self.map_panel.Refresh()
                self.status_display.update_score()

if __name__ == "__main__":
    app = wx.App(False)
    top = MainFrame()
    top.Show()
    app.MainLoop()
