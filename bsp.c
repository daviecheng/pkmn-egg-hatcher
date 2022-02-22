#include <stdio.h>
#include "pico/stdlib.h"
#include "bsp.h"

/* Functions -------------------------------------------------------------------------*/
void debounceISR(){
    gpio_set_irq_enabled(BUTTON, GPIO_IRQ_EDGE_RISE, false);
    
    int k;
    for(k=0; k<1000; k++){
        if(gpio_get(BUTTON) == 0){
            k = 0;
        }
    }

    gpio_put(POWER, !gpio_get(POWER));
    gpio_put(25,!gpio_get(25));

    for(k=0; k<1000; k++){
        if(gpio_get(BUTTON) == 1){
            k = 0;
        }
    }

    gpio_set_irq_enabled(BUTTON, GPIO_IRQ_EDGE_RISE, true);
}
void eggInit(){
    GPIO_init();
    stdio_init_all();
    sleep_ms(5000);
}

void GPIO_init(){
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(POWER);
    gpio_set_dir(POWER, GPIO_OUT);

    gpio_init(CTRL_VERTICAL);
    gpio_set_dir(CTRL_VERTICAL, GPIO_OUT);

    gpio_init(CTRL_ZL);
    gpio_set_dir(CTRL_ZL, GPIO_OUT);

    // Enable button interrupt
    gpio_set_irq_enabled_with_callback(BUTTON,  GPIO_IRQ_EDGE_RISE, true, &debounceISR);

}