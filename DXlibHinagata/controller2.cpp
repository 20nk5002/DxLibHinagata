// Include

#include "DxLib.h"
#include "controller2.h"

// 実体の宣言
char controller2::held_[ 16 ];
char controller2::pressed_[ 16 ];
char controller2::released_[ 16 ];
bool controller2::save_key_[ 16 ];
XINPUT_STATE controller2::xinput;

// 更新
void controller2::update()
{
    // コントローラー入力取得
    GetJoypadXInputState( DX_INPUT_PAD2, &xinput );

    // 一度だけ取得
    for( int i = 0; i < 16; ++i )
    {
        // 状態初期化
        held_[ i ] = 0;
        pressed_[ i ] = 0;
        released_[ i ] = 0;

        // 現在押されているか
        if( xinput.Buttons[ i ] )
        {
            // 押されてる
            held_[ i ] = 1;

            // 前回押されているか
            if( !save_key_[ i ] )
            {
                // 押されていないので入力を受け付ける
                pressed_[ i ] = 1;    // 押されたから１
                save_key_[ i ] = true;// 押されたフラグを有効にする
            }
        }
        else
        {
            // １ループ前までは押されていたか
            if( save_key_ )
            {
                // 離された
                released_[ i ] = 1;
            }

            // 押されていないのでフラグを無効にする
            save_key_[ i ] = false;
        }
    }
}