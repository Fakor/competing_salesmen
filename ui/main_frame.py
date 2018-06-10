import wx

from client import Client

class MainFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, title="MainFrame", size=(300,250))
        panel = wx.Panel(self)
        box = wx.BoxSizer(wx.VERTICAL)

        self.btn = wx.Button(panel,-1,"Generate map")
        box.Add(self.btn,0,wx.ALIGN_CENTER)
        self.btn.Bind(wx.EVT_BUTTON,self.OnClicked)

        self.command=None
        self.client=Client()
        self.Show()

    def OnClicked(self, event):
        btn = event.GetEventObject().GetLabel() 
        print("Label of pressed button = ",btn)
        data = self.client.transceive("generate_map")
        print(data)

if __name__ == "__main__":
    app = wx.App(False)
    top = MainFrame()
    top.Show()
    app.MainLoop()
