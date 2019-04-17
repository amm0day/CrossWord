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

    Vinputs[0]->word = words->words->word;
    Hinputs[0]->word = words->words->next->word;

// printGrid(grid);

printf("Vertical:\n");
    printInputsArray(Vinputs, Vlen);
printf("Horizontal:\n");
    printInputsArray(Hinputs, Hlen);

printIntersections(intrs, Ilen);

// printWordsDict(words);

    return 0;
}
