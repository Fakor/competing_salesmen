import wx

class StatusDisplay(wx.Panel):
    def __init__(self, parent, panel_size, number_of_salesmen):
        wx.Panel.__init__(self, parent)
        self.SetClientSize(panel_size)
        self.number_of_salesmen = number_of_salesmen

        top_sizer = wx.BoxSizer(wx.VERTICAL)
        info_sizer = wx.BoxSizer(wx.HORIZONTAL)
        score_sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.scoreboard = []
        for i in range(self.number_of_salesmen):
            print(i)
            self.scoreboard.append(wx.StaticText(self, label=str(0)))
            score_sizer.Add(self.scoreboard[-1], 0, wx.ALL, 5)
            
            
        self.info = wx.StaticText(self, label="Info")

        
        info_sizer.Add(self.info, 0, wx.ALL, 5)
        
        top_sizer.Add(info_sizer, 0 , wx.LEFT)
        top_sizer.Add(score_sizer, wx.LEFT)
        
        self.SetSizer(top_sizer)
        top_sizer.Fit(self)

    def new_score(self, new_score):
        for new_score, text in zip(new_score, self.scoreboard):
            text.SetLabel(str(new_score))
    
