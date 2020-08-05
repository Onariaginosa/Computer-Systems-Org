#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notes.h"

#define INVALID -1

// ***** IMPLEMENT ME! *****
void print_chord(int note_index, int chord_index) {
    char* noteList[CHORD_STEP_COUNT[chord_index] + 1];
    noteList[0] = NOTES[note_index];
    int currentNoteIndex = note_index;
    for (int i = 0; i < CHORD_STEP_COUNT[chord_index]; i++) {
    currentNoteIndex = CHORD_STEPS[chord_index][i] + currentNoteIndex;
    if (currentNoteIndex > NOTE_COUNT) {
        currentNoteIndex = currentNoteIndex - NOTE_COUNT;
    }
    noteList[i+1] = NOTES[currentNoteIndex];       
    }
    printf("%s%s: ",NOTES[note_index], CHORD_SUFFIXES[chord_index]);  
    for (int i = 0; i < CHORD_STEP_COUNT[chord_index] +1 ; i++) {
        printf("%s ", noteList[i]);
    }
    printf("\n");
}

// ***** Feel free to add more functions if you think they will make it easier to check argument validity.
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
