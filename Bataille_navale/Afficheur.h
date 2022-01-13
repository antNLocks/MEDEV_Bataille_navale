#pragma once

/// <summary>
/// \class Afficheur
/// \brief Permet l'affichage graphique du jeu à partir de l'état courant en mémoire
/// </summary>
class Afficheur {

private :
	int nbrCase;
	float coorGrilleJoueur[4];
	float coorGrilleOrdi[4];
	void afficheGrille(float x_bas_gauche, float y_bas_gauche, float x_haut_droite, float y_haut_droite);
	void afficheTouche(bool grilleActive, int noColonne, int noLigne);

public :
	Afficheur();
	void affichage();

};