#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

word_t init_word(char* word) {
    word_t w;
    
    w.value = malloc((strlen(word) + 1) * sizeof(char));
    if (!w.value) {
        fprintf(stderr, "[!] Memory allocation for value failed\n");
        exit(EXIT_FAILURE); 
    }
    strcpy(w.value, word); 


    w.whichLines = malloc(10 * sizeof(int)); 
    w.whichLinesSize = 10;
    if (!w.whichLines) {
        fprintf(stderr, "[!] Memory allocation for whichLines failed\n");
        free(w.value); 
        exit(EXIT_FAILURE); 
    }

    w.lineCounter = 0; 

    return w; 
}