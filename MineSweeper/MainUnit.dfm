object MainForm: TMainForm
  Left = 192
  Top = 107
  Width = 708
  Height = 494
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 200
    Top = 168
    object N1: TMenuItem
      Caption = #1048#1075#1088#1072
      object N2: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1053#1086#1074#1072#1103
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N5: TMenuItem
        Caption = #1047#1072#1082#1086#1085#1095#1080#1090#1100
        OnClick = N5Click
      end
    end
    object N6: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N6Click
    end
  end
end
