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

void Afficheur::afficheTirRate(bool grilleActive, int noColonne, int noLigne)
{
    colorierCase(grilleActive, noLigne ,noColonne, 0.0f, 0.0f, 1.0f); // bleu
}

void Afficheur::afficheTirTouche(bool grilleActive, int noLigne, int noColonne)
{
    colorierCase(grilleActive, noLigne, noColonne, 1.0f, 0.0f, 0.0f); // rouge
}

void Afficheur::afficheTirCoule(bool grilleActive, int noColonne, int noLigne)
{
    colorierCase(grilleActive, noLigne, noColonne, 0.364f, 0.023f, 0.501f); // violet
}

void Afficheur::dataFiller()
{
    Bateau bateau1 = { PORTE_AVION,{0,0},true };
    Bateau bateau2 = { CROISEUR,{0,1},true };
    Bateau bateau3 = { CONTRE_TORPILLEUR,{0,2},true };
    Bateau bateau4 = { SOUS_MARIN,{0,3},true };
    Bateau bateau5 = { TORPILLEUR,{0,4},true };
    bateauxJoueur.push_back(bateau1);
    bateauxJoueur.push_back(bateau2);
    bateauxJoueur.push_back(bateau3);
    bateauxJoueur.push_back(bateau4);
    bateauxJoueur.push_back(bateau5);
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

void Afficheur::affichage()
{
    glClear(GL_COLOR_BUFFER_BIT);

    afficheGrille(true);
    afficheGrille(false);

    // Tests d'affichage à retirer
    afficheTirTouche(true, 2, 1);
    afficheTirCoule(true, 4, 1);
    afficheTirRate(true, 6, 1);

    glFlush();
}
