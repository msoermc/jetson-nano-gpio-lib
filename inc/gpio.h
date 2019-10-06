/**
 * @author Isaiah Rondeau
 * @date October 5, 2019
 * @brief Jetson Nano GPIO Library 
 *
 * Jetson Nano GPIO library to access input and output fucntions on the pin headers
 */

#ifndef GPIO_H
#define GPIO_H

// GPIO Pin mapping flags
#define PIN_7	216
#define PIN_11	50
#define PIN_12	79
#define PIN_13	14
#define PIN_15	194
#define PIN_16	232
#define PIN_18	15
#define PIN_19	16
#define PIN_21	17
#define PIN_22	13
#define PIN_23	18
#define PIN_24	19
#define PIN_26	20
#define PIN_29	149
#define PIN_31	200
#define PIN_32	168
#define PIN_33	38
#define PIN_35	76
#define PIN_36	51
#define PIN_37	12
#define PIN_38	77
#define PIN_40	78

// GPIO Direction mapping flags
#define OUTPUT	0
#define INPUT	1

// GPIO Value mapping flags
#define LOW 	0
#define HIGH	1

// GPIO Edge mapping flags
#define NONE 	"none"
#define RISING	"rising"
#define FALLING	"falling"
#define BOTH	"both"

/**
 * @brief Export control of userspace to file
 * 
 * Export control of userspace to a file to access a pin's properties
 *
 * @param gpio GPIO pin number
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_export(unsigned int gpio);

/**
 * @brief Return control of userspace to kernel
 * 
 * Return control of userspace back to the kernel
 *
 * @param gpio GPIO pin number
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_unexport(unsigned int gpio);

/**
 * @breif
 *
 *
 *
 * @param gpio GPIO pin number
 * @param direction Direction OUTPUT/INPUT to assign pin
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_set_dir(unsigned int gpio, unsigned int direction);

/**
 * @brief
 * 
 * 
 *
 * @param gpio GPIO pin number
 * @param value Pin value to set
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_set_val(unsigned int gpio, unsigned int value);

/**
 * @breif
 *
 * 
 *
 * @param
 *
 * @return Value of GPIO pin
 */
int gpio_get_val(unsigned int gpio);


/**
 * @brief
 * 
 * 
 *
 * @param gpio GPIO pin number
 * @param option Write any number greater than zero to set the logic to active low
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_set_active_low(unsigned int gpio, unsigned int option);

#endif