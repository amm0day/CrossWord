#include "../include/header.h"

void Solver(winput **Vinputs, int Vlen, winput **Hinputs,  int Hlen, intersection **intrs, int Ilen, dict *words){
	
	dict *tmp;
	word *tmpWlst;


	for(int i = 0; i < Vlen; i++){
		tmp = words;
		while(tmp && tmp->len != Vinputs[i]->len)
			tmp = tmp->next;
		if (!tmp){
			printf("This grid has no solution with given dictionary");
			return;
		}
		tmpWlst = tmp->words; 
		while(tmpWlst)
			if (tryWord(Vinputs[i], tmpWlst))
				break;
			else
				tmpWlst = tmpWlst->next;
	}
	
	for(int i = 0; i < Hlen; i++){
		tmp = words;
		while(tmp && tmp->len != Hinputs[i]->len)
			tmp = tmp->next;
		if (!tmp){
			printf("This grid has no solution with given dictionary");
			return;
		}
		tmpWlst = tmp->words; 
		while(tmpWlst)
			if (tryWord(Hinputs[i], tmpWlst))
				break;
			else
				tmpWlst = tmpWlst->next;
	}

}

size_t tryWord(winput *Winput, word *word){
	intersection *intrs;

	if (word->used)
		return 0;

	Winput->word = word->word ;
	for(int i = 0; i < Winput->nrOfI; i++)	{
		intrs = Winput->intrs[i];
		if (*intrs->Hword && *intrs->Vword && 
			(*intrs->Hword)[intrs->Hpos] != (*intrs->Vword)[intrs->Vpos]){
			Winput->word = NULL;
			return 0;
		}	
	}
	if (*intrs->Hword && *intrs->Vword){
		printf("%s [%d] == %s [%d]", *intrs->Hword, intrs->Hpos, *intrs->Vword, intrs->Vpos);
		printf(" | [%c] == [%c]\n", (*intrs->Hword)[intrs->Hpos], (*intrs->Vword)[intrs->Vpos]);
	}
	word->used = 1;
	return 1;
}