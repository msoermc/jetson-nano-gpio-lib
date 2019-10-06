/**
 * @author Isaiah Rondeau
 * @date October 5, 2019
 * @brief Jetson Nano GPIO Library 
 *
 * Jetson Nano GPIO library to access input and output fucntions on the pin headers
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "gpio.h"

/**
 * @brief Export control of userspace to file
 * 
 * Export control of userspace to a file to access a pin's properties
 *
 * @param gpio GPIO pin number
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_export(unsigned int gpio) {
	
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (fd < 0) {
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/**
 * @brief Return control of userspace to kernel
 * 
 * Return control of userspace back to the kernel
 *
 * @param gpio GPIO pin number
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_unexport(unsigned int gpio) {

	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
	if (fd < 0) {
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/**
 * @breif Assign GPIO pin as INPUT/OUTPUT
 *
 * Assign the given GPIO pin to read either input or output
 *
 * @param gpio GPIO pin number
 * @param direction Direction OUTPUT/INPUT to assign pin
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_set_dir(unsigned int gpio, unsigned int direction) {
	
	return 0;
}

/**
 * @brief Set GPIO value to HIGH/LOW
 * 
 * Set the given GPIO pin value to either high or low
 *
 * @param gpio GPIO pin number
 * @param value Pin value to set
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_write(unsigned int gpio, unsigned int value) {

	return 0;
}

/**
 * @breif Read GPIO value
 *
 * Read the given GPIO pin value as either high or low
 *
 * @param gpio GPIO pin number
 *
 * @return Value of GPIO pin as HIGH or LOW
 */
int gpio_read(unsigned int gpio) {
	
	return 0;
}

/**
 * @brief Set GPIO to read active low
 * 
 * Set the GPIO pin to read values in the active low state
 *
 * @param gpio GPIO pin number
 * @param option Write any number greater than zero to set the logic to active low
 *
 * @return 0 on success, or -1 on failure and errno is set
 */
int gpio_set_active_low(unsigned int gpio, unsigned int option) {

	return 0;
}
