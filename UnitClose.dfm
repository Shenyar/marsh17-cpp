object FormPClose: TFormPClose
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1077#1088#1077#1085#1086#1089' '#1096#1080#1092#1088#1086#1074' '#1074' '#1089#1090#1072#1088#1091#1102' '#1041#1072#1079#1091' '#1044#1072#1085#1085#1099#1093
  ClientHeight = 102
  ClientWidth = 445
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 418
    Height = 23
    Caption = #1048#1076#1077#1090' '#1087#1077#1088#1077#1085#1086#1089' '#1096#1080#1092#1088#1086#1074' '#1074' '#1089#1090#1072#1088#1091#1102' '#1041#1072#1079#1091' '#1044#1072#1085#1085#1099#1093'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 117
    Height = 23
    Caption = #1054#1089#1090#1072#1083#1086#1089#1100' 245'
  end
  object ProgressBar1: TProgressBar
    Left = 144
    Top = 56
    Width = 282
    Height = 23
    Step = 5
    TabOrder = 0
  end
  object ADOconn_dbf: TADOConnection
    LoginPrompt = False
    Left = 112
    Top = 16
  end
  object ADOsqlexec: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from m_karta'
      ''
      'order by id desc;')
    Left = 72
    Top = 56
  end
  object ADOdbf: TADOQuery
    Connection = ADOconn_dbf
    OnPostError = ADOdbfPostError
    Parameters = <>
    Left = 112
    Top = 56
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 176
    Top = 24
  end
  object ADOmdb: TADOQuery
    Connection = FormMain.ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select * from to_old_dbf;')
    Left = 40
    Top = 56
  end
end
