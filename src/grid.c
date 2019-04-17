#include "../include/header.h"


intersection** setIntersectionsOnGrig(sgrid *grid, int *len){
    int icount = 0;

    // Set an id for each intersection
    for (int i = 0; i < grid->y; i++)
        for (int j = 0; j < grid->x; j++)
            if (grid->grid[i][j] > -1 && (((i + 1 < grid->y && -1 < grid->grid[i + 1][j]) || 
                        (i - 1 >= 0 && -1 < grid->grid[i - 1][j])) &&
                    ((-1 < grid->grid[i][j + 1] && j + 1 < grid->x) || 
                        (j - 1 >= 0 && -1 < grid->grid[i][j - 1]))))
                grid->grid[i][j] = ++icount;
    
    intersection** intrs = (intersection**)malloc(sizeof(intersection*) * icount);

    for (int i = 0; i < icount; i++)
        intrs[i] = (intersection*)malloc(sizeof(intersection));
    *len = icount;
    icount = 0;

    // Set intersections position for coross words
    for (int i = 0; i < grid->y; i++)
        for (int j = 0; j < grid->x; j++)
            if (grid->grid[i][j] > 0){
                (intrs[icount])->id = grid->grid[i][j];
                int char_pos = 0;
                while (i - char_pos >= 0 && -1 < grid->grid[i - char_pos][j])
                    char_pos++;
                (intrs[icount])->Hpos = char_pos;
                char_pos = 0;
                while (j - char_pos >= 0 && -1 < grid->grid[i][j - char_pos])
                    char_pos++;
                (intrs[icount])->Vpos = char_pos;
                icount++;
            }
    return intrs;
}

winput  **horizontalWordsInputs(sgrid *grid, intersection** intrs, int* len){

    int counter = 0;
    int ic;

    for (int i = 0; i < grid->y; i++)
        for (int j = 0; j < grid->x; j++)
            if (j + 1 < grid->x && -1 < grid->grid[i][j] && -1 < grid->grid[i][j + 1]){
                counter++;
                while (j < grid->x && -1 < grid->grid[i][j])
                    j++;
            }
    winput  **Vinputs = (winput**)malloc(sizeof(winput*) * counter);
    for (int i = 0; i < counter; i++)
        Vinputs[i] = (winput*)malloc(sizeof(winput));
    *len = counter;
    counter = 0;
    for (int i = 0; i < grid->y; i++)
        for (int j = 0; j < grid->x; j++)
            if (j + 1 < grid->x && -1 < grid->grid[i][j] && -1 < grid->grid[i][j + 1]){
                (Vinputs[counter])->len = 0;
                (Vinputs[counter])->word = NULL;
                ic = 0;
                for (int x = j; x < grid->x && -1 < grid->grid[i][x]; x++)
                    ic++;
                (Vinputs[counter])->intrs = (intersection**)malloc(sizeof(intersection*) * ic);
                (Vinputs[counter])->nrOfI = ic;
                ic = 0;
                while (j < grid->x && -1 < grid->grid[i][j]){
                    if (grid->grid[i][j] > 0){
                        (Vinputs[counter])->intrs[ic] = (intrs[grid->grid[i][j]-1]);
                        ic++;
                        (intrs[grid->grid[i][j]-1])->Hword = (char**)malloc(sizeof(char*));
                        (intrs[grid->grid[i][j]-1])->Hword = &((Vinputs[counter])->word);
                        (Vinputs[counter])->nrOfI = ic;
                    }
                    (Vinputs[counter])->len++;
                    j++;
                }
                counter++;
            }
    return Vinputs;
}

winput  **verticalWordsInputs(sgrid *grid, intersection** intrs, int* len){

    int counter = 0;
    int ic;

    for (int j = 0; j < grid->x; j++)
        for (int i = 0; i < grid->y; i++)
            if (i + 1 < grid->y && -1 < grid->grid[i][j] && -1 < grid->grid[i + 1][j]){
                counter++;
                while (i < grid->y && -1 < grid->grid[i][j])
                    i++;
            }

    winput  **Vinputs = (winput**)malloc(sizeof(winput*) * counter);
    for (int i = 0; i < counter; i++)
        Vinputs[i] = (winput*)malloc(sizeof(winput));
    
    *len = counter;
    counter = 0;
    for (int j = 0; j < grid->x; j++)
        for (int i = 0; i < grid->y; i++)
            if (i + 1 < grid->y && -1 < grid->grid[i][j] && -1 < grid->grid[i + 1][j]){
                (Vinputs[counter])->len = 0;
                (Vinputs[counter])->word = NULL;
                ic = 0;
                for (int x = i; x < grid->y && -1 < grid->grid[x][j]; x++)
                    ic++;
                (Vinputs[counter])->intrs = (intersection**)malloc(sizeof(intersection*) * ic);
                ic = 0;
                while (i < grid->y && -1 < grid->grid[i][j]){
                    if (grid->grid[i][j] > 0){
                        (Vinputs[counter])->intrs[ic] = (intrs[grid->grid[i][j]-1]);
                        ic++;
                        (intrs[grid->grid[i][j]-1])->Vword = &(Vinputs[counter])->word;
                        (Vinputs[counter])->nrOfI = ic;
                    }

                    (Vinputs[counter])->len++;
                    i++;
                }
                counter++;
            }
    // Sort by intersection id
    winput          *tmp;
    int             i1 = 0, i2 = 0;
    for(int i = 0; i < counter - 1; i++) {
        if ((Vinputs[i]->intrs[0])->id > (Vinputs[i + 1]->intrs[0])->id){
            tmp = Vinputs[i];
            Vinputs[i] = Vinputs[i + 1];
            Vinputs[i + 1] = tmp;
            i = -1;
        }
    }
    return Vinputs;
}

void printGrid(sgrid *grid){
    for (int i = 0; i < grid->y; i++){
        for (int j = 0; j < grid->x; j++){
            if (grid->grid[i][j] > -1 && grid->grid[i][j] < 10)
                printf(" %d", grid->grid[i][j]);
            else
                printf("%d", grid->grid[i][j]);
        }
        printf("\n");
    }
}

void printInputsArray(winput **in_array, int len){
    printf("%d\n", len);
    for (int i = 0; i < len; i++){
        printf("l = %d, w = %s[", in_array[i]->len, in_array[i]->word);
        for(int j = 0; j < in_array[i]->nrOfI; j++)
            printf(" %d ", (in_array[i]->intrs[j])->id);    
        printf("]\n");
    }
}

void printWordsDict(dict* wdict){
    while (wdict){
        printf("l = %d\n", wdict->len);
        word *tmp = wdict->words;
        while (tmp){
            printf("\t%s\n", tmp->word);
            tmp = tmp->next;
        }
        wdict = wdict->next;
    }
    
}

void printIntersections(intersection **intrs, int len){
    for(int i = 0; i < len; i++) {
        printf("[%d] H %s, V %s\n", intrs[i]->id, *intrs[i]->Hword, *intrs[i]->Vword);
    }
}