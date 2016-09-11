object FormDetail: TFormDetail
  Left = 0
  Top = 0
  Caption = #1052#1072#1088#1096#1088#1091#1090#1085#1072#1103' '#1082#1072#1088#1090#1072
  ClientHeight = 595
  ClientWidth = 900
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 870
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  DesignSize = (
    900
    595)
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1064#1080#1092#1088
    Layout = tlCenter
  end
  object Label2: TLabel
    Left = 8
    Top = 52
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1052#1072#1088#1096#1088#1091#1090' '#1082#1072#1088#1090#1072
    Layout = tlCenter
  end
  object Label3: TLabel
    Left = 8
    Top = 90
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #8470' '#1079#1072#1082#1072#1079#1072
    Layout = tlCenter
  end
  object Label4: TLabel
    Left = 8
    Top = 127
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
    Layout = tlCenter
  end
  object Label5: TLabel
    Left = 8
    Top = 164
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1047#1072#1082#1072#1079#1095#1080#1082
    Layout = tlCenter
  end
  object Label6: TLabel
    Left = 8
    Top = 201
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1043#1088#1091#1087#1087#1072
    Layout = tlCenter
  end
  object Label7: TLabel
    Left = 8
    Top = 238
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1056#1077#1084#1086#1085#1090
    Layout = tlCenter
  end
  object Label8: TLabel
    Left = 8
    Top = 275
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1050'-'#1074#1086' '#1087#1086' '#1079#1072#1082#1072#1079#1091
    Layout = tlCenter
  end
  object Label9: TLabel
    Left = 8
    Top = 312
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1050'-'#1074#1086' '#1090#1077#1093#1085#1086#1083#1086#1075#1080#1081
    Layout = tlCenter
  end
  object Label10: TLabel
    Left = 8
    Top = 349
    Width = 150
    Height = 31
    Alignment = taRightJustify
    AutoSize = False
    Caption = #1052#1077#1090#1072#1083#1083
    Layout = tlCenter
  end
  object Shape1: TShape
    Left = 325
    Top = 0
    Width = 2
    Height = 600
    Anchors = [akLeft, akTop, akBottom]
  end
  object Label11: TLabel
    Left = 56
    Top = 392
    Width = 209
    Height = 49
    Alignment = taCenter
    Anchors = [akLeft, akBottom]
    AutoSize = False
    Caption = #1055#1077#1088#1077#1093#1086#1076' '#1082' '#1087#1077#1088#1077#1095#1085#1102' '#1086#1087#1077#1088#1072#1094#1080#1081' '#1087#1086' F2'
    WordWrap = True
  end
  object Label12: TLabel
    Left = 352
    Top = 6
    Width = 88
    Height = 29
    Caption = #1044#1077#1090#1072#1083#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label13: TLabel
    Left = 352
    Top = 314
    Width = 337
    Height = 29
    Anchors = [akLeft, akBottom]
    Caption = #1047#1072#1075#1086#1090#1086#1074#1082#1080' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1076#1077#1090#1072#1083#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Shape2: TShape
    Left = 327
    Top = 304
    Width = 580
    Height = 2
    Anchors = [akLeft, akRight, akBottom]
  end
  object Label14: TLabel
    Left = 40
    Top = 472
    Width = 249
    Height = 49
    Alignment = taCenter
    Anchors = [akLeft, akBottom]
    AutoSize = False
    Caption = #1055#1077#1088#1077#1093#1086#1076' '#1082' '#1076#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086#1081' '#1086#1089#1085#1072#1089#1090#1082#1077' '#1087#1086' F4'
    WordWrap = True
  end
  object e_shifr: TDBEditEh
    Left = 164
    Top = 16
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'shifr'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_marsh_kart: TDBEditEh
    Left = 164
    Top = 53
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'num_kart'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 1
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_num_zak: TDBEditEh
    Left = 164
    Top = 89
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'num_zakaz'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 2
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_name: TDBEditEh
    Left = 164
    Top = 127
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'name'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 3
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_zakaz: TDBEditEh
    Left = 164
    Top = 164
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'zakazchik'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 4
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_group: TDBComboBoxEh
    Left = 164
    Top = 201
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'igroup'
    DataSource = FormMain.DataSource1
    DynProps = <>
    DropDownBox.Width = 210
    EditButtons = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      #1056#1077#1079#1094#1099
      #1056#1077#1078#1091#1097#1072#1103
      #1056#1077#1079#1100#1073#1072
      #1057#1083#1086#1078#1085#1086'-'#1092#1072#1089#1086#1085#1085#1072#1103
      #1052#1077#1088#1080#1090#1077#1083#1100#1085#1072#1103
      #1058#1086#1095#1085#1072#1103' '#1084#1077#1093#1072#1085#1080#1082#1072
      #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090' II '#1087#1086#1088#1103#1076#1082#1072)
    KeyItems.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7')
    ParentFont = False
    TabOrder = 5
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_remont: TDBComboBoxEh
    Left = 164
    Top = 238
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'remont'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      #1053#1077#1090
      #1044#1072)
    KeyItems.Strings = (
      '0'
      '1')
    ParentFont = False
    TabOrder = 6
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_kol_shifr: TDBEditEh
    Left = 164
    Top = 275
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'kol_shifrov'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 7
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_kol_tech: TDBEditEh
    Left = 164
    Top = 312
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'kol_tech'
    DataSource = FormMain.DataSource1
    DynProps = <>
    EditButtons = <>
    TabOrder = 8
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object e_metal: TDBComboBoxEh
    Left = 164
    Top = 349
    Width = 150
    Height = 31
    Alignment = taLeftJustify
    DataField = 'metal'
    DataSource = FormMain.DataSource1
    DynProps = <>
    DropDownBox.Width = 230
    EditButtons = <>
    Items.Strings = (
      #1053#1077' '#1086#1073#1077#1089#1087#1077#1095#1077#1085' '#1084#1077#1090#1072#1083#1083#1086#1084
      #1064#1080#1092#1088' '#1080#1079#1075#1086#1090#1086#1074#1083#1077#1085
      #1052#1077#1090#1072#1083#1083' '#1079#1072#1082#1072#1079#1072#1085
      #1055#1086' '#1080#1079#1084#1077#1085#1077#1085#1085#1086#1084#1091' '#1095#1077#1088#1090#1077#1078#1091)
    KeyItems.Strings = (
      '0'
      '1'
      '2'
      '3')
    TabOrder = 9
    Visible = True
    OnKeyUp = e_shifrKeyDown
  end
  object DBGridDetail: TDBGridEh
    Left = 338
    Top = 41
    Width = 549
    Height = 217
    Anchors = [akLeft, akTop, akRight, akBottom]
    AutoFitColWidths = True
    DataSource = DataSourceDetail
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    ParentFont = False
    TabOrder = 10
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    OnDblClick = DBGridDetailDblClick
    OnEnter = DBGridDetailEnter
    OnKeyDown = DBGridDetailKeyDown
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'number'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1053#1086#1084#1077#1088
        Width = 100
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'dname'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 250
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'kol_na_shifr'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1076#1077#1090#1072#1083#1077#1081
        Width = 80
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object DBGridZag: TDBGridEh
    Left = 343
    Top = 349
    Width = 549
    Height = 200
    Anchors = [akLeft, akRight, akBottom]
    AutoFitColWidths = True
    DataSource = DataSourceZag
    DynProps = <>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    IndicatorOptions = [gioShowRowIndicatorEh]
    ParentFont = False
    TabOrder = 11
    VertScrollBar.VisibleMode = sbAlwaysShowEh
    OnKeyPress = DBGridZagKeyPress
    OnKeyUp = DBGridZagKeyUp
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'priznak'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1055#1088#1080#1079#1085#1072#1082
        Width = 55
      end
      item
        AutoDropDown = True
        DynProps = <>
        EditButtons = <>
        FieldName = 'lookup'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1052#1072#1090#1077#1088#1080#1072#1083
        Width = 150
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'razmer'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1056#1072#1079#1084#1077#1088
        Width = 150
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'kol_zag'
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1083'-'#1074#1086' '#1079#1072#1075'.'
        Width = 80
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object b_add_det: TButton
    Left = 352
    Top = 264
    Width = 160
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1077#1090#1072#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = b_add_detClick
  end
  object b_del_det: TButton
    Left = 518
    Top = 264
    Width = 160
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1076#1077#1090#1072#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = b_del_detClick
  end
  object b_info_det: TButton
    Left = 681
    Top = 264
    Width = 160
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1076#1077#1090#1072#1083#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = b_info_detClick
  end
  object b_add_zag: TButton
    Left = 352
    Top = 555
    Width = 160
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1075#1086#1090#1086#1074#1082#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = b_add_zagClick
  end
  object b_del_zag: TButton
    Left = 518
    Top = 555
    Width = 160
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1075#1086#1090#1086#1074#1082#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
    OnClick = b_del_zagClick
  end
  object b_dop_osn: TButton
    Left = 80
    Top = 522
    Width = 161
    Height = 65
    Anchors = [akLeft, akBottom]
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1086#1089#1085#1072#1089#1090#1082#1072
    TabOrder = 17
    WordWrap = True
    OnClick = b_dop_osnClick
  end
  object ADOdetail: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    AfterInsert = ADOdetailAfterInsert
    BeforePost = ADOdetailBeforePost
    AfterPost = ADOdetailAfterPost
    AfterScroll = ADOdetailAfterScroll
    OnPostError = ADOdetailPostError
    Parameters = <>
    SQL.Strings = (
      'select * from detail'
      'where'
      'shifr_id = 90'
      
        'order by IIf( Val(IIf(number Is Null, "!", number)) =0, 9999, Va' +
        'l(number) ), id ;')
    Left = 464
    Top = 110
  end
  object ADOzag: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    AfterInsert = ADOzagAfterInsert
    BeforePost = ADOzagBeforePost
    AfterPost = ADOzagAfterPost
    OnPostError = ADOzagPostError
    Parameters = <>
    SQL.Strings = (
      'select * from zagotov'
      'where zagotov.detail = 401;')
    Left = 512
    Top = 454
    object ADOzaglookup: TStringField
      FieldKind = fkLookup
      FieldName = 'lookup'
      LookupDataSet = ADOmaterial
      LookupKeyFields = 'id'
      LookupResultField = 'mname'
      KeyFields = 'material'
      Lookup = True
    end
    object ADOzagid: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object ADOzagdetail: TIntegerField
      FieldName = 'detail'
    end
    object ADOzagmaterial: TIntegerField
      FieldName = 'material'
    end
    object ADOzagmassa: TFloatField
      FieldName = 'massa'
    end
    object ADOzagrazmer: TWideStringField
      FieldName = 'razmer'
    end
    object ADOzagpriznak: TWideStringField
      FieldName = 'priznak'
      Size = 1
    end
    object ADOzagkol_zag: TIntegerField
      FieldName = 'kol_zag'
    end
    object ADOzagkodzag: TWideStringField
      FieldName = 'kodzag'
      Size = 2
    end
  end
  object DataSourceDetail: TDataSource
    DataSet = ADOdetail
    Left = 520
    Top = 110
  end
  object DataSourceZag: TDataSource
    DataSet = ADOzag
    Left = 552
    Top = 454
  end
  object ADOmaterial: TADOQuery
    Connection = FormMain.ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from material;')
    Left = 600
    Top = 400
  end
  object DataSourceMaterial: TDataSource
    DataSet = ADOmaterial
    Left = 632
    Top = 400
  end
  object ADOsqlexec: TADOQuery
    Connection = FormMain.ADOConnection1
    Parameters = <>
    Left = 32
    Top = 408
  end
  object ADOdbf: TADOQuery
    Parameters = <>
    Left = 72
    Top = 408
  end
end
