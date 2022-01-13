#include <iostream>
#include "Afficheur.h"

#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif

Afficheur afficheur;

GLvoid affichage() {
    afficheur.affichage();
}

GLvoid clavier(unsigned char touche, int x, int y) {
    switch (touche) {
    case 'p':
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //Plein
        break;
    case 'f':
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Fil de fer
        break;
    case 's':
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); //Sommets
        break;
    case 'q':
    case 27 :
        exit(0);
        break;
    }

    glutPostRedisplay(); //Reaffiche la scene
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //Init de glut
    glutInitDisplayMode(GLUT_RGB); //Choix du mode d'affichage
    glutInitWindowPosition(200, 200); //Position initaile de la fenêtre
    glutInitWindowSize(700, 700); //Taille initiale de la fenêtre
    glutCreateWindow("Bataille Navale"); //Creation de la fenêtre GLUT

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //Couleur effacement buffer
    
    //Fonction de callbacks
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);

    glutMainLoop();
}