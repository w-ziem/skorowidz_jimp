#include <stdio.h>
#include <stdlib.h>
#include "skorowidz.h"


//dodawanie słowa do skorowidzu
void add_word(word_t* word, skorowidz_t* s){
    if(s->wordCounter >= MAX_SIZE){
        fprintf(stderr, "[!] Max number of words reached");
        return;
    }
    s->words[s->wordCounter] = word;
    s->wordCounter++;
}

//wyświetlanie skorowidzu
void print_skorowidz(skorowidz_t* s){
    for (int i=0; i<s->wordCounter; i++){
        if(s->words[i]){
            printf("%s : ",s->words[i]->value);
            for(int j = 0; j < s->words[i]->lineCounter;j++){
                printf("%d ", s->words[i]->whichLines[j]);
            }
            printf("\n");
        }else{
            fprintf(stderr, "[!] Pointer is NULL");
            return;
        }
    }
}

