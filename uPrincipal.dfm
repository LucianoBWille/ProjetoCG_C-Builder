object Form1: TForm1
  Left = 178
  Top = 144
  Width = 1176
  Height = 568
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelCoordenadaVP: TLabel
    Left = 363
    Top = 507
    Width = 3
    Height = 13
  end
  object LabelCoordenadaMundo: TLabel
    Left = 2
    Top = 507
    Width = 3
    Height = 13
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 503
    Height = 503
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 501
      Height = 501
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
    end
  end
  object PageControl1: TPageControl
    Left = 503
    Top = 0
    Width = 657
    Height = 529
    ActivePage = TabSheetMundoVP
    TabIndex = 1
    TabOrder = 1
    object TabSheetPoligonos: TTabSheet
      Caption = 'Poligonos'
      object LabelPoligonos: TLabel
        Left = 131
        Top = 16
        Width = 46
        Height = 13
        Caption = 'Poligonos'
      end
      object LabelPontos: TLabel
        Left = 352
        Top = 16
        Width = 33
        Height = 13
        Caption = 'Pontos'
      end
      object BtnDesselecionar: TButton
        Left = 8
        Top = 8
        Width = 105
        Height = 25
        Caption = 'Desselecionar Tudo'
        TabOrder = 0
        OnClick = BtnDesselecionarClick
      end
      object ListBoxPoligonos: TListBox
        Left = 120
        Top = 32
        Width = 217
        Height = 97
        ItemHeight = 13
        TabOrder = 1
        OnClick = ListBoxPoligonosClick
      end
      object ListBoxPontos: TListBox
        Left = 344
        Top = 32
        Width = 297
        Height = 97
        ItemHeight = 13
        TabOrder = 2
        OnClick = ListBoxPontosClick
      end
      object PageControl2: TPageControl
        Left = 0
        Top = 136
        Width = 649
        Height = 369
        ActivePage = TabSheetdicionaPoligono
        TabIndex = 0
        TabOrder = 3
        object TabSheetdicionaPoligono: TTabSheet
          Caption = 'Adicionar'
          object PageControl3: TPageControl
            Left = 0
            Top = 0
            Width = 641
            Height = 337
            ActivePage = TabSheet3
            TabIndex = 1
            TabOrder = 0
            object TabSheet2: TTabSheet
              Caption = 'Poligono'
              object BtnNovoComMouse: TButton
                Left = 8
                Top = 8
                Width = 105
                Height = 25
                Caption = 'Novo Com Mouse'
                TabOrder = 0
                OnClick = BtnNovoComMouseClick
              end
            end
            object TabSheet3: TTabSheet
              Caption = 'Circulo'
              ImageIndex = 1
              object EdRaioCirculo: TEdit
                Left = 8
                Top = 24
                Width = 121
                Height = 21
                TabOrder = 0
                Text = '10'
              end
              object BtnNovoCirculo: TButton
                Left = 152
                Top = 24
                Width = 75
                Height = 25
                Caption = 'Novo Circulo'
                TabOrder = 1
                OnClick = BtnNovoCirculoClick
              end
            end
          end
        end
        object TabSheet1: TTabSheet
          Caption = 'Editar'
          ImageIndex = 2
          object BtnRemoverPonto: TButton
            Left = 8
            Top = 40
            Width = 105
            Height = 25
            Caption = 'Remover Ponto'
            TabOrder = 0
            OnClick = BtnRemoverPontoClick
          end
          object BtnRemoverPoligono: TButton
            Left = 8
            Top = 8
            Width = 105
            Height = 25
            Caption = 'Remover Poligono'
            TabOrder = 1
            OnClick = BtnRemoverPoligonoClick
          end
        end
      end
    end
    object TabSheetMundoVP: TTabSheet
      Caption = 'Mundo / VP'
      ImageIndex = 1
      object SpeedBtnCenter: TSpeedButton
        Left = 72
        Top = 72
        Width = 57
        Height = 57
        Caption = 'CENTER'
        OnClick = SpeedBtnCenterClick
      end
      object SpeedBtnDown: TSpeedButton
        Left = 72
        Top = 136
        Width = 57
        Height = 57
        Caption = 'DOWN'
        OnClick = SpeedBtnDownClick
      end
      object SpeedBtnLeft: TSpeedButton
        Left = 8
        Top = 72
        Width = 57
        Height = 57
        Caption = 'LEFT'
        OnClick = SpeedBtnLeftClick
      end
      object SpeedBtnRight: TSpeedButton
        Left = 136
        Top = 72
        Width = 57
        Height = 57
        Caption = 'RIGHT'
        OnClick = SpeedBtnRightClick
      end
      object SpeedBtnUp: TSpeedButton
        Left = 72
        Top = 8
        Width = 57
        Height = 57
        Caption = 'UP'
        OnClick = SpeedBtnUpClick
      end
      object LabelXmax: TLabel
        Left = 352
        Top = 16
        Width = 26
        Height = 13
        Caption = 'Xmax'
      end
      object LabelYmax: TLabel
        Left = 495
        Top = 16
        Width = 26
        Height = 13
        Caption = 'Ymax'
      end
      object LabelXmin: TLabel
        Left = 352
        Top = 64
        Width = 23
        Height = 13
        Caption = 'Xmin'
      end
      object LabelYmin: TLabel
        Left = 498
        Top = 64
        Width = 23
        Height = 13
        Caption = 'Ymin'
      end
      object Label1: TLabel
        Left = 192
        Top = 8
        Width = 119
        Height = 13
        Caption = 'Porcentagem dos passos'
      end
      object SpeedButton1: TSpeedButton
        Left = 136
        Top = 32
        Width = 33
        Height = 30
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 32
        Top = 32
        Width = 31
        Height = 30
        OnClick = SpeedButton2Click
      end
      object SpeedButton3: TSpeedButton
        Left = 32
        Top = 136
        Width = 31
        Height = 33
        OnClick = SpeedButton3Click
      end
      object SpeedButton4: TSpeedButton
        Left = 136
        Top = 136
        Width = 33
        Height = 33
        OnClick = SpeedButton4Click
      end
      object BtnZoomIn: TButton
        Left = 214
        Top = 64
        Width = 75
        Height = 25
        Caption = 'ZoomIn'
        TabOrder = 0
        OnClick = BtnZoomInClick
      end
      object BtnZoomOut: TButton
        Left = 214
        Top = 112
        Width = 75
        Height = 25
        Caption = 'ZoomOut'
        TabOrder = 1
        OnClick = BtnZoomOutClick
      end
      object EdYmax: TEdit
        Left = 496
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '250,0'
      end
      object EdXmax: TEdit
        Left = 352
        Top = 32
        Width = 121
        Height = 21
        TabOrder = 3
        Text = '250,0'
      end
      object EdXmin: TEdit
        Left = 352
        Top = 80
        Width = 121
        Height = 21
        TabOrder = 4
        Text = '-250,0'
      end
      object EdYmin: TEdit
        Left = 496
        Top = 80
        Width = 121
        Height = 21
        TabOrder = 5
        Text = '-250,0'
      end
      object BtnAtulizar: TButton
        Left = 350
        Top = 120
        Width = 123
        Height = 33
        Caption = 'Atualizar'
        TabOrder = 6
        OnClick = BtnAtulizarClick
      end
      object BtnResetar: TButton
        Left = 494
        Top = 120
        Width = 123
        Height = 33
        Caption = 'Resetar'
        TabOrder = 7
        OnClick = BtnResetarClick
      end
      object Edit1: TEdit
        Left = 216
        Top = 24
        Width = 73
        Height = 21
        TabOrder = 8
        Text = '0,1'
      end
      object RadioGroup1: TRadioGroup
        Left = 16
        Top = 324
        Width = 185
        Height = 129
        Caption = 'Tipo de Reta'
        TabOrder = 9
        OnClick = RadioGroup1Click
      end
    end
  end
end
