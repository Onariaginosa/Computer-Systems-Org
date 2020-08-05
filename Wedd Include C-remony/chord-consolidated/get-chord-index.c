// These #include’s are just guides. Add/remove as appropriate based on your code.
#include <stdio.h>
#include <string.h>

#include "notes.h"

// ***** Copy just your `main` and program-specific helper functions here (if any). *****
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("This program requires exactly 1 command line argument.\n");
        return 1;
    }
    int chordIndex = get_chord_index(argv[1]);
    if (chordIndex == INVALID) {
        printf("%s is not a valid chord. \n", argv[1]);
    } else {
        printf("%s is at CHORD_SUFFIXES index %d. \n", argv[1], chordIndex);
    }

    return 0;
}
