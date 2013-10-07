#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

Pile * creerPile(int _capacite)
{
	Pile * pile;

	pile = (Pile *) malloc(sizeof(Pile));
	pile->capacite = _capacite;
	pile->sommet = 0;
	pile->tableau = (int *) malloc(sizeof(int) * pile->capacite);

	return pile;
}

void detruirePile(Pile ** _pile)
{
	free((*_pile)->tableau);
	free(*_pile);
}

int capacitePile(Pile * _pile)
{
	return _pile->capacite;
}

int pileVide(Pile * _pile)
{
	return (_pile->sommet == 0);
}

int pilePleine(Pile * _pile)
{
	return (_pile->sommet >= _pile->capacite);
}

void empiler(Pile * _pile, int _valeur)
{
	if(!pilePleine(_pile))
	{
		_pile->tableau[_pile->sommet] = _valeur; 
		_pile->sommet++;
	}
	else
	{
		printf("La pile est pleine ! Impossible d'ajouter un élément \n");
	}

}

int depiler(Pile * _pile)
{
	if(!pileVide(_pile))
	{
		_pile->sommet--;
		return _pile->tableau[_pile->sommet+1];
	}
	printf("La pile est vide ! Impossible de dépiler. \n");
	return -1;
}

int sommet(Pile * _pile)
{
	return _pile->tableau[_pile->sommet];
}