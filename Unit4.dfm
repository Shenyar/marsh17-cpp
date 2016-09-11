object FormPrint: TFormPrint
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1077#1095#1072#1090#1100
  ClientHeight = 315
  ClientWidth = 499
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 384
    Top = 8
    Width = 81
    Height = 23
    Caption = #1055#1077#1095#1072#1090#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 112
    Width = 262
    Height = 23
    Caption = #1055#1077#1088#1077#1095#1077#1085#1100' '#1096#1080#1092#1088#1086#1074' '#1085#1072' '#1087#1077#1095#1072#1090#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object CheckComplect: TCheckBox
    Left = 24
    Top = 37
    Width = 409
    Height = 17
    Alignment = taLeftJustify
    Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1086#1074#1086#1095#1085#1072#1103' '#1082#1072#1088#1090#1072' '#1082' '#1087#1088#1080#1089#1087#1086#1089#1086#1073#1083#1077#1085#1080#1102
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 0
  end
  object CheckTrud: TCheckBox
    Left = 40
    Top = 69
    Width = 393
    Height = 17
    Alignment = taLeftJustify
    Caption = #1050#1072#1088#1090#1072' '#1090#1088#1091#1076#1086#1077#1084#1082#1086#1089#1090#1080' '#1096#1080#1092#1088#1072' '#1085#1072' '#1080#1079#1076#1077#1083#1080#1077
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object Button1: TButton
    Left = 328
    Top = 141
    Width = 145
    Height = 89
    Caption = #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 328
    Top = 236
    Width = 145
    Height = 57
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089' '#1087#1077#1095#1072#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    WordWrap = True
    OnClick = Button2Click
  end
  object ListName: TListBox
    Left = 16
    Top = 141
    Width = 281
    Height = 152
    ItemHeight = 23
    TabOrder = 4
  end
  object PrintDialog1: TPrintDialog
    Left = 16
    Top = 8
  end
  object ADOtemp: TADOQuery
    Connection = FormMain.ADOConnection1
    Parameters = <>
    Left = 56
    Top = 8
  end
end
