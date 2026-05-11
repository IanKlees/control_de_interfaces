#include <stdio.h>
#include "pico/stdlib.h"
// hola soy cata y amo a ian <3
/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  // Demora para esperar la conexion
  sleep_ms(1000);

  // Inicializacion de GP3IO con gpio_init()

  /* Habilito el GPIO25 (LED)
  gpio_init(PICO_DEFAULT_LED_PIN);
  GPIO25 como salida
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
  Configuracion de entrada/salida con gpio_set_dir()

  */
  
  gpio_init(6);
  gpio_set_dir(6, GPIO_IN);
  gpio_pull_down(6);

  gpio_init(20);
  gpio_set_dir(20, GPIO_OUT);

  while (true) {

    // Declarando variable que contiene el valor del gpio6
    int gp6 = gpio_get(6);

    // Prender el led segun el valor de gpio6
    if (gp6 == 1){
        gpio_put(20, 1); // Se prende el LED
    }
    else{
        gpio_put(20, 0); // Se apaga el LED
    }
    
  }
  return 0;
}