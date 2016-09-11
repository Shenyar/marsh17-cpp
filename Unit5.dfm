object FormDopOsn: TFormDopOsn
  Left = 0
  Top = 0
  Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1086#1089#1085#1072#1089#1090#1082#1072
  ClientHeight = 370
  ClientWidth = 510
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  Scaled = False
  OnKeyDown = FormKeyDown
  DesignSize = (
    510
    370)
  PixelsPerInch = 96
  TextHeight = 23
  object DBGridEh1: TDBGridEh
    Left = 8
    Top = 8
    Width = 494
    Height = 324
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataSource = DataOsn
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    OptionsEh = [dghFixed3D, dghHighlightFocus, dghClearSelection, dghEnterAsTab, dghDialogFind, dghColumnResize, dghColumnMove, dghExtendVertLines]
    ParentFont = False
    TabOrder = 0
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'zakaz'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1056#1072#1079#1084#1077#1088' '#1079#1072#1082#1072#1079#1072
        Width = 150
      end
      item
        DisplayFormat = '0.00'
        DynProps = <>
        EditButtons = <>
        FieldName = 'trud'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1058#1088#1091#1076#1086#1077#1084#1082#1086#1089#1090#1100
        Width = 150
      end
      item
        DisplayFormat = '0.00'
        DynProps = <>
        EditButtons = <>
        FieldName = 'money'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1044#1077#1085#1100#1075#1080
        Width = 150
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object b_add: TButton
    Left = 16
    Top = 338
    Width = 120
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = b_addClick
  end
  object b_del: TButton
    Left = 142
    Top = 338
    Width = 120
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = b_delClick
  end
  object ADOosn: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    BeforePost = ADOosnBeforePost
    OnPostError = ADOosnPostError
    Parameters = <>
    SQL.Strings = (
      'select * from dop_osnastka'
      'where dop_osnastka.shifr_id = '
      '355;')
    Left = 120
    Top = 80
  end
  object DataOsn: TDataSource
    DataSet = ADOosn
    Left = 160
    Top = 80
  end
end
