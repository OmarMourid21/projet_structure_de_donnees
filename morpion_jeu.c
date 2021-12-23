#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

uint64_t trad_tab_dec(char tab[9]);
char* trad_dec_tab(uint64_t at);
void affiche_tableau(uint64_t dec);
bool existe_esp(uint64_t dec);
bool terminer_vertical(uint64_t dec);
bool terminer_horizental(uint64_t dec);
bool terminer_diag(uint64_t dec);
int jeu_morp(void);


int main()
{
	int res = jeu_morp();
	if(res == 1) printf("le joueur x ");
	else if(res == -1) printf("le joueur o ");
	else printf("match null");
	return 0;
}




int jeu_morp(void)
{
	char tab[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	uint8_t place;
	uint8_t cp=0;

    affiche_tableau(trad_tab_dec(tab));
	while(cp<9)
	{
		printf("\nchoose from 1 to 9\n");
		scanf("%u",&place);

		if( cp % 2 == 0 ) tab[place-1] = 'x';
		else tab[place-1] = '0';

		affiche_tableau(trad_tab_dec(tab));
		if(terminer_vertical(trad_tab_dec(tab)))
		{
			if(cp % 2 == 0) return 1;
			if(cp % 2 != 0) return -1;
		}
		if(terminer_horizental(trad_tab_dec(tab)))
		{
			if(cp % 2 == 0) return 1;
			if(cp % 2 != 0) return -1;
		}
		if(terminer_diag(trad_tab_dec(tab)))
		{
			if(cp % 2 == 0) return 1;
			if(cp % 2 != 0) return -1;
		}
		cp++;
	}
	return 0;
}


//%----------------------------------------------------------------
uint64_t trad_tab_dec(char tab[9])
{
	uint64_t i,res=0;

	for ( i = 0 ; i < 9 ; i++)
	{
		
        if(tab[i]==' '){
            res += 0;
        }

        else if (tab[i]=='x'){
            res += 2*pow(3,8-i);
        }

        else{
            res += 1*pow(3,8-i);
        }
	}

	return res;
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

void affiche_tableau(uint64_t dec)
{
	char* tab;
	uint8_t i;
	tab = (char*)malloc(9*sizeof(char));
	tab = trad_dec_tab(dec);

	for ( i = 0 ; i < 9 ; i++)
	{
		printf("|%c",tab[i]);
		if( (i+1) % 3 == 0 && i != 0) printf("|\n");
	}
}

bool terminer_vertical(uint64_t dec)
{
	uint8_t i;
	uint8_t cc[3]={1,1,1};
	char* tab;
	tab = (char*)malloc(9*sizeof(char));
	tab = trad_dec_tab(dec);
	for(i = 0 ; i < 2 ; i++)
	{
		if(tab[i*3] == tab[(i+1)*3]) cc[0]++;
		if(tab[i*3 + 1] == tab[(i+1)*3 + 1])  cc[1]++;
		if(tab[i*3 + 2] == tab[(i+1)*3 + 2])  cc[2]++;
	}

	for(i = 0 ; i < 3 ; i++)
	{
		if(cc[i] == 3 && tab[i] != ' ') return true;
	}
	return false;
}

bool terminer_horizental(uint64_t dec)
{
	uint8_t i;
	uint8_t cc[3]={1,1,1};
	char* tab;
	tab = (char*)malloc(9*sizeof(char));
	tab = trad_dec_tab(dec);
	for(i = 0 ; i < 2 ; i++)
	{
		if(tab[i] == tab[i+1]) cc[0]++;
		if(tab[i+3] == tab[(i+1)+3])  cc[1]++;
		if(tab[i+6] == tab[(i+1)+6])  cc[2]++;
	}

	for(i = 0 ; i < 3 ; i++)
	{
		if(cc[i] == 3 && tab[i*3] != ' ') return true;
	}
	return false;
}

bool terminer_diag(uint64_t dec)
{
	uint8_t i;
	uint8_t cc[2] = {1,1};
	char* tab;
	tab = (char*)malloc(9*sizeof(char));
	tab = trad_dec_tab(dec);
	for(i = 0 ; i < 2 ; i++)
	{
		if(tab[2+2*i] == tab[4+i*2]) cc[0]++;
		if(tab[4*i] == tab[4+i*4])  cc[1]++;
	}
	if (cc[0] == 3 && tab[2] != ' ') return true;
	if (cc[1] == 3 && tab[0] != ' ') return true;

	return false;
}