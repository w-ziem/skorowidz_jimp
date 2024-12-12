#include "word.h"


#ifndef _SKOROWIDZ_H_
#define _SKOROWIDZ_H_
#define MAX_SIZE 8192


typedef struct{
    int wordCounter;
    word_t* words[MAX_SIZE];
}skorowidz_t;


void add_word(word_t* word, skorowidz_t* s);
void print_skorowidz(skorowidz_t* s);


#endif