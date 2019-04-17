#include "../include/header.h"

void setIntersections(intersection* intrs, sgrid* grid){

    for (int y = 0; y < grid->y; y++){
        for (int x = 0; x < grid->y; x++){
            if (y == 0){
                if (!(grid->grid[y][x] && grid->grid[y+1][x])){
                    
                }
            }
        }
    }
}

void addIntersection(intersection* intrs, sgrid* grid, int y, int x){
    int  id;
    int  Vpos = 0;
    int  Vlen;

    while(intrs->next){
        intrs = intrs->next;
    }
    id = intrs->id;

    intrs->next = (intersection*)malloc(sizeof(intersection));
    intrs = intrs->next;
    
    for(int i = y - 1; i >= 0 && !grid->grid[i][x]; i--){
        Vpos++;
    }
    for(int i = y - 1; i >= 0 && !grid->grid[i][x]; i--){
        Vpos++;
    }
    
    grid->grid[y][x]
}
    int             id;
    int             Vpos;
    int             Vlen;
    word*           Vword;
    int             Hpos;
    int             Hlen;
    word*           Hword;