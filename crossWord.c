#include "include/header.h"


int main()
{
    sgrid       *grid = (sgrid*)malloc(sizeof(sgrid));
    dict        *words = (dict*)malloc(sizeof(dict));
    intersection** intrs;
    winput  **Vinputs;
    winput  **Hinputs;
    int         Hlen;
    int         Vlen;
    int         Ilen;

    readFile(words, grid, "in/crossword");

    intrs = setIntersectionsOnGrig(grid, &Ilen);
    Hinputs = horizontalWordsInputs(grid, intrs, &Hlen);
    Vinputs = verticalWordsInputs(grid, intrs, &Vlen);


printGrid(grid);

backTrack(Vinputs, Vlen, Hinputs,  Hlen, words, 0, 0);
// Solver(Vinputs, Vlen, Hinputs, Hlen, intrs, Ilen, words);
// printf("Vertical:\n");
//     printInputsArray(Vinputs, Vlen);
// printf("Horizontal:\n");
//     printInputsArray(Hinputs, Hlen);

// printIntersections(intrs, Ilen);

// printWordsDict(words);

completeGrig(intrs, grid);    

    return 0;
}
