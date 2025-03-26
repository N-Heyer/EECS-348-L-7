#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}


void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}