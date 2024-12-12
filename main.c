#include <stdio.h>
#include <stdlib.h>
#include "skorowidz.h"
#include "word.h"
#include "utils.h"


int main(int argc, char **argv){
    FILE* in = argc > 1 ? fopen(argv[1], "r") : NULL;
    if(!in){
        fprintf(stderr, "[!] No input file\n");
        return EXIT_FAILURE;
    }
    skorowidz_t skorowidz;
    get_entry(argc, argv, &skorowidz); //dodaje szukane slowa do skorowidza
    find_words(in, &skorowidz); //szuka slow, korzysta ze sprawdz linijke
    print_skorowidz(&skorowidz); //wypisuje gotowy skorowidz
    //FIXME: nie robimy żadnego free
}