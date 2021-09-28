// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode( true );

    // ��ʉ𑜓x��ύX
    SetGraphMode( 1280, 720, 32 );

    // DX���C�u�����̏�����
    if( DxLib_Init() == -1 )
    {
        // �G���[
        return 0;
    }

    // ����ʂɕ`�悷��
    SetDrawScreen( DX_SCREEN_BACK );

    // ���C�����[�v
    while( ProcessMessage() != -1 )
    {

        // ��ʏ�����
        ClearDrawScreen();

        // ����ʂɕ`�悵�����e��\�ɕ\������
        ScreenFlip();
    }

    // DX���C�u�����̔j��
    DxLib_End();

    return 0;
}