/*
Author: Nick Heyer
KUID: 3142337
Date: 3/26/25
Lab: Assignment2
Last modified: 3/26/25
EECS 348 Lab 7 
Football score possibilities
input: user input
Output: all the possible nfl score combinations based on the user's inputted number
Collaborators: ChatGPT was used to find syntax errors and help with the structure. 
*/

#include <stdio.h>
// func to find all possibile combos of scores for a given num
void findCombinations(int score) {
    printf("Possible combinations of scoring plays for score %d:\n", score);

    int found = 0; // check if one valid combo is found
    for (int td2pt = 0; td2pt <= score / 8; td2pt++) { // TD w 2PT conv 8PT
        for (int td1pt = 0; td1pt <= score / 7; td1pt++) { // TD w FG 7 PT
            for (int td = 0; td <= score / 6; td++) { // touch w extra PT 6 PT
                for (int fg = 0; fg <= score / 3; fg++) { // FG 3 PT
                    for (int safety = 0; safety <= score / 2; safety++) { // safety 2 pt
                         // calc the total score from currenmt combo
                        if (td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            // print valid score combos
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n",
                                   td2pt, td1pt, td, fg, safety);
                            found = 1; // atleast one valid combo exist
                        }
                    }
                }
            }
        }
    }

    if (!found) { // if no valid combos are found notify the user
        printf("No valid scoring combos for %d.\n", score); 
    }
    printf("\n"); 
}

int main() {
    int score; // store user input

    while (1) { // loop to continuosly prompt the user until termination
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score); // take user input

        if (score <= 1) { // if score is 0 or 1 exit loop
            break;
        }

        findCombinations(score); // call func to compute and print valid score combos
    }

    printf("Program Term.\n"); // proves program termination
    return 0; // return
}