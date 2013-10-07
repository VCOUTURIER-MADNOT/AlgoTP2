#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "outilsPile.h"

void afficherPile(Pile * _pile) /*Attention refaire la fonction pour qu'elle respecte la pile (empiler / depiler)*/
{
	int i, temp;
	pile * pileTemp;

	printf("\n La pile a les caractéristiques suivantes : \n");
	printf("\t Le dernier élément est à l'index : %d, \n", _pile->sommet);
	printf("\t La pile a une capacité de %d éléments. \n", _pile->capacite);
	printf("\t Les éléments de la pile sont :\n");

	pileTemp = creerPile(_pile->capacite);

	for(i = _pile->sommet - 1 ; i >= 0 ; i++)
	{
		temp = depiler(_pile);
		printf("\t\t Elément n°%d : %d\n", i, temp);
		empiler(pileTemp, temp);
	}

	for(i = 0 ; i < _pile->capacite ; i++)
	{
		empiler(_pile, depiler(pileTemp));
	}
}

void testPile()
{
	Pile * pile;
	int choix, elmtDepil;

	printf("Création d'une pile\n");
	printf("Quelle sera la taille maximum de la pile ? \n");
	pile = creerPile(saisieInt(10));

	do
	{
		printf("\n0. Quitter.\n");
		printf("1. Ajouter un élément.\n");
		printf("2. Supprimer un élément.\n");
		printf("3. Afficher la pile.\n");
		choix = saisieInt(1);

		switch(choix)
		{
			case 1:
				printf("Saisissez un entier :\n");
				empiler(pile, saisieInt(10));
				break;
			case 2:
				elmtDepil = depiler(pile);
				break;
			case 3:
				afficherPile(pile);
				break;
			default:
				break;
		}
	}
	while(choix != 0);
}

int saisieInt()
{
	int res;

	printf("Choix : ");
	scanf("%d", &res);
	printf("\n");

	return res;
}