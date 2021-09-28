// Include

#include "DxLib.h"
#include "controller2.h"

// ���̂̐錾
char controller2::held_[ 16 ];
char controller2::pressed_[ 16 ];
char controller2::released_[ 16 ];
bool controller2::save_key_[ 16 ];
XINPUT_STATE controller2::xinput;

// �X�V
void controller2::update()
{
    // �R���g���[���[���͎擾
    GetJoypadXInputState( DX_INPUT_PAD2, &xinput );

    // ��x�����擾
    for( int i = 0; i < 16; ++i )
    {
        // ��ԏ�����
        held_[ i ] = 0;
        pressed_[ i ] = 0;
        released_[ i ] = 0;

        // ���݉�����Ă��邩
        if( xinput.Buttons[ i ] )
        {
            // ������Ă�
            held_[ i ] = 1;

            // �O�񉟂���Ă��邩
            if( !save_key_[ i ] )
            {
                // ������Ă��Ȃ��̂œ��͂��󂯕t����
                pressed_[ i ] = 1;    // �����ꂽ����P
                save_key_[ i ] = true;// �����ꂽ�t���O��L���ɂ���
            }
        }
        else
        {
            // �P���[�v�O�܂ł͉�����Ă�����
            if( save_key_ )
            {
                // �����ꂽ
                released_[ i ] = 1;
            }

            // ������Ă��Ȃ��̂Ńt���O�𖳌��ɂ���
            save_key_[ i ] = false;
        }
    }
}