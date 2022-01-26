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
	// Contient les bateaux appartenant au joueur à afficher sur la grille du joueur
	std::vector<Bateau> bateauxOrdi;
	// Contient les bateaux appartenant a l'ordi qui ne seront pas affiché
	std::vector<Tir> tirsJoueur;
	// Contient les tirs du joueur à afficher sur la grille de l'ordi
	std::vector<Tir> tirsOrdi;
	// Contient les tirs de l'ordi à afficher sur la grille du joueur

	void setBateauxJoueur(std::vector<Bateau> bateauxJoueurs);
	void setBateauxOrdi(std::vector<Bateau> bateauxOrdi);
	void setTirsJoueur(std::vector<Tir> tirsJoueur);
	void setTirsOrdi(std::vector<Tir> TirsOrdi);

	void colorierCase(bool grilleActive, int noColonne, int noLigne, float R, float G, float B);

	void afficheGrille(bool grilleActive);
	void afficheBateaux(bool grilleActive);
	void afficheTirs(bool grilleActive);
	void afficheBateau(bool grilleActive, int noLigne, int noColonne);
	void afficheTirRate(bool grilleActive, int noColonne, int noLigne);
	void afficheTirTouche(bool grilleActive, int noColonne, int noLigne);
	void afficheTirCoule(bool grilleActive, int noColonne, int noLigne);

public :
	Afficheur();
	/// <summary>
	/// Réalise l'affichage à partir de l'état du jeu courant en mémoire
	/// </summary>
	void affichage();

};
