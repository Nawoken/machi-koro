#include <stdio.h>
#include <stdbool.h>
#include "minivilles.h"
#include <time.h>
#include <stdlib.h>

//Définition des constantes de jeu
int deck_j1[19];
int deck_j2[19];
int banque_j1;
int banque_j2;
int price[19] = {1, 1, 1, 2, 2, 3, 8, 6, 7, 5, 3, 6, 3, 3, 2, 16, 22, 4, 10};
int pile[19] = {4, 4, 6, 6, 6, 6, 4, 4, 4, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4};
int minimaxdepth = 6;

int best_move;

int eval(int joueur) {

	int s = 0;

	if (joueur == J1) {

		if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) { //on teste d'abord si le joueur gagne
			s = s + 100000;
			return s;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0)) { //sinon on teste les combinaisons de 3 cartes
			s = s + 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) {
			s = s + 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[GARE] != 0)) {
			s = s + 1000;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0)) {
			s = s + 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0)) { //puis les combinaisons de 2 cartes
			s = s + 100;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[GARE] != 0)) {
			s = s + 100;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) {
			s = s + 100;
		} else if ((deck_j1[GARE] != 0) && (deck_j1[RADIO] != 0)) {
			s = s + 100;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[RADIO] != 0)) {
			s = s + 100;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[GARE] != 0)) {
			s = s + 100;
		} else if (deck_j1[CENTRE_COMMERCIAL] != 0) {//et enfin les cartes seules
			s = s + 30;
		} else if (deck_j1[PARC] != 0) {
			s = s + 30;
		} else if (deck_j1[RADIO] != 0) {
			s = s + 30;
		} else if (deck_j1[GARE] != 0) {
			s = s + 30;
		}
		
		// Heuristique : faire acheter à l'IA le combo ferme + fromagerie
		if ((deck_j1[FROMAGERIE] != 0) && (deck_j1[FERME] != 0)) {
			s = s + 10;
		}
		
		if (deck_j1[FERME] != 0) {
			s = s + deck_j1[FERME];
		}
		
		if (deck_j1[FROMAGERIE] != 0) {
			s = s + 10*deck_j1[FROMAGERIE];
		}
		
		//Heuristique : faire acheter à l'IA forêt + fabriques + mines si jamais le combo précédent n'est pas dispo
		if ((deck_j1[FORET] != 0) && (deck_j1[FABRIQUE] != 0)) {
			s = s + 10;
		}
		
		if ((deck_j1[MINE] != 0) && (deck_j1[FABRIQUE] != 0)) {
			s = s + 10;
		}
		
		if (deck_j1[FORET] != 0) {
			s = s + 3*deck_j1[FORET];
		}
		
		if (deck_j1[FABRIQUE] != 0) {
			s = s + 3*deck_j1[FABRIQUE];
		}
		
		if (deck_j1[MINE] != 0) {
			s = s + 6*deck_j1[MINE];
		}
		
		
		//Heuristique : les champs de blé c'est nul
		if (deck_j1[CHAMPS] > 1) {
			s = s - 30;
		}

		if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) { //on teste ensuite les cartes de l'adversaire
			s = s -100000;
			return s;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0)) { 
			s = s - 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) {
			s = s - 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[GARE] != 0)) {
			s = s - 1000;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0)) {
			s = s - 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0)) {
			s = s - 100;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[GARE] != 0)) {
			s = s - 100;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) {
			s = s - 100;
		} else if ((deck_j2[GARE] != 0) && (deck_j2[RADIO] != 0)) {
			s = s - 100;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[RADIO] != 0)) {
			s = s - 100;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[GARE] != 0)) {
			s = s - 100;
		} else if (deck_j2[CENTRE_COMMERCIAL] != 0) {
			s = s - 30;
		} else if (deck_j2[PARC] != 0) {
			s = s - 30;
		} else if (deck_j2[RADIO] != 0) {
			s = s - 30;
		} else if (deck_j2[GARE] != 0) {
			s = s - 30;
		}
		
		// Heuristique : faire acheter à l'IA le combo ferme + fromagerie
		if ((deck_j2[FROMAGERIE] != 0) && (deck_j2[FERME] != 0)) {
			s = s - 10;
		}
		
		if (deck_j2[FERME] != 0) {
			s = s - deck_j2[FERME];
		}
		
		if (deck_j2[FROMAGERIE] != 0) {
			s = s - 10*deck_j2[FROMAGERIE];
		}
		
		//Heuristique : faire acheter à l'IA forêt + fabriques + mines si jamais le combo précédent n'est pas dispo
		if ((deck_j2[FORET] != 0) && (deck_j2[FABRIQUE] != 0)) {
			s = s - 10;
		}
		
		if ((deck_j2[MINE] != 0) && (deck_j2[FABRIQUE] != 0)) {
			s = s - 10;
		}
		
		if (deck_j2[FORET] != 0) {
			s = s - 3*deck_j2[FORET];
		}
		
		if (deck_j2[FABRIQUE] != 0) {
			s = s - 3*deck_j2[FABRIQUE];
		}
		
		if (deck_j2[MINE] != 0) {
			s = s - 6*deck_j2[MINE];
		}
		
		//Heuristique : les champs de blé c'est nul
		if (deck_j2[CHAMPS] > 1) {
			s = s + 30;
		}

	} else {

		if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) { 
			s = s + 100000;
			return s;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0)) { 
			s = s + 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) {
			s = s + 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[GARE] != 0)) {
			s = s + 1000;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[RADIO] != 0) && (deck_j2[GARE] != 0)) {
			s = s + 1000;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[RADIO] != 0)) { 
			s = s + 100;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[GARE] != 0)) {
			s = s + 100;
		} else if ((deck_j2[PARC] != 0) && (deck_j2[CENTRE_COMMERCIAL] != 0)) {
			s = s + 100;
		} else if ((deck_j2[GARE] != 0) && (deck_j2[RADIO] != 0)) {
			s = s + 100;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[RADIO] != 0)) {
			s = s + 100;
		} else if ((deck_j2[CENTRE_COMMERCIAL] != 0) && (deck_j2[GARE] != 0)) {
			s = s + 100;
		} else if (deck_j2[CENTRE_COMMERCIAL] != 0) {
			s = s + 30;
		} else if (deck_j2[PARC] != 0) {
			s = s + 30;
		} else if (deck_j2[RADIO] != 0) {
			s = s + 30;
		} else if (deck_j2[GARE] != 0) {
			s = s + 30;
		}
		
		// Heuristique : faire acheter à l'IA le combo ferme + fromagerie
		if ((deck_j2[FROMAGERIE] != 0) && (deck_j2[FERME] != 0)) {
			s = s + 10;
		}
		
		if (deck_j2[FERME] != 0) {
			s = s + deck_j2[FERME];
		}
		
		if (deck_j2[FROMAGERIE] != 0) {
			s = s + 10*deck_j2[FROMAGERIE];
		}
		
		//Heuristique : faire acheter à l'IA forêt + fabriques + mines si jamais le combo précédent n'est pas dispo
		if ((deck_j2[FORET] != 0) && (deck_j2[FABRIQUE] != 0)) {
			s = s + 10;
		}
		
		if ((deck_j2[MINE] != 0) && (deck_j2[FABRIQUE] != 0)) {
			s = s + 10;
		}
		
		if (deck_j2[FORET] != 0) {
			s = s + 3*deck_j2[FORET];
		}
		
		if (deck_j2[FABRIQUE] != 0) {
			s = s + 3*deck_j2[FABRIQUE];
		}
		
		if (deck_j2[MINE] != 0) {
			s = s + 6*deck_j2[MINE];
		}
		
		//Heuristique : les champs de blé c'est nul
		if (deck_j2[CHAMPS] > 1) {
			s = s - 30;
		}

		if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) { 
			s = s - 100000;
			return s;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0)) { 
			s = s - 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) {
			s = s - 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[GARE] != 0)) {
			s = s - 1000;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[RADIO] != 0) && (deck_j1[GARE] != 0)) {
			s = s - 1000;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[RADIO] != 0)) { 
			s = s - 100;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[GARE] != 0)) {
			s = s - 100;
		} else if ((deck_j1[PARC] != 0) && (deck_j1[CENTRE_COMMERCIAL] != 0)) {
			s = s - 100;
		} else if ((deck_j1[GARE] != 0) && (deck_j1[RADIO] != 0)) {
			s = s - 100;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[RADIO] != 0)) {
			s = s - 100;
		} else if ((deck_j1[CENTRE_COMMERCIAL] != 0) && (deck_j1[GARE] != 0)) {
			s = s - 100;
		} else if (deck_j1[CENTRE_COMMERCIAL] != 0) {
			s = s - 30;
		} else if (deck_j1[PARC] != 0) {
			s = s - 30;
		} else if (deck_j1[RADIO] != 0) {
			s = s - 30;
		} else if (deck_j1[GARE] != 0) {
			s = s - 30;
		}
		
		// Heuristique : faire acheter à l'IA le combo ferme + fromagerie
		if ((deck_j1[FROMAGERIE] != 0) && (deck_j1[FERME] != 0)) {
			s = s - 10;
		}
		
		if (deck_j1[FERME] != 0) {
			s = s - deck_j1[FERME];
		}
		
		if (deck_j1[FROMAGERIE] != 0) {
			s = s - 10*deck_j1[FROMAGERIE];
		}
		
		//Heuristique : faire acheter à l'IA forêt + fabriques + mines si jamais le combo précédent n'est pas dispo
		if ((deck_j1[FORET] != 0) && (deck_j1[FABRIQUE] != 0)) {
			s = s - 10;
		}
		
		if ((deck_j1[MINE] != 0) && (deck_j1[FABRIQUE] != 0)) {
			s = s - 10;
		}
		
		if (deck_j1[FORET] != 0) {
			s = s - 3*deck_j1[FORET];
		}
		
		if (deck_j1[FABRIQUE] != 0) {
			s = s - 3*deck_j1[FABRIQUE];
		}
		
		if (deck_j1[MINE] != 0) {
			s = s - 6*deck_j1[MINE];
		}
		
		//Heuristique : les champs de blé c'est nul
		if (deck_j2[CHAMPS] > 1) {
			s = s - 30;
		}
	}

	return s;
}

int maximin(int joueur, int depth, int num_niveau, int nb) // niveau minimisant de l'adversaire
{
	int moves[20];
	
	if (depth == 0) {
		return eval(J1);

	} else {
		
		int banque_j1_old = banque_j1;
		int banque_j2_old = banque_j2;

		if (depth != minimaxdepth) {
			int dice = dice_throw(nb);
			apply_effects(dice, joueur);
		}
	
		for (int i=0; i<19; i++) {
			moves[i] = 0;
		}
		
		//L'IA peut toujours choisir de ne rien acheter
		moves[19] = 1;
	
		//On recherche toutes les cartes achetables
		for (int i=0; i<19; i++) {
			if (joueur == J1) {
				if ((banque_j1 >= price[i]) && (pile[i] > 0)) {
					if ((i == CENTRE_AFFAIRES) || (i == STADE) || (i == TV) || (i == PARC) || (i == RADIO) || (i == GARE) || (i == CENTRE_COMMERCIAL)) {
						if (deck_j1[i] < 1) {
							moves[i] = 1;
						}
					} else {
						moves[i] = 1;
					}
				}
			} else {
				if ((banque_j2 >= price[i]) && (pile[i] > 0)) {
					if ((i == CENTRE_AFFAIRES) || (i == STADE) || (i == TV) || (i == PARC) || (i == RADIO) || (i == GARE) || (i == CENTRE_COMMERCIAL)) {
						if (deck_j2[i] < 1) {
							moves[i] = 1;
						}
					} else {
						moves[i] = 1;
					}
				}
			}
		}
		
		//L'IA n'essaye même pas d'acheter des cartes nécessitant 2 dés sans la gare
		for (int i=9; i<=14; i++) {
			if (joueur == J1) {
				if (deck_j1[GARE] == 0) {
					moves[i]= 0;
				}
			} else {
				if (deck_j2[GARE] == 0) {
					moves[i] = 0;
				}
			}
		}
		
		int min = WIN;
	
    	for (int i=0; i<20; i++) {
	
			if (moves[i] != 0) {		            
				bool buy_ok = buy(joueur,i);
    	        int eval = minimax(-joueur, depth - 1, num_niveau + 1, nb);
    	        if (buy_ok) unbuy(joueur, i);
				banque_j1 = banque_j1_old;
				banque_j2 = banque_j2_old;
    	       	if (eval<min) {
					min = eval;
				}
    	    }
    	}

    	return min;
	}
}		

int minimax(int joueur, int depth, int num_niveau, int nb) // niveau maximisant de l'IA
{
	
	int moves[20];
	
	if (depth == 0) {
		return eval(J1);

	} else {
		
		int banque_j1_old = banque_j1;
		int banque_j2_old = banque_j2;

		if (depth != minimaxdepth) {
			int dice = dice_throw(nb);
			apply_effects(dice, joueur);
		}
	
		for (int i=0; i<19; i++) {
			moves[i] = 0;
		}
		
		//L'IA peut toujours choisir de ne rien acheter
		moves[19] = 1;
	
		//On recherche toutes les cartes achetables
		for (int i=0; i<19; i++) {
			if (joueur == J1) {
				if ((banque_j1 >= price[i]) && (pile[i] > 0)) {
					if ((i == CENTRE_AFFAIRES) || (i == STADE) || (i == TV) || (i == PARC) || (i == RADIO) || (i == GARE) || (i == CENTRE_COMMERCIAL)) {
						if (deck_j1[i] < 1) {
							moves[i] = 1;
						}
					} else {
						moves[i] = 1;
					}
				}
			} else {
				if ((banque_j2 >= price[i]) && (pile[i] > 0)) {
					if ((i == CENTRE_AFFAIRES) || (i == STADE) || (i == TV) || (i == PARC) || (i == RADIO) || (i == GARE) || (i == CENTRE_COMMERCIAL)) {
						if (deck_j2[i] < 1) {
							moves[i] = 1;
						}
					} else {
						moves[i] = 1;
					}
				}
			}
		}
		
		//L'IA n'essaye même pas d'acheter des cartes nécessitant 2 dés sans la gare
		for (int i=9; i<=14; i++) {
			if (joueur == J1) {
				if (deck_j1[GARE] == 0) {
					moves[i]= 0;
				}
			} else {
				if (deck_j2[GARE] == 0) {
					moves[i] = 0;
				}
			}
		}
		
		int max = LOSE;
	
    	for (int i=0; i<20; i++) {
	
			if (moves[i] != 0) {       
				bool buy_ok = buy(joueur,i);
    	        int eval = maximin(-joueur, depth - 1, num_niveau + 1, nb);
    	        if (buy_ok) unbuy(joueur, i);
				banque_j1 = banque_j1_old;
				banque_j2 = banque_j2_old;
    	       	if (eval>max) {
					max = eval;
					if (num_niveau==0) best_move = i;
				}
    	    }
    	}

    	return max;
	}
}

int main(void) {

	//Initialisation de rand pour les dés
	
	srand(time(NULL));

	//Initialisation des jeux de départ et des banques

	banque_j1 = 3;
	banque_j2 = 3;	

	deck_j1[CHAMPS] = 1;
	deck_j1[BOULANGERIE] = 1;
	deck_j2[CHAMPS] = 1;
	deck_j2[BOULANGERIE] = 1;

	pile[CHAMPS] = pile[CHAMPS] - 2;
	pile[BOULANGERIE] = pile[BOULANGERIE] - 2;

	for(int i=2; i<19; i++) {
		deck_j1[i] = 0;
		deck_j2[i] = 0;
	}

	/*
	Déroulement d'un tour :
	- Si le joueur a la gare, on lui demande s'il veut lancer un ou deux dés. Sinon il n'en lance qu'un.
	- Si le joueur a la tour radio, il peut choisir des relancer ses dés une fois
	- On applique les effets en fonction du lancer de dé obtenu
	- Le joueur choisit s'il veut acheter et quoi
	- Si le joueur a le parc et a fait un double, il rejoue immédiatement après
	*/

	int mode = 1;
	printf("Quel mode de jeu ? 1: Joueur VS joueur 2: IA VS Joueur 3: IA VS Joueur aléatoire\n");
	scanf("%d",&mode);

	if (mode == 1) {

		while ((is_won(J1) == false) && (is_won(J2) == false)) {
	
			//TOUR DE J1
	
			int compteur = 0;
			bool played_twice = false;
	
			while (played_twice == false) {
	
				bool justbought = false;
				int nb = 1;
				printf("Tour de J1\n\n");
		
				if (deck_j1[GARE] != 0) {
					printf("Combien de dés voulez-vous lancer ? (1 ou 2)\n");
					scanf("%d",&nb);
				}
		
				int dice = dice_throw(nb);
				printf("Résultat du lancer de dé : %d\n\n", dice);
		
				if (deck_j1[RADIO] != 0) {
					char choice[25];
					do {
						printf("Relancer ? (O/N)\n");
						scanf("%s",choice);
						if (choice[0] == 'O') {
							dice = dice_throw(nb);
							printf("Résultat du lancer de dé : %d\n\n", dice);
						}
					}
					while ((choice[0] != 'O') && (choice[0] != 'N'));
				}
		
				apply_effects(dice, J1);
	
				print_game();
		
				int card = 0;
				bool buy_ok = false;
		
				while (buy_ok == false) {
					printf("Que voulez-vous acheter ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 6: Centre d'affaires\n 7: Stade\n 8: Chaîne de télévision\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Parc d'attractions\n 16: Tour radio\n 17: Gare\n 18: Centre commercial\n 19: Rien\n 20: Afficher le détail des cartes\n");
					scanf("%d",&card);
					if (card == 20) {
						details();
					} else {
						buy_ok = buy(J1, card);
					}
				}
		
				if (card == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
		
				if (is_won(J1)) {
					goto end;
				}
				
				if ((deck_j1[PARC] != 0) && (dice%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("Vous avez fait un double, vous allez donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}
	
			}
	
			//TOUR DE J2
	
			compteur = 0;
			played_twice = false;
	
			while (played_twice == false) {
	
				bool justbought = false;
				int nb = 1;
				printf("Tour de J2\n\n");
		
				if (deck_j2[GARE] != 0) {
					printf("Combien de dés voulez-vous lancer ? (1 ou 2)\n");
					scanf("%d",&nb);
				}
		
				int dice = dice_throw(nb);
				printf("Résultat du lancer de dé : %d\n\n", dice);
		
				if (deck_j1[RADIO] != 0) {
					char choice[25];
					do {
						printf("Relancer ? (O/N)\n");
						scanf("%s",choice);
						if (choice[0] == 'O') {
							dice = dice_throw(nb);
							printf("Résultat du lancer de dé : %d\n\n", dice);
						}
					}
					while ((choice[0] != 'O') && (choice[0] != 'N'));
				}
		
				apply_effects(dice, J2);
	
				print_game();
		
				int card = 0;
				bool buy_ok = false;
		
				while (buy_ok == false) {
					printf("Que voulez-vous acheter ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 6: Centre d'affaires\n 7: Stade\n 8: Chaîne de télévision\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Parc d'attractions\n 16: Tour radio\n 17: Gare\n 18: Centre commercial\n 19: Rien\n 20: Afficher le détail des cartes\n");
					scanf("%d",&card);
					if (card == 20) {
						details();
					} else {
						buy_ok = buy(J2, card);
					}
				}
		
				if (card == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
		
				if (is_won(J2)) {
					goto end;
				}
				
				if ((deck_j2[PARC] != 0) && (dice%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("Vous avez fait un double, vous allez donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}
	
			}
	
		}
	
		end:

		if (is_won(J1) == true) {
			printf("La partie est terminée, victoire de J1.\n");
		} else if (is_won(J2) == true) {
			printf("La partie est terminée, victoire de J2.\n");
		}

	} else if (mode == 2) {

		int IA = J1;
		int tour = 0;

		while ((is_won(IA) == false) && (is_won(J2) == false)) {
	
			//TOUR DE L'IA
	
			int compteur = 0;
			bool played_twice = false;
			int tobuy[100];
			int howmany[20];
	
			while (played_twice == false) {
				
				printf("Tour de L'IA\n\n");
				
				bool justbought = false;
				
				for (int i = 0; i<25; i++) {
					tobuy[i] = 0;
				}
				
				best_move = 19;
				int dice1 = dice_throw(1);
				
				if (deck_j1[GARE] != 0) {
					if ((deck_j1[FROMAGERIE] != 0) || (deck_j1[FABRIQUE] != 0) || (deck_j1[MINE] != 0) || (deck_j1[RESTAURANT] != 0) || (deck_j1[VERGER] != 0) || (deck_j1[MARCHE] != 0)) {
						dice1 = dice_throw(2);
					} else {
						dice1 = dice_throw(1);
					}
				} else {
					dice1 = dice_throw(1);
				}
				
				printf("Résultat du lancer de dé de l'IA: %d\n\n", dice1);
				apply_effects(dice1, IA);
				print_game();
				
				//Méthode de Monte-Carlo sur 25 répétitions de l'algorithme Minimax
				
				for (int i = 0; i<25; i++) {
					
					if (deck_j1[GARE] != 0) {
						if ((deck_j1[FROMAGERIE] != 0) || (deck_j1[FABRIQUE] != 0) || (deck_j1[MINE] != 0) || (deck_j1[RESTAURANT] != 0) || (deck_j1[VERGER] != 0) || (deck_j1[MARCHE] != 0)) {
							minimax(IA, minimaxdepth, 0, 2);
						} else {
							minimax(IA, minimaxdepth, 0, 1);
						}
					} else {
						minimax(IA, minimaxdepth, 0, 1);
					}
					
					tobuy[i] = best_move;
					//printf("L'IA devrait acheter %d\n", best_move);
				}
				
				for (int i = 0; i<20; i++) {
					howmany[i] = 0;
				}
				
				
				for (int carte = 0; carte<20; carte++) {	
					for (int i = 0; i<25; i++) {
						if (tobuy[i] == carte) {
							howmany[carte] = howmany[carte] + 1;
						}
					}
				}
				
				int max = 0;
				int ind = 0;
			
				for (int carte = 0; carte<20; carte++) {
					if (howmany[carte] > max) {
						max = howmany[carte];
						ind = carte;
					}
				}
				
				//Ouverture : on achète toujours les fermes en premier
				if ((pile[FERME] > 0) && (banque_j1 > price[FERME])) {
					ind = FERME;
				}
				
				//Fermeture : si on peut acheter les monuments, on les achète
				if ((pile[CENTRE_COMMERCIAL] > 0) && (banque_j1 > price[CENTRE_COMMERCIAL]) && (deck_j1[CENTRE_COMMERCIAL] == 0)) {
					ind = CENTRE_COMMERCIAL;
				}
				
				if ((pile[PARC] > 0) && (banque_j1 > price[PARC]) && (deck_j1[PARC] == 0)) {
					ind = PARC;
				}
				
				if ((pile[RADIO] > 0) && (banque_j1 > price[RADIO]) && (deck_j1[RADIO] == 0)) {
					ind = RADIO;
				}
				
				if (ind != 19) {
					printf("L'IA achète %d\n\n", ind);
					buy(IA, ind);
				} else {
					printf("L'IA ne va rien acheter\n");
				}
		
				if (ind == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
		
				if (is_won(IA)) {
					goto end2;
				}
				
				if ((deck_j1[PARC] != 0) && (dice1%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("L'IA a fait un double, elle va donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}
				
				tour = tour + 1;
	
			}
	
			//TOUR DE J2
	
			compteur = 0;
			played_twice = false;
	
			while (played_twice == false) {
				
				bool justbought = false;
				int nb = 1;
				printf("Tour de J2\n\n");
		
				if (deck_j2[GARE] != 0) {
					printf("Combien de dés voulez-vous lancer ? (1 ou 2)\n");
					scanf("%d",&nb);
				}
		
				int dice2 = dice_throw(nb);
				printf("Résultat du lancer de dé : %d\n\n", dice2);
		
				if (deck_j1[RADIO] != 0) {
					char choice[25];
					do {
						printf("Relancer ? (O/N)\n");
						scanf("%s",choice);
						if (choice[0] == 'O') {
							dice2 = dice_throw(nb);
							printf("Résultat du lancer de dé : %d\n\n", dice2);
						}
					}
					while ((choice[0] != 'O') && (choice[0] != 'N'));
				}
		
				apply_effects(dice2, J2);
	
				print_game();
		
				int card = 0;
				bool buy_ok = false;
		
				while (buy_ok == false) {
					printf("Que voulez-vous acheter ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 6: Centre d'affaires\n 7: Stade\n 8: Chaîne de télévision\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Parc d'attractions\n 16: Tour radio\n 17: Gare\n 18: Centre commercial\n 19: Rien\n 20: Afficher le détail des cartes\n");
					scanf("%d",&card);
					if (card == 20) {
						details();
					} else {
						buy_ok = buy(J2, card);
					}
				}
		
				if (card == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
		
				if (is_won(J2)) {
					goto end2;
				}
				
				if ((deck_j2[PARC] != 0) && (dice2%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("Vous avez fait un double, vous allez donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}
	
			}
	
		}
	
		end2:

		if (is_won(J1) == true) {
			printf("La partie est terminée, victoire de J1.\n");
		} else if (is_won(J2) == true) {
			printf("La partie est terminée, victoire de J2.\n");
		}
		
	} else if (mode == 3) {
		
		int IA = J1;
		int tour = 0;

		while ((is_won(IA) == false) && (is_won(J2) == false)) {
	
			//TOUR DE L'IA
	
			int compteur = 0;
			bool played_twice = false;
			int tobuy[100];
			int howmany[20];
	
			while (played_twice == false) {
				
				printf("Tour de L'IA\n\n");
				
				bool justbought = false;
				
				for (int i = 0; i<25; i++) {
					tobuy[i] = 0;
				}
				
				best_move = 19;
				int dice1 = dice_throw(1);
				
				if (deck_j1[GARE] != 0) {
					if ((deck_j1[FROMAGERIE] != 0) || (deck_j1[FABRIQUE] != 0) || (deck_j1[MINE] != 0) || (deck_j1[RESTAURANT] != 0) || (deck_j1[VERGER] != 0) || (deck_j1[MARCHE] != 0)) {
						dice1 = dice_throw(2);
					} else {
						dice1 = dice_throw(1);
					}
				} else {
					dice1 = dice_throw(1);
				}
				
				printf("Résultat du lancer de dé de l'IA : %d\n\n", dice1);
				apply_effects(dice1, IA);
				print_game();
				
				//Méthode de Monte-Carlo sur 25 répétitions de l'algorithme Minimax
				
				for (int i = 0; i<25; i++) {
					
					if (deck_j1[GARE] != 0) {
						if ((deck_j1[FROMAGERIE] != 0) || (deck_j1[FABRIQUE] != 0) || (deck_j1[MINE] != 0) || (deck_j1[RESTAURANT] != 0) || (deck_j1[VERGER] != 0) || (deck_j1[MARCHE] != 0)) {
							minimax(IA, minimaxdepth, 0, 2);
						} else {
							minimax(IA, minimaxdepth, 0, 1);
						}
					} else {
						minimax(IA, minimaxdepth, 0, 1);
					}
					
					tobuy[i] = best_move;
					//printf("L'IA devrait acheter %d\n", best_move);
				}
				
				for (int i = 0; i<20; i++) {
					howmany[i] = 0;
				}
				
				for (int carte = 0; carte<20; carte++) {	
					for (int i = 0; i<25; i++) {
						if (tobuy[i] == carte) {
							howmany[carte] = howmany[carte] + 1;
						}
					}
				}
				
				int max = 0;
				int ind = 0;
			
				for (int carte = 0; carte<20; carte++) {
					if (howmany[carte] > max) {
						max = howmany[carte];
						ind = carte;
					}
				}
				
				//Ouverture : on achète toujours les fermes en premier
				if ((pile[FERME] > 0) && (banque_j1 > price[FERME])) {
					ind = FERME;
				}
				
				//Fermeture : si on peut acheter les monuments, on les achète
				if ((pile[CENTRE_COMMERCIAL] > 0) && (banque_j1 > price[CENTRE_COMMERCIAL]) && (deck_j1[CENTRE_COMMERCIAL] == 0)) {
					ind = CENTRE_COMMERCIAL;
				}
				
				if ((pile[PARC] > 0) && (banque_j1 > price[PARC]) && (deck_j1[PARC] == 0)) {
					ind = PARC;
				}
				
				if ((pile[RADIO] > 0) && (banque_j1 > price[RADIO]) && (deck_j1[RADIO] == 0)) {
					ind = RADIO;
				}
				
				if (ind != 19) {
					printf("L'IA achète %d\n\n", ind);
					buy(IA, ind);
				} else {
					printf("L'IA ne va rien acheter\n");
				}
				
				if (ind == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
		
				if (is_won(IA)) {
					goto end3;
				}
				
				if ((deck_j1[PARC] != 0) && (dice1%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("L'IA a fait un double, elle va donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}
				
				tour = tour + 1;
	
			}
	
			//TOUR DE L'IA ALEATOIRE
	
			compteur = 0;
			played_twice = false;
	
			while (played_twice == false) {
				
				printf("Tour de L'IA aléatoire\n\n");
				
				bool justbought = false;
				
				int play[20];
				
				for (int i=0; i<19; i++) {
					play[i] = 0;
				}
				
				play[19] = 1;
				
				int dice2 = dice_throw(1);
				
				if (deck_j1[GARE] != 0) {
					dice2 = dice_throw(2);
				}
				
				printf("Résultat du lancer de dé de l'IA aléatoire : %d\n\n", dice2);
				apply_effects(dice2, J2);
				print_game();
				
				for (int i=0; i<19; i++) {
					if ((banque_j2 >= price[i]) && (pile[i] > 0)) {
						if ((i == CENTRE_AFFAIRES) || (i == STADE) || (i == TV) || (i == PARC) || (i == RADIO) || (i == GARE) || (i == CENTRE_COMMERCIAL)) {
							if (deck_j2[i] < 1) {
								play[i] = 1;
							}
						} else {
							play[i] = 1;
						}
					}
				}
				
				bool buyable = false;
				int to_buy;
				
				while (buyable == false) {
					to_buy = (rand() % 20);
					if (play[to_buy] != 0) {
						buy(J2, to_buy);
						buyable = true;
					}
				}
				
				printf("L'IA aléatoire achète %d\n\n", to_buy);
				
				if (to_buy == PARC) {
					justbought = true;
				} else {
					justbought = false;
				}
					
				if (is_won(J2)) {
					goto end3;
				}
				
				if ((deck_j1[PARC] != 0) && (dice2%2 == 0) && (justbought == false)) {
					if (compteur == 0) {
						compteur = compteur + 1;
						printf("L'IA aléatoire a fait un double, elle va donc rejouer un tour\n\n");
					} else {
						played_twice = true;
					}
				} else {
					played_twice = true;
				}	
			}	
		}
	
		end3:

		if (is_won(IA) == true) {
			printf("La partie est terminée, victoire de l'IA.\n");
		} else if (is_won(J2) == true) {
			printf("La partie est terminée, victoire de l'IA aléatoire.\n");
		}
	}

	return 0;
}
