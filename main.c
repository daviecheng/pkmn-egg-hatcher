#include <stdio.h>
#include "pico/stdlib.h"
#include "bsp.h"

int main(){

    eggInit();
    while(1){
        for(int curIndex=0; curIndex<11 && gpio_get(POWER) == 1; curIndex++){
            gpio_put(CTRL_ZL, !gpio_get(CTRL_ZL));
            sleep_ms(1000);

            if(curIndex == 10){
                gpio_put(CTRL_VERTICAL, !gpio_get(CTRL_VERTICAL));
            }

            if(gpio_get(POWER) == 0){
                gpio_put(CTRL_ZL, 0);
                gpio_put(CTRL_VERTICAL, 0);
            }
        }
    }
}



