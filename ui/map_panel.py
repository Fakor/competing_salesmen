import wx

class MapPanel(wx.Panel):
    def __init__(self, parent):
        #wx.Frame.__init__(self, None, wx.ID_ANY, title="MainFrame", size=(300,250))
        wx.Panel.__init__(self, parent)
        self.SetClientSize((300,300))
        self.SetBackgroundStyle(wx.BG_STYLE_CUSTOM)
        self.Bind(wx.EVT_SIZE, self.on_size)
        self.Bind(wx.EVT_PAINT, self.on_paint)

    def on_size(self, event):
        print("SIZE")
        event.Skip()
        
    def on_paint(self, event):
        self.SetClientSize((300,300))
        w, h = self.GetClientSize()
        print(w, h)
        dc = wx.AutoBufferedPaintDC(self)
        dc.Clear()
        brush = wx.Brush("blue") 
        dc.SetBackground(brush)
        dc.SetPen(wx.Pen(wx.RED, 4))
        dc.DrawCircle(10,10,1)
        dc.DrawCircle(40,40,1)
        dc.DrawCircle(140,140,1)
        dc.DrawCircle(200, 40,1)
       
       


if __name__ == "__main__":
    app=wx.App(False)
    pp=MapPanel()
    app.MainLoop()
