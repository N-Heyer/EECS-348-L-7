#include <stdio.h>

void findCombinations(int score) {
    printf("Possible combinations of scoring plays for score %d:\n", score);

    int found = 0;
    for (int td2pt = 0; td2pt <= score / 8; td2pt++) {
        for (int td1pt = 0; td1pt <= score / 7; td1pt++) {
            for (int td = 0; td <= score / 6; td++) {
                for (int fg = 0; fg <= score / 3; fg++) {
                    for (int safety = 0; safety <= score / 2; safety++) {
                        if (td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n",
                                   td2pt, td1pt, td, fg, safety);
                            found = 1;
                        }
                    }
                }
            }
        }
    }
