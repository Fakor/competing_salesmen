import wx

class StatusDisplay(wx.Panel):
    def __init__(self, parent, panel_size, salesmen):
        wx.Panel.__init__(self, parent)
        self.SetClientSize(panel_size)
        self.salesmen = salesmen
        self.scoreboard = []

        self.top_sizer = wx.BoxSizer(wx.VERTICAL)
        self.info_sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.score_sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.setup_scoreboard(self.salesmen)


        self.info = wx.StaticText(self, label="Info", size=(150,50))


        self.info_sizer.Add(self.info, 0, wx.ALL, 5)

        self.top_sizer.Add(self.info_sizer, 0 , wx.LEFT)
        self.top_sizer.Add(self.score_sizer, wx.LEFT)

        self.SetSizer(self.top_sizer)
        self.top_sizer.Fit(self)

    def setup_scoreboard(self, salesmen):
        self.salesmen = salesmen
        self.score_sizer.Clear()
        for salesman in self.salesmen:
            text = wx.StaticText(self, label=str(0), size=(50,50))
            text.SetFont(wx.Font(24, wx.NORMAL, wx.NORMAL, wx.BOLD))
            self.scoreboard.append(text)
            self.score_sizer.Add(text, salesman.score, wx.ALL, 5)
        self.SetSizer(self.top_sizer)
        self.top_sizer.Fit(self)

    def update_score(self):
        for salesman, text in zip(self.salesmen, self.scoreboard):
            text.SetLabel(str(salesman.score))
