
#include <msp430xG46x.h>
#include "LCD_defs.h"

void LCD_min();
void LCD_all_off();
void LCD_sec();
void LCD_msec();

unsigned char min, sec;
unsigned int msec;

int main( void )
{
  WDTCTL = WDTPW + WDTHOLD;                             // Stop WDT
  // Select COM1-COM2-COM3
  P5DIR |= 0x1E;                                        // Ports P5.2, P5.3 and P5.4 as outputs
  P5SEL |= 0x1E;                                        // Ports P5.2, P5.3 and P5.4 as special function (COM1, COM2 and COM3)
  // Active S4 to S25
  LCDAPCTL0 = LCDS24 | LCDS20 | LCDS16 | LCDS12 | LCDS8 | LCDS4;
  // LCDA configuration
  LCDACTL = LCDFREQ_192 | LCD4MUX | LCDSON | LCDON;     // (ACLK = 32768)/192, 4-mux LCD, LCD_A on, Segments on
  LCDAVCTL0 = LCDCPEN;                                  // Charge pump enable
  LCDAVCTL1 = VLCD_3_44;                                // VLCD = 3,44 V
  LCD_all_off();

  // Timer_A configuration
  TAR = 0;			                       // Clean Timer A counter
  CCTL0 = CCIE;                                        // CCR0 interrupt enabled
  CCR0 = 3268;				               // this count correspond to 1 mseg
  TACTL = TASSEL_1 + MC_1 + ID_0;                      // ACLK, continuous mode
  //TACTL = TASSEL_1 + MC_1 + ID_0 + TAIE;
  // LED1 and LED2 configuration
  P2DIR = 0xFF;                                        // P2 as output
  P2OUT = 0x04;				               // Set P1.1 and P1.2

// SW1 and SW2 ports configuration
  P1SEL &= ~0x03;                                       // P1.0 and P1.1 I/O ports
  P1DIR &= ~0x03;                                       // P1.0 and P1.1 digital inputs
  P1IFG = 0x00;                                         // clear all interrupts pending
  P1IE |= 0x03;                                         // enable port interrupts

  // init memory clock data	
  min = 0;
  sec = 0;
  msec = 0;

  LCD_min();
  LCD_sec();
  LCD_msec();

  _BIS_SR(LPM3_bits + GIE);		                      // Enable interrupts and enter LPM3
}

//******************************************************************
// Write min
//******************************************************************
void LCD_min()
{
	unsigned char min1,min2;
	
	min1 = min/10;
	min2 = min%10;
	
	switch (min1)
	{
		case 1: P7_A1;
				break;
		case 2: P7_A2;
		        break;
		case 3: P7_A3;
		        break;
		case 4: P7_A4;
		        break;
		case 5: P7_A5;
		        break;
		case 0: P7_A0;
		        break;
	}
switch (min2)
	{
		case 1: P6_A1;
		        break;
		case 2: P6_A2;
		        break;
		case 3: P6_A3;
		        break;
		case 4: P6_A4;
		        break;
		case 5: P6_A5;
		        break;
		case 6: P6_A6;
		        break;
		case 7: P6_A7;
		        break;
		case 8: P6_A8;
		        break;
		case 9: P6_A9;
		        break;
		case 0: P6_A0;
		        break;
	}	
}
//******************************************************************
// Write sec
//******************************************************************
void LCD_sec()
{
	unsigned char sec1,sec2;
	
	sec1 = sec / 10;
	sec2 = sec % 10;
	
	switch (sec1)
	{
		case 1:P5_A1;
		       break;
		case 2:P5_A2;
			   break;
		case 3:P5_A3;
			   break;
		case 4:P5_A4;
			   break;
		case 5:P5_A5;
		       break;
		case 0:P5_A0;
		       break;
	}
switch (sec2)
	{
		case 1: P4_A1;
		        break;
		case 2: P4_A2;
		        break;
		case 3: P4_A3;
		        break;
		case 4: P4_A4;
		        break;
		case 5: P4_A5;
		        break;
		case 6: P4_A6;
		        break;
		case 7: P4_A7;
		        break;
		case 8: P4_A8;
		        break;
		case 9: P4_A9;
		        break;
		case 0: P4_A0;
	}	
}
//******************************************************************
// Write msec
//******************************************************************
void LCD_msec()
{
	switch (msec)
	{
		case 1: P3_A1;
		        break;
		case 2: P3_A2;
		        break;
		case 3: P3_A3;
		        break;
		case 4: P3_A4;
		        break;
		case 5: P3_A5;
		        break;
		case 6: P3_A6;
		        break;
		case 7: P3_A7;
		        break;
		case 8: P3_A8;
		        break;
		case 9: P3_A9;
		        break;
		case 0: P3_A0;
		        break;
	}
    P2_A0;
    P1_A0;
}
//******************************************************************
// Timer_A ISR
//******************************************************************
#pragma vector=TIMERA0_VECTOR
__interrupt void TimerA0_ISR (void)
{	
 P2OUT |=0x02;				    // LED1 turn on
 P2OUT ^=0x04;				    // LED2 toogle

 msec++;				        // manage memory clock
 LCD_msec();

 if (msec == 10)
  {
  	msec = 0;
  	sec++;
  	LCD_sec();
  	if (sec == 60)
  	{
  		sec = 0;
  		min++;
  		LCD_min();
  		if (min == 60)
  		{
  			min = 0;
  		}
  	}
  }	

 if (sec & 0x01)			    // toogle clock dots
    {
      P3_DOT_ON;	
      P5_DOT_ON;
    }
 else
    {
      P3_DOT_OFF;
      P5_DOT_OFF;
    }

 P2OUT &=~0x02;				    // LED1 turn off

 switch (sec)				    // LCD demo
   {
     case 2:
               PL_ON;
               PR_ON;
               DOLLAR_ON;
               break;
     case 4:
               P1_ON;
               RX_ON;
               break;
     case 6:
              P2_ON;
              DOLLAR_OFF;
              break;
     case 8:
              P3_ON;
              TX_ON;
     		  break;
     case 10:
              P4_ON;
              AU_ON;
     		  break;
     case 12:
              AR_ON;
              AU_OFF;
              TX_OFF;
              RX_OFF;
     		  break;
     case 14:
              AD_ON;
              AR_OFF;
              ERRO_ON;
     		  break;
     case 16:
              AL_ON;
              AD_OFF;
              ANT_ON;
     		  break;
     case 18:
              AL_OFF;
     		  break;
     case 20:
              PL_OFF;
              P1_OFF;
              P2_OFF;
              P3_OFF;
              P4_OFF;
              PR_OFF;
     		  break;
     case 22:
              ERRO_OFF;
     		  break;
     case 24:
     		  break;
     case 26:
              BAT_LOW;
     		  break;
     case 28:
              BAT_50;
              SIGN_LESS_ON;
     		  break;
     case 30:
              BAT_90;
              MEMO_ON;
     		  break;
     case 32:
              BAT_FULL;
              ANT_OFF;
              MEMO_OFF;
     		  break;
     case 34:
     		  break;
     case 36:
              SIGN_LESS_OFF;
     		  break;
     case 38:
     		  break;
     case 40:
     		  break;
     case 42:
              BAT_OFF;
     		  break;
     case 44:
              BAT_FULL;
              LEV_1;
     		  break;
     case 46:
              BAT_OFF;
              LEV_2;
     		  break;
     case 48:
              BAT_FULL;
              LEV_3;
     		  break;
     case 50:
              BAT_OFF;
              LEV_OFF;
              F1_ON;
              F4_OFF;
     		  break;
     case 52:
              F2_ON;
     		  break;
     case 54:
              F3_ON;
              F1_OFF;
     		  break;
     case 56:
              F4_ON;
              F2_OFF;
     		  break;
     case 58:
              F4_OFF;
              F3_OFF;
              ENV_ON;
              break;
     }
}
//******************************************************************
// Port1 Interrupt Service Rotine
//******************************************************************
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR (void)
{	
  if (P1IFG == 0x01)                        // SW1 interrupt
  {											// change charg Pump Voltage
   	if ((LCDAVCTL1 & 0x1E) > 0x1E) LCDAVCTL1 = 0;
  	else LCDAVCTL1 +=0x02;
  }

  if (P1IFG == 0x02)                        // SW2 interrupt
  {											// change LCD frequency
   	if ((LCDACTL & 0xE0)== 0xE0) LCDACTL &= ~0xE0;
  	else LCDACTL +=  0x20;
  }

  P1IFG = 0x00;	                             // clean all pending interrupts
}
//******************************************************************
// LCD clean routine
//******************************************************************
void LCD_all_off(void)
{
 LCDM2 = 0x00;
 LCDM3 = 0x00;
 LCDM4 = 0x00;
 LCDM5 = 0x00;
 LCDM6 = 0x00;
 LCDM7 = 0x00;
 LCDM8 = 0x00;
 LCDM9 = 0x00;
 LCDM10 = 0x00;
 LCDM11 = 0x00;
 LCDM12 = 0x00;
 LCDM13 = 0x00;
}

