import wx

from client import Client
from map_panel import MapPanel

class MainFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None)
        self.panel = wx.Panel(self, id=wx.ID_ANY)

        self.SetClientSize((600,400))
        self.Center()

        self.generate_map_button = wx.Button(self.panel,wx.ID_ANY,"Generate map")
        self.perform_turn_button = wx.Button(self.panel, wx.ID_ANY,"Perform turn")
        self.exit_button = wx.Button(self.panel, wx.ID_ANY, "EXIT")

        self.generate_map_button.Bind(wx.EVT_BUTTON,self.GenerateMap)
        self.perform_turn_button.Bind(wx.EVT_BUTTON,self.PerformTurn)
        self.exit_button.Bind(wx.EVT_BUTTON,self.ExitButtonClicked)

        self.map_panel = MapPanel(self.panel, (200,200), (3,3))

        top_sizer = wx.BoxSizer(wx.HORIZONTAL)
        button_sizer = wx.BoxSizer(wx.VERTICAL)
        map_sizer = wx.BoxSizer(wx.VERTICAL)

        map_sizer.Add(self.map_panel, 0, wx.ALIGN_TOP|wx.FIXED_MINSIZE)

        button_sizer.Add(self.generate_map_button, 0, wx.ALL)
        button_sizer.Add(self.perform_turn_button, 0, wx.ALL)
        button_sizer.Add(self.exit_button, 0, wx.ALL)

        top_sizer.Add(button_sizer, 0, wx.LEFT)
        top_sizer.Add(map_sizer, 0, wx.ALIGN_TOP)

        self.panel.SetSizer(top_sizer)
        top_sizer.Fit(self)
        self.command=None
        self.client=Client()
        self.Show()

    def GenerateMap(self, event):
        server_response = self.client.transceive("generate_map")
        self.handle_response(server_response)

    def PerformTurn(self, event):
        server_response = self.client.transceive("perform_turn")
        self.handle_response(server_response)
        
    def ExitButtonClicked(self, event):
        print("Exit program")
        self.Close()

    def handle_response(self, response):
        for label, data in response.items():
            if label == "new_map":
                self.map_panel.set_map(data["map"])
            elif label == "turn_performed":
                self.map_panel.move_salesmen(data)

if __name__ == "__main__":
    app = wx.App(False)
    top = MainFrame()
    top.Show()
    app.MainLoop()
