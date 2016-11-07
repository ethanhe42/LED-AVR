//** 文件名：led.c  
//** 功能：LED依次循环点亮
//** 说明：低电平的LED位灯亮，高电平灯灭
//**     PORTB口输出数据，PC5高电平使能

#include <avr/io.h>
#include <util/delay.h>
#define LED_CS PC5
#define PB_MASK 0xFF

void LED_Init()
{
    PORTB = PB_MASK;
    DDRB = PB_MASK;
    PORTC |= _BV(LED_CS);
    DDRC |= _BV(LED_CS);
}

void textbook(){
   int i;
    uint8_t led_sel;
    LED_Init();

    while (1) {
		i = 0;
		led_sel = 0x01;
		while (i < 3)  {
			PORTB = ~led_sel;
			_delay_ms(300);
			if (led_sel == 0x80) {
				led_sel = 0x01;
				++i;
			}
			else
				led_sel *= 2;
		}
		i = 0;
		led_sel = 0x80;
		while (i < 3) {
			PORTB = ~led_sel;
			_delay_ms(300);
			if (led_sel == 0x01) {
				led_sel = 0x80;
			    ++i;
			}
			else
				led_sel /= 2;
		}
		for  (i = 0; i < 3; ++i) {
			PORTB |= PB_MASK;
			_delay_ms(500);
			PORTB &= ~PB_MASK;
			_delay_ms(500);
		}
    }
    return 0;
}



int main()
{
 if (0) {textbook; return;}
 int i;
    uint8_t led_sel;
    LED_Init();

    while (1) {
		i = 0;
		led_sel = 0x01;
		while (i < 3)  {
			PORTB = ~led_sel;
			_delay_ms(300);
  			if (led_sel == 0x80) {
				led_sel = 0x01;
				++i;
			}
			else
				led_sel *= 2;
		}
		i = 0;
		led_sel = 0x80;
		while (i < 3) {
			PORTB = ~led_sel;
			_delay_ms(300);
			if (led_sel == 0x01) {
				led_sel = 0x80;
			    ++i;
			}
			else
				led_sel /= 2;
		}
		for  (i = 0; i < 3; ++i) {
			PORTB |= PB_MASK;
			_delay_ms(500);
			PORTB &= ~PB_MASK;
			_delay_ms(500);
		}
		i=0;
		while (i < 5) {
			PORTB =0x11;
            _delay_ms(1000);
			PORTB =0x22;
            _delay_ms(1000);
			PORTB =0x44;
            _delay_ms(1000);
            PORTB =0x88;
			_delay_ms(1000);
	    	++i;
			}
        i=0;
		while (i < 5) {
			PORTB =0xEE;
            _delay_ms(1000);
			PORTB =0xDD;
            _delay_ms(1000);
			PORTB =0xBB;
            _delay_ms(1000);
            PORTB =0x77;
			_delay_ms(1000);
			++i;
		}
    }
    return 0;
}
