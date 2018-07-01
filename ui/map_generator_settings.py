import wx
import json


class MapGeneratorSettings(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent)
        self.Bind(wx.EVT_CLOSE, self.when_closed)
        self.Centre()

        self.settings_used = True

        self.settings = {}
        self.settings["type"] = "random"
        self.settings["seed"] = 0

        top_sizer = wx.BoxSizer(wx.VERTICAL)
        option_sizer = wx.BoxSizer(wx.VERTICAL)
        button_sizer = wx.BoxSizer(wx.HORIZONTAL)

        option_seed_sizer = wx.BoxSizer(wx.HORIZONTAL)

        seed_text = wx.StaticText(self, label="SEED")
        self.seed_edit = wx.TextCtrl(self, value=str(self.settings["seed"]))
        option_seed_sizer.Add(seed_text, 0, wx.CENTRE)
        option_seed_sizer.Add(self.seed_edit, 0, wx.ALL)

        save_button = wx.Button(self, wx.ID_ANY, "Save")
        save_button.Bind(wx.EVT_BUTTON,self.save)
        button_sizer.Add(save_button, 0, wx.LEFT)

        top_sizer.Add(option_seed_sizer, 0, wx.CENTRE)
        top_sizer.Add(button_sizer, 0, wx.CENTRE)
        self.SetSizer(top_sizer)
        top_sizer.Fit(self)

    def save(self, event):
        self.seed = self.seed_edit.GetLineText(0)
        self.settings_used = False

    def when_closed(self, event):
        self.Hide()

    def get_settings_command(self):
        return {"map_generator_settings": self.settings}
