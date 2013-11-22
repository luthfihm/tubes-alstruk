#include "adt-deck.h"

int main (){
	
	infotype K;
	Deck D;
	int i=1;
	
	CreateEmpty(&D);
	DefaultDeck(&D);
	ShuffleDeck(&D);
	DeckReady(&D);
	while(i<=68){
		Draw(&D,&K);
		printf("%d %c %d \n",ID(K),Jenis(K),Guna(K));
		i++;
	}
	return 0;
}
