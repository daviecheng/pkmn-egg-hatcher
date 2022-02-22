#ifndef __BSP_H__
#define __BSP_H__

/* Pins */
#define LED 25
#define BUTTON 22
#define POWER 20
#define CTRL_ZL 19
#define CTRL_VERTICAL 18

/* GPIO */
#define GPIO_OE (*((unsigned int *)(SIO_BASE + 0x020U)))
#define GPIO_OUTPUT (*((unsigned int *)(SIO_BASE + 0x010U)))

/* Functions */
void eggInit();
void GPIO_init();
void debounceISR();

#endif // __BSP_H__
