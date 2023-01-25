#include <stm32f10x.h>
#define bz 0 // PB0

// Funcoes para serem usadas no programa
void lcd_init(void); // Iniciar o display corretamente
void lcd_command(unsigned char cmd); // Enviar comandos
void lcd_data(unsigned char data); // Envia dados (caractere ASCII)
void lcd_print(char * str); // Envia strings
void lcd_putValue(unsigned char value); // Usada internamente
void delay_us(uint16_t t); // Atraso de micro segundos
void delay_ms(uint16_t t); // Atraso de mili segundos

// Definicoes
#define LCD_RS 15
#define LCD_EN 12

// Variaveis globais
static uint16_t switchA;
static uint16_t switchB;
static uint16_t switchC;
int oitava = 1;
int ciclo = 1;

// Programa
int main()
{
	// Desabilitando interface JTAG
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
	
	// Ativando clocks da GPIO e o TIM3
	RCC->APB2ENR |= 0xFC;
	RCC->APB1ENR |= (1<<1);
	
	// Configurando switches como inputs de info e o buzzer como funcao alt
	GPIOA->CRL = 0x43344444;
	GPIOA->CRH = 0x34433443;
	GPIOB->CRL = 0x4444444B;
	GPIOB->CRH = 0x44444444;
	GPIOC->CRH = 0x44444444;
	
	lcd_init();
	
	lcd_command(0x01);
	lcd_print("Oitava: 1");
	lcd_command(0xC0);
	lcd_print("Ciclo: 25%");
	
	TIM3->CCER &= ~(1<<8); // disable TIM3
	TIM3->CCMR2 = 0x0068 ; /* PWM1 */
	TIM3->PSC = 7200 -1;
	
	while (1)
	{
		// Leitura dos inputs
		switchA = GPIOA->IDR;
		switchA &= 0xFF;
		
		switchB = GPIOB->IDR;
		
		switchC = GPIOC->IDR;
		switchC &= 0xF000;
		
		// Condicoes
		// Switch cases
		switch(switchA)
		{
			case 0xF0: // SW8
			{
				if (oitava == 2) TIM3->ARR = 14 - 1;
				else TIM3->ARR = 28 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0x90: // SW8
			{
				if (oitava == 2) TIM3->ARR = 14 - 1;
				else TIM3->ARR = 28 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0xD0: // SW8
			{
				if (oitava == 2) TIM3->ARR = 14 - 1;
				else TIM3->ARR = 28 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0xB0: // SW8
			{
				if (oitava == 2) TIM3->ARR = 14 - 1;
				else TIM3->ARR = 28 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			
			case 0xE8: // SW9
			{
				if (oitava == 2) TIM3->ARR = 13 - 1;
				else TIM3->ARR = 25 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0xC8: // SW9
			{
				if (oitava == 2) TIM3->ARR = 13 - 1;
				else TIM3->ARR = 25 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0xA8: // SW9
			{
				if (oitava == 2) TIM3->ARR = 13 - 1;
				else TIM3->ARR = 25 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0x88: // SW9
			{
				if (oitava == 2) TIM3->ARR = 13 - 1;
				else TIM3->ARR = 25 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			
			case 0x78: // SW14
			{
				if (oitava == 2) TIM3->ARR = 16 - 1;
				else TIM3->ARR = 32 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0x58: // SW14
			{
				if (oitava == 2) TIM3->ARR = 16 - 1;
				else TIM3->ARR = 32 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0x38: // SW14
			{
				if (oitava == 2) TIM3->ARR = 16 - 1;
				else TIM3->ARR = 32 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			case 0x18: // SW14
			{
				if (oitava == 2) TIM3->ARR = 16 - 1;
				else TIM3->ARR = 32 - 1;
				
				if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
				else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
				else TIM3->CCR3 = (TIM3->ARR *75/100);
				
				TIM3->CCER |=(1<<8); // ativa o som
				TIM3->CR1 = 1;
				delay_ms(100);
				break;
			}
			
			default:
			{
				switch(switchC)
				{
					case 0x6000: // SW15
					{
						if (oitava == 2) TIM3->ARR = 13 - 1;
						else TIM3->ARR = 27 - 1;
						
						if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
						else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
						else TIM3->CCR3 = (TIM3->ARR *75/100);
						
						TIM3->CCER |=(1<<8); // ativa o som
						TIM3->CR1 = 1;
						delay_ms(100);
						break;
					}
					
					case 0xA000: // SW16
					{
						if (oitava == 2) TIM3->ARR = 12 - 1;
						else TIM3->ARR = 24 - 1;
						
						if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
						else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
						else TIM3->CCR3 = (TIM3->ARR *75/100);
						
						TIM3->CCER |=(1<<8); // ativa o som
						TIM3->CR1 = 1;
						delay_ms(100);
						break;
					}
					
					case 0xC000: // SW17
					{
						if (oitava == 2) TIM3->ARR = 11 - 1;
						else TIM3->ARR = 21 - 1;
						
						if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
						else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
						else TIM3->CCR3 = (TIM3->ARR *75/100);
						
						TIM3->CCER |=(1<<8); // ativa o som
						TIM3->CR1 = 1;
						delay_ms(100);
						break;
					}
					
					default:
					{
						switch(switchB)
						{
							case 0xEFF8: // SW1
							{
								oitava = 1;
								lcd_command(0x80);
								lcd_print("Oitava: 1");
								delay_ms(100);
								break;
							}
							
							case 0xDFF8: // SW2
							{
								oitava = 2;
								lcd_command(0x80);
								lcd_print("Oitava: 2");
								delay_ms(100);
								break;
							}
							
							case 0xBFF8: // SW3
							{
								if (ciclo == 1)
								{
									ciclo = 2;
									lcd_command(0xC0);
									lcd_print("Ciclo: 50%");
								}
								else if (ciclo == 2)
								{
									ciclo = 3;
									lcd_command(0xC0);
									lcd_print("Ciclo: 75%");
								}
								else
								{
									ciclo = 1;
									lcd_command(0xC0);
									lcd_print("Ciclo: 25%");
								}
								delay_ms(100);
								break;
							}
							
							case 0xFFD8: // SW5
							{
								if (oitava == 2) TIM3->ARR = 19 - 1;
								else TIM3->ARR = 38 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xFFE8: // SW6
							{
								if (oitava == 2) TIM3->ARR = 17 - 1;
								else TIM3->ARR = 34 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xFFF0: // SW7
							{
								if (oitava == 2) TIM3->ARR = 15 - 1;
								else TIM3->ARR = 30 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xFEF8: // SW10
							{
								if (oitava == 2) TIM3->ARR = 11 - 1;
								else TIM3->ARR = 22 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xFDF8: // SW11
							{
								if (oitava == 2) TIM3->ARR = 10 - 1;
								else TIM3->ARR = 20 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xF7F8: // SW12
							{
								if (oitava == 2) TIM3->ARR = 19 - 1;
								else TIM3->ARR = 38 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							case 0xFBF8: // SW13
							{
								if (oitava == 2) TIM3->ARR = 18 - 1;
								else TIM3->ARR = 36 - 1;
								
								if (ciclo == 1) TIM3->CCR3 = (TIM3->ARR *25/100);
								else if (ciclo == 2) TIM3->CCR3 = (TIM3->ARR *50/100);
								else TIM3->CCR3 = (TIM3->ARR *75/100);
								
								TIM3->CCER |=(1<<8); // ativa o som
								TIM3->CR1 = 1;
								delay_ms(100);
								break;
							}
							
							default:
							{
								TIM3->CCER = 0x0000 ; // enable sound
								TIM3->CR1 = 0;
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
}


void lcd_putValue(unsigned char value)
{
	uint16_t aux; //variable to help to build appropriate data out
	aux = 0x0000; //clear aux
	GPIOA->BRR = (1<<5)|(1<<6)|(1<<8)|(1<<11); // clear data lines
	aux = value & 0xF0;
	aux = aux>>4;
	GPIOA->BSRR = ((aux&0x0008)<<8) | ((aux&0x0004)<<3) |	((aux&0x0002)<<5) | ((aux&0x0001)<<8);
	GPIOA->ODR |= (1<<LCD_EN); /* EN = 1 for H-to-L pulse */
	delay_ms(3);			/* make EN pulse wider */
	GPIOA->ODR &= ~ (1<<LCD_EN);	/* EN = 0 for H-to-L pulse */
	delay_ms(1);			/* wait	*/
	GPIOA->BRR = (1<<5)|(1<<6)|(1<<8)|(1<<11); // clear data lines
	aux = 0x0000; //clear aux
	aux = value & 0x0F;
	GPIOA->BSRR = ((aux&0x0008)<<8) | ((aux&0x0004)<<3) |	((aux&0x0002)<<5) | ((aux&0x0001)<<8);
	GPIOA->ODR |= (1<<LCD_EN); /* EN = 1 for H-to-L pulse */
	delay_ms(3);			/* make EN pulse wider */
  GPIOA->ODR &= ~(1<<LCD_EN);	/* EN = 0 for H-to-L pulse */
  delay_ms(1);			/* wait	*/
}


void lcd_command(unsigned char cmd)
{
	GPIOA->ODR &= ~ (1<<LCD_RS);	/* RS = 0 for command */
	lcd_putValue(cmd);
}


void lcd_data(unsigned char data)
{
	GPIOA->ODR |= (1<<LCD_RS);	/* RS = 1 for data */
	lcd_putValue(data); 
}


void lcd_print(char * str)
{
  unsigned char i = 0;

	while(str[i] != 0) /* while it is not end of string */
	{
		lcd_data(str[i]); /* show str[i] on the LCD */
		i++;
	}
}


void lcd_init()
{
	delay_ms(15);
	GPIOA->ODR &= ~(1<<LCD_EN);	/* LCD_EN = 0 */
	delay_ms(3); 			/* wait 3ms */
	lcd_command(0x33); //lcd init.
	delay_ms(5);
	lcd_command(0x32); //lcd init.
	delay_us(3000);
	lcd_command(0x28); // 4-bit mode, 1 line and 5x8 charactere set
	delay_ms(3);
	lcd_command(0x0e); // display on, cursor on
	delay_ms(3);
	lcd_command(0x01); // display clear
	delay_ms(3);
	lcd_command(0x06); // move right
	delay_ms(3);
}


void delay_us(uint16_t t)
{
	volatile unsigned long l = 0;
	for(uint16_t i = 0; i < t; i++)
		for(l = 0; l < 6; l++)
		{
		}
}


void delay_ms(uint16_t t)
{
	volatile unsigned long l = 0;
	for (uint16_t i = 0; i < t ; i++)
		for (l = 0; l < 6000; l++)
		{
		}
}