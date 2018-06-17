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
        self.border = (5,5)

    def on_size(self, event):
        print("SIZE")
        event.Skip()
        
    def set_map(self, new_map):
        self._map = new_map
        self.Refresh()

    def move_salesmen(self, data):
        print("Moving salesmen", data)

    def print_map(self, event):
        w, h = self.GetClientSize()
        x_scaler = ( w - self.border[0]) / self.map_size[0]
        y_scaler = ( h - self.border[1]) / self.map_size[1]

        dc = wx.AutoBufferedPaintDC(self)
        dc.Clear()
        brush = wx.brush = wx.Brush("blue")
        dc.SetBackground(brush)
        dc.SetPen(wx.Pen(wx.BLUE, 4))
        for city in self._map.get("cities", []):
            x = self.border[0] + city[0] * x_scaler
            y = h -self.border[1] - city[1] * y_scaler
            dc.DrawCircle(x, y, 1)
        dc.SetPen(wx.Pen(wx.RED, 4))
        for salesman in self._map.get("salesmen", []):
            x = self.border[0] + salesman[0] * x_scaler
            y = h -self.border[1] - salesman[1] * y_scaler
            dc.DrawCircle(x, y, 1)

if __name__ == "__main__":
    app=wx.App(False)
    pp=MapPanel()
    app.MainLoop()
