#include "structure.h"

//CONSTRUCTEURS



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

bool Plateau::testcoulejoueur(Bateau b) {
	
	
	switch (b.Type) { 
		
		case TORPILLEUR: //2 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 1) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==2) {return true;}
			break;
		
		case SOUS_MARIN : //3 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 1) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 2) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==3) {return true;}
			break;
			
		case CONTRE_TORPILLEUR : //3 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 1) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 2) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==3) {return true;}
			break;
			
			case CROISEUR : //4 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 1) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 2) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 3) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==4) {return true;}
			break;
			
			case PORTE_AVION : //5 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0]) && (tirsOrdi[i].Position[1] == b.Position[1] + 4)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 1) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 2) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 3) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsOrdi.size();i++) {
				if ((tirsOrdi[i].Position[0] == b.Position[0] + 4) && (tirsOrdi[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==5) {return true;}
			break;
	}
		
	return false;
}

bool Plateau::testcouleordi(Bateau b) {
	
	switch (b.Type) { 
		
		case TORPILLEUR: //2 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 1) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==2) {return true;}
			break;
		
		case SOUS_MARIN : //3 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 1) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 2) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==3) {return true;}
			break;
			
		case CONTRE_TORPILLEUR : //3 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 1) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 2) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==3) {return true;}
			break;
			
			case CROISEUR : //4 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 1) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 2) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 3) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==4) {return true;}
			break;
			
			case PORTE_AVION : //5 de longueur
			
			int a = 0;
			
			for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
				}
			}
			
			//Si le bateau part vers le bas
			if (b.Direction) {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 1)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 2)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 3)) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0]) && (tirsJoueur[i].Position[1] == b.Position[1] + 4)) {
					a++;
					}
				}
			}
			
			//Si le bateau part vers la droite
			else {
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 1) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 2) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 3) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
				for (i=0;i<tirsJoueur.size();i++) {
				if ((tirsJoueur[i].Position[0] == b.Position[0] + 4) && (tirsJoueur[i].Position[1] == b.Position[1])) {
					a++;
					}
				}
			}
			
			if (a==5) {return true;}
			break;
	}
		
	return false;
}
		
void Plateau::testVictoire() {
	if (bateauxJoueur.size() == 0) { State = VICTOIRE_ORDI; }
	if (bateauxOrdi.size() == 0) { State = VICTOIRE_JOUEUR;}
}

void Plateau::changerBateau(Bateau b) {}




