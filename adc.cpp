#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include "stdlib.h"
#include "ssd1306.h"
#include <string>;
#define MAX_DIGITS 10


int raw=0;
int num=99;
void testString(int x);
int radius,posx,posy,j,x;
char* int2char(int iNumber);
int x1;


using namespace std;

static int map(long x,	long in_min, long in_max,	long out_min,	long out_max){
	return (x	-	in_min)	*	(out_max	-	out_min) / (in_max	-	in_min) +	out_min;
}



int main(void){
	
	SSD1306_Init();
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
	
	ADC1->SMPR2 |= ADC_SMPR2_SMP6;
	
	ADC1->SQR3 |= (0<<0);
	
	ADC1->CR2 |=ADC_CR2_CONT;
	
	ADC1->CR2 |=ADC_CR2_ADON;
	
	ADC1->CR2 |=ADC_CR2_RSTCAL;
	
	while(ADC1->CR2 & ADC_CR2_RSTCAL){;}
		
	ADC1->CR2 |= ADC_CR2_CAL;
		
	while(ADC1->CR2 & ADC_CR2_CAL){;}
		
	ADC1->CR2 |=ADC_CR2_ADON;
	
	while(1){
		
		
		SSD1306_GotoXY(20,12);
		
	testString(j);

		    	SSD1306_GotoXY(58,22);

					SSD1306_UpdateScreen(); 
		
		SSD1306_Fill(SSD1306_COLOR_BLACK);
			           
		j<60? j++:j=0;
		
			x1= map(raw, 0, 4095, 0, 127);
		
		if(ADC1->SR & ADC_SR_EOC)
		{
		 raw= ADC1->DR;
		}	}}

void testString(int x)
{
	
	SSD1306_GotoXY(64, 32);
	SSD1306_Putc('5', &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<10000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	SSD1306_GotoXY(64, 32);
	SSD1306_Putc('4', &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<10000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	SSD1306_GotoXY(64, 32);
	SSD1306_Putc('3', &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<10000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	SSD1306_GotoXY(64, 32);
	SSD1306_Putc('2', &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<10000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	SSD1306_GotoXY(64, 32);
	SSD1306_Putc('1', &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<10000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	SSD1306_GotoXY(16, 32);
	SSD1306_Puts("GO GO GO!", &Font_11x18, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
	for(int i=0; i<20000; i++)
	SSD1306_Fill(SSD1306_COLOR_BLACK);
	
	
	SSD1306_GotoXY(0, 0);
	SSD1306_Puts("SCORE", &Font_7x10, SSD1306_COLOR_WHITE);
	
	SSD1306_GotoXY(90, 0);
	SSD1306_Puts("TIME", &Font_7x10, SSD1306_COLOR_WHITE);
	
	while(num!=0){
        num--;
        
		    char num_char[MAX_DIGITS + sizeof(char)];
        
				sprintf(num_char, "%d", num);
		
				SSD1306_GotoXY(97, 0);
				SSD1306_Puts(num_char, &Font_7x10, SSD1306_COLOR_WHITE);
				for(int i=0;i<1000;i++);
        
        }
	
	SSD1306_DrawPixel(x1, 30, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1+1, 30, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1-1, 30, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1+2, 30, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1-2, 30, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1, 30+1, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1, 30-1, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1, 30+2, SSD1306_COLOR_WHITE);
	SSD1306_DrawPixel(x1, 30-2, SSD1306_COLOR_WHITE);
	
	
	
}