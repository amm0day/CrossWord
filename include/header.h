#ifndef TO_H
# define TO_H

# include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


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
    char            *Vword;
    int             Hpos;
    char            *Hword;
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
    intersection**  intrs;
    int             nrOfI;
}                   winput;

intersection** setIntersectionsOnGrig(sgrid *grid);
winput  **horizontalWordsInputs(sgrid *grid, intersection** intrs, int* len);
winput  **verticalWordsInputs(sgrid *grid, intersection** intrs,  int* len);
void readFile(dict  *words, sgrid *grid);
void printGrid(sgrid *grid);
void printInputsArray(winput **in_array, int len);
void printWordsDict(dict* wdict);

#endif