#ifndef __CONST_VAR_H
#define __CONST_VAR_H


extern uint8_t  WhoAmI ;         /*variável responsável por ler o registrador WHO_AM_I*/
extern uint8_t  OutXL  ;         /*variável responsável por ler o registrador OUT_X_L*/
extern uint8_t  OutXH  ;         /*variável responsável por ler o registrador OUT_X_H*/
extern uint8_t  OutYL  ;         /*variável responsável por ler o registrador OUT_Y_L*/
extern uint8_t  OutYH  ;         /*variável responsável por ler o registrador OUT_Y_H*/
extern uint8_t  OutZL  ;         /*variável responsável por ler o registrador OUT_Z_L*/
extern uint8_t  OutZH  ;         /*variável responsável por ler o registrador OUT_Z_H*/
extern uint8_t  StatusReg  ;     /*variável responsável por ler o registrador STATUS_REG2*/
extern uint8_t  ctrl_reg[7];
//extern uint8_t  Ctrl_reg1;
//extern uint8_t  Ctrl_reg2;
//extern uint8_t  Ctrl_reg3;
//extern uint8_t  Ctrl_reg4;
//extern uint8_t  Ctrl_reg5;
//extern uint8_t  Ctrl_reg6;
extern uint8_t Int1_dur;
extern uint8_t Int1_ths;
extern uint8_t Int1_cfg;
extern int16_t  MEMS_OutX  ;    /*variável responsável por montar o dado do eixo X*/
extern int16_t  MEMS_OutY  ;    /*variável responsável por montar o dado do eixo Y*/
extern int16_t  MEMS_OutZ  ;    /*variável responsável por montar o dado do eixo Z*/
extern int16_t  MEMS_OutX_Ref  ;/*variável responsável por ter a referencia de posicionamento X*/
extern int16_t  MEMS_OutY_Ref  ;/*variável responsável por ter a referencia de posicionamento Y*/
extern int16_t  MEMS_OutZ_Ref  ;/*variável responsável por ter a referencia de posicionamento Z*/
extern uint8_t  MEMS_data_ready ;    /*variável responsável por informar que os dados estão prontas*/


extern uint16_t  Count_ms ;   				/*variável responsável pelo delay*/
extern uint16_t  DataReady ;   				  /*variável responsável pela indicação de ODReady*/

#endif
