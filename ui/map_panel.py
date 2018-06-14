import wx

class MapPanel(wx.Panel):
    def __init__(self, parent, panel_size, map_size):
        wx.Panel.__init__(self, parent)
        self.SetClientSize(panel_size)
        self.map_size = map_size
        self.SetBackgroundStyle(wx.BG_STYLE_CUSTOM)
        self.Bind(wx.EVT_SIZE, self.on_size)
        self.Bind(wx.EVT_PAINT, self.print_map)
        self._map = {}

    def on_size(self, event):
        print("SIZE")
        event.Skip()
        
    def set_map(self, new_map):
        self._map = new_map
        self.Refresh()

    def print_map(self, event):
        w, h = self.GetClientSize()
        print("DRAWING", self._map, w, h)
        x_scaler = w / self.map_size[0]
        y_scaler = h / self.map_size[1]

        dc = wx.AutoBufferedPaintDC(self)
        dc.Clear()
        brush = wx.brush = wx.Brush("blue")
        dc.SetBackground(brush)
        dc.SetPen(wx.Pen(wx.RED, 4))
        for city in self._map.get("cities", []):
            dc.DrawCircle(city[0] * x_scaler, city[1] * y_scaler, 1)

if __name__ == "__main__":
    app=wx.App(False)
    pp=MapPanel()
    app.MainLoop()
