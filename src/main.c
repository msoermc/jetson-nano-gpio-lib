/**
 * @project Jetson GPIO Library
 * @date October 5 2019
 * @author Aqeel AlShafei, Isaiah Rondeau
 */

#include <stdio.h>
#include <stdlib.h>

#include "gpio.h"

int main(int argc, char* argv[]) {

	int outPin = PIN_7;

	if (gpio_export(outPin) != 0) {
		perror("Error exporting pin");
		return EXIT_FAILURE;
	}

	if (gpio_set_dir(outPin, OUTPUT) != 0) {
		perror("Error setting pin direction");
		return EXIT_FAILURE;
	}

	if (gpio_write(outPin, HIGH) != 0) {
		perror("Error writing pin HIGH");
		return EXIT_FAILURE;
	}

	if (gpio_unexport(outPin) != 0) {
		perror("Error unexporting pin");
		return EXIT_FAILURE;
	}

    return 0;
}
