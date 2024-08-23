#include <stdio.h>
#include <assert.h>
#include <string.h>

void printColorMapRow(int majorIndex, int minorIndex) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    printf("%d | %s | %s\n", majorIndex * 5 + minorIndex, majorColor[majorIndex], minorColor[minorIndex]);
}

int printColorMap() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printColorMapRow(i, j);
        }
    }
    return 25;
}

int main() {
    char buffer[4096]; 
    FILE *stream = fmemopen(buffer, sizeof(buffer), "w");
    FILE *old_stdout = stdout;
    stdout = stream;

    int result = printColorMap();

    fflush(stdout);
    stdout = old_stdout;
    fclose(stream);

    const char* expectedOutput = "0 | White | Blue\n"
                                 "1 | White | Orange\n"
                                 "2 | White | Green\n"
                                 "3 | White | Brown\n"
                                 "4 | White | Slate\n"
                                 "5 | Red | Blue\n"
                                 "6 | Red | Orange\n"
                                 "7 | Red | Green\n"
                                 "8 | Red | Brown\n"
                                 "9 | Red | Slate\n"
                                 "10 | Black | Blue\n"
                                 "11 | Black | Orange\n"
                                 "12 | Black | Green\n"
                                 "13 | Black | Brown\n"
                                 "14 | Black | Slate\n"
                                 "15 | Yellow | Blue\n"
                                 "16 | Yellow | Orange\n"
                                 "17 | Yellow | Green\n"
                                 "18 | Yellow | Brown\n"
                                 "19 | Yellow | Slate\n"
                                 "20 | Violet | Blue\n"
                                 "21 | Violet | Orange\n"
                                 "22 | Violet | Green\n"
                                 "23 | Violet | Brown\n"
                                 "24 | Violet | Slate\n";

    assert(strcmp(buffer, expectedOutput) == 0);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
