
    
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
    // contador
    int contador=0;

  // Mensaje por USB
  printf("\nHola mundo!\n");

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    printf("LED prendido\n");
    contador +=1;
    // mensaje de contador
    printf("la cantidad de encendidos son:%d", contador);

    // Demora
    sleep_ms(500);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Mensaje por USB
    printf("LED apagado\n");
    // Demora
    sleep_ms(500);
  }
  return 0;
}
