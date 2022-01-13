#pragma once

#include<vector>
#include "structure.h"

/// <summary>
/// \class Afficheur
/// \brief Permet l'affichage graphique du jeu
/// </summary>
class Afficheur {

private :
	int nbrCase;
	float coorGrilleJoueur[4];
	float coorGrilleOrdi[4];

	std::vector<Bateau> bateauxJoueur;
	// Contient les bateaux appartenant au joueur � afficher sur la grille du joueur
	std::vector<Bateau> bateauxOrdi;
	// Contient les bateaux appartenant a l'ordi qui ne seront pas affich�
	std::vector<Tir> tirsJoueur;
	// Contient les tirs du joueur � afficher sur la grille de l'ordi
	std::vector<Tir> tirsOrdi;
	// Contient les tirs de l'ordi � afficher sur la grille du joueur

	void colorierCase(bool grilleActive, int noColonne, int noLigne, float R, float G, float B);

	void afficheGrille(bool grilleActive);
	void afficheBateaux(bool grilleActive);
	void afficheTirRate(bool grilleActive, int noColonne, int noLigne);
	void afficheTirTouche(bool grilleActive, int noColonne, int noLigne);
	void afficheTirCoule(bool grilleActive, int noColonne, int noLigne);

	void dataFiller();

public :
	Afficheur();
	/// <summary>
	/// R�alise l'affichage � partir de l'�tat du jeu courant en m�moire
	/// </summary>
	void affichage();

};