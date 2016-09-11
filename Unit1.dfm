object FormMain: TFormMain
  Left = 0
  Top = 0
  ActiveControl = DBGridEh1
  Caption = #1052#1072#1088#1096#1088#1091#1090#1085#1099#1077' '#1082#1072#1088#1090#1099' '#1094#1077#1093#1072' '#8470'17'
  ClientHeight = 565
  ClientWidth = 713
  Color = clBtnFace
  Constraints.MinHeight = 560
  Constraints.MinWidth = 710
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  DesignSize = (
    713
    565)
  PixelsPerInch = 96
  TextHeight = 19
  object DBGridEh1: TDBGridEh
    Left = 8
    Top = 39
    Width = 697
    Height = 461
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataSource = DataSource1
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    Options = [dgEditing, dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
    OptionsEh = [dghFixed3D, dghHighlightFocus, dghClearSelection, dghAutoSortMarking, dghRowHighlight, dghDialogFind, dghColumnResize, dghExtendVertLines]
    ParentFont = False
    ReadOnly = True
    SortLocal = True
    STFilter.Local = True
    TabOrder = 0
    TitleParams.Font.Charset = DEFAULT_CHARSET
    TitleParams.Font.Color = clWindowText
    TitleParams.Font.Height = -19
    TitleParams.Font.Name = 'Tahoma'
    TitleParams.Font.Style = []
    TitleParams.MultiTitle = True
    TitleParams.ParentFont = False
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    OnDblClick = DBGridEh1DblClick
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'shifr'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1064#1080#1092#1088
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'num_kart'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #8470' '#1084#1072#1088#1096#1088#1091#1090#1085#1086#1081' '#1082#1072#1088#1090#1099
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'num_zakaz'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #8470' '#1079#1072#1082#1072#1079#1072
        Width = 120
      end
      item
        Alignment = taRightJustify
        DynProps = <>
        EditButtons = <>
        FieldName = 'date'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = []
        Footers = <>
        Title.Caption = #1044#1072#1090#1072' '#1074#1074#1086#1076#1072
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'id'
        Footers = <>
        Title.SortIndex = 1
        Title.SortMarker = smDownEh
        Visible = False
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 713
    Height = 33
    ButtonHeight = 27
    Caption = 'ToolBar1'
    DrawingStyle = dsGradient
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    List = True
    ParentFont = False
    TabOrder = 1
    object Label1: TLabel
      Left = 0
      Top = 0
      Width = 105
      Height = 27
      AutoSize = False
      Caption = ' '#1053#1072#1081#1090#1080' '#1096#1080#1092#1088': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 105
      Top = 0
      Width = 135
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyDown = Edit1KeyDown
    end
    object b_find: TBitBtn
      Left = 240
      Top = 0
      Width = 33
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      Glyph.Data = {
        F6040000424DF604000000000000360000002800000015000000130000000100
        180000000000C004000000000000000000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FEFEFEFCFCFCB3ACA8F7F7F7F7F7F7FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FCFCFCB59F94683A22977868977868F8F7F7FDFDFDFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FEFEFEE3D8D28A553882492B82492BA9826EF8F7F7FDFDFDFEFEFEFDFDFDFDFD
        FDFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFCFCFCE8DBD49F62409F6240995733B98C74F9F7F7F0EAE7DECCC2E1CF
        C6F4F0EEFCFCFCFCFCFCFEFEFEFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFCFCFCE8DBD49F62409F6240995733B98C74F9F7F7F0EAE7DECCC2E1CF
        C6F4F0EEFCFCFCFCFCFCFEFEFEFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFCFCFCEBDED5EBDED5B06E45AB6538BA815CAB6538AB6538AB65
        38AD693FD6B7A3D6B7A3FCFCFCFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFCFCFCFCFCFCECDFD5B6713FB46D39B87543CFA383CDA0
        7FB6713FB46D39B46D39DABBA3FCFCFCFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFDFDFDFDFDFDEAD8C9BB7539C1834DF4EEE9FBFBFBFBFB
        FBF0E5DCBD7B42BD7B42BC783DF3ECE5FEFEFEFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFCFCFCFCFCFCDBB794C07C39E0C2A5FCFCFCFFFFFFFFFF
        FFFCFCFCD9B28CD9B28CC07C39E4CCB3FDFDFDFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFCFCFCFCFCFCDDB88FC58439E5CBAFFDFDFDFFFFFFFFFF
        FFFCFCFCDEBC96DEBC96C58439E5CBAFFDFDFDFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFDFDFDFDFDFDE9D4B7C98C39D4A464F9F8F7FDFDFDFCFC
        FCF7F4F0CE9A52CE9A52C98C39F1E6D8FEFEFEFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFEFEFEFEFEFEF9F8F7D6AB64CD9439D7AB65E9D4B3E7D1
        ADD5A55ACD9439CD9439DAB373FBFBFBFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFEFEFEFEFEFEF9F8F7D6AB64CD9439D7AB65E9D4B3E7D1
        ADD5A55ACD9439CD9439DAB373FBFBFBFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDF5EFE1DCB85FD4A736D4A736D4A7
        36D4A736DEBE6EDEBE6EF6F4ECFDFDFDFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFAF9F7EEE1B3E8D389E9D5
        90EFE3BAFBFBFBFBFBFBFDFDFDFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEFDFDFDFCFCFCFCFC
        FCFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00}
      ParentFont = False
      TabOrder = 1
      OnClick = b_findClick
    end
    object b_cancel_find: TBitBtn
      Left = 273
      Top = 0
      Width = 33
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      Glyph.Data = {
        F6040000424DF604000000000000360000002800000015000000130000000100
        180000000000C004000000000000000000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
        FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
        FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEB39C8AB39C8AD3C6BBFEFEFEFEFEFEFDFDFDFCFCFCFCFC
        FCD3C6BBB39C8AB39C8AFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEB39C8AB39C8AD3C6BBFEFEFEFEFEFEFDFDFDFCFCFCFCFC
        FCD3C6BBB39C8AB39C8AFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFED8CABDD8CABD8C6441D8CABDD8CABDFDFDFDD8CABDD8CA
        BD8C6441D8CABDD8CABDFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFEFEFEFEFEFEDDCFC09C73489C7348DDCFC09C73489C73
        48DDCFC0FEFEFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFEFEFEFEFEFEDDCFC09C73489C7348DDCFC09C73489C73
        48DDCFC0FEFEFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEE3D4C3E3D4C3AC814EE3D4C3E3D4
        C3FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEFEFEFEFEFEFEE8D9C5BB8E55BB8E55E8D9C5BB8E55BB8E
        55E8D9C5FEFEFEFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEFEFEFEFEFEFEE8D9C5BB8E55BB8E55E8D9C5BB8E55BB8E
        55E8D9C5FEFEFEFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEEBDCC7EBDCC7C79A5BEBDCC7EBDCC7FEFEFEEBDCC7EBDC
        C7C79A5BEBDCC7EBDCC7FEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEE2C7A0E2C7A0EEDFC9FEFEFEFEFEFEFFFFFFFEFEFEFEFE
        FEEEDFC9E2C7A0E2C7A0FEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFEFEFEE2C7A0E2C7A0EEDFC9FEFEFEFEFEFEFFFFFFFEFEFEFEFE
        FEEEDFC9E2C7A0E2C7A0FEFEFEFEFEFEFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00}
      ParentFont = False
      TabOrder = 2
      OnClick = b_cancel_findClick
    end
  end
  object b_add: TButton
    Left = 8
    Top = 506
    Width = 203
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1084#1072#1088#1096'. '#1082#1072#1088#1090#1091
    TabOrder = 2
    OnClick = b_addClick
  end
  object b_copy: TButton
    Left = 8
    Top = 534
    Width = 203
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1096#1080#1092#1088
    TabOrder = 3
    OnClick = b_copyClick
  end
  object b_edit: TButton
    Left = 217
    Top = 506
    Width = 203
    Height = 53
    Anchors = [akLeft, akBottom]
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' / '#1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 4
    WordWrap = True
    OnClick = b_editClick
  end
  object b_add_print: TButton
    Left = 426
    Top = 506
    Width = 203
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1087#1077#1095#1072#1090#1100
    TabOrder = 5
    OnClick = b_add_printClick
  end
  object b_print: TButton
    Left = 426
    Top = 534
    Width = 203
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1053#1072#1087#1077#1095#1072#1090#1072#1090#1100' '#1076#1086#1073#1072#1074#1083#1077#1085#1085#1086#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = b_printClick
  end
  object b_del: TButton
    Left = 635
    Top = 506
    Width = 70
    Height = 53
    Anchors = [akRight, akBottom]
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1096#1080#1092#1088
    TabOrder = 7
    WordWrap = True
    OnClick = b_delClick
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\Marsh17.mdb;Pers' +
      'ist Security Info=False;'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 160
    Top = 230
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    AfterPost = ADOQuery1AfterPost
    OnPostError = ADOQuery1PostError
    Parameters = <>
    SQL.Strings = (
      'select * from m_karta'
      ''
      'order by id desc;')
    Left = 208
    Top = 232
    object ADOQuery1id: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object ADOQuery1shifr: TWideStringField
      FieldName = 'shifr'
    end
    object ADOQuery1num_kart: TWideStringField
      FieldName = 'num_kart'
      Size = 10
    end
    object ADOQuery1num_zakaz: TWideStringField
      FieldName = 'num_zakaz'
      Size = 10
    end
    object ADOQuery1name: TWideStringField
      FieldName = 'name'
      Size = 30
    end
    object ADOQuery1zakazchik: TWideStringField
      FieldName = 'zakazchik'
      Size = 6
    end
    object ADOQuery1igroup: TIntegerField
      FieldName = 'igroup'
    end
    object ADOQuery1remont: TWordField
      FieldName = 'remont'
    end
    object ADOQuery1kol_shifrov: TIntegerField
      FieldName = 'kol_shifrov'
    end
    object ADOQuery1kol_tech: TIntegerField
      FieldName = 'kol_tech'
    end
    object ADOQuery1metal: TWordField
      FieldName = 'metal'
    end
    object ADOQuery1date: TDateTimeField
      FieldName = 'date'
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 256
    Top = 232
  end
  object ADOsql: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 448
    Top = 400
  end
  object ADOexecsql: TADOCommand
    Connection = ADOConnection1
    Parameters = <>
    Left = 416
    Top = 400
  end
end
