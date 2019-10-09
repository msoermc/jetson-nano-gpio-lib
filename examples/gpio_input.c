/**
 * @project Jetson Nano GPIO Library
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

	if (gpio_set_dir(inPin, OUTPUT) != 0) {
		perror("Error setting pin direction");
		return EXIT_FAILURE;
	}

//	if (gpio_set_active_low(outPin, TRUE) != 0) {
//		perror("Error writing pin active low");
//		return EXIT_FAILURE;
//	}

	if (gpio_read(inPin) != 0) {
		perror("Error writing pin HIGH");
		return EXIT_FAILURE;
	}

	scanf("pause");

	if (gpio_unexport(outPin) != 0) {
		perror("Error unexporting pin");
		return EXIT_FAILURE;
	}

    return 0;
}
