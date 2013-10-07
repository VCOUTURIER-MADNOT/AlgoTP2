#ifndef DEF_PILE
#define DEF_PILE

	typedef struct
	{
		int capacite;
		int sommet;
		int * tableau;
	} Pile;

	Pile * creerPile(int _capacite);
	void detruirePile(Pile ** p);
	int capacitePile(Pile * _pile);
	int pileVide(Pile * _pile);
	int pilePleine(Pile * _pile);
	void empiler(Pile * _pile, int _valeur);
	int depiler(Pile * _pile);
	int sommet(Pile * _pile);


#endif