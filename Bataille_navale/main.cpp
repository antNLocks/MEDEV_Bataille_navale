// OpenGLHelloWorld.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
//#include <Windows.h>
#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

GLvoid affichage() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.5f);

    glEnd();

    

    glEnd();

    glFlush();
}

GLvoid damier()
{
    return GLvoid();
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
    glutCreateWindow("OpenGL Hello World"); //Creation de la fenêtre GLUT

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Couleur effacement buffer
    
    //Fonction de callbacks
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);

    glutMainLoop();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
