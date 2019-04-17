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

    readFile(words, grid);

    intrs = setIntersectionsOnGrig(grid);
    Hinputs = horizontalWordsInputs(grid, intrs, &Hlen);
    Vinputs = verticalWordsInputs(grid, intrs, &Vlen);

printGrid(grid);

printf("Vertical:\n");
    printInputsArray(Vinputs, Vlen);
printf("Horizontal:\n");
    printInputsArray(Hinputs, Hlen);

printWordsDict(words);

    return 0;
}
