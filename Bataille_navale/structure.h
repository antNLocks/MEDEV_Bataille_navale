#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <vector>
//Pour le random
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <map>
using namespace std;

#define NB_TYPES_BATEAU 5
enum TypeBateau { PORTE_AVION = 0, CROISEUR, CONTRE_TORPILLEUR, SOUS_MARIN, TORPILLEUR };

inline map<TypeBateau, int> tailleBateauMap = {{PORTE_AVION, 5}, {CROISEUR, 4}, {CONTRE_TORPILLEUR, 3}, {SOUS_MARIN, 3}, {TORPILLEUR, 2},};

#define PORTE_AVION_SIZE 5
#define CROISEUR_SIZE 4
#define CONTRE_TORPILLEUR_SIZE 3
#define SOUS_MARIN_SIZE 3
#define TORPILLEUR_SIZE 2

enum Etat {START, TOUR_JOUEUR, TOUR_ORDI, VICTOIRE_JOUEUR, VICTOIRE_ORDI };

///
/// Repr�sente un tir avec sa position et s'il a touch� ou non
///
struct Tir {

    ///
    /// La case en haut a gauche est la case (0;0). On ecrit dabord la ligne puis la colonne, ex : B3 = (2;1)
    ///
	int Position[2];

    ///
    /// false: a cote true: touche
    ///
    bool Resultat;

};

///
/// Représente un bateau en donnant son type, sa position et sa direction
///
struct Bateau {

    ///
    /// Donne le type de bateau: TypeBateau { PORTE_AVION, CROISEUR, CONTRE_TORPILLEUR, SOUS_MARIN, TORPILLEUR };
    ///
    TypeBateau Type;

    ///
    /// La case en haut a gauche est la case (0;0). On �crit dabord la ligne puis la colonne, ex : B3 = (2;1)
    ///
	int Position[2];

    ///
    /// false: horizontal, bateau dessine a partir de la case position vers la droite. true: vertical, bateau dessine  a partir de la case position vers le bas
    ///
	bool Direction;
};

///
/// Une classe qui contient les donnees sur les bateaux et les tirs des deux adversaires, et letat de la partie
///
class Plateau {

private:

    ///
    /// Etat dans laquelle la partie se trouve : Etat {START, TOUR_JOUEUR, TOUR_ORDI, VICTOIRE_JOUEUR, VICTOIRE_ORDI };
    ///
    Etat State;

    ///
    ///Contient les bateaux appartenant au joueur a afficher sur la grille du joueur
    ///
    vector<Bateau> bateauxJoueur;

    ///
    ///Contient les bateaux appartenant a l ordi qui ne seront pas affiche
    ///
    vector<Bateau> bateauxOrdi;

    ///
    ///Contient les tirs du joueur a afficher sur la grille de l ordi
    ///
    vector<Tir> tirsJoueur;

    ///
    ///Contient les tirs de l ordi a afficher sur la grille du joueur
    ///
    vector<Tir> tirsOrdi;

    ///
    ///Teste si b1 et b2 sont en collision
    ///
    bool testcollisionbateaux(Bateau b1, Bateau b2);
public:

    //CONSTRUCTEURS

    ///
    ///Construit un plateau avec des bateaux places aleatoirement et une liste de vecteurs tirs vides
    ///
    Plateau() {
        this -> State = START;
        this -> bateauxJoueur = {};
        this -> bateauxOrdi = {};
        this -> tirsJoueur = {};
        this -> tirsOrdi = {};
    }

    //GETTEURS

    ///
    ///Renvoie l etat du plateau
    ///
    Etat getState() const;

    ///
    ///Renvoie la liste des bateaux du joueur
    ///
    vector<Bateau> getBateauxJoueur() const;

    ///
    ///Renvoie la liste des bateaux de l ordi
    ///
    vector<Bateau> getBateauxOrdi() const;

    ///
    ///Renvoie la liste des tirs du joueur
    ///
    vector<Tir> getTirsJoueur() const;

    ///
    ///Renvoie la liste des tirs de l ordi
    ///
    vector<Tir> getTirsOrdi() const;

    //SETTEURS
    
    ///
    /// Change l etat de la partie
    ///
    void setState(Etat e);

    //FONCTIONS

    ///
    /// Modifie bateauxJoueuer avec un vecteur de bateaux places aleatoirement contenant un bateau de chaque type qui ne se recouvrent pas pour le joueur, pas parfait, probleme d occlusion par manque de temps, a n utiliser qu u
    ///
    void initialiseBateauxJ();

    ///
    /// Modifie bateauxOrdi avec un vecteur de bateaux places aleatoirement contenant un bateau de chaque type qui ne se recouvrent pas pour l ordi, pas parfait, probleme d occlusion par manque de temps
    ///
    void initialiseBateauxO();

    ///
    /// Verifie si l un des joueurs a gagne et change l etat (State)
    ///
    void testVictoire();

    ///
    /// Change la position du bateau considere, permet au joueur de placer ses bateaux en debut de partie (State = START)
    ///
    void changerBateau(Bateau b);

    ///
    ///Enleve les bateaux entierement touches de la liste
    ///
    void majBateaux();

    ///
    ///Teste si le bateau b est coule a cause des tirs
    ///
    bool testcoule(Bateau b, vector<Tir> tirs);

    ///
    ///Teste si le tir t touche au moins un des bateaux
    ///
    bool testtouche(Tir t, vector<Bateau> bateaux);

    ///
    ///Teste si un bateau joueur est entierement touche
    ///
    bool testcoulejoueur(Bateau b);

    ///
    ///Teste si un bateau ordinateur est entierement touche
    ///
    bool testcouleordi(Bateau b);

    ///
    ///Prend une position donn�e et ajoute un tir au joueur
    ///
    void maketirjoueur(int ligne,int colonne);

    ///
    ///Ajoute un tir a l ordinateur en fonction du comportement defini
    ///
    void maketirordi();

    // void input(Touche); a implementer plus tard

};

#endif
