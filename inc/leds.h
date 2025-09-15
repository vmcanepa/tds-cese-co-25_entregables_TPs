#include <stdbool.h>
#include <stdint.h>

void LedsInitDriver(uint16_t * puerto_virtual);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

void LedsAllTurnOn(void);

void LedsAllTurnOff(void);

int LedsIsOn(int led);

int LedsIsOff(int led);
