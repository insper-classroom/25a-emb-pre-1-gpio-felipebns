#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN = 28;

const int RED = 5;
const int PURPLE = 8;
const int BLUE = 11;
const int YELLOW = 15;


int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_init(RED);
  gpio_init(PURPLE);
  gpio_init(BLUE);
  gpio_init(YELLOW);

  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);
  
  gpio_set_dir(RED, GPIO_OUT);
  gpio_set_dir(PURPLE, GPIO_OUT);
  gpio_set_dir(BLUE, GPIO_OUT);
  gpio_set_dir(YELLOW, GPIO_OUT);


  while (true) {
    if (!gpio_get(BTN)) {
      gpio_put(RED, 1);
      sleep_ms(300);
      gpio_put(RED, 0);

      gpio_put(PURPLE, 1);
      sleep_ms(300);
      gpio_put(PURPLE, 0);

      gpio_put(BLUE, 1);
      sleep_ms(300);
      gpio_put(BLUE, 0);

      gpio_put(YELLOW, 1);
      sleep_ms(300);
      gpio_put(YELLOW, 0);

      while (!gpio_get(BTN)) {
      };
    }
  }
}
