#ifndef STRUCTURE_H
#define STRUCTURE_H

enum TypeBateau { PORTE_AVION, CROISEUR, CONTRE_TORPILLEUR, SOUS_MARIN };

struct Tir {

	int Position[2];
	// La case en haut � gauche est la case (0;0)
	// On �crit d�abord la ligne puis la colonne, ex : B3 = (2;1)

	bool Direction;
	// false : 0 : � cot�
	// true : 1 : touch�

};

struct Bateau {
	TypeBateau Type;
	
	int Position[2];
	// La case en haut � gauche est la case (0;0)
	// On �crit d�abord la ligne puis la colonne, ex : B3 = (2;1)

	bool Direction;
	// false : 0 : horizontal, bateau dessin� � partir de la case position vers la droite
	// true : 1 : vertical, bateau dessin� � partir de la case position vers le bas
};

#endif
