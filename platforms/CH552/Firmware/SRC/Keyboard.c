/**
 * @author Chi Zhang
 * @date 2023/1/13
 */

#include "Keyboard.h"

#include "string.h"
#include "Uart.h"
#include "AT.h"

extern UINT8X Ep4Buffer[];

BOOL Keyboard_Flag = 0;
UINT8I TargetKey;

void Keyboard_Press(void){
	if(TargetKey == 0xFF)
		return;
	Keyboard_Flag = 0;
	Ep4Buffer[2] = TargetKey;
	UEP4_T_LEN = 8;                                             //�ϴ����ݳ���
	UEP4_CTRL = UEP4_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;                //������ʱ�ϴ����ݲ�Ӧ��ACK

	while(Keyboard_Flag == 0)
		;    /*�ȴ���һ���������*/
	Ep4Buffer[2] = 0;
	UEP4_T_LEN = 8;                                             //�ϴ����ݳ���
	UEP4_CTRL = UEP4_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;                //������ʱ�ϴ����ݲ�Ӧ��ACK
}
