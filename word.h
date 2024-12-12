#ifndef _WORD_H_
#define _WORD_H_

typedef struct{
    int lineCounter;
    int* whichLines;
    int whichLinesSize;
    char* value;
}word_t;


word_t init_word(char* word);



#endif