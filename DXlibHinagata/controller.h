#pragma once
//class
class controller
{
private:
    static char held_[ 16 ];       //������Ă���L�[
    static char pressed_[ 16 ];    //�P�x���������ꂽ�L�[
    static char released_[ 16 ];   //�����ꂽ�L�[
    static bool save_key_[ 16 ];   //�O�񉟂��ꂽ���L������t���O
    static XINPUT_STATE xinput;    //�R���g���[���[�\����

public:
    static void update();   //�X�V
   
        //�L�[���͔z��擪�|�C���^��Ԃ�
        static const char* getHeld() { return held_; }
    static const char* getPressed() { return pressed_; }
    static const char* getReleased() { return released_; }
};