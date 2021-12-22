#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>

typedef struct boite
{
	uint64_t cas;
	uint8_t *billes;
	uint8_t taille;
}boite;

void cas_bille(boite *t);
char* trad_dec_tab(uint64_t at);



void cas_bille(boite *t)
{
	char *tab;
	int i, cp = 0;
	uint8_t *Billes;

	tab = (char*) malloc( sizeof(char) * 10 );
	tab = trad_dec_tab( t->cas );

	for( i=0 ; i < 9 ; i++ )
	{
		if( tab[i] == ' ') cp++;
	}
	printf("cp = %d\n",cp);
	t->taille = cp;
	Billes = (uint8_t*) malloc( sizeof(uint8_t) * cp);
	cp = 0;

	for( i=0 ; i < 9 ; i++ )
	{
		if( tab[i] == ' ') 
		{
			Billes[cp] = i;
			printf("%d",Billes[cp]);
			printf("il ya une espace\n");
			cp++;
		}
	}

	t->billes = Billes;
}

char* trad_dec_tab(uint64_t at)
{
    uint64_t i,op;
    char *tab;
    tab = (char*)malloc(9*sizeof(char));
    op = at;
    for(i = 0 ; i < 9 ; i++)
    {
        if(floor(op / pow(3,8-i)) == 1)
        {
            tab[i] = 'o';
            op = op - 1*pow(3,8-i);
        }

        else if (floor(op / pow(3,8-i)) == 2) 
        {
            tab[i]= 'x';
            op = op - 2*pow(3,8-i);
        }
        else
        {
            tab[i] = ' ';
        }
    }
    return tab;
}


int main()
{
	uint8_t i;
	boite b1;

	b1.cas = 7290;

	cas_bille(&b1);
	printf("la taille de la boite est %d\n",b1.taille);
	printf("\n------------------------\n");
	for ( i = 0 ; i < b1.taille ; i++)
	{
		printf("%d|",b1.billes[i]);
	}
	printf("\n------------------------\n");

	return EXIT_SUCCESS;
}