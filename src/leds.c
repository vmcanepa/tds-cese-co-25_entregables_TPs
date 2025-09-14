#include "leds.h"

void LedsInitDriver(uint16_t * puerto_virtual)
{
    *puerto_virtual = 0x0000; /* apagar todos los LEDs al iniciar.*/
}
