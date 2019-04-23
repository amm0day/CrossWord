#include "../include/header.h"

void readFile(dict  *words, sgrid *grid, char* fl){
    FILE *  fp;
    char *  line;
    size_t  len = 0;
    int     lnlen = 0;
    int lncounter = 0;
    dict    *tmp = NULL;
    word    *new_word;

    fp = fopen(fl, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    // Read first word for list initialization
    getline(&line, &len, fp);
    lnlen = strlen(line) - 1;
    if (lnlen){
        line[lnlen] = '\0';
        new_word = (word*)malloc(sizeof(word));
        new_word->word = line;
        new_word->used = 0;
        new_word->next = NULL;
        words->words = new_word;
        words->len = lnlen;
        words->next = NULL;
        line = NULL;
    } else {
        printf("Invalid file input");
        exit(1);
    }
    while (getline(&line, &len, fp) != -1) {
        lnlen = strlen(line) - 1;
        line[lnlen] = '\0';
        // read grid size
        if (lnlen && line[0] == '#'){
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
        // read grid
        } else if (lnlen && (line[0] == ' ' || line[0] == '1')){
            for (int i = 0; i < grid->x; i++){
                if (line[i] != '1')
                    grid->grid[lncounter][i] = -1;
                else
                    grid->grid[lncounter][i] = 0;
            }
            lncounter++;
        // read words
        } else if (lnlen && line[0] != ' ' && line[0] != '1'){
            new_word = (word*)malloc(sizeof(word));
            new_word->word = line;
            new_word->used = 0;
            new_word->next = NULL;
            printf("%s %d\n", new_word->word, lnlen);
            tmp = words;
            while(tmp){
                if (tmp->len == lnlen){
                    new_word->next = tmp->words;
                    tmp->words = new_word;
                    break;
                }
                else if (tmp->next)
                    tmp = tmp->next;
                else {
                    tmp->next = (dict*)malloc(sizeof(dict));
                    tmp = tmp->next;
                    tmp->words = new_word;
                    tmp->len = lnlen;
                    tmp->next = NULL;
                    break;
                }
            }
            line = NULL;
        }
    }
    fclose(fp);
}
