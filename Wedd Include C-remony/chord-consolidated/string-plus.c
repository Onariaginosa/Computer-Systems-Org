#include <stdbool.h>
#include <string.h>  // In case your implementation needs it. It does not have to.

// Helper function for determining if a string validly expresses a non-negative integer.
// Feel free to use where needed (and to study it as an example).
bool is_non_negative_numeral(char* numeral) {
    int numeral_length = strlen(numeral);
    for (int i = 0; i < numeral_length; i++) {
        if (numeral[i] < '0' || numeral[i] > '9') {
            return false;
        }
    }

    return true;
}

// ***** MOVE YOUR IMPLEMENTATION HERE! *****
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
