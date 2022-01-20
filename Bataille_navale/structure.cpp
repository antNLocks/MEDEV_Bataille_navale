#include "structure.h"

//GETTEURS

Etat Plateau::getState() const {
	return State;
}

vector<Bateau> Plateau::getBateauxJoueur() const {
	return bateauxJoueur;
}

vector<Bateau> Plateau::getBateauxOrdi() const {
	return bateauxOrdi;
}

vector<Tir> Plateau::getTirsJoueur() const {
	return tirsJoueur;
}

vector<Tir> Plateau::getTirsOrdi() const {
	return tirsOrdi;
}

//FONCTIONS

void Plateau::majBateaux() {

	int i;

	//Bateaux du joueur
	for (i=0;i<bateauxJoueur.size();i++) {
		if (testcoulejoueur(bateauxJoueur[i])) {
			bateauxJoueur.erase(bateauxJoueur.begin() + i);
			i--;
		}
	}

	//Bateaux de l ordi
	for (i=0;i<bateauxOrdi.size();i++) {
		if (testcouleordi(bateauxOrdi[i])) {
			bateauxOrdi.erase(bateauxOrdi.begin() + i);
			i--;
		}
	}
}

bool Plateau::testcoule(Bateau b, vector<Tir> tirs){
	int a;
	int i;

	switch (b.Type) {

		case TORPILLEUR: //2 de longueur

			a = 0;

			for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
				}
			}

			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
			}

			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 1) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}

			if (a==2) {return true;}
			break;

		case SOUS_MARIN : //3 de longueur

			a = 0;

			for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
				}
			}

			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}

			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 1) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 2) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}

			if (a==3) {return true;}
			break;

		case CONTRE_TORPILLEUR : //3 de longueur

			a = 0;

			for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
				}
			}

			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}

			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 1) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 2) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}

			if (a==3) {return true;}
			break;

			case CROISEUR : //4 de longueur

			a = 0;

			for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
				}
			}

			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
			}

			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 1) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 2) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 3) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}

			if (a==4) {return true;}
			break;

			case PORTE_AVION : //5 de longueur

			a = 0;

			for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
				}
			}

			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0]) && (tirs[i].Position[1] == b.Position[1] + 4)) {
					a++;
					}
				}
			}

			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 1) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 2) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 3) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirs.size();i++) {
				if ((tirs[i].Position[0] == b.Position[0] + 4) && (tirs[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}

			if (a==5) {return true;}
			break;
	}

	return false;
}

bool Plateau::testcoulejoueur(Bateau b) {
	return testcoule(b, tirsOrdi);
}

bool Plateau::testcouleordi(Bateau b) {
	return testcoule(b, tirsJoueur);
}

void Plateau::testVictoire() {
	if (bateauxJoueur.size() == 0) { State = VICTOIRE_ORDI; }
	if (bateauxOrdi.size() == 0) { State = VICTOIRE_JOUEUR;}
}

void Plateau::changerBateau(Bateau b) {
	b.Type = static_cast<TypeBateau>((static_cast<int>(b.Type) + 1) % NB_TYPES_BATEAU);
}

bool Plateau::testtouche(Tir t, vector<Bateau> bateaux){
	//Verification si touche ou coule
	int a = 0;

	for (int i=0;i<bateaux.size();i++) { //On verifie si on a touche un des bateaux
		switch (bateaux[i].Type) { //On fonctionne selon le type de bateau

			case TORPILLEUR : //2 de longueur
				if (bateaux[i].Direction) { //Le bateau va vers le bas
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 1 == t.Position[1])) {
						a=1;
					}
				}
				else { //Le bateau va vers la droite
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 1 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
				}
				break;

			case SOUS_MARIN : //3 de longueur
				if (bateaux[i].Direction) { //Le bateau va vers le bas
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 1 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 2 == t.Position[1])) {
						a=1;
					}

				}
				else { //Le bateau va vers la droite
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 1 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 2 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
				}
				break;

			case CONTRE_TORPILLEUR: //3 de longueur
				if (bateaux[i].Direction) { //Le bateau va vers le bas
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 1 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 2 == t.Position[1])) {
						a=1;
					}

				}
				else { //Le bateau va vers la droite
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 1 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 2 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
				}
				break;

			case CROISEUR : //4 de longueur
				if (bateaux[i].Direction) { //Le bateau va vers le bas
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 1 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 2 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 3 == t.Position[1])) {
						a=1;
					}

				}
				else { //Le bateau va vers la droite
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 1 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 2 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 3 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
				}
				break;

			case PORTE_AVION : //5 de longueur
				if (bateaux[i].Direction) { //Le bateau va vers le bas
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 1 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 2 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 3 == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] + 4 == t.Position[1])) {
						a=1;
					}

				}
				else { //Le bateau va vers la droite
					if ((bateaux[i].Position[0] == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 1 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 2 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 3 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
					if ((bateaux[i].Position[0] + 4 == t.Position[0]) && (bateaux[i].Position[1] == t.Position[1])) {
						a=1;
					}
				}
				break;
			}
		}

		return a == 1;
}

void Plateau::maketirjoueur(int ligne,int colonne) {

	Tir t;
	t.Position[0] = ligne;
	t.Position[1] = colonne;


	//Si on touche, on a resultat = 1
	t.Resultat = testtouche(t, bateauxOrdi);

	//On ajoute ce tir au vecteur
	tirsJoueur.push_back(t);
}

void Plateau::maketirordi() {
	//Pour l instant, l ordi est idiot

	Tir t;
	int b = 0;

	//Initialisation bidon necessaire
	t.Position[0] = 30;
	t.Position[1] = 30;

	//Initialisation de la position
	int ligne = rand() % 10; //int entre 0 et 9
	int colonne = rand() % 10;

	while ((t.Position[0] == 30) || (t.Position[1] == 30)) { //Verification pour ne pas tirer deux fois au meme endroit

		for (int i=0; i<tirsOrdi.size();i++) { //On regarde si on n'a pas deja un tir a cet endroit
			if ((tirsOrdi[i].Position[0] == ligne) && (tirsOrdi[i].Position[1] == colonne)) {
				b = 1;
			}
		}
		if (b==0) { //Si c'est bon, on tire ici
			t.Position[0] = ligne;
			t.Position[1] = colonne;
		}
		else { //Sinon on recommence
			ligne = rand() % 10;
			colonne = rand() % 10;
		}
		b=0;
	}


	//Si on touche, on a resultat = 1
	t.Resultat = testtouche(t, bateauxJoueur);


		//On ajoute le tir au vecteur
		tirsOrdi.push_back(t);
}

bool Plateau::testcollisionbateaux(Bateau b1, Bateau b2){
	vector<int> lignesB1;
	vector<int> lignesB2;

	vector<int> colonnesB1;
  vector<int> colonnesB2;

	if(b1.Direction){ //b1 vertical
		for(int i = 0; i < tailleBateauMap[b1.Type]; i++){
			colonnesB1.push_back(b1.Position[1]);
			lignesB1.push_back(b1.Position[0] + i);
		}
	}else { //b1 horizontal
		for(int i = 0; i < tailleBateauMap[b1.Type]; i++){
			lignesB1.push_back(b1.Position[0]);
			colonnesB1.push_back(b1.Position[1] + i);
		}
	}

	if(b2.Direction){ //b2 vertical
		for(int i = 0; i < tailleBateauMap[b2.Type]; i++){
			colonnesB2.push_back(b2.Position[1]);
			lignesB2.push_back(b2.Position[0] + i);
		}
	}else { //b2 horizontal
		for(int i = 0; i < tailleBateauMap[b2.Type]; i++){
			lignesB2.push_back(b2.Position[0]);
			colonnesB2.push_back(b2.Position[1 ]+ i);
		}
	}

	for(int i1 = 0; i1 < lignesB1.size(); i1++){
		for(int i2 = 0; i2 < lignesB2.size(); i2++){
					if(lignesB1[i1] == lignesB2[i2] && colonnesB1[i1] == colonnesB2[i2])
						return true;

			}
	}
	return false;
}

vector<Bateau> Plateau::initialiseBateauxJ() {

	int ligne,colonne;

	//AJOUT PORTE AVION
	Bateau b1;
	b1.Type = PORTE_AVION;

	//Direction
	int D1 = rand() % 2; //int entre 0 et 1
	bool D11 = (bool)D1;
	b1.Direction = D11;

	//Position
	if (b1.Direction) {
		colonne = rand() % 10; //int entre 1 et 9
		ligne = rand() % 6; //int entre 1 et 6 (pour ne pas depasser de la grille
	}
	else {
		ligne = rand() % 10;
		colonne = rand() % 6;
	}

	//On ajoute dans le vecteur
	bateauxJoueur.push_back(b1);

	//AJOUT	CROISEUR
	Bateau b2;
	b2.Type = CROISEUR;

	//Direction
	int D2 = rand() % 2; //int entre 0 et 1
	bool D22 = (bool)D2;
	b2.Direction = D22;

	//Position
	if (b2.Direction) {

	}
	else {

	}



}
