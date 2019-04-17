#include "../include/header.h"

void readFile(dict  *words, sgrid *grid){
    FILE *  fp;
    char *  line;
    size_t  len = 0;
    int     lnlen = 0;
    int lncounter = 0;
    dict    *tmp;
    word    *new_word;

    fp = fopen("in/crossword", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (getline(&line, &len, fp) != -1) {
        lnlen = strlen(line) - 1;
        line[lnlen] = '\0';
        // read grid size
        if (line[0] == '#'){
            lnlen = 1;
            grid->y = 0;
            while (line[lnlen] && (line[lnlen] >= '0' && line[lnlen] <= '9'))
                grid->y = grid->y * 10 + (line[lnlen++] - '0');
            lnlen++;
            grid->x = 0;
            while (line[lnlen] && (line[lnlen] >= '0' && line[lnlen]<= '9'))
                grid->x = grid->x * 10 + (line[lnlen++] - '0');
            
            grid->grid = (int**)malloc(sizeof(int*) * grid->y);
            for (int i = 0; i < grid->y; i++)
                grid->grid[i] = (int*)malloc(sizeof(int) * grid->x);
            printf("%d %d\n", grid->y, grid->x);
        // read words
        } else if (line[0] != ' ' && line[0] != '1'){
            new_word = (word*)malloc(sizeof(word));
            new_word->word = line;
            new_word->used = 0;
            tmp = &words;
            while(tmp){
                if (tmp->len == lnlen)
                    break;
                tmp = tmp->next;
            }
            if (!tmp){
                tmp = (dict*)malloc(sizeof(dict));
                tmp->len = lnlen;
                tmp->next = words;
                tmp->words = NULL;
                words = tmp;
            }
            new_word->next = tmp->words;
            tmp->words = new_word;
        } else if (line[0] == ' ' || line[0] == '1'){
            for (int i = 0; i < grid->x; i++){
                if (line[i] != '1')
                    grid->grid[lncounter][i] = -1;
                else
                    grid->grid[lncounter][i] = 0;
            }
            lncounter++;
        }
    }
    fclose(fp);
}
