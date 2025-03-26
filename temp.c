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

int main() {
    float temperature;
    int current_scale, target_scale;

    while (1) {
        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current_scale);

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        if (current_scale == target_scale) {
            printf("Current scale and target scale cannot be the same. Try again.\n");
            continue;
        }

        float converted_temperature;
        float converted_to_celsius;

        if (current_scale == 1) { 
            converted_to_celsius = temperature;
            if (target_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else { 
                converted_temperature = celsius_to_kelvin(temperature);
            }
        } else if (current_scale == 2) { 
            converted_to_celsius = fahrenheit_to_celsius(temperature);
            if (target_scale == 1) {
                converted_temperature = converted_to_celsius; 
            } else { 
                converted_temperature = celsius_to_kelvin(converted_to_celsius);
            }
        } else { 
            converted_to_celsius = kelvin_to_celsius(temperature);
            if (target_scale == 1) {
                converted_temperature = converted_to_celsius; 
            } else { 
                converted_temperature = celsius_to_fahrenheit(converted_to_celsius);
            }
        }

        printf("Converted temperature: %.2f", converted_temperature);
        if (target_scale == 1) {
            printf("°C\n");
        } else if (target_scale == 2) {
            printf("°F\n");
        } else {
            printf("K\n");
        }


        categorize_temperature(converted_to_celsius);


        char repeat;
        printf("Do you want to perform another conversion? (y/n): ");
        scanf(" %c", &repeat);
        if (repeat != 'y' && repeat != 'Y') {
            break;
        }
    }

    return 0;
}