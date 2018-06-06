#include "minivilles.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void print_game() {
	
	printf("Cartes de J1 :\n");
	for(int i=0; i<19; i++) {
		if (deck_j1[i] != 0) {
			if (i == 0) {
				printf("Champs de blé : %d\n", deck_j1[i]);
			} else if (i == 1) {
				printf("Boulangerie : %d\n", deck_j1[i]);
			} else if (i == 2) {
				printf("Ferme : %d\n", deck_j1[i]);
			} else if (i == 3) {
				printf("Café : %d\n", deck_j1[i]);
			} else if (i == 4) {
				printf("Supérette : %d\n", deck_j1[i]);
			} else if (i == 5) {
				printf("Forêt : %d\n", deck_j1[i]);
			} else if (i == 6) {
				printf("Centre d'affaires : %d\n", deck_j1[i]);
			} else if (i == 7) {
				printf("Stade : %d\n", deck_j1[i]);
			} else if (i == 8) {
				printf("Chaîne de télévision : %d\n", deck_j1[i]);
			} else if (i == 9) {
				printf("Fromagerie : %d\n", deck_j1[i]);
			} else if (i == 10) {
				printf("Fabique de meubles : %d\n", deck_j1[i]);
			} else if (i == 11) {
				printf("Mine : %d\n", deck_j1[i]);
			} else if (i == 12) {
				printf("Restaurant : %d\n", deck_j1[i]);
			} else if (i == 13) {
				printf("Verger : %d\n", deck_j1[i]);
			} else if (i == 14) {
				printf("Marché de fruits et légumes : %d\n", deck_j1[i]);
			} else if (i == 15) {
				printf("Parc d'attractions : %d\n", deck_j1[i]);
			} else if (i == 16) {
				printf("Tour radio : %d\n", deck_j1[i]);
			} else if (i == 17) {
				printf("Gare : %d\n", deck_j1[i]);
			} else {
				printf("Centre commercial : %d\n", deck_j1[i]);
			}
		}
	}

	printf("Nombre de pièces de J1 : %d\n\n", banque_j1);

	printf("Cartes de J2 :\n");
	for(int i=0; i<19; i++) {
		if (deck_j2[i] != 0) {
			if (i == 0) {
				printf("Champs de blé : %d\n", deck_j2[i]);
			} else if (i == 1) {
				printf("Boulangerie : %d\n", deck_j2[i]);
			} else if (i == 2) {
				printf("Ferme : %d\n", deck_j2[i]);
			} else if (i == 3) {
				printf("Café : %d\n", deck_j2[i]);
			} else if (i == 4) {
				printf("Supérette : %d\n", deck_j2[i]);
			} else if (i == 5) {
				printf("Forêt : %d\n", deck_j2[i]);
			} else if (i == 6) {
				printf("Centre d'affaires : %d\n", deck_j2[i]);
			} else if (i == 7) {
				printf("Stade : %d\n", deck_j2[i]);
			} else if (i == 8) {
				printf("Chaîne de télévision : %d\n", deck_j2[i]);
			} else if (i == 9) {
				printf("Fromagerie : %d\n", deck_j2[i]);
			} else if (i == 10) {
				printf("Fabique de meubles : %d\n", deck_j2[i]);
			} else if (i == 11) {
				printf("Mine : %d\n", deck_j2[i]);
			} else if (i == 12) {
				printf("Restaurant : %d\n", deck_j2[i]);
			} else if (i == 13) {
				printf("Verger : %d\n", deck_j2[i]);
			} else if (i == 14) {
				printf("Marché de fruits et légumes : %d\n", deck_j2[i]);
			} else if (i == 15) {
				printf("Parc d'attractions : %d\n", deck_j2[i]);
			} else if (i == 16) {
				printf("Tour radio : %d\n", deck_j2[i]);
			} else if (i == 17) {
				printf("Gare : %d\n", deck_j2[i]);
			} else {
				printf("Centre commercial : %d\n", deck_j2[i]);
			}
		}
	}

	printf("Nombre de pièces de J2 : %d\n\n", banque_j2);

}

void details() {
	
	printf("Carte");
	printf(BLUE " bleue " RESET);
	printf(": pendant le tour de n'importe quel joueur\n");
	printf("Carte");
	printf(GREEN " verte " RESET);
	printf(": pendant votre tour uniquement \n");
	printf("Carte");
	printf(RED " rouge " RESET);
	printf(": vole les pièces au joueur qui a lancé les dés \n");
	printf("Carte");
	printf(PURPLE " violette " RESET);
	printf(": effet spécial, vole les pièces au joueur qui a lancé les dés \n");
	printf("Carte");
	printf(YELLOW " jaune " RESET);
	printf(": monument, achetez les 4 pour gagner \n");
	
	printf("┌───────────┐\n");
	printf("│Dé à avoir.│\n");
	printf("│...........│\n");
	printf("│.Nom carte.│\n");	
	printf("│...........│\n");	
	printf("│...Gain....│\n");	
	printf("│...........│\n");	
	printf("│.Coût......│\n");	
	printf("└───────────┘\n");
	
	
	
	printf(BLUE "┌───────────┐" RESET);
	printf(GREEN "┌───────────┐" RESET);
	printf(BLUE "┌───────────┐" RESET);
	printf(RED "┌───────────┐\n" RESET);
	
	printf(BLUE "│.....1.....│" RESET);
	printf(GREEN "│....2-3....│" RESET);
	printf(BLUE "│.....2.....│" RESET);
	printf(RED"│.....3.....│\n" RESET);
	
	printf(BLUE "│.....■.....│" RESET);
	printf(GREEN "│.....♥.....│" RESET);
	printf(BLUE "│.....♣.....│" RESET);
	printf(RED "│.....♦.....│\n" RESET);
	
	printf(BLUE "│..Champs...│" RESET);
	printf(GREEN "│Boulangerie│" RESET);
	printf(BLUE "│...Ferme...│" RESET);
	printf(RED "│...Café....│\n" RESET);
	
	printf(BLUE "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(RED "│...........│\n" RESET);
	
	printf(BLUE "│.....1.....│" RESET);
	printf(GREEN "│.....1.....│" RESET);
	printf(BLUE "│.....1.....│" RESET);
	printf(RED "│.....1.....│\n" RESET);
	
	printf(BLUE "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(RED "│...........│\n" RESET);
	
	printf(BLUE "│.1.........│" RESET);
	printf(GREEN "│.1.........│" RESET);
	printf(BLUE "│.1.........│" RESET);
	printf(RED "│.2.........│\n" RESET);
	
	printf(BLUE "└───────────┘" RESET);
	printf(GREEN "└───────────┘" RESET);
	printf(BLUE "└───────────┘" RESET);
	printf(RED "└───────────┘\n" RESET);
	
	
	
	
	printf(GREEN "┌───────────┐" RESET);
	printf(BLUE "┌───────────┐" RESET);
	printf(PURPLE "┌───────────┐" RESET);
	printf(PURPLE "┌───────────┐\n" RESET);
	
	printf(GREEN "│.....4.....│" RESET);
	printf(BLUE "│.....5.....│" RESET);
	printf(PURPLE "│.....6.....│" RESET);
	printf(PURPLE "│.....6.....│\n" RESET);
	
	printf(GREEN "│.....♥.....│" RESET);
	printf(BLUE "│.....♠.....│" RESET);
	printf(PURPLE "│...........│" RESET);
	printf(PURPLE "│...........│\n" RESET);
	
	printf(GREEN "│.Supérette.│" RESET);
	printf(BLUE "│...Forêt...│" RESET);
	printf(PURPLE "│Centre aff.│" RESET);
	printf(PURPLE "│...Stade...│\n" RESET);
		
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(PURPLE "│...........│" RESET);
	printf(PURPLE "│...........│\n" RESET);	
	
	printf(GREEN "│.....3.....│" RESET);
	printf(BLUE "│.....1.....│" RESET);
	printf(PURPLE "│..Echange..│" RESET);
	printf(PURPLE "│.....2.....│\n" RESET);
	
		printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(PURPLE "│...........│" RESET);
	printf(PURPLE "│...........│\n" RESET);
	
	printf(GREEN "│.2.........│" RESET);
	printf(BLUE "│.2.........│" RESET);
	printf(PURPLE "│.8.........│" RESET);
	printf(PURPLE "│.6.........│\n" RESET);
	
	
	printf(GREEN "└───────────┘" RESET);
	printf(BLUE "└───────────┘" RESET);
	printf(PURPLE "└───────────┘" RESET);
	printf(PURPLE "└───────────┘\n" RESET);
	
	
	
	
	printf(PURPLE "┌───────────┐" RESET);
	printf(GREEN "┌───────────┐" RESET);
	printf(GREEN "┌───────────┐" RESET);
	printf(BLUE "┌───────────┐\n" RESET);
	
	printf(PURPLE "│.....6.....│" RESET);
	printf(GREEN "│.....7.....│" RESET);
	printf(GREEN "│.....8.....│" RESET);
	printf(BLUE "│.....9.....│\n" RESET);
	
	printf(PURPLE "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│.....♠.....│\n" RESET);
	
	printf(PURPLE "│.Chaîne TV.│" RESET);
	printf(GREEN "│.Fromagerie│" RESET);
	printf(GREEN "│.Fabrique..│" RESET);
	printf(BLUE "│...Mine....│\n" RESET);
	
	printf(PURPLE "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│\n" RESET);
	
	printf(PURPLE "│.....5.....│" RESET);
	printf(GREEN "│...3*♣.....│" RESET);
	printf(GREEN "│...3*♠.....│" RESET);
	printf(BLUE "│.....5.....│\n" RESET);
	
	printf(PURPLE "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(GREEN "│...........│" RESET);
	printf(BLUE "│...........│\n" RESET);
	
	printf(PURPLE "│.7.........│" RESET);
	printf(GREEN "│.5.........│" RESET);
	printf(GREEN "│.3.........│" RESET);
	printf(BLUE "│.6.........│\n" RESET);
	
	printf(PURPLE "└───────────┘" RESET);
	printf(GREEN "└───────────┘" RESET);
	printf(GREEN "└───────────┘" RESET);
	printf(BLUE "└───────────┘\n" RESET);
	
	
	
	
	printf(RED "┌───────────┐" RESET);
	printf(BLUE "┌───────────┐" RESET);
	printf(GREEN "┌───────────┐\n" RESET);
	
	printf(RED "│...9-10....│" RESET);
	printf(BLUE "│....10.....│" RESET);
	printf(GREEN "│...11-12...│\n" RESET);
	
	printf(RED "│.....♦.....│" RESET);
	printf(BLUE "│.....■.....│" RESET);
	printf(GREEN "│...........│\n" RESET);
	
	printf(RED "│Restaurant.│" RESET);
	printf(BLUE "│..Verger...│" RESET);
	printf(GREEN "│..Marché...│\n" RESET);
	
	printf(RED "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(GREEN "│...........│\n" RESET);
	
	printf(RED "│.....2.....│" RESET);
	printf(BLUE "│.....3.....│" RESET);
	printf(GREEN "│....2*■....│\n" RESET);
	
	
	printf(RED "│...........│" RESET);
	printf(BLUE "│...........│" RESET);
	printf(GREEN "│...........│\n" RESET);
	
	printf(RED "│.3.........│" RESET);
	printf(BLUE "│.3.........│" RESET);
	printf(GREEN "│.2.........│\n" RESET);
	
	printf(RED "└───────────┘" RESET);
	printf(BLUE "└───────────┘" RESET);
	printf(GREEN "└───────────┘\n" RESET);
	
	
	
	
	printf(YELLOW "┌───────────┐" RESET);
	printf(YELLOW "┌───────────┐" RESET);
	printf(YELLOW "┌───────────┐" RESET);
	printf(YELLOW "┌───────────┐\n" RESET);
	
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│\n" RESET);
	
	printf(YELLOW "│...Parc....│" RESET);
	printf(YELLOW "│...Radio...│" RESET);
	printf(YELLOW "│...Gare....│" RESET);
	printf(YELLOW "│Centre comm│\n" RESET);
	
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│...........│\n" RESET);
	
	printf(YELLOW "│.Si double.│" RESET);
	printf(YELLOW "│1 fois/tour│" RESET);
	printf(YELLOW "│.Possible..│" RESET);
	printf(YELLOW "│.+1 pièce..│\n" RESET);
	
	printf(YELLOW "│..rejouez..│" RESET);
	printf(YELLOW "│.relancez..│" RESET);
	printf(YELLOW "│.de lancer.│" RESET);
	printf(YELLOW "│./♦ ou /♥..│\n" RESET);
	
		printf(YELLOW "│...........│" RESET);
	printf(YELLOW "│..vos dés..│" RESET);
	printf(YELLOW "│2 dés/tour.│" RESET);
	printf(YELLOW "│...........│\n" RESET);
	
	printf(YELLOW "│.16........│" RESET);
	printf(YELLOW "│.22........│" RESET);
	printf(YELLOW "│.4.........│" RESET);
	printf(YELLOW "│.10........│\n" RESET);
	
	printf(YELLOW "└───────────┘" RESET);
	printf(YELLOW "└───────────┘" RESET);
	printf(YELLOW "└───────────┘" RESET);
	printf(YELLOW "└───────────┘\n" RESET);

}

bool buy(int joueur, int carte) { 

	if (carte != 19) {
		if (joueur == J1) {
			if (banque_j1 >= price[carte]) {
				if (pile[carte] > 0) {
					if ((carte == CENTRE_AFFAIRES) || (carte == STADE) || (carte == TV) || (carte == PARC) || (carte == RADIO) || (carte == GARE) || (carte == CENTRE_COMMERCIAL)) {
						if (deck_j1[carte] < 1) {
							deck_j1[carte] = deck_j1[carte] + 1;
							banque_j1 = banque_j1 - price[carte];
							pile[carte] = pile[carte] - 1;
							return true;
						} else {
							printf("Vous avez déjà cet établissement spécial\n");
							return false;
						}
					} else {
						deck_j1[carte] = deck_j1[carte] + 1;
						banque_j1 = banque_j1 - price[carte];
						pile[carte] = pile[carte] - 1;
						return true;
					}
				} else {
					printf("Cette carte ne peut plus être achetée\n");
					return false;
				}
			} else {
				//printf("Vous ne possédez pas assez de pièces\n");
				//La ligne précédente est commentée car elle nuit à la lecture lors d'une partie contre l'IA.
				return false;
			}
		} else {
			if (banque_j2 >= price[carte]) {
				if (pile[carte] > 0) {
					if ((carte == CENTRE_AFFAIRES) || (carte == STADE) || (carte == TV) || (carte == PARC) || (carte == RADIO) || (carte == GARE) || (carte == CENTRE_COMMERCIAL)) {
						if (deck_j2[carte] < 1) {
							deck_j2[carte] = deck_j2[carte] + 1;
							banque_j2 = banque_j2 - price[carte];
							pile[carte] = pile[carte] - 1;
							return true;
						} else {
							printf("Vous avez déjà cet établissement spécial\n");
							return false;
						}
					} else {
						deck_j2[carte] = deck_j2[carte] + 1;
						banque_j2 = banque_j2 - price[carte];
						pile[carte] = pile[carte] - 1;
						return true;
					}
				} else {
					printf("Cette carte ne peut plus être achetée\n");
					return false;
				}
			} else {
				//printf("Vous ne possédez pas assez de pièces\n");
				//La ligne précédente est commentée car elle nuit à la lecture lors d'une partie contre l'IA.
				return false;
			}
		}
	} else {
		return true;
	}
}

void unbuy(int joueur, int carte) {

	if (carte != 19) {
		if (joueur == J1) {
			if (deck_j1[carte] > 0) {
				deck_j1[carte] = deck_j1[carte] - 1;
				banque_j1 = banque_j1 + price[carte];
				pile[carte] = pile[carte] + 1;
			}
		} else {
			if (deck_j2[carte] > 0) {
				deck_j2[carte] = deck_j2[carte] - 1;
				banque_j2 = banque_j2 + price[carte];
				pile[carte] = pile[carte] + 1;
			}
		}
	}
}


bool is_won(int joueur) {
    
	if (joueur == J1) {

		if ((deck_j1[PARC] >= 1) && (deck_j1[RADIO] >= 1) && (deck_j1[GARE] >= 1) && (deck_j1[CENTRE_COMMERCIAL] >= 1)) {
			return true;
		} else {
			return false;
		}

	} else {

		if ((deck_j2[PARC] >= 1) && (deck_j2[RADIO] >= 1) && (deck_j2[GARE] >= 1) && (deck_j2[CENTRE_COMMERCIAL] >= 1)) {
			return true;
		} else {
			return false;
		}
	}

}

int dice_throw(int nb) {

	if(nb == 1) {
		
		int dice = (rand() % 6) + 1;
		return dice;

	} else {

		int dice1 = (rand() % 6) + 1;
		int dice2 = (rand() % 6) + 1;
		return (dice1 + dice2);
	}

}
		

void apply_effects(int dice, int joueur) {

	if (joueur == J1) {
		
		//PAIEMENTS EFFECTUES AVANT GAINS
		
		if (dice == 3) {
			if (deck_j2[CAFE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					if (banque_j1 >= (1 + 1)*deck_j2[CAFE]) {
						banque_j2 = banque_j2 + (1 + 1)*deck_j2[CAFE];
						banque_j1 = banque_j1 - (1 + 1)*deck_j2[CAFE];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				} else {
					if (banque_j1 >= 1*deck_j2[CAFE]) {
						banque_j2 = banque_j2 + 1*deck_j2[CAFE];
						banque_j1 = banque_j1 - 1*deck_j2[CAFE];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				}
			}
		}

		if ((dice == 9) || (dice == 10)) {
			if (deck_j2[RESTAURANT] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					if (banque_j1 >= (2 + 1)*deck_j2[RESTAURANT]) {
						banque_j2 = banque_j2 + (2 + 1)*deck_j2[RESTAURANT];
						banque_j1 = banque_j1 - (2 + 1)*deck_j2[RESTAURANT];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				} else {
					if (banque_j1 >= 2*deck_j2[RESTAURANT]) {
						banque_j2 = banque_j2 + 2*deck_j2[RESTAURANT];
						banque_j1 = banque_j1 - 2*deck_j2[RESTAURANT];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				}
			}
		}
		
		if (dice == 6) {
		
			if (deck_j1[STADE] != 0) {
				if (banque_j2 >= 2*deck_j1[STADE]) {
					banque_j1 = banque_j1 + 2*deck_j1[STADE];
					banque_j2 = banque_j2 - 2*deck_j1[STADE];
				} else {
					banque_j1 = banque_j1 + banque_j2;
					banque_j2 = 0;
				}
			}

			if (deck_j1[TV] != 0) {
				if (banque_j2 >= 5*deck_j1[TV]) {
					banque_j1 = banque_j1 + 5*deck_j1[TV];
					banque_j2 = banque_j2 - 5*deck_j1[TV];
				} else {
					banque_j1 = banque_j1 + banque_j2;
					banque_j2 = 0;
				}
			}
		}

		//GAINS EFFECTUES APRES PAIEMENTS

		if (dice == 1) {
			if (deck_j1[CHAMPS] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[CHAMPS];
			}
			if (deck_j2[CHAMPS] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[CHAMPS];
			}
		}

		if (dice == 2) {
			if (deck_j1[BOULANGERIE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 + (1 + 1)*deck_j1[BOULANGERIE];
				} else {
					banque_j1 = banque_j1 + 1*deck_j1[BOULANGERIE];
				}
			}
			if (deck_j1[FERME] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[BOULANGERIE];
			}
			if (deck_j2[FERME] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FERME];
			}
		}

		if (dice == 3) {
			if (deck_j1[BOULANGERIE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 + (1 + 1)*deck_j1[BOULANGERIE];
				} else {
					banque_j1 = banque_j1 + 1*deck_j1[BOULANGERIE];
				}
			}
		}

		if (dice == 4) {
			if (deck_j1[SUPERETTE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 + (3 + 1)*deck_j1[SUPERETTE];
				} else {
					banque_j1 = banque_j1 + 3*deck_j1[SUPERETTE];
				}
			}
		}

		if (dice == 5) {
			if (deck_j1[FORET] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[FORET];
			}
			if (deck_j2[FORET] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FORET];
			}
		}

		if (dice == 7) {
			if (deck_j1[FROMAGERIE] != 0) {
				banque_j1 = banque_j1 + 3*deck_j1[FERME]*deck_j1[FROMAGERIE];
			}
		}

		if (dice == 8) {
			if (deck_j1[FABRIQUE] != 0) {
				banque_j1 = banque_j1 + 3*deck_j1[FABRIQUE]*(deck_j1[MINE]+deck_j1[FORET]);
			}
		}

		if (dice == 9) {
			if (deck_j1[MINE] != 0) {
				banque_j1 = banque_j1 + 5*deck_j1[MINE];
			}
			if (deck_j2[MINE] != 0) {
				banque_j2 = banque_j2 + 5*deck_j2[MINE];
			}			
		}

		if (dice == 10) {
			if (deck_j1[VERGER] != 0) {
				banque_j1 = banque_j1 + 3*deck_j1[VERGER];
			}
			if (deck_j2[VERGER] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[VERGER];
			}			
		}

		if ((dice == 11) || (dice == 12)) {
			if (deck_j1[MARCHE] != 0) {
				banque_j1 = banque_j1 + 2*deck_j1[MARCHE]*(deck_j1[CHAMPS]+deck_j1[VERGER]);
			}
		}

		//ECHANGES
		
		//Dé-commenter cette partie pour jouer avec le centre d'affaires contre un joueur.

/*
		if (dice == 6) {

			if (deck_j1[CENTRE_AFFAIRES] != 0) {
				bool choice = false;
				while (choice == false) {
					printf("Quel établissement (à vous) voulez-vous échanger ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Aucun\n");
					int trade1;
					scanf("%d",&trade1);
					printf("Contre quoi ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n");
					int trade2;
					scanf("%d",&trade2);

					if ((trade1 < 15) && (trade2 < 15) && (trade1 != 6) && (trade1 != 7) && (trade1 != 8) && (trade2 != 6) && (trade2 != 7) && (trade2 != 8)) {
						if (deck_j1[trade1] != 0) {
							if (deck_j2[trade2] != 0) {
								choice = true;
								deck_j1[trade1] = deck_j1[trade1] - 1;
								deck_j2[trade2] = deck_j2[trade2] - 1;
								deck_j1[trade2] = deck_j1[trade2] + 1;
								deck_j2[trade1] = deck_j2[trade1] + 1;
							} else {
								printf("J2 ne possède pas la carte demandée\n");
							}
						} else {
							printf("Vous ne possédez pas cette carte\n");
						}
					} else if (trade1 == 15) {
						choice = true;
					} else if ((trade1 >= 16) || (trade2 >= 15) || (trade1 == 6) || (trade1 == 7) || (trade1 == 8) || (trade2 == 6)  || (trade2 == 7) || (trade2 == 8)) {
						printf("Choix invalide, veuillez recommencer\n");
					}
				}

			}
		}
*/		

	} else {
		
		//PAIEMENTS EFFECTUES AVANT GAINS
		
		if (dice == 3) {
			if (deck_j1[CAFE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					if (banque_j2 >= (1 + 1)*deck_j1[CAFE]) {
						banque_j1 = banque_j1 + (1 + 1)*deck_j1[CAFE];
						banque_j2 = banque_j2 - (1 + 1)*deck_j1[CAFE];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				} else {
					if (banque_j2 >= 1*deck_j1[CAFE]) {
						banque_j1 = banque_j1 + 1*deck_j1[CAFE];
						banque_j2 = banque_j2 - 1*deck_j1[CAFE];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				}
			}
		}

		if ((dice == 9) || (dice == 10)) {
			if (deck_j1[RESTAURANT] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					if (banque_j2 >= (2 + 1)*deck_j1[RESTAURANT]) {
						banque_j1 = banque_j1 + (2 + 1)*deck_j1[RESTAURANT];
						banque_j2 = banque_j2 - (2 + 1)*deck_j1[RESTAURANT];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				} else {
					if (banque_j2 >= 2*deck_j1[RESTAURANT]) {
						banque_j1 = banque_j1 + 2*deck_j1[RESTAURANT];
						banque_j2 = banque_j2 - 2*deck_j1[RESTAURANT];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				}
			}
		}
		
		if (dice == 6) {
			
			if (deck_j2[STADE] != 0) {
				if (banque_j1 >= 2*deck_j2[STADE]) {
					banque_j2 = banque_j2 + 2*deck_j2[STADE];
					banque_j1 = banque_j1 - 2*deck_j2[STADE];
				} else {
					banque_j2 = banque_j2 + banque_j1;
					banque_j1 = 0;
				}
			}

			if (deck_j2[TV] != 0) {
				if (banque_j1 >= 5*deck_j2[TV]) {
					banque_j2 = banque_j2 + 5*deck_j2[TV];
					banque_j1 = banque_j1 - 5*deck_j2[TV];
				} else {
					banque_j2 = banque_j2 + banque_j1;
					banque_j1 = 0;
				}
			}
		}

		//GAINS EFFECTUES APRÈS PAIEMENTS

		if (dice == 1) {
			if (deck_j1[CHAMPS] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[CHAMPS];
			}
			if (deck_j2[CHAMPS] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[CHAMPS];
			}
		}

		if (dice == 2) {
			if (deck_j2[BOULANGERIE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (1 + 1)*deck_j2[BOULANGERIE];
				} else {
					banque_j2 = banque_j2 + 1*deck_j2[BOULANGERIE];
				}
			}
			if (deck_j1[FERME] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[BOULANGERIE];
			}
			if (deck_j2[FERME] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FERME];
			}
		}

		if (dice == 3) {
			if (deck_j2[BOULANGERIE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (1 + 1)*deck_j2[BOULANGERIE];
				} else {
					banque_j2 = banque_j2 + 1*deck_j2[BOULANGERIE];
				}
			}
		}

		if (dice == 4) {
			if (deck_j2[SUPERETTE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (3 + 1)*deck_j2[SUPERETTE];
				} else {
					banque_j2 = banque_j2 + 3*deck_j2[SUPERETTE];
				}
			}
		}

		if (dice == 5) {
			if (deck_j1[FORET] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[FORET];
			}
			if (deck_j2[FORET] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FORET];
			}
		}

		if (dice == 7) {
			if (deck_j2[FROMAGERIE] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[FERME]*deck_j2[FROMAGERIE];
			}
		}

		if (dice == 8) {
			if (deck_j2[FABRIQUE] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[FABRIQUE]*(deck_j2[MINE]+deck_j2[FORET]);
			}
		}

		if (dice == 9) {
			if (deck_j1[MINE] != 0) {
				banque_j1 = banque_j1 + 5*deck_j1[MINE];
			}
			if (deck_j2[MINE] != 0) {
				banque_j2 = banque_j2 + 5*deck_j2[MINE];
			}			
		}

		if (dice == 10) {
			if (deck_j1[VERGER] != 0) {
				banque_j1 = banque_j1 + 3*deck_j1[VERGER];
			}
			if (deck_j2[VERGER] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[VERGER];
			}			
		}

		if ((dice == 11) || (dice == 12)) {
			if (deck_j2[MARCHE] != 0) {
				banque_j2 = banque_j2 + 2*deck_j2[MARCHE]*(deck_j2[CHAMPS]+deck_j2[VERGER]);
			}
		}

		//ECHANGES	
		
		//Dé-commenter cette partie pour jouer avec le centre d'affaires contre un joueur.

/*
		if (dice == 6) {

			if (deck_j2[CENTRE_AFFAIRES] != 0) {
				bool choice = false;
				while (choice == false) {
					printf("Quel établissement (à vous) voulez-vous échanger ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Aucun\n");
					int trade1;
					scanf("%d",&trade1);
					printf("Contre quoi ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n");
					int trade2;
					scanf("%d",&trade2);

					if ((trade1 < 15) && (trade2 < 15) && (trade1 != 6) && (trade1 != 7) && (trade1 != 8) && (trade2 != 6) && (trade2 != 7) && (trade2 != 8)) {
						if (deck_j2[trade1] != 0) {
							if (deck_j1[trade2] != 0) {
								choice = true;
								deck_j2[trade1] = deck_j2[trade1] - 1;
								deck_j1[trade2] = deck_j1[trade2] - 1;
								deck_j2[trade2] = deck_j2[trade2] + 1;
								deck_j1[trade1] = deck_j1[trade1] + 1;
							} else {
								printf("J1 ne possède pas la carte demandée\n");
							}
						} else {
							printf("Vous ne possédez pas cette carte\n");
						}
					} else if (trade1 == 15) {
						choice = true;
					} else if ((trade1 >= 16) || (trade2 >= 15) || (trade1 == 6) || (trade1 == 7) || (trade1 == 8) || (trade2 == 6)  || (trade2 == 7) || (trade2 == 8)) {
						printf("Choix invalide, veuillez recommencer\n");
					}
				}

			}
		}
*/
	}
}



void unapply_effects(int dice, int joueur) {

	if (joueur == J1) {
		
		//GAINS INVERSES EFFECTUES EN PREMIER
		
		if (dice == 1) {
			if (deck_j1[CHAMPS] != 0) {
				banque_j1 = banque_j1 - 1*deck_j1[CHAMPS];
			}
			if (deck_j2[CHAMPS] != 0) {
				banque_j2 = banque_j2 - 1*deck_j2[CHAMPS];
			}
		}

		if (dice == 2) {
			if (deck_j1[BOULANGERIE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 - (1 + 1)*deck_j1[BOULANGERIE];
				} else {
					banque_j1 = banque_j1 - 1*deck_j1[BOULANGERIE];
				}
			}
			if (deck_j1[FERME] != 0) {
				banque_j1 = banque_j1 - 1*deck_j1[BOULANGERIE];
			}
			if (deck_j2[FERME] != 0) {
				banque_j2 = banque_j2 - 1*deck_j2[FERME];
			}
		}

		if (dice == 3) {
			if (deck_j1[BOULANGERIE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 - (1 + 1)*deck_j1[BOULANGERIE];
				} else {
					banque_j1 = banque_j1 - 1*deck_j1[BOULANGERIE];
				}
			}
		}

		if (dice == 4) {
			if (deck_j1[SUPERETTE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					banque_j1 = banque_j1 - (3 + 1)*deck_j1[SUPERETTE];
				} else {
					banque_j1 = banque_j1 - 3*deck_j1[SUPERETTE];
				}
			}
		}

		if (dice == 5) {
			if (deck_j1[FORET] != 0) {
				banque_j1 = banque_j1 - 1*deck_j1[FORET];
			}
			if (deck_j2[FORET] != 0) {
				banque_j2 = banque_j2 - 1*deck_j2[FORET];
			}
		}

		if (dice == 7) {
			if (deck_j1[FROMAGERIE] != 0) {
				banque_j1 = banque_j1 - 3*deck_j1[FERME]*deck_j1[FROMAGERIE];
			}
		}

		if (dice == 8) {
			if (deck_j1[FABRIQUE] != 0) {
				banque_j1 = banque_j1 - 3*deck_j1[FABRIQUE]*(deck_j1[MINE]+deck_j1[FORET]);
			}
		}

		if (dice == 9) {
			if (deck_j1[MINE] != 0) {
				banque_j1 = banque_j1 - 5*deck_j1[MINE];
			}
			if (deck_j2[MINE] != 0) {
				banque_j2 = banque_j2 - 5*deck_j2[MINE];
			}			
		}

		if (dice == 10) {
			if (deck_j1[VERGER] != 0) {
				banque_j1 = banque_j1 - 3*deck_j1[VERGER];
			}
			if (deck_j2[VERGER] != 0) {
				banque_j2 = banque_j2 - 3*deck_j2[VERGER];
			}			
		}

		if ((dice == 11) || (dice == 12)) {
			if (deck_j1[MARCHE] != 0) {
				banque_j1 = banque_j1 - 2*deck_j1[MARCHE]*(deck_j1[CHAMPS]+deck_j1[VERGER]);
			}
		}
		
		//PAIEMENTS INVERSES
		
		if (dice == 3) {
			if (deck_j2[CAFE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					if (banque_j1 >= (1 + 1)*deck_j2[CAFE]) {
						banque_j2 = banque_j2 + (1 + 1)*deck_j2[CAFE];
						banque_j1 = banque_j1 - (1 + 1)*deck_j2[CAFE];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				} else {
					if (banque_j1 >= 1*deck_j2[CAFE]) {
						banque_j2 = banque_j2 + 1*deck_j2[CAFE];
						banque_j1 = banque_j1 - 1*deck_j2[CAFE];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				}
			}
		}

		if ((dice == 9) || (dice == 10)) {
			if (deck_j2[RESTAURANT] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					if (banque_j1 >= (2 + 1)*deck_j2[RESTAURANT]) {
						banque_j2 = banque_j2 + (2 + 1)*deck_j2[RESTAURANT];
						banque_j1 = banque_j1 - (2 + 1)*deck_j2[RESTAURANT];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				} else {
					if (banque_j1 >= 2*deck_j2[RESTAURANT]) {
						banque_j2 = banque_j2 + 2*deck_j2[RESTAURANT];
						banque_j1 = banque_j1 - 2*deck_j2[RESTAURANT];
					} else {
						banque_j2 = banque_j2 + banque_j1;
						banque_j1 = 0;
					}
				}
			}
		}
		
		if (dice == 6) {
		
			if (deck_j1[STADE] != 0) {
				if (banque_j2 >= 2*deck_j1[STADE]) {
					banque_j1 = banque_j1 + 2*deck_j1[STADE];
					banque_j2 = banque_j2 - 2*deck_j1[STADE];
				} else {
					banque_j1 = banque_j1 + banque_j2;
					banque_j2 = 0;
				}
			}

			if (deck_j1[TV] != 0) {
				if (banque_j2 >= 5*deck_j1[TV]) {
					banque_j1 = banque_j1 + 5*deck_j1[TV];
					banque_j2 = banque_j2 - 5*deck_j1[TV];
				} else {
					banque_j1 = banque_j1 + banque_j2;
					banque_j2 = 0;
				}
			}
		}

		//GAINS EFFECTUES APRES PAIEMENTS
		
		//Dé-commenter cette partie pour jouer avec le centre d'affaires contre un joueur.

		

		//ECHANGES

/*
		if (dice == 6) {

			if (deck_j1[CENTRE_AFFAIRES] != 0) {
				bool choice = false;
				while (choice == false) {
					printf("Quel établissement (à vous) voulez-vous échanger ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Aucun\n");
					int trade1;
					scanf("%d",&trade1);
					printf("Contre quoi ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n");
					int trade2;
					scanf("%d",&trade2);

					if ((trade1 < 15) && (trade2 < 15) && (trade1 != 6) && (trade1 != 7) && (trade1 != 8) && (trade2 != 6) && (trade2 != 7) && (trade2 != 8)) {
						if (deck_j1[trade1] != 0) {
							if (deck_j2[trade2] != 0) {
								choice = true;
								deck_j1[trade1] = deck_j1[trade1] - 1;
								deck_j2[trade2] = deck_j2[trade2] - 1;
								deck_j1[trade2] = deck_j1[trade2] + 1;
								deck_j2[trade1] = deck_j2[trade1] + 1;
							} else {
								printf("J2 ne possède pas la carte demandée\n");
							}
						} else {
							printf("Vous ne possédez pas cette carte\n");
						}
					} else if (trade1 == 15) {
						choice = true;
					} else if ((trade1 >= 16) || (trade2 >= 15) || (trade1 == 6) || (trade1 == 7) || (trade1 == 8) || (trade2 == 6)  || (trade2 == 7) || (trade2 == 8)) {
						printf("Choix invalide, veuillez recommencer\n");
					}
				}

			}
		}
*/		

	} else {
		
		//PAIEMENTS EFFECTUES AVANT GAINS
		
		if (dice == 3) {
			if (deck_j1[CAFE] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					if (banque_j2 >= (1 + 1)*deck_j1[CAFE]) {
						banque_j1 = banque_j1 + (1 + 1)*deck_j1[CAFE];
						banque_j2 = banque_j2 - (1 + 1)*deck_j1[CAFE];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				} else {
					if (banque_j2 >= 1*deck_j1[CAFE]) {
						banque_j1 = banque_j1 + 1*deck_j1[CAFE];
						banque_j2 = banque_j2 - 1*deck_j1[CAFE];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				}
			}
		}

		if ((dice == 9) || (dice == 10)) {
			if (deck_j1[RESTAURANT] != 0) {
				if (deck_j1[CENTRE_COMMERCIAL] != 0) {
					if (banque_j2 >= (2 + 1)*deck_j1[RESTAURANT]) {
						banque_j1 = banque_j1 + (2 + 1)*deck_j1[RESTAURANT];
						banque_j2 = banque_j2 - (2 + 1)*deck_j1[RESTAURANT];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				} else {
					if (banque_j2 >= 2*deck_j1[RESTAURANT]) {
						banque_j1 = banque_j1 + 2*deck_j1[RESTAURANT];
						banque_j2 = banque_j2 - 2*deck_j1[RESTAURANT];
					} else {
						banque_j1 = banque_j1 + banque_j2;
						banque_j2 = 0;
					}
				}
			}
		}
		
		if (dice == 6) {
			
			if (deck_j2[STADE] != 0) {
				if (banque_j1 >= 2*deck_j2[STADE]) {
					banque_j2 = banque_j2 + 2*deck_j2[STADE];
					banque_j1 = banque_j1 - 2*deck_j2[STADE];
				} else {
					banque_j2 = banque_j2 + banque_j1;
					banque_j1 = 0;
				}
			}

			if (deck_j2[TV] != 0) {
				if (banque_j1 >= 5*deck_j2[TV]) {
					banque_j2 = banque_j2 + 5*deck_j2[TV];
					banque_j1 = banque_j1 - 5*deck_j2[TV];
				} else {
					banque_j2 = banque_j2 + banque_j1;
					banque_j1 = 0;
				}
			}
		}

		//GAINS EFFECTUES APRÈS PAIEMENTS

		if (dice == 1) {
			if (deck_j1[CHAMPS] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[CHAMPS];
			}
			if (deck_j2[CHAMPS] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[CHAMPS];
			}
		}

		if (dice == 2) {
			if (deck_j2[BOULANGERIE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (1 + 1)*deck_j2[BOULANGERIE];
				} else {
					banque_j2 = banque_j2 + 1*deck_j2[BOULANGERIE];
				}
			}
			if (deck_j1[FERME] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[BOULANGERIE];
			}
			if (deck_j2[FERME] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FERME];
			}
		}

		if (dice == 3) {
			if (deck_j2[BOULANGERIE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (1 + 1)*deck_j2[BOULANGERIE];
				} else {
					banque_j2 = banque_j2 + 1*deck_j2[BOULANGERIE];
				}
			}
		}

		if (dice == 4) {
			if (deck_j2[SUPERETTE] != 0) {
				if (deck_j2[CENTRE_COMMERCIAL] != 0) {
					banque_j2 = banque_j2 + (3 + 1)*deck_j2[SUPERETTE];
				} else {
					banque_j2 = banque_j2 + 3*deck_j2[SUPERETTE];
				}
			}
		}

		if (dice == 5) {
			if (deck_j1[FORET] != 0) {
				banque_j1 = banque_j1 + 1*deck_j1[FORET];
			}
			if (deck_j2[FORET] != 0) {
				banque_j2 = banque_j2 + 1*deck_j2[FORET];
			}
		}

		if (dice == 7) {
			if (deck_j2[FROMAGERIE] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[FERME]*deck_j2[FROMAGERIE];
			}
		}

		if (dice == 8) {
			if (deck_j2[FABRIQUE] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[FABRIQUE]*(deck_j2[MINE]+deck_j2[FORET]);
			}
		}

		if (dice == 9) {
			if (deck_j1[MINE] != 0) {
				banque_j1 = banque_j1 + 5*deck_j1[MINE];
			}
			if (deck_j2[MINE] != 0) {
				banque_j2 = banque_j2 + 5*deck_j2[MINE];
			}			
		}

		if (dice == 10) {
			if (deck_j1[VERGER] != 0) {
				banque_j1 = banque_j1 + 3*deck_j1[VERGER];
			}
			if (deck_j2[VERGER] != 0) {
				banque_j2 = banque_j2 + 3*deck_j2[VERGER];
			}			
		}

		if ((dice == 11) || (dice == 12)) {
			if (deck_j2[MARCHE] != 0) {
				banque_j2 = banque_j2 + 2*deck_j2[MARCHE]*(deck_j2[CHAMPS]+deck_j2[VERGER]);
			}
		}

		//ECHANGES	
		
		//Dé-commenter cette partie pour jouer avec le centre d'affaires contre un joueur.

/*
		if (dice == 6) {

			if (deck_j2[CENTRE_AFFAIRES] != 0) {
				bool choice = false;
				while (choice == false) {
					printf("Quel établissement (à vous) voulez-vous échanger ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n 15: Aucun\n");
					int trade1;
					scanf("%d",&trade1);
					printf("Contre quoi ?\n 0: Champs de blé\n 1: Boulangerie\n 2: Ferme\n 3: Café\n 4: Supérette\n 5: Forêt\n 9: Fromagerie\n 10: Fabrique de meubles\n 11: Mine\n 12: Restaurant\n 13: Verger\n 14: Marché de fruits et légumes\n");
					int trade2;
					scanf("%d",&trade2);

					if ((trade1 < 15) && (trade2 < 15) && (trade1 != 6) && (trade1 != 7) && (trade1 != 8) && (trade2 != 6) && (trade2 != 7) && (trade2 != 8)) {
						if (deck_j2[trade1] != 0) {
							if (deck_j1[trade2] != 0) {
								choice = true;
								deck_j2[trade1] = deck_j2[trade1] - 1;
								deck_j1[trade2] = deck_j1[trade2] - 1;
								deck_j2[trade2] = deck_j2[trade2] + 1;
								deck_j1[trade1] = deck_j1[trade1] + 1;
							} else {
								printf("J1 ne possède pas la carte demandée\n");
							}
						} else {
							printf("Vous ne possédez pas cette carte\n");
						}
					} else if (trade1 == 15) {
						choice = true;
					} else if ((trade1 >= 16) || (trade2 >= 15) || (trade1 == 6) || (trade1 == 7) || (trade1 == 8) || (trade2 == 6)  || (trade2 == 7) || (trade2 == 8)) {
						printf("Choix invalide, veuillez recommencer\n");
					}
				}

			}
		}
*/
	}
}
