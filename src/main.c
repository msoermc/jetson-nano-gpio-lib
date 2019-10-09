/**
 * @project Jetson GPIO Library
 * @date October 5 2019
 * @author Aqeel AlShafei, Isaiah Rondeau
 */

#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"

int main(int argc, char* argv[]) {

	int inPin = PIN_7;

	if (gpio_export(inPin) != 0) {
		perror("Error exporting pin");
		return EXIT_FAILURE;
	}

	if (gpio_set_dir(inPin, INPUT) != 0) {
		perror("Error setting pin direction");
		return EXIT_FAILURE;
	}

//	if (gpio_set_edge(inPin, BOTH) != 0) {
//		perror("Error setting pin edge");
//		return EXIT_FAILURE;
//	}
//
//	if (gpio_set_active_low(inPin, TRUE) != 0) {
//		perror("Error writing pin active low");
//		return EXIT_FAILURE;
//	}

	for (int i = 0; i < 100; i++) {
		printf("%d\n", gpio_read(inPin));
	}

	scanf("pause");

	if (gpio_unexport(inPin) != 0) {
		perror("Error unexporting pin");
		return EXIT_FAILURE;
	}

    return 0;
}
