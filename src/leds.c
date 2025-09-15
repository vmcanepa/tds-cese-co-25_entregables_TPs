#include <stdbool.h>
#include "leds.h"
#include "errores.h"

#define ALL_LED_OFF       0x0000
#define FIRST_BIT         1
#define LED_TO_BIT_OFFSET 1

static uint16_t * puerto;

static uint16_t LedToMask(int led)
{
    return FIRST_BIT << (led - LED_TO_BIT_OFFSET);
}

static bool IsLedValid(int led)
{
    bool result = led >= 1 && led <= 16;
    if(!result)
    {
        Alerta("El led no es válido.");
    }
    return result;
}

void LedsInitDriver(uint16_t * puerto_virtual)
{
    puerto = puerto_virtual;
    LedsAllTurnOff(); /* apagar todos los LEDs al iniciar.*/
}

void LedsTurnOn(int led)
{
    if(!IsLedValid(led))
    {
        return;
    }
    *puerto |= LedToMask(led);
}

void LedsTurnOff(int led)
{
    if(!IsLedValid(led))
    {
        return;
    }
    *puerto &= ~LedToMask(led);
}

void LedsAllTurnOn(void)
{
    *puerto = ~ALL_LED_OFF;
}

void LedsAllTurnOff(void)
{
    *puerto = ALL_LED_OFF;
}

int LedsIsOn(int led)
{
    if(!IsLedValid(led))
    {
        return -1;
    }
    return (0 != (*puerto & LedToMask(led)));
}

int LedsIsOff(int led)
{
    int state;

    state = LedsIsOn(led);
    return state < 0 ? -1 : !state;
}
