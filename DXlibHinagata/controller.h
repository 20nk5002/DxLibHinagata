#pragma once
//class
class controller
{
private:
    static char held_[ 16 ];       //押されているキー
    static char pressed_[ 16 ];    //１度だけ押されたキー
    static char released_[ 16 ];   //離されたキー
    static bool save_key_[ 16 ];   //前回押されたか記憶するフラグ
    static XINPUT_STATE xinput;    //コントローラー構造体

public:
    static void update();   //更新
   
        //キー入力配列先頭ポインタを返す
        static const char* getHeld() { return held_; }
    static const char* getPressed() { return pressed_; }
    static const char* getReleased() { return released_; }
};