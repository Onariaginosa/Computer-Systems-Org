#include <stdbool.h>
#include <stdio.h>
#include <string.h>  // In case your implementation needs it. It does not have to.

#include "string-plus.h"
#include "notes.h"

char *NOTES[] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"};
int NOTE_COUNT = sizeof(NOTES) / sizeof(char*);

// C has more sophisticated ways to express these structures, but at our level we
// stay with multiple arrays that have coordinated index values (i.e., the same
// index on these arrays corresopnds to the same type of chord).
char *CHORD_SUFFIXES[] = {
    "",     // major
    "m",    // minor
    "7",    // dominant 7th
    "M7",   // major 7th
    "m7",   // minor 7th
    "dim7"  // diminished 7th
};

int CHORD_COUNT = sizeof(CHORD_SUFFIXES) / sizeof(char*);

// C needs to know the maximum size of the inner array, but not the outer one 🤷🏽‍♂️
int CHORD_STEPS[][3] = {
    {4, 3},     // major
    {3, 4},     // minor
    {4, 3, 3},  // dominant 7th
    {4, 3, 4},  // major 7th
    {3, 4, 3},  // minor 7th
    {3, 3, 3}   // diminished 7th
};

// Yes, there are ways of computing this dynamically but for now we choose to list
// them explicitly to show how these arrays correspond to each other.
int CHORD_STEP_COUNT[] = {
    2,  // major
    2,  // minor
    3,  // dominant 7th
    3,  // major 7th
    3,  // minor 7th
    3   // diminished 7th
};

// ***** MOVE YOUR IMPLEMENTATIONS HERE! *****
int get_max_note_length() {
    int maxLength = 0;
    for(int i = 0; i < NOTE_COUNT; i++) {
        if (strlen(NOTES[i]) > maxLength) {
            maxLength = strlen(NOTES[i]);
        }	
    }
    return maxLength;
}

int get_max_chord_suffix_length() {
    int maxLength = 0;
    for(int i = 0; i < CHORD_COUNT; i++) {
        if (strlen(CHORD_SUFFIXES[i]) > maxLength) {
            maxLength = strlen(CHORD_SUFFIXES[i]);
        }	
    }
    return maxLength;
}

int get_note_index(char* string) {
    for (int i = 0; i < NOTE_COUNT; i++) {
        if(strcmp(NOTES[i], string) == 0) {
            return i;
        }
    }
    return INVALID;
}

int get_chord_index(char* string) {
    for (int i = 0; i < CHORD_COUNT; i++) {
        if(strcmp(CHORD_SUFFIXES[i], string) == 0) {
            return i;
        }
    }
    return INVALID;
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
