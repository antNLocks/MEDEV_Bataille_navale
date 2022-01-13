#pragma once

#include<vector>
#include "structure.h"

/// <summary>
/// \class Afficheur
/// \brief Permet l'affichage graphique du jeu à partir de l'état courant en mémoire
/// </summary>
class Afficheur {

private :
	int nbrCase;
	float coorGrilleJoueur[4];
	float coorGrilleOrdi[4];

	std::vector<Bateau> bateauxJoueur;
	// Contient les bateaux appartenant au joueur a afficher sur la grille du joueur
	std::vector<Bateau> bateauxOrdi;
	// Contient les bateaux appartenant a l ordi qui ne seront pas affiche
	std::vector<Tir> tirsJoueur;
	// Contient les tirs du joueur a afficher sur la grille de l ordi
	std::vector<Tir> tirsOrdi;
	// Contient les tirs de l ordi a afficher sur la grille du joueur

	void afficheGrille(float x_bas_gauche, float y_bas_gauche, float x_haut_droite, float y_haut_droite);
	void colorierCase(bool grilleActive, int noColonne, int noLigne, float R, float G, float B);
	void afficheTirRate(bool grilleActive, int noColonne, int noLigne);
	void afficheTirTouche(bool grilleActive, int noColonne, int noLigne);
	void afficheTirCoule(bool grilleActive, int noColonne, int noLigne);

	void dataFiller();

public :
	Afficheur();
	void affichage();

};