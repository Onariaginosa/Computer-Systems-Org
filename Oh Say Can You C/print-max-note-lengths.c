#include <stdio.h>
#include <string.h>

#include "notes.h"

// ***** IMPLEMENT ME! *****
int get_max_note_length() {
    int maxLength = 0;
    for(int i = 0; i < NOTE_COUNT; i++) {
        if (strlen(NOTES[i]) > maxLength) {
            maxLength = strlen(NOTES[i]);
        }	
    }
    return maxLength;
}

// ***** IMPLEMENT ME! *****
int get_max_chord_suffix_length() {
    int maxLength = 0;
    for(int i = 0; i < CHORD_COUNT; i++) {
        if (strlen(CHORD_SUFFIXES[i]) > maxLength) {
            maxLength = strlen(CHORD_SUFFIXES[i]);
        }	
    }
    return maxLength;
}

int main(int argc, char** argv) {
    // Check for the correct number of arguments.
    if (argc != 1) {
        printf("This program requires no command line arguments:\n");
        return 1;
    }

    int maxNoteLength = get_max_note_length();
    int maxChordSuffixLength = get_max_chord_suffix_length();

    printf("The longest NOTES string is %d characters long and the longest CHORD_SUFFIXES string is %d characters\n", maxNoteLength, maxChordSuffixLength);

    return 0;
}
