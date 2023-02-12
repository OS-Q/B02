#include "NuMicro.h"
#include "vcom_serial.h"
#include "hid_transfer.h"

#include "DAP.h"


/* �� Option ������ C/C++ ҳ�У�
   ���� DAP_FW_V1��   ���� CMSIS-DAP v1 �̼���ʹ�� HID ����Э��
   ������ DAP_FW_V1�� ���� CMSIS-DAP v2 �̼���ʹ�� WINUSB ����Э��
*/


void systemInit(void);
void USB_Config(void);

int main(void)
{
	systemInit();
	
	DAP_Setup();
	
	USB_Config();
		
	GPIO_SetMode(PC, (1 << 0), GPIO_MODE_OUTPUT);	// PC0 => UART RXD ״ָ̬ʾ
	GPIO_SetMode(PC, (1 << 1), GPIO_MODE_OUTPUT);	// PC1 => UART TXD ״ָ̬ʾ
	
    while(1)
    {
		usbd_hid_process();
		
		VCOM_TransferData();
		
		PC0 = !(UART2->FIFOSTS & UART_FIFOSTS_RXIDLE_Msk);
		PC1 = !(UART2->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk);
    }
}


void systemInit(void)
{
	SYS_UnlockReg();
	
	SYS->GPF_MFPH &= ~(SYS_GPF_MFPL_PF2MFP_Msk     | SYS_GPF_MFPL_PF3MFP_Msk);
    SYS->GPF_MFPH |=  (SYS_GPF_MFPL_PF2MFP_XT1_OUT | SYS_GPF_MFPL_PF3MFP_XT1_IN);
	
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);		// ʹ��HXT���ⲿ����12MHz��
    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);	// �ȴ�HXT�ȶ�

    CLK_SetCoreClock(192000000);				// ��PLL����ָ��Ƶ����Ϊϵͳʱ��
	
	CLK->PCLKDIV = (CLK_PCLKDIV_PCLK0DIV2 | CLK_PCLKDIV_PCLK1DIV2);
	
	SYS_LockReg();
	
	SystemCoreClock = 192000000;
	
	CyclesPerUs = SystemCoreClock / 1000000;
}


void USB_Config(void)
{
	SYS_UnlockReg();
	
	SYS->USBPHY &= ~SYS_USBPHY_HSUSBROLE_Msk;	// Device only
	
    SYS->USBPHY &= ~SYS_USBPHY_HSUSBACT_Msk;
    SYS->USBPHY |=  SYS_USBPHY_HSUSBEN_Msk;
    for(int i = 0; i < CyclesPerUs*10; i++) __NOP();	// at lease 10uS
    SYS->USBPHY |=  SYS_USBPHY_HSUSBACT_Msk;

    CLK_EnableModuleClock(HSUSBD_MODULE);

	SYS_LockReg();
	
	
	HSUSBD_Open(&gsHSInfo, HID_ClassRequest, NULL);
    HSUSBD_SetVendorRequest(WINUSB_VendorRequest);

    HID_Init();		// Endpoint configuration
	
	VCOM_Init();

    HSUSBD_Start();
    
    NVIC_EnableIRQ(USBD20_IRQn);
}
