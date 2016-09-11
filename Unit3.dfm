object FormOp: TFormOp
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080
  ClientHeight = 569
  ClientWidth = 814
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
    814
    569)
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 183
    Height = 23
    Caption = #1055#1077#1088#1077#1095#1077#1085#1100' '#1086#1087#1077#1088#1072#1094#1080#1081':'
  end
  object Label2: TLabel
    Left = 224
    Top = 8
    Width = 107
    Height = 23
    Caption = #1044#1077#1090#1072#1083#1100': '#1076'22'
  end
  object Shape1: TShape
    Left = 203
    Top = 0
    Width = 2
    Height = 569
    Anchors = [akLeft, akTop, akBottom]
  end
  object DBGridEh1: TDBGridEh
    Left = 216
    Top = 37
    Width = 590
    Height = 488
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataSource = DataSourceList
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    OddRowColor = clWindow
    ParentFont = False
    TabOrder = 0
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    OnAdvDrawDataCell = DBGridEh1AdvDrawDataCell
    OnKeyDown = DBGridEh1KeyDown
    OnKeyPress = DBGridEh1KeyPress
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'chex'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1062#1077#1093
        Width = 55
      end
      item
        AutoDropDown = True
        DynProps = <>
        EditButtons = <>
        FieldName = 'opname'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1054#1087#1077#1088#1072#1094#1080#1103
        Width = 150
      end
      item
        Alignment = taCenter
        DynProps = <>
        EditButtons = <>
        FieldName = 'razr'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1056#1072#1079#1088#1103#1076
        Width = 70
      end
      item
        Alignment = taLeftJustify
        DynProps = <>
        EditButtons = <>
        FieldName = 'time_min'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1042#1088#1077#1084#1103
        Width = 90
      end
      item
        Alignment = taLeftJustify
        DynProps = <>
        EditButtons = <>
        FieldName = 'pzv_min'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1055#1047#1042
        Width = 90
      end
      item
        Alignment = taCenter
        DynProps = <>
        EditButtons = <>
        FieldName = 'kol'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1083'-'#1074#1086
        Width = 70
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object Button1: TButton
    Left = 224
    Top = 531
    Width = 190
    Height = 30
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1087#1077#1088#1072#1094#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 420
    Top = 531
    Width = 190
    Height = 30
    Anchors = [akLeft, akBottom]
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1086#1087#1077#1088#1072#1094#1080#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 37
    Width = 185
    Height = 524
    Anchors = [akLeft, akTop, akBottom]
    Lines.Strings = (
      '1 '#1090#1086#1082'.'#1095#1087#1091' EEN320')
    ScrollBars = ssVertical
    TabOrder = 3
    WordWrap = False
  end
  object ADOlist: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    BeforeInsert = ADOlistBeforeInsert
    AfterInsert = ADOlistAfterInsert
    AfterPost = ADOlistAfterPost
    OnPostError = ADOlistPostError
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM list'
      'WHERE list.detail = 355'
      'ORDER BY list.num_op;')
    Left = 352
    Top = 256
    object ADOlistid: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object ADOlistdetail: TIntegerField
      FieldName = 'detail'
    end
    object ADOlistoperation: TIntegerField
      FieldName = 'operation'
    end
    object ADOlisttime_min: TFloatField
      FieldName = 'time_min'
      OnSetText = ADOlisttime_minSetText
    end
    object ADOlistrazr: TIntegerField
      FieldName = 'razr'
      MaxValue = 8
    end
    object ADOlistpzv_min: TFloatField
      FieldName = 'pzv_min'
      OnSetText = ADOlisttime_minSetText
    end
    object ADOlistkol: TIntegerField
      FieldName = 'kol'
    end
    object ADOlistnum_op: TFloatField
      FieldName = 'num_op'
    end
    object ADOlistchex: TWideStringField
      FieldName = 'chex'
      Size = 8
    end
    object ADOlistopname: TStringField
      FieldKind = fkLookup
      FieldName = 'opname'
      LookupDataSet = ADOoperation
      LookupKeyFields = 'id'
      LookupResultField = 'oname'
      KeyFields = 'operation'
      Lookup = True
    end
  end
  object ADOoperation: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    AfterOpen = ADOoperationAfterOpen
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM operation'
      'WHERE operation.group = 2'
      'ORDER BY operation.oname;')
    Left = 64
    Top = 224
  end
  object DataSourceList: TDataSource
    DataSet = ADOlist
    Left = 392
    Top = 256
  end
  object DataSourceOp: TDataSource
    DataSet = ADOoperation
    Left = 104
    Top = 224
  end
end
