#include <stdio.h>

//conver c to f
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

//convert f to c
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// convert c to k
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// convert k to c
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// func to cat temp and suggest
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
    float temperature;  // store inputted temp
    int current_scale, target_scale;

    while (1) {  // loop

        // user input
        printf("Enter the temperature: ");
        scanf("%f", &temperature);

        // input for temp scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current_scale);

        // conversion to 
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        // if user selects same scale prompt again
        if (current_scale == target_scale) {
            printf("Current scale and target scale cannot be the same. Try again.\n");
            continue;  // skip and start over
        }

        float converted_temperature;  // store final
        float converted_to_celsius;   // store converstion to C for cat

        // convert based on uyser scale
        if (current_scale == 1) { // if C
            converted_to_celsius = temperature;
            if (target_scale == 2) { 
                converted_temperature = celsius_to_fahrenheit(temperature); // convert to F
            } else { 
                converted_temperature = celsius_to_kelvin(temperature); //convert to K
            }
        } else if (current_scale == 2) { // if user = F
            converted_to_celsius = fahrenheit_to_celsius(temperature); //conver to c
            if (target_scale == 1) {
                converted_temperature = converted_to_celsius;  // c remains same
            } else { 
                converted_temperature = celsius_to_kelvin(converted_to_celsius); // convert to K
            }
        } else { // if scale is K
            converted_to_celsius = kelvin_to_celsius(temperature); // convert to C
            if (target_scale == 1) {
                converted_temperature = converted_to_celsius;  // C remains same
            } else { 
                converted_temperature = celsius_to_fahrenheit(converted_to_celsius); //convert to F
            }
        }

        //print converted temp
        printf("Converted temperature: %.2f", converted_temperature);
        if (target_scale == 1) {
            printf("°C\n");
        } else if (target_scale == 2) {
            printf("°F\n");
        } else {
            printf("K\n");
        }

        // call cat 
        categorize_temperature(converted_to_celsius);

        // ask the user to repeat the program
        char repeat;
        printf("Do you want to perform another conversion? (y/n): ");
        scanf(" %c", &repeat); // syntax handling
        if (repeat != 'y' && repeat != 'Y') {
            break;  // exit loop using y and Y
        }
    }

    return 0;  // return / END
}
