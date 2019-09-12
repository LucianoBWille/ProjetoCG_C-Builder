object Form1: TForm1
  Left = 185
  Top = 129
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 529
  ClientWidth = 1160
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
    ActivePage = TabSheetPoligonos
    TabIndex = 0
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
        ActivePage = TabSheet1
        TabIndex = 1
        TabOrder = 3
        object TabSheetdicionaPoligono: TTabSheet
          Caption = 'Adicionar'
          object PageControl3: TPageControl
            Left = 0
            Top = 0
            Width = 641
            Height = 337
            ActivePage = TabSheet2
            TabIndex = 0
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
              object Button6: TButton
                Left = 152
                Top = 88
                Width = 75
                Height = 25
                Caption = 'Button6'
                TabOrder = 1
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
          object LabelDx: TLabel
            Left = 304
            Top = 56
            Width = 13
            Height = 13
            Caption = 'Dx'
          end
          object LabelDy: TLabel
            Left = 368
            Top = 56
            Width = 13
            Height = 13
            Caption = 'Dy'
          end
          object LabelSx: TLabel
            Left = 304
            Top = 128
            Width = 12
            Height = 13
            Caption = 'Sx'
          end
          object LabelSy: TLabel
            Left = 368
            Top = 128
            Width = 12
            Height = 13
            Caption = 'Sy'
          end
          object Label2: TLabel
            Left = 304
            Top = 256
            Width = 81
            Height = 13
            Caption = #194'ngulo em Graus'
          end
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
          object EdDyTrans: TEdit
            Left = 368
            Top = 72
            Width = 57
            Height = 21
            TabOrder = 2
            Text = '0,0'
          end
          object EdSyEscalona: TEdit
            Left = 368
            Top = 144
            Width = 57
            Height = 21
            TabOrder = 3
            Text = '1,0'
          end
          object EdAnguloRotacao: TEdit
            Left = 304
            Top = 272
            Width = 121
            Height = 21
            TabOrder = 4
            Text = '0,0'
          end
          object BtnTranslada: TButton
            Left = 448
            Top = 72
            Width = 145
            Height = 25
            Caption = 'Transla'#231#227'o'
            TabOrder = 5
            OnClick = BtnTransladaClick
          end
          object BtnEscalonaNormal: TButton
            Left = 448
            Top = 144
            Width = 145
            Height = 25
            Caption = 'Escalonamento'
            TabOrder = 6
            OnClick = BtnEscalonaNormalClick
          end
          object BtnRotacionaNormal: TButton
            Left = 448
            Top = 272
            Width = 145
            Height = 25
            Caption = 'Rota'#231#227'o'
            TabOrder = 7
            OnClick = BtnRotacionaNormalClick
          end
          object EdDxTrans: TEdit
            Left = 304
            Top = 72
            Width = 57
            Height = 21
            TabOrder = 8
            Text = '0,0'
          end
          object EdSxEscalona: TEdit
            Left = 304
            Top = 144
            Width = 57
            Height = 21
            TabOrder = 9
            Text = '1,0'
          end
          object BtnRefletirTotal: TButton
            Left = 296
            Top = 208
            Width = 97
            Height = 25
            Caption = 'Refletir Total'
            TabOrder = 10
            OnClick = BtnRefletirTotalClick
          end
          object BtnRefletirEmX: TButton
            Left = 408
            Top = 208
            Width = 97
            Height = 25
            Caption = 'Refletir em X'
            TabOrder = 11
            OnClick = BtnRefletirEmXClick
          end
          object BtnRefletirEmY: TButton
            Left = 520
            Top = 208
            Width = 97
            Height = 25
            Caption = 'Refletir em Y'
            TabOrder = 12
            OnClick = BtnRefletirEmYClick
          end
          object GroupBoxHomo: TGroupBox
            Left = 56
            Top = 112
            Width = 185
            Height = 193
            Caption = ' Homogeneo '
            TabOrder = 13
            object Translada: TCheckBox
              Left = 16
              Top = 32
              Width = 97
              Height = 17
              Caption = 'Translada'
              TabOrder = 0
            end
            object Escalona: TCheckBox
              Left = 16
              Top = 72
              Width = 97
              Height = 17
              Caption = 'Escalona'
              TabOrder = 1
            end
            object Rotaciona: TCheckBox
              Left = 16
              Top = 112
              Width = 97
              Height = 17
              Caption = 'Rotaciona'
              TabOrder = 2
            end
            object BtnExeHomo: TButton
              Left = 16
              Top = 152
              Width = 153
              Height = 25
              Caption = 'Executar'
              TabOrder = 3
              OnClick = BtnExeHomoClick
            end
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
      object SpeedBtnUpRight: TSpeedButton
        Left = 136
        Top = 32
        Width = 33
        Height = 30
        OnClick = SpeedBtnUpRightClick
      end
      object SpeedBtnUpLeft: TSpeedButton
        Left = 32
        Top = 32
        Width = 31
        Height = 30
        OnClick = SpeedBtnUpLeftClick
      end
      object SpeedBtnDownLeft: TSpeedButton
        Left = 32
        Top = 136
        Width = 31
        Height = 33
        OnClick = SpeedBtnDownLeftClick
      end
      object SpeedBtnDownRight: TSpeedButton
        Left = 136
        Top = 136
        Width = 33
        Height = 33
        OnClick = SpeedBtnDownRightClick
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
        Caption = ' Tipo de Reta '
        TabOrder = 9
        OnClick = RadioGroup1Click
      end
      object RadioGroupClipping: TRadioGroup
        Left = 376
        Top = 216
        Width = 185
        Height = 153
        Caption = ' Clipping '
        TabOrder = 10
        OnClick = RadioGroupClippingClick
      end
      object BtnClipp: TButton
        Left = 376
        Top = 368
        Width = 185
        Height = 25
        Caption = 'Clipp'
        TabOrder = 11
        OnClick = BtnClippClick
      end
    end
  end
end
