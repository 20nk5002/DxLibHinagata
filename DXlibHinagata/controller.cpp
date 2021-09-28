// Include

#include "DxLib.h"
#include "controller.h"

// ���̂̐錾
char controller::held_[ 16 ];
char controller::pressed_[ 16 ];
char controller::released_[ 16 ];
bool controller::save_key_[ 16 ];
XINPUT_STATE controller::xinput;

// �X�V
void controller::update()
{
    // �R���g���[���[���͎擾
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    
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