#include "skorowidz.h"


#ifndef _UTILS_H_
#define _UTILS_H_

void get_entry(int argc, char** argv, skorowidz_t* skorowidz); //dodaje szukane slowa do skorowidza
void find_words(FILE* in, skorowidz_t *skorowidz); //szuka slow, korzysta ze sprawdz linijke
void check_line(char* currLine, skorowidz_t* skorowidz, int lineNum);


#endif