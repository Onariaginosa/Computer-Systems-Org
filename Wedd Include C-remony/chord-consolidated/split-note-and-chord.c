// These #include’s are just guides. Add/remove as appropriate based on your code.
#include <stdio.h>
#include <string.h>

#include "notes.h"

#define MAX_SUBSTRING 15

// ***** Copy just your `main` and program-specific helper functions here (if any). *****
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("This program requires exactly 1 command line argument.\n");
        return 1;
    }
    char note[MAX_SUBSTRING + 1];
    char chord[MAX_SUBSTRING + 1];
    
    int validity = split_note_and_chord(argv[1], note, chord); 

    if (validity == INVALID) {
        printf("%s is not a valid chord. \n", argv[1]);
    } else {
        printf("[%s] [%s]\n", note, chord);
    }

    return 0;
}
