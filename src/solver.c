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

// void backTrack(winput **Vinputs, int Vlen, winput **Hinputs,  int Hlen, dict *words, int H, int V){
// 	dict *tmp;
// 	word *tmpWlst;
// 	if (V == Vlen && H == Hlen)
// 		return;
	
// 	if (V < H && V < Vlen){
// 		tmp = words;
// 		while(tmp && tmp->len != Vinputs[V]->len)
// 			tmp = tmp->next;
// 		if (!tmp){
// 			printf("This grid has no solution with given dictionary");
// 			return;
// 		}
// 		if (Vinputs[V]->word)
// 			tmpWlst = Vinputs[V]->
// 		else
// 			tmpWlst = tmp->words; 
// 		while(tmpWlst)
// 			if (tryWord(Vinputs[V], tmpWlst))
// 				break;
// 			else
// 				tmpWlst = tmpWlst->next;
// 	}
// }

void backTrack(winput **Vinputs, int Vlen, winput **Hinputs,  int Hlen, dict *words, int H, int V){
	dict *tmpDict;
	word *tmpWord;

	while (1){
		tmpDict = words;
		if (V == Vlen && H == Hlen)
			return;
		
		if (V <= H && V < Vlen){
			while (tmpDict && tmpDict->len != Vinputs[V]->len) 
				tmpDict = tmpDict->next;
			if (!tmpDict){
				printf("Words with len %d doesn't exists\n", Vinputs[V]->len);
				return;
			}
			tmpWord = tmpDict->words;
			while (tmpWord) {
				if (tryWord(Vinputs[V], tmpWord)){
					printf("breaked ");
					V++;
					break;
				} else
					tmpWord = tmpWord->next;
			}
			printf("pointer = %p, len = %d\n", tmpWord, Vinputs[V]->len);
			if (!tmpWord && H != 0)
				H--;			
			// else {
			// 	printf("Problem has no solution on V\n");
			// 	return;
			// }
			printf("On V = %d\n", V);
		} else {
			while (tmpDict && tmpDict->len != Hinputs[H]->len) 
				tmpDict = tmpDict->next;
			if (!tmpDict) {
				printf("Words with len %d doesn't exists\n", Hinputs[H]->len);
				return;
			}
			tmpWord = tmpDict->words;
			while (tmpWord) {
				if (tryWord(Hinputs[H], tmpWord)){
					printf("breaked ");
					H++;
					break;
				} else
					tmpWord = tmpWord->next;
			}
			if (!tmpWord && V != 0)
				V--;
			// else {
			// 	printf("Problem has no solution on H\n");
			// 	return;
			// }
			printf("On H = %d\n", H);

		}
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
		printf("%s\n", *Winput->intrs[i]->Hword);
			Winput->word = NULL;
			return 0;
		}	
	}

	word->used = 1;
	return 1;
}