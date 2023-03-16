/**************************************************************************/
/*                                                                        */
/*                                                                        */
/*                                                                        */
/*                          LCD Symbols definitions                       */
/*                                                                        */
/*                             Softbaugh SBLCDA4                          */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/* MSP430 Teaching ROM                                                    */
/* Produced by: MSP430@UBI Group - www.msp430.ubi.pt                      */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/*  See the details of the LCD descriptio in Annex B                      */
/*  SBLCDA4_Specification.pdf                                             */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/*                                        Copyright by Texas Instruments  */
/**************************************************************************/


                                                   //  Symbols

#define DOLLAR_ON LCDM13 |= 0x10                   //    $ (ON)
#define DOLLAR_OFF LCDM13 &= ~0x10                 //    $ (OFF)

#define TX_ON LCDM13 |= 0x02                     //    TX (ON)
#define TX_OFF LCDM13 &= ~0x02                   //    TX (OFF)

#define ENV_ON LCDM13 |= 0x01                     //    ENV (ON)
#define ENV_OFF LCDM13 &= ~0x01                   //    ENV (OFF)

#define RX_ON LCDM13 |= 0x04                       //    RX (ON)
#define RX_OFF LCDM13 &= ~0x04                     //    RX (ON)

#define DIG_1_ON LCDM13 |= 0x08                    //    digit(8) = "1" (ON)
#define DIG_1_OFF LCDM13 &= ~0x08                  //    digit(8) = "1" (OFF)

#define ERRO_ON LCDM13 |= 0x20                     //    ERR (ON)
#define ERRO_OFF LCDM13 &= ~0x20                   //    ERR (OFF)

#define SIGN_LESS_ON LCDM13 |= 0x40                //    MINUS (ON)
#define SIGN_LESS_OFF LCDM13 &= ~0x40              //    MINUS (OFF)

#define MEMO_ON LCDM13 |= 0x80                     //    MEM (ON)
#define MEMO_OFF LCDM13 &= ~0x80                   //    MEM (OFF)

#define ANT_ON LCDM12 |= 0x10                      //    ANT (ON)
#define ANT_OFF LCDM12 &= ~0x10                    //    ANT (OFF)

#define BAT_OFF LCDM12 &= ~0x0F                    //    BAT_OFF = "BB"+"B0"+"B1"+"BT" (OFF)
#define BAT_FULL LCDM12 |= 0x0F                    //    BAT_FULL = "BB"+"B0"+"B1"+"BT" (ON)
#define BAT_LOW LCDM12 |= 0x08                     //    BAT_LOW = "BB" (ON)
#define BAT_50 LCDM12 |= 0x0C                      //    BAT_50% = "BB"+"B0" (ON)
#define BAT_90 LCDM12 |= 0x0e                      //    BAT_90% = "BB"+"B0"+"B1" (ON)

#define LEV_OFF LCDM12 &= ~0xE0                    //    LEV_OFF = "A0"+"A1"+"A2" (OFF)
#define LEV_1 LCDM12 |= 0x80                       //    LEV_1 = "A0" (ON)
#define LEV_2 LCDM12 |= 0xC0                       //    LEV_2 = "A0"+"A1" (ON)
#define LEV_3 LCDM12 |= 0xE0                       //    LEV_3 = "A0"+"A1"+"A2" (ON)

#define F1_ON LCDM10 |= 0x10                       //    F1 (ON)
#define F1_OFF LCDM10 &= ~0x10                     //    F1 (OFF)

#define F2_ON LCDM10 |= 0x20                       //    F2 (ON)
#define F2_OFF LCDM10 &= ~0x20                     //    F2 (OFF)

#define F3_ON LCDM10 |= 0x40                       //    F3 (ON)
#define F3_OFF LCDM10 &= ~0x40                     //    F3 (OFF)

#define F4_ON LCDM10 |= 0x80                       //    F4 (ON)
#define F4_OFF LCDM10 &= ~0x80                     //    F4 (OFF)

#define F5_ON LCDM10 |= 0x01                       //    F5 (ON)
#define F5_OFF LCDM10 &= ~0x01                     //    F5 (OFF)

#define AU_ON LCDM11 |= 0x10                       //    AU = "arrow up" (ON)
#define AU_OFF LCDM11 &= ~0x10                     //    AU = "arrow up" (OFF)

#define AR_ON LCDM11 |= 0x20                       //    AR = "arrow right" (ON)
#define AR_OFF LCDM11 &= ~0x20                     //    AR = "arrow right" (OFF)

#define AD_ON LCDM11 |= 0x40                       //    AD = "arrow down" (ON)
#define AD_OFF LCDM11 &= ~0x40                     //    AD = "arrow down" (OFF)

#define AL_ON LCDM11 |= 0x80                       //    AL = "arrow left" (ON)
#define AL_OFF LCDM11 &= ~0x80                     //    AL = "arrow left" (OFF)

#define PL_ON LCDM11 |= 0x01                       //    PL (ON)
#define PL_OFF LCDM11 &= ~0x01                     //    PL (OFF)

#define P0_ON LCDM11 |= 0x02                       //    P0 (ON)
#define P0_OFF LCDM11 &= ~0x02                     //    P0 (OFF)

#define P1_ON LCDM11 |= 0x04                       //    P1 (ON)
#define P1_OFF LCDM11 &= ~0x04                     //    P1 (OFF)

#define P2_ON LCDM11 |= 0x80                       //    P2 (ON)
#define P2_OFF LCDM11 &= ~0x80                     //    P2 (OFF)

#define P3_ON LCDM10 |= 0x02                       //    P3 (ON)
#define P3_OFF LCDM10 &= ~0x02                     //    P3 (OFF)

#define P4_ON LCDM10 |= 0x04                       //    P4 (ON)
#define P4_OFF LCDM10 &= ~0x04                     //    P4 (OFF)

#define PR_ON LCDM10 |= 0x08                       //    PR (ON)
#define PR_OFF LCDM10 &= ~0x08                     //    PR (OFF)

#define P1_NULL LCDM3 = 0x00                       //    digit(1) (OFF)
#define P1_A0 LCDM3 = 0x5F                         //    digit(1) = "0" (ON)
#define P1_A1 LCDM3 = 0x06                         //    digit(1) = "1" (ON)
#define P1_A2 LCDM3 = 0x6B                         //    digit(1) = "2" (ON)
#define P1_A3 LCDM3 = 0x2F                         //    digit(1) = "3" (ON)
#define P1_A4 LCDM3 = 0x36                         //    digit(1) = "4" (ON)
#define P1_A5 LCDM3 = 0x3D                         //    digit(1) = "5" (ON)
#define P1_A6 LCDM3 = 0x7D                         //    digit(1) = "6" (ON)
#define P1_A7 LCDM3 = 0x07                         //    digit(1) = "7" (ON)
#define P1_A8 LCDM3 = 0x7F                         //    digit(1) = "8" (ON)
#define P1_A9 LCDM3 = 0x3F                         //    digit(1) = "9" (ON)
#define P1_DOT_ON LCDM3 |= 0x80                    //    digit(1) = "." (ON)
#define P1_DOT_OFF LCDM3 &= ~0x80                  //    digit(1) = "." (OFF)

#define P2_NULL LCDM4 = 0x00                       //    digit(2) (OFF)
#define P2_A0 LCDM4 = 0x5F                         //    digit(2) = "0" (ON)
#define P2_A1 LCDM4 = 0x06                         //    digit(2) = "1" (ON)
#define P2_A2 LCDM4 = 0x6B                         //    digit(2) = "2" (ON)
#define P2_A3 LCDM4 = 0x2F                         //    digit(2) = "3" (ON)
#define P2_A4 LCDM4 = 0x36                         //    digit(2) = "4" (ON)
#define P2_A5 LCDM4 = 0x3D                         //    digit(2) = "5" (ON)
#define P2_A6 LCDM4 = 0x7D                         //    digit(2) = "6" (ON)
#define P2_A7 LCDM4 = 0x07                         //    digit(2) = "7" (ON)
#define P2_A8 LCDM4 = 0x7F                         //    digit(2) = "8" (ON)
#define P2_A9 LCDM4 = 0x3F                         //    digit(2) = "9" (ON)
#define P2_DOT_ON LCDM4 |= 0x80                    //    digit(2) = "." (ON)
#define P2_DOT_OFF LCDM4 &= ~0x80                  //    digit(2) = "." (OFF)


#define P3_NULL LCDM4 = 0x00                       //    digit(3) (OFF)
#define P3_A0 LCDM5 = 0x5F                         //    digit(3) = "0" (ON)
#define P3_A1 LCDM5 = 0x06                         //    digit(3) = "1" (ON)
#define P3_A2 LCDM5 = 0x6B                         //    digit(3) = "2" (ON)
#define P3_A3 LCDM5 = 0x2F                         //    digit(3) = "3" (ON)
#define P3_A4 LCDM5 = 0x36                         //    digit(3) = "4" (ON)
#define P3_A5 LCDM5 = 0x3D                         //    digit(3) = "5" (ON)
#define P3_A6 LCDM5 = 0x7D                         //    digit(3) = "6" (ON)
#define P3_A7 LCDM5 = 0x07                         //    digit(3) = "7" (ON)
#define P3_A8 LCDM5 = 0x7F                         //    digit(3) = "8" (ON)
#define P3_A9 LCDM5 = 0x3F                         //    digit(3) = "9" (ON)
#define P3_DOT_ON LCDM5 |= 0x80                    //    digit(3) = "." (ON)
#define P3_DOT_OFF LCDM5 &= ~0x80                  //    digit(3) = "." (OFF)

#define P4_NULL LCDM6 = 0x00                       //    digit(4) (OFF)
#define P4_A0 LCDM6 = 0x5F                         //    digit(4) = "0" (ON)
#define P4_A1 LCDM6 = 0x06                         //    digit(4) = "1" (ON)
#define P4_A2 LCDM6 = 0x6B                         //    digit(4) = "2" (ON)
#define P4_A3 LCDM6 = 0x2F                         //    digit(4) = "3" (ON)
#define P4_A4 LCDM6 = 0x36                         //    digit(4) = "4" (ON)
#define P4_A5 LCDM6 = 0x3D                         //    digit(4) = "5" (ON)
#define P4_A6 LCDM6 = 0x7D                         //    digit(4) = "6" (ON)
#define P4_A7 LCDM6 = 0x07                         //    digit(4) = "7" (ON)
#define P4_A8 LCDM6 = 0x7F                         //    digit(4) = "8" (ON)
#define P4_A9 LCDM6 = 0x3F                         //    digit(4) = "9" (ON)
#define P4_DOT_ON LCDM6 |= 0x80                    //    digit(4) = "." (ON)
#define P4_DOT_OFF LCDM6 &= ~0x80                  //    digit(4) = "." (OFF)

#define P5_NULL LCDM7 = 0x00                       //    digit(5) (OFF)
#define P5_A0 LCDM7 = 0x5F                         //    digit(5) = "0" (ON)
#define P5_A1 LCDM7 = 0x06                         //    digit(5) = "1" (ON)
#define P5_A2 LCDM7 = 0x6B                         //    digit(5) = "2" (ON)
#define P5_A3 LCDM7 = 0x2F                         //    digit(5) = "3" (ON)
#define P5_A4 LCDM7 = 0x36                         //    digit(5) = "4" (ON)
#define P5_A5 LCDM7 = 0x3D                         //    digit(5) = "5" (ON)
#define P5_A6 LCDM7 = 0x7D                         //    digit(5) = "6" (ON)
#define P5_A7 LCDM7 = 0x07                         //    digit(5) = "7" (ON)
#define P5_A8 LCDM7 = 0x7F                         //    digit(5) = "8" (ON)
#define P5_A9 LCDM7 = 0x3F                         //    digit(5) = "9" (ON)
#define P5_DOT_ON LCDM7 |= 0x80                    //    digit(5) = "." (ON)
#define P5_DOT_OFF LCDM7 &= ~0x80                  //    digit(5) = "." (OFF)

#define P6_NULL LCDM8 = 0x00                       //    digit(6) (OFF)
#define P6_A0 LCDM8 = 0x5F                         //    digit(6) = "0" (ON)
#define P6_A1 LCDM8 = 0x06                         //    digit(6) = "1" (ON)
#define P6_A2 LCDM8 = 0x6B                         //    digit(6) = "2" (ON)
#define P6_A3 LCDM8 = 0x2F                         //    digit(6) = "3" (ON)
#define P6_A4 LCDM8 = 0x36                         //    digit(6) = "4" (ON)
#define P6_A5 LCDM8 = 0x3D                         //    digit(6) = "5" (ON)
#define P6_A6 LCDM8 = 0x7D                         //    digit(6) = "6" (ON)
#define P6_A7 LCDM8 = 0x07                         //    digit(6) = "7" (ON)
#define P6_A8 LCDM8 = 0x7F                         //    digit(6) = "8" (ON)
#define P6_A9 LCDM8 = 0x3F                         //    digit(6) = "9" (ON)
#define P6_DOT_ON LCDM8 |= 0x80                    //    digit(6) = "." (ON)
#define P6_DOT_OFF LCDM8 &= ~0x80                  //    digit(6) = "." (OFF)

#define P7_NULL LCDM9 = 0x00                       //    digit(7) (OFF)
#define P7_A0 LCDM9 = 0x5F                         //    digit(7) = "0" (ON)
#define P7_A1 LCDM9 = 0x06                         //    digit(7) = "1" (ON)
#define P7_A2 LCDM9 = 0x6B                         //    digit(7) = "2" (ON)
#define P7_A3 LCDM9 = 0x2F                         //    digit(7) = "3" (ON)
#define P7_A4 LCDM9 = 0x36                         //    digit(7) = "4" (ON)
#define P7_A5 LCDM9 = 0x3D                         //    digit(7) = "5" (ON)
#define P7_A6 LCDM9 = 0x7D                         //    digit(7) = "6" (ON)
#define P7_A7 LCDM9 = 0x07                         //    digit(7) = "7" (ON)
#define P7_A8 LCDM9 = 0x7F                         //    digit(7) = "8" (ON)
#define P7_A9 LCDM9 = 0x3F                         //    digit(7) = "9" (ON)
#define P7_DOT_ON LCDM9 |= 0x80                    //    digit(7) = "." (ON)
#define P7_DOT_OFF LCDM9 &= ~0x80                  //    digit(7) = "." (OFF)
