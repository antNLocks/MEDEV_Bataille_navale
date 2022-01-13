#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif

#include "Afficheur.h"

void Afficheur::afficheGrille(float x_bas_gauche, float y_bas_gauche, float x_haut_droite, float y_haut_droite)
{
    int nbrCase = 10;
    float largeur = (x_haut_droite - x_bas_gauche) / nbrCase;
    float hauteur = (y_haut_droite - y_bas_gauche) / nbrCase;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            glBegin(GL_QUADS);
            // Alternance de la couleur des cases
            if ((i + j) % 2 == 0) {glColor3f(0.211, 0.580, 0.921);}
            else {glColor3f(0.211, 0.682, 0.921);}
            glVertex2f(x_bas_gauche + i*largeur, y_bas_gauche + j*hauteur);
            glVertex2f(x_bas_gauche + (i+1) * largeur, y_bas_gauche + j * hauteur);
            glVertex2f(x_bas_gauche + (i+1) * largeur, y_bas_gauche + (j+1) * hauteur);
            glVertex2f(x_bas_gauche + i * largeur, y_bas_gauche + (j+1) * hauteur);
            glEnd();
        }
    }
}

Afficheur::Afficheur()
{
}

void Afficheur::affichage()
{
    glClear(GL_COLOR_BUFFER_BIT);

    afficheGrille(-1.0f,-1.0f,1.0f,1.0f);

    glFlush();
}
