#ifndef CW_H
# define CW_H

# include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct      word
{
    char            *word;
    int             used;
    struct word     *next;
}                   word;

typedef struct      dict
{
    word            *words;
    int             len;
    struct dict     *next;
}                   dict;

typedef struct      intersection
{
    int             Vpos;
    char            **Vword;
    int             Hpos;
    char            **Hword;
    int             id;
}                   intersection;

typedef struct      sgrid
{
    int             **grid;
    int             y;
    int             x;
}                   sgrid;

typedef struct      wdinput
{
    char            *word;
    int             len;
    intersection    **intrs;
    int             nrOfI;
}                   winput;

intersection** setIntersectionsOnGrig(sgrid *grid, int *len);
winput  **horizontalWordsInputs(sgrid *grid, intersection** intrs, int* len);
winput  **verticalWordsInputs(sgrid *grid, intersection** intrs,  int* len);
void Solver(winput **Vinputs, int Vlen, winput **Hinputs,  int Hlen, intersection **intrs, int Ilen, dict *words);
void readFile(dict  *words, sgrid *grid, char* fl);
void printGrid(sgrid *grid);
void printInputsArray(winput **in_array, int len);
void printWordsDict(dict* wdict);
void printIntersections(intersection **intrs, int len);
void completeGrig(intersection **intrs, sgrid *grid);
size_t tryWord(winput *Winput, word *word);

#endif