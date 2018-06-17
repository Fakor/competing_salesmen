import wx

class MapPanel(wx.Panel):
    def __init__(self, parent, panel_size, map_size):
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
        self.salesmen = []
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
        print(new_map)
        self.cities = new_map.get("cities", [])
        self.salesmen = new_map.get("salesmen", [])
        self.map_drawn = False
        self.Refresh()

    def move_salesmen(self, data):
        dc = wx.ClientDC(self)
        brush = wx.brush = wx.Brush("blue")
        dc.SetBackground(brush)

        new_salesmen_positions = data.get("salesmen", [])
        dc.SetPen(wx.Pen(wx.RED, 1))
        for salesman, new_position in zip(self.salesmen, new_salesmen_positions):
            last_x, last_y = self.get_salesman_last_position(salesman)
            self.update_salesman_position(salesman, new_position)
            dc.DrawLine(last_x, last_y, *new_position)
            print(salesman, new_position)
        dc.DrawLine(0,0,100,100)

    def get_salesman_last_position(self, salesman):
        return salesman[-2], salesman[-1]

    def update_salesman_position(self, salesman, new_position):
        salesman.extend(new_position)

    def print_map(self, event):
        dc = wx.PaintDC(self)
        brush = wx.brush = wx.Brush("blue")
        dc.SetBackground(brush)
        dc.Clear()
        dc.SetPen(wx.Pen(wx.BLUE, 4))
        for city in self.cities:
            x, y = self.get_position(city)
            dc.DrawCircle(x, y, 1)

        dc.SetPen(wx.Pen(wx.RED, 4))
        for salesman in self.salesmen:
            x, y = self.get_position(salesman)
            dc.DrawCircle(x, y, 1)


if __name__ == "__main__":
    app=wx.App(False)
    pp=MapPanel()
    app.MainLoop()
