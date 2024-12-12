#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "word.h"

#define BUFSIZE 8192

void get_entry(int argc, char** argv, skorowidz_t* skorowidz){
    for (int i=2; i<argc; i++){
        word_t* word = malloc(sizeof(word_t));
        if (!word){
            fprintf(stderr, "[!] Memory allocation failed for word");
            return;
        }
        *word=init_word(argv[i]);
        add_word(word,skorowidz);
    }
} 
void find_words(FILE* in, skorowidz_t *skorowidz){
    char currLine[BUFSIZE];
    int lineNum = 1;
    while (fgets(currLine, BUFSIZE, in) != NULL) {
        check_line(currLine, skorowidz, lineNum);
        lineNum++;
    }

}


void check_line(char* currLine, skorowidz_t* skorowidz, int lineNum){
    // int found = 0;
    char temp_buf[BUFSIZE];
    strncpy(temp_buf, currLine, BUFSIZE);

    // Tworzymy kopię bufora 'buf' do zmiennej 'temp_buf', ponieważ strtok modyfikuje
    // oryginalny ciąg znaków. Dzięki temu możemy wielokrotnie dzielić linie na tokeny bez utraty danych.

    // Dzielimy linię na tokeny (słowa), używając spacji, tabulatorów i nowych linii jako separatorów
    char *token = strtok(temp_buf, " \t\n");
    while (token != NULL) {
        for (int i = 0; i < skorowidz->wordCounter; i++) {
            // Porównujemy każdy token z argumentami do wyszukiwania
            if (strcmp(token, skorowidz->words[i]->value) == 0) {
                // Jeśli znaleźliśmy pasujące słowo, dodajemy linie do wystąpień słowa sprawdzając czy jest na to pamięć
                if(skorowidz->words[i]->lineCounter == skorowidz->words[i]->whichLinesSize){
                    skorowidz->words[i]->whichLines = realloc(skorowidz->words[i]->whichLines, 2 * skorowidz->words[i]->whichLinesSize * sizeof(int));
                    if(!skorowidz->words[i]->whichLines){
                        fprintf(stderr, "[!] Memory allocation failed for whichLines\n");
                        return;
                    }
                }
                skorowidz->words[i]->whichLines[skorowidz->words[i]->lineCounter] = lineNum;
                skorowidz->words[i]->lineCounter++;
                }
        }
        //po sprawdzeniu wszystkich slow z listy przesuwamy token na następne słowo
        token = strtok(NULL, " \t\n");

    }

}
