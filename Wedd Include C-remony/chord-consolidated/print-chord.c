// These #include’s are just guides. Add/remove as appropriate based on your code.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notes.h"

// ***** Copy just your `main` and program-specific helper functions here (if any). *****
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("This program requires exactly 2 command line argument.\n");
        return 1;
    }

    int noteIndex = atoi(argv[1]);
    int chordIndex = atoi(argv[2]);
    
    if((noteIndex == 0 && argv[1][0] != '0') || (chordIndex == 0 && argv[1][0] != '0')) {
        printf("Either %s or %s is not a valid index. \n", argv[1], argv[2]);
    }
    else if(noteIndex >= NOTE_COUNT || chordIndex >= CHORD_COUNT || noteIndex < 0 || chordIndex < 0) {
        printf("Either %s or %s is out of range.\n", argv[1], argv[2]);
    }
    else {
        print_chord(noteIndex, chordIndex);
    }


    return 0;
}
