/* Tests:
 * - Iniciar el driver y revisar que todos los leds estén apagados.
 * - Prender un led y verificar que no cambia el resto.
 * - Prender un led y cualquiera apagarlo.
 * - Prender más de un led, apagar uno y verificar que el resto siguen sin
 * cambio.
 * - Prender un led y apagarlo en ambos extremos.
 * - Prender todos los leds.
 * - Prender y apagar todos los leds.
 * - Prender algunos leds más de una vez y verificar que sigue prendido.
 * - Apagar algunos leds más de una vez y verificar que siguen apagados.
 * - Prender algunos leds, despues prender todos y comprobar que todos los leds
 * quedan prendidos.
 * - Prender todos, apagar algunos, apagar todos y comprobar que todos los leds
 * quedan apagados.
 * - Consultar el estado de un led encendido y comprobar que es correcto.
 * - Consultar el estado de un led apagado y comprobar que es correcto.
 * - Tratar de manipular un led fuera de rango y comprobar que se genera un
 * error.
 */

#include "leds.h"
#include "unity.h"

static uint16_t puerto_virtual;

void setUp(void)
{
    LedsInitDriver(&puerto_virtual);
}

void tearDown(void)
{
}

/**
 * @brief Al iniciar todos los leds están apagados.
 */
void test_al_iniciar_todos_los_leds_estan_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;

    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Prender un led y verificar que no cambia el resto.
 */
void test_prender_un_led_y_verificar_que_no_cambie_el_resto(void)
{
    LedsTurnOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

/**
 * @brief Prender un led cualquiera y apagarlo.
 */
void test_prender_un_led_cualquiera_y_apagarlo(void)
{
    LedsTurnOn(5);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}
