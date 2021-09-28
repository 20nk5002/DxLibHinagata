// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    // ウィンドウモードに設定
    ChangeWindowMode( true );

    // 画面解像度を変更
    SetGraphMode( 1280, 720, 32 );

    // DXライブラリの初期化
    if( DxLib_Init() == -1 )
    {
        // エラー
        return 0;
    }

    // 裏画面に描画する
    SetDrawScreen( DX_SCREEN_BACK );

    // メインループ
    while( ProcessMessage() != -1 )
    {

        // 画面初期化
        ClearDrawScreen();

        // 裏画面に描画した内容を表に表示する
        ScreenFlip();
    }

    // DXライブラリの破棄
    DxLib_End();

    return 0;
}