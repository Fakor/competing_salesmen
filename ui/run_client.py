#!/usr/bin/env python3

import wx

from main_frame import MainFrame

if __name__ == "__main__":
    app = wx.App(False)
    frame = MainFrame()
    app.MainLoop()
