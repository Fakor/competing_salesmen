import wx

class MapGeneratorSettings(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent)
        self.Bind(wx.EVT_CLOSE, self.when_closed)

    def when_closed(self, event):
        self.Hide()
