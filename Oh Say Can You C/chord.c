#include <stdio.h>
#include <string.h>

#include "notes.h"

#define MAX_SUBSTRING 15
#define INVALID -1
// ***** Feel free to add more functions if you think they will make it easier to implement this program.


int get_max_note_length() {
    int maxLength = 0;
    for (int i = 0; i < NOTE_COUNT; i++) {
        if(strlen(NOTES[i]) > 0) {
            maxLength = strlen(NOTES[i]);
        }
    }
    return maxLength;
}

int get_chord_index(char* string) {
    for (int i = 0; i < CHORD_COUNT; i++) {
        if(strcmp(CHORD_SUFFIXES[i], string) == 0) {
            return i;
        }
    }
    return INVALID;
}

int get_note_index(char* string) {
    for (int i = 0; i < NOTE_COUNT; i++) {
        if(strcmp(NOTES[i], string) == 0) {
            return i;
        }
    }
    return INVALID;
}

void split_string_at_index(char* string, int index, char* left, char* right) {
    int length = strlen(string);
    
    for (int i = 0; i < index; i++) {
        left[i] = string[i];
    }
    left[index] = '\0';
    for (int i = 0; i < length-index; i++) {
        right[i] = string[i+index];
    }
    right[length-index] = '\0';
    
}

int split_note_and_chord(char* string, char* note, char* chord) {
    int maxNoteLength = get_max_note_length();
    for (int i = 0; i <= maxNoteLength; i++) {
        split_string_at_index(string, i, note, chord);
        int note_Index = get_note_index(note);
        int chord_Index = get_chord_index(chord);
        if(get_note_index(note) != INVALID && get_chord_index(chord) != INVALID) {
            return 0;
        } 
        note[0] = '\0';
        chord[0] = '\0';
    }
    return INVALID;
}

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


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("This program requires exactly 1 command line argument.\n");
        return 1;
    }

    char note[MAX_SUBSTRING +1];
    char chord[MAX_SUBSTRING +1];
    int validity = split_note_and_chord(argv[1], note, chord);
    if(validity == INVALID) {
        printf("%s is not a valid chord. \n", argv[1]);
    } else {
        print_chord(get_note_index(note), get_chord_index(chord));
    }

    return 0;
}
