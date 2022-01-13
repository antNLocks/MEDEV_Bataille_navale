#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif

#include "Afficheur.h"

void Afficheur::afficheGrille(float x_bas_gauche, float y_bas_gauche, float x_haut_droite, float y_haut_droite)
{
    float largeur = (x_haut_droite - x_bas_gauche) / nbrCase;
    float hauteur = (y_haut_droite - y_bas_gauche) / nbrCase;
    for (int i = 0; i < nbrCase; i++) {
        for (int j = 0; j < nbrCase; j++) {
            glBegin(GL_QUADS);
            // Alternance de la couleur des cases
            if ((i + j) % 2 == 0) {glColor3f(0.211f, 0.580f, 0.921f);}
            else {glColor3f(0.211f, 0.682f, 0.921f);}
            glVertex2f(x_bas_gauche + i*largeur, y_bas_gauche + j*hauteur);
            glVertex2f(x_bas_gauche + (i+1) * largeur, y_bas_gauche + j * hauteur);
            glVertex2f(x_bas_gauche + (i+1) * largeur, y_bas_gauche + (j+1) * hauteur);
            glVertex2f(x_bas_gauche + i * largeur, y_bas_gauche + (j+1) * hauteur);
            glEnd();
        }
    }
}

void Afficheur::afficheTouche(bool grilleActive, int noLigne, int noColonne)
{
    noLigne = 9 - noLigne;

    float coorGrille[4];
    if (grilleActive) { // C'est la grille du joueur qui est affich�e � gauche
        for (int index = 0; index < 4; index++) {
            coorGrille[index] = coorGrilleJoueur[index];
        }
    }
    else { // C'est la grille de l'ordi qui est affich�e � droite
        for (int index = 0; index < 4; index++) {
            coorGrille[index] = coorGrilleOrdi[index];
        }
    }

    float largeur = (coorGrille[2] - coorGrille[0]) / nbrCase;
    float hauteur = (coorGrille[3] - coorGrille[1]) / nbrCase;
    glBegin(GL_QUADS);
    // Alternance de la couleur des cases
    glColor3f(1.0f, 0.0f, 0.0f); // rouge
    glVertex2f(coorGrille[0] + noColonne*largeur, coorGrille[1] + noLigne*hauteur);
    glVertex2f(coorGrille[0] + (noColonne + 1)*largeur, coorGrille[1] + noLigne*hauteur);
    glVertex2f(coorGrille[0] + (noColonne + 1)*largeur, coorGrille[1] + (noLigne + 1)*hauteur);
    glVertex2f(coorGrille[0] + noColonne*largeur, coorGrille[1] + (noLigne + 1)*hauteur);
    glEnd();
}

Afficheur::Afficheur()
{
    nbrCase = 10;
    coorGrilleJoueur[0] = 2 * (1.0f / 11) - 1; // Abcisse des coordonn�es �cran du point en bas � gauche de la grille du joueur
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

    afficheGrille(coorGrilleJoueur[0], coorGrilleJoueur[1], coorGrilleJoueur[2], coorGrilleJoueur[3]);
    afficheGrille(coorGrilleOrdi[0], coorGrilleOrdi[1], coorGrilleOrdi[2], coorGrilleOrdi[3]);
    afficheTouche(true, 2, 1);

    glFlush();
}
