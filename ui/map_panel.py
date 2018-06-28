import wx

class MapPanel(wx.Panel):
    def __init__(self, parent, panel_size, map_size, salesmen):
        wx.Panel.__init__(self, parent)
        self.SetClientSize(panel_size)
        self.w, self.h = self.GetClientSize()
        self.map_size = map_size
        self.SetBackgroundStyle(wx.BG_STYLE_CUSTOM)
        self.Bind(wx.EVT_SIZE, self.on_size)
        self.Bind(wx.EVT_PAINT, self.print_map)
        self._map = {}
        self.border = (5,5)
        self.cities = []
        self.salesmen = salesmen
        self.map_drawn = False
        self.set_scalers()

    def set_scalers(self):
        self.x_scaler = ( self.w - self.border[0]) / self.map_size[0]
        self.y_scaler = ( self.h - self.border[1]) / self.map_size[1]

    def get_position(self, real_position):
        x = self.border[0] + real_position[0] * self.x_scaler
        y = self.h -self.border[1] - real_position[1] * self.y_scaler
        return x, y

    def on_size(self, event):
        print("SIZE")
        event.Skip()
        
    def set_map(self, new_map):
        self.cities = new_map.get("cities", [])
        self.map_drawn = False
        self.Refresh()

    def print_map(self, event):
        dc = wx.PaintDC(self)
        brush = wx.brush = wx.Brush("blue")
        dc.SetBackground(brush)
        dc.Clear()
        dc.SetPen(wx.Pen(wx.BLUE, 4))
        for city in self.cities:
            x, y = self.get_position(city)
            dc.DrawCircle(x, y, 1)
        for salesman in self.salesmen:
            dc.SetPen(wx.Pen(salesman.color, 4))
            trajectory = salesman.trajectory
            last_x, last_y = self.get_position(trajectory[0])
            dc.DrawCircle(last_x, last_y, 1)
            for org_x, org_y, tagged_city in trajectory[1:]:
                dc.SetPen(wx.Pen(salesman.color, 1))
                x, y = self.get_position([org_x, org_y])
                dc.DrawLine(last_x, last_y, x, y)
                last_x = x
                last_y = y
                if tagged_city:
                    dc.SetPen(wx.Pen(salesman.color, 4))
                    dc.DrawCircle(x,y,1)


if __name__ == "__main__":
    app=wx.App(False)
    pp=MapPanel()
    app.MainLoop()
