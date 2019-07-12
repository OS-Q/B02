
#include "stm32f0xx_hal.h"
#include "lis3dh_driver.h"

uint8_t  WhoAmI ; 
uint8_t  OutXL  ;       
uint8_t  OutXH  ; 
uint8_t  OutYL  ;      
uint8_t  OutYH  ;      
uint8_t  OutZL  ;      
uint8_t  OutZH  ;        
uint8_t  StatusReg  ;   
uint8_t  Ctrl_reg1;
uint8_t  Ctrl_reg2;
uint8_t  Ctrl_reg3;
uint8_t  Ctrl_reg4;
uint8_t  Ctrl_reg5;
uint8_t  Ctrl_reg6;
uint8_t Int1_dur;
uint8_t Int1_ths;
uint8_t Int1_cfg;
int16_t  MEMS_OutX  ;    /*variável responsável por montar o dado do eixo X*/
int16_t  MEMS_OutY  ;    /*variável responsável por montar o dado do eixo Y*/
int16_t  MEMS_OutZ  ;    /*variável responsável por montar o dado do eixo Z*/
int16_t  MEMS_OutX_Ref  ;/*variável responsável por ter a referencia de posicionamento X*/
int16_t  MEMS_OutY_Ref  ;/*variável responsável por ter a referencia de posicionamento Y*/
int16_t  MEMS_OutZ_Ref  ;/*variável responsável por ter a referencia de posicionamento Z*/
uint8_t  MEMS_data_ready ;/*variável responsável por informar que os dados estão prontas*/
uint8_t Int_counter,status_bit;
uint8_t StatusRegVar;
uint8_t StatusAUXVar;
AxesRaw_t leitura;
AxesRaw_t leitura_inicial;

uint16_t  Count_ms ;   				/*variável responsável pelo delay*/
uint16_t  DataReady;   				  /*variável responsável pela indicação de ODReady*/
