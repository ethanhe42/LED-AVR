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

int main()
{
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
		while (i < 3) {
			PORTB =0x7E;
            _delay_ms(300);
			PORTB =0xBD;
            _delay_ms(300);
			PORTB =0xDB;
            _delay_ms(300);
            PORTB =0xE7;
			_delay_ms(300);

			if (PORTB ==0xE7) {
				
			    ++i;
			}
			}
        i=0;
		while (i < 3) {
			PORTB =0xE7;
            _delay_ms(300);
			PORTB =0xDB;
            _delay_ms(300);
			PORTB =0xBD;
            _delay_ms(300);
            PORTB =0x7E;
			_delay_ms(300);
			if (PORTB ==0x7E) {
				
			    ++i;
			}


		}


    }
    return 0;
}
