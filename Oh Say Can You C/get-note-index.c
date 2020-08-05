#include <stdio.h>
#include <string.h>

#include "notes.h"

#define INVALID -1

// ***** IMPLEMENT ME! *****
int get_note_index(char* string) {
    for (int i = 0; i < NOTE_COUNT; i++) {
        if(strcmp(NOTES[i], string) == 0) {
            return i;
        }
    }
    return INVALID;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("This program requires exactly 1 command line argument.\n");
        return 1;
    }
    int noteIndex = get_note_index(argv[1]);
    if (noteIndex == INVALID) {
        printf("%s is not a valid note. \n", argv[1]);
    } else {
        printf("%s is at NOTES index %d. \n", argv[1], noteIndex);
    }

    return 0;
}
