#ifndef ERRORES_H
#define ERRORES_H

#define Error(mensaje) RegistrarMensaje(ERROR, __FUNCTION__, __LINE__, mensaje)

#define Alerta(mensaje)                                                        \
    RegistrarMensaje(ALERTA, __FUNCTION__, __LINE__, mensaje)

#define Informacion(mensaje)                                                   \
    RegistrarMensaje(INFORMACION, __FUNCTION__, __LINE__, mensaje)

#define Depuracion(mensaje)                                                    \
    RegistrarMensaje(DEPURACION, __FUNCTION__, __LINE__, mensaje)

typedef enum gravedad_e
{
    ERROR,       /**< Mensaje de error. */
    ALERTA,      /**< Mensaje de alerta. */
    INFORMACION, /**< Mensaje de informacion. */
    DEPURACION,  /**< Mensaje de depuracion. */
} gravedad_t;

/**
 * @brief Función para registrar un mensaje en la bitácora de errores del
 * sistema.
 *
 * @param gravedad  Nivel de gravedad del mensaje registrado.
 * @param funcion   Función que realiza el registro del mensaje.
 * @param linea     Línea del código fuente en la que se llama al registro del
 *                  mensaje.
 * @param mensaje   Cadena de caracteres con el mensaje que se desea registrar.
 */
void RegistrarMensaje(gravedad_t gravedad, const char * funcion, int linea,
                      const char * mensaje);

#endif
