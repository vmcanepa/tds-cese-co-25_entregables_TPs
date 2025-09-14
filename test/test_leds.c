/* Tests:
 * - Prender un led y apagarlo en ambos extremos.
 * - Prender y apagar todos los leds.
 * - Prender algunos leds más de una vez y verificar que sigue prendido.
 * - Apagar algunos leds más de una vez y verificar que siguen apagados.
 * - Prender algunos leds, despues prender todos y comprobar que todos los leds
 * quedan prendidos.
 * - Prender todos, apagar algunos, apagar todos y comprobar que todos los leds
 * quedan apagados.
 * - Consultar el estado de un led encendido y comprobar que es correcto.
 * - Consultar el estado de un led apagado y comprobar que es correcto.
 */

#include "leds.h"
#include "unity.h"
#include "mock_errores.h"

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

/**
 * @brief Prender más de un led, apagar uno y verificar que el resto siguen sin
 * cambio.
 */
void test_prender_mas_de_un_led_apagar_uno_y_verificar_que_el_resto_sigue(void)
{
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

/**
 * @brief Tratar de prender un led fuera de rango y comprobar que se genera un
 * error.
 */
void test_tratar_prender_led_fuera_rango_y_comprobar_que_se_genera_error(void)
{
    // RegistrarMensaje_Expect(ALERTA, "LedsTurnOn", 0, "El led no es valido");
    // RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Tratar de apagar un led fuera de rango y comprobar que se genera un
 * error.
 */
void test_tratar_apagar_led_fuera_rango_y_comprobar_que_se_genera_error(void)
{
    // RegistrarMensaje_Expect(ALERTA, "LedsTurnOn", 0, "El led no es valido");
    // RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOff(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);

    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Prender todos los leds.
 */
void test_prender_todos_los_leds(void)
{
    LedsAllTurnOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

/**
 * @brief Apagar todos los leds.
 */
void test_apagar_todos_los_leds(void)
{
    LedsAllTurnOn();
    LedsAllTurnOff();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}
