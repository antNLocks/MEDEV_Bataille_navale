#include <iostream>
#include "Afficheur.h"
#include "structure.h"
#include <string>

#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif

Afficheur afficheur;

GLvoid affichage() {
	Plateau P = Plateau();
	P.initialiseBateauxJ();
	P.initialiseBateauxO();
	while ((P.getState() != VICTOIRE_JOUEUR) || (P.getState() != VICTOIRE_ORDI)) {
		P.setState(TOUR_JOUEUR);
		cout << "Quelle est la ligne que vous voulez toucher ?" << endl ;
		int ligne,colonne;
		cin >> ligne ;
		cout << "Quelle est la colonne que vous voulez toucher ?" << endl ;
		cin >> colonne;
		P.maketirjoueur(ligne,colonne);
		P.majBateaux();
		afficheur.affichage(P.getBateauxJoueur(),P.getBateauxOrdi(),P.getTirsJoueur(),P.getTirsOrdi());
		P.setState(TOUR_ORDI);
		P.maketirordi();
		P.majBateaux();
		afficheur.affichage(P.getBateauxJoueur(),P.getBateauxOrdi(),P.getTirsJoueur(),P.getTirsOrdi());
		P.testVictoire();
	}
	
	string V;
	if (P.getState() == VICTOIRE_JOUEUR) {
		V = "le joueur.";
	}
	else {
		V = "l'ordinateur.";
	}
	cout << "Le vainqueur est: " << V << endl;
    
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

void MakeGame() {
	
	
	
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); //Init de glut
    glutInitDisplayMode(GLUT_RGB); //Choix du mode d'affichage
    glutInitWindowPosition(200, 200); //Position initaile de la fenêtre
    glutInitWindowSize(1100, 600); //Taille initiale de la fenêtre
    glutCreateWindow("Bataille Navale"); //Creation de la fenêtre GLUT

    glClearColor(0.960f, 0.964f, 0.756f, 0.0f); //Couleur effacement buffer beige
    //Fonction de callbacks
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);


    glutMainLoop();
}



