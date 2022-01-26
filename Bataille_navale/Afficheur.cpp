#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif

#include "Afficheur.h"

void Afficheur::afficheGrille(bool grilleActive)
{
    for (int i = 0; i < nbrCase; i++) {
        for (int j = 0; j < nbrCase; j++) {
            // Alternance de la couleur des cases
            if ((i + j) % 2 == 0) {
                colorierCase(grilleActive, i, j, 0.211f, 0.580f, 0.921f);
            }
            else {
                colorierCase(grilleActive, i, j, 0.211f, 0.682f, 0.921f);
            }
        }
    }
}

void Afficheur::afficheBateaux(bool grilleActive)
{
    if (grilleActive) { // C'est la grille du joueur qui est remplie avec les bateaux
        for (int i = 0; i < bateauxJoueur.size(); i++) { // Pour chaque bateau
            int l = 0;
            int c = 0;
            for (int j = 0; j < tailleBateauMap[bateauxJoueur[i].Type]; j++) { // Pour chaque case du bateau
                afficheBateau(grilleActive, bateauxJoueur[i].Position[0]+l, bateauxJoueur[i].Position[1]+c);
                if (bateauxJoueur[i].Direction) { l = l + 1; }
                else { c = c + 1; }
            }
        }
    }
    else { // C'est la grille de l'ordi qui est qui est remplie avec les bateaux
        for (int i = 0; i < bateauxOrdi.size(); i++) { // Pour chaque bateau
            int l = 0;
            int c = 0;
            for (int j = 0; j < tailleBateauMap[bateauxOrdi[i].Type]; j++) { // Pour chaque case du bateau
                afficheBateau(grilleActive, bateauxOrdi[i].Position[0] + l, bateauxOrdi[i].Position[1] + c);
                if (bateauxOrdi[i].Direction) { l = l + 1; }
                else { c = c + 1; }
            }
        }
    }
}

void Afficheur::afficheTirs(bool grilleActive)
{
    if (grilleActive) { // On affiche les tirs de l'ordi sur la grille du joueur
        for (int i = 0; i < tirsOrdi.size(); i++) { // Pour chaque tir
            if (tirsOrdi[i].Resultat) {
                afficheTirTouche(grilleActive, tirsOrdi[i].Position[0], tirsOrdi[i].Position[1]);
            }
            else {
                afficheTirCoule(grilleActive, tirsOrdi[i].Position[0], tirsOrdi[i].Position[1]);
            }
        }
    }
    else {
        for (int i = 0; i < tirsJoueur.size(); i++) { // Pour chaque tir
            if (tirsJoueur[i].Resultat) {
                afficheTirTouche(grilleActive, tirsJoueur[i].Position[0], tirsJoueur[i].Position[1]);
            }
            else {
                afficheTirCoule(grilleActive, tirsJoueur[i].Position[0], tirsJoueur[i].Position[1]);
            }
        }
    }
}

void Afficheur::afficheBateau(bool grilleActive, int noLigne, int noColonne)
{
    colorierCase(grilleActive, noLigne, noColonne, 0.5f, 0.5f, 0.5f); // gris
}

void Afficheur::setBateauxJoueur(std::vector<Bateau> _bateauxJoueurs)
{
    bateauxJoueur = _bateauxJoueurs;
}

void Afficheur::setBateauxOrdi(std::vector<Bateau> _bateauxOrdi)
{
    bateauxOrdi = _bateauxOrdi;
}

void Afficheur::setTirsJoueur(std::vector<Tir> _tirsJoueur)
{
    tirsJoueur = _tirsJoueur;
}

void Afficheur::setTirsOrdi(std::vector<Tir> _tirsOrdi)
{
    tirsOrdi = _tirsOrdi;
}

void Afficheur::colorierCase(bool grilleActive, int noLigne, int noColonne, float R, float G, float B)
{
    noLigne = 9 - noLigne;

    float coorGrille[4];
    if (grilleActive) { // C'est la grille du joueur qui est affichée à gauche
        for (int index = 0; index < 4; index++) {
            coorGrille[index] = coorGrilleJoueur[index];
        }
    }
    else { // C'est la grille de l'ordi qui est affichée à droite
        for (int index = 0; index < 4; index++) {
            coorGrille[index] = coorGrilleOrdi[index];
        }
    }

    float largeur = (coorGrille[2] - coorGrille[0]) / nbrCase;
    float hauteur = (coorGrille[3] - coorGrille[1]) / nbrCase;
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
    glVertex2f(coorGrille[0] + noColonne * largeur, coorGrille[1] + noLigne * hauteur);
    glVertex2f(coorGrille[0] + (noColonne + 1) * largeur, coorGrille[1] + noLigne * hauteur);
    glVertex2f(coorGrille[0] + (noColonne + 1) * largeur, coorGrille[1] + (noLigne + 1) * hauteur);
    glVertex2f(coorGrille[0] + noColonne * largeur, coorGrille[1] + (noLigne + 1) * hauteur);
    glEnd();
}

void Afficheur::afficheTirRate(bool grilleActive, int noLigne, int noColonne)
{
    colorierCase(grilleActive, noLigne ,noColonne, 0.0f, 0.0f, 1.0f); // bleu
}

void Afficheur::afficheTirTouche(bool grilleActive, int noLigne, int noColonne)
{
    colorierCase(grilleActive, noLigne, noColonne, 1.0f, 0.0f, 0.0f); // rouge
}

void Afficheur::afficheTirCoule(bool grilleActive, int noLigne, int noColonne)
{
    colorierCase(grilleActive, noLigne, noColonne, 0.364f, 0.023f, 0.501f); // violet
}

Afficheur::Afficheur()
{
    nbrCase = 10;
    coorGrilleJoueur[0] = 2 * (1.0f / 11) - 1; // Abcisse des coordonnées écran du point en bas à gauche de la grille du joueur
    coorGrilleJoueur[1] = 2 * (1.0f / 6) - 1;
    coorGrilleJoueur[2] = 2 * (5.0f / 11) - 1;
    coorGrilleJoueur[3] = 2 * (5.0f / 6) - 1;
    coorGrilleOrdi[0] = 2 * (6.0f / 11) - 1;
    coorGrilleOrdi[1] = 2 * (1.0f / 6) - 1;
    coorGrilleOrdi[2] = 2 * (10.0f / 11) - 1;
    coorGrilleOrdi[3] = 2 * (5.0f / 6) - 1;
}

void Afficheur::affichage(vector<Bateau> bateauxJoueur, vector<Bateau> bateauxOrdi, vector<Tir> tirsJoueur, vector<Tir> tirsOrdi)
{
    setBateauxJoueur(bateauxJoueur);
    setBateauxOrdi(bateauxOrdi);
    setTirsJoueur(tirsJoueur);
    setTirsOrdi(tirsOrdi);

    glClear(GL_COLOR_BUFFER_BIT);

    afficheGrille(true);
    afficheGrille(false);

    afficheBateaux(true);
    //afficheBateaux(false); On affiche pas les bateaux de l'ordi

    afficheTirs(true);
    afficheTirs(false);

    glFlush();
}
