#ifndef __VCOM_SERIAL_H__
#define __VCOM_SERIAL_H__


/* CDC Class Specific Request */
#define SET_LINE_CODE       0x20
#define GET_LINE_CODE       0x21
#define SET_CONTROL_LINE	0x22



typedef struct __attribute__((packed)) {
    uint32_t u32DTERate;     	// Baud rate
    uint8_t  u8CharFormat;   	// stop bit:  0 - 1 Stop bit, 1 - 1.5 Stop bits, 2 - 2 Stop bits
    uint8_t  u8ParityType;   	// parity:    0 - None, 1 - Odd, 2 - Even, 3 - Mark, 4 - Space
    uint8_t  u8DataBits;     	// data bits: 5, 6, 7, 8, 16
} STR_VCOM_LINE_CODING;

extern STR_VCOM_LINE_CODING LineCfg;



#define RX_BUFF_SIZE    512 	// RX buffer size
#define TX_BUFF_SIZE    512 	// RX buffer size

typedef struct {
	uint8_t  rx_buff[RX_BUFF_SIZE];
	uint16_t rx_bytes;
	uint16_t rx_head;
	uint16_t rx_tail;
	uint8_t  tx_buff[TX_BUFF_SIZE];
	uint16_t tx_bytes;
	uint16_t tx_head;
	uint16_t tx_tail;
	
	uint16_t hw_flow;	// BIT0: DTR(Data Terminal Ready) , BIT1: RTS(Request To Send)
	
	uint8_t  in_buff[64];
	uint16_t in_bytes;
	uint8_t  out_buff[64];
	uint16_t out_bytes;
	uint16_t out_ready;
} VCOM;

extern volatile VCOM Vcom;



void VCOM_Init(void);
void VCOM_TransferData(void);

void VCOM_SetLineCoding(void);
void VCOM_BulkIN_Handler(void);
void VCOM_BulkOUT_Handler(void);


#endif
