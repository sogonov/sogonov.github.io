static unsigned int results[Num_of_Results];
#define Num_of_Results_1 128
static unsigned int results_1[Num_of_Results_1];
// ?????? ??? ???????? ???????????
void main(void)
{
WDTCTL = WDTPW+WDTHOLD; // ???? WATCHDOG
 ADC12CTL0 = ADC12ON+REFON+REF2_5V+SHT0_6; 
 ADC12CTL1 = ADC12ON+REFON+REF2_5V+SHT0_6; 
 // ????????? ???, ????????? ???????? ??????????, ????????? ?????? ???
 ADC12CTL1 = SHP; // ????? ?????
 ADC12MCTL0 = INCH_10+SREF_1; // ????? ??????
 ADC12MCTL1 = INCH_11+SREF_1;
 ADC12IE = 0x01; // ?????????? ??????????
// ???????? ??? ?????????? ?????????? ?????????
 for (int i=0; i<0x3600; i++) { }
 ADC12CTL0 |= ENC; // ???? ??????????????
 _EINT(); // ?????????? ??????????
 while(1)
 {
 ADC12CTL0 |= ADC12SC; // ???? ??????????????
 _BIS_SR(LPM0_bits); // ??????? ? ????? LPM0
_NOP(); // ??? ????? ????????
 }
 for (int i=0; i<0x3600; i++) { }
 ADC12CTL1 |= ENC; // ???? ??????????????
 _EINT();
 while(1)
 {
 ADC12CTL1 |= ADC12SC; // ???? ??????????????
 _BIS_SR(LPM0_bits); // ??????? ? ????? LPM0
_NOP(); // ??? ????? ????????
 }
}
#pragma vector=ADC_VECTOR
__interrupt void ADC12_ISR ()
{
static unsigned int index = 0;
static unsigned int index_1 = 0;
if (ADC12IV = 6) then results[index] = ADC12MEM0; 
 index = (index+1)%Num_of_Results;
if (ADC12IV = 8) then results_1[index_1] = ADC12MEM1; 
 index_1 = (index_1+1)%Num_of_Results_1;
 // Increment results index, modulo
 _BIC_SR_IRQ(LPM0_bits); // ??????? ? ???????? ?????
}
