#ifndef STRUCTURE_H
#define STRUCTURE_H

enum TypeBateau { PORTE_AVION, CROISEUR, CONTRE_TORPILLEUR, SOUS_MARIN };

enum Etat {START, TOUR_JOUEUR, TOUR_ORDI, VICTOIRE_JOUEUR, VICTOIRE_ORDI };

struct Tir {

	int Position[2];
	// La case en haut a gauche est la case (0;0)
	// On ecrit dabord la ligne puis la colonne, ex : B3 = (2;1)

	bool Direction;
	// false : 0 : a cote
	// true : 1 : touche

};

struct Bateau {
	TypeBateau Type;
	
	int Position[2];
	// La case en haut a gauche est la case (0;0)
	// On �crit dabord la ligne puis la colonne, ex : B3 = (2;1)

	bool Direction;
	// false : 0 : horizontal, bateau dessine a partir de la case position vers la droite
	// true : 1 : vertical, bateau dessine a partir de la case position vers le bas
};

class Plateau {
    
private:
    Etat State;

    vector<Bateau> bateauxJoueur;
    // Contient les bateaux appartenant au joueur a afficher sur la grille du joueur

    vector<Bateau> bateauxOrdi;
    // Contient les bateaux appartenant a l ordi qui ne seront pas affiche

    vector<Tir> tirsJoueur;
    // Contient les tirs du joueur a afficher sur la grille de l ordi

    vector<Tir> tirsOrdi;
    // Contient les tirs de l ordi a afficher sur la grille du joueur

public:

    //CONSTRUCTEURS

    //GETTEURS

    Etat getState() const;
    vector<Bateau> getBateauxJoueur() const;
    vector<Bateau> getBateauxOrdi() const;
    vector<Tir> getTirsJoueur() const;
    vector<Tir> getTirsOrdi() const;

    //FONCTIONS

    vector<Bateau> initialiseBateaux();
    // Retourne un vecteur de bateau place aleatoirement contenant un bateau de chaque type qui ne se recouvrent pas

    void testVictoire();
    // Verifie si l un des joueurs a gagne et change l etat (State)

    void changerBateau(Bateau b);
    // Change la position du bateau considere, permet au joueur de placer ses bateaux en debut de partie 
    // (State = START)

    void input(Touche);

};



#endif
