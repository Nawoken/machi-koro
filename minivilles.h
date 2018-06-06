#ifndef MINIVILLES_H
#define MINIVILLES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * 
 * @file minivilles.h
 * 
 * @brief Quelques définitions pour implémenter le jeu de société 
 * Minivilles.
 *
 * @author Jill Leflour
 * 
 * 
 * La variante de Minivilles implémentée ici est un jeu à deux joueurs.
 * Les deux joueurs tentent de construire les 4 cartes Monument du jeu 
 * (Parc, Tour radio, Gare, Centre commercial) et peuvent construire une
 * importante variété d'autres cartes Bâtiment.
 * 
 * Au début de chaque tour, le joueur dont c'est le tour lance un (ou 
 * deux) dés, puis récolte éventuellement les gains associés à ce lancer 
 * de dé en fonction de ses cartes, et décide ensuite de construire (ou 
 * non) un bâtiment. Celui qui réunit les 4 Monument gagne 
 * instantanément la partie.
 * 
 * On peut pendant son tour taper "20" dans le terminal pour obtenir le
 * détail des effets des cartes, en ASCII.
 * 
 * Lien vers l'explication des règles : 
 * http://jeuxstrategieter.free.fr/Minivilles_complet.php
 * 
 * L'IA ne sachant pas jouer avec le Centre d'affaires, celui-ci est 
 * désactivé par défaut. Pour l'utiliser dans une partie joueur contre
 * joueur, il suffit de dé-commenter les 4 parties correspondantes dans
 * "minivilles.c".
 * 
 * NB : L'IA gagne à 95% (test effectué sur 20 parties) contre un joueur 
 * jouant de manière aléatoire, mais a des difficultés notables contre 
 * les joueurs humains ... notamment car elle ne planifie pas de 
 * stratégie à très long terme et s'adapte mal si on contre son plan de
 * jeu. (comprendre : il ne faut pas piquer les fermes de l'IA) On 
 * remarquera également que Minivilles est par essence un jeu où le 
 * hasard a une très forte influence, ce qui rend possible une défaite 
 * contre un joueur jouant sciemment mal.
 */
 
/**
 * Valeur représentant le joueur jouant en premier.
 */
#define J1 1

/**
 * Valeur représentant le joueur jouant en deuxième.
 */
#define J2 -1

/**
 * Constantes représentant les différentes cartes du jeu.
 */
#define CHAMPS 0
#define BOULANGERIE 1
#define FERME 2
#define CAFE 3
#define SUPERETTE 4
#define FORET 5
#define CENTRE_AFFAIRES 6 
#define STADE 7
#define TV 8
#define FROMAGERIE 9
#define FABRIQUE 10
#define MINE 11
#define RESTAURANT 12
#define VERGER 13
#define MARCHE 14
#define PARC 15
#define RADIO 16
#define GARE 17
#define CENTRE_COMMERCIAL 18

/**
 * Valeur représentant la victoire de la partie.
 */
#define WIN (+100000)

/**
 * Valeur représentant la défaite de la partie.
 */
#define LOSE (-100000)

/**
 * Définition des valeurs des couleurs pour l'affichage des cartes.
 */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"

/**
 * Tableaux représentant les cartes possédées par chacun des joueurs.
 * (ex: si le joueur 1 possède 2 cartes "Champs", deck_j1[CHAMPS] = 2)
 */
extern int deck_j1[19];
extern int deck_j2[19];

/**
 * Variables représentant le nombre de pièces possédées par chaque joueur.
 */
extern int banque_j1;
extern int banque_j2;

/**
 * Tableau représentant le coût  de construction de chaque carte. (ex: 
 * price[CAFE] = prix de la carte "Café" = 2)
 */
extern int price[19];

/**
 * Tableau représentant le nombre de chaque carte disponible à la 
 * construction. (ex: il y a 6 cartes "Ferme" que les 2 joueurs doivent
 * se partager, donc pile[FERME] = 6. Si J1 en achète une, pile[FERME] =
 * 5, etc)
 */
extern int pile[19];

/**
 * Constante représentant la profondeur de l'algorithme minimax.
 */
extern int minimaxdepth;

/**
 * @brief Ajoute au deck de 'joueur' la carte 'carte' et retire à la 
 * banque de 'joueur' le coût de la carte.
 *
 * @param joueur  Le numéro du joueur qui achète la carte. (1 ou -1)
 * 
 * @param carte  Le numéro de la carte à acheter.
 *
 * @return Un booléen valant true si l'achat s'est effectué 
 * correctement, false sinon. (pas assez de pièces, plus de cartes dans
 * la pile ...)
 */
bool buy(int joueur, int carte);

/**
 * @brief Retire au deck de 'joueur' la carte 'carte' et ajoute à la 
 * banque de 'joueur' le coût de la carte.
 *
 * @param joueur  Le numéro du joueur qui vend la carte. (1 ou -1)
 * 
 * @param carte  Le numéro de la carte à vendre.
 */
void unbuy(int joueur, int carte);

/**
 * @brief Détermine si le joueur 'joueur' a gagné la partie.
 *
 * @param joueur  Le numéro du joueur dont on teste la victoire.
 *
 * @return un booléen 'true' si 'joueur' a gagné la partie, 'false' 
 * sinon
 */
bool is_won(int joueur);

/**
 * @brief Pour un lancer de dé donné, applique les effets des cartes
 * possédées par les 2 joueurs du point de vue de 'joueur'.
 *
 * @param dice  La valeur du lancer de dé.
 * 
 * @param joueur  Le numéro du joueur du point de vue duquel on applique
 * les effets.
 */
void apply_effects(int dice, int joueur);

/**
 * @brief Pour un lancer de dé donné, applique les effets inverses des 
 * cartes possédées par les 2 joueurs du point de vue de 'joueur'.
 *
 * @param dice  La valeur du lancer de dé.
 * 
 * @param joueur  Le numéro du joueur du point de vue duquel on applique
 * les effets inverses.
 */
void unapply_effects(int dice, int joueur);

/**
 * @brief Affiche l'état du jeu : cartes possédées et nombre de pièces.
 */
void print_game();

/**
 * @brief Une des 2 fonctions minimax représentant le niveau minimisant 
 * de l'adversaire.
 *
 * @param joueur  Le numéro du joueur dont c'est le tour.
 * 
 * @param depth  La profondeur (actuelle) de l'algorithme minimax. La
 * profondeur max est déterminée par la constante minimaxdepth.
 * 
 * @param num_niveau  Le niveau (actuel) de l'algorithme minimax. Si
 * depth = minimaxdepth, num_niveau = 0. (num_niveau = depth % 
 * minimaxdepth)
 * 
 * @param nb  Le nombre de dés à lancer à chaque niveau.
 */
int maximin(int joueur, int depth, int num_niveau, int nb);

/**
 * @brief Une des 2 fonctions minimax représentant le niveau maximisant 
 * de l'IA.
 *
 * @param joueur  Le numéro du joueur dont c'est le tour.
 * 
 * @param depth  La profondeur (actuelle) de l'algorithme minimax. La
 * profondeur max est déterminée par la constante minimaxdepth.
 * 
 * @param num_niveau  Le niveau (actuel) de l'algorithme minimax. Si
 * depth = minimaxdepth, num_niveau = 0. (num_niveau = depth % 
 * minimaxdepth)
 * 
 * @param nb  Le nombre de dés à lancer à chaque niveau.
 */
int minimax(int joueur, int depth, int num_niveau, int nb);

/**
 * @brief Evalue la situation vis-à-vis de la victoire du joueur 
 * 'joueur'. Quelques heuristiques "classiques" de Minivilles sont
 * implémentées.
 *
 * @param joueur  Le numéro du joueur dont on veut évaluer la situation.
 *
 * @return Un nombre compris entre -100000 (défaite) et 100000 
 * (victoire).
 */
int eval(int joueur);

/**
 * @brief Simule un lancer de dé(s).
 *
 * @param nb  Le nombre de dés à lancer. (1 ou 2)
 *
 * @return Un entier correspondant au lancer de dé ou à la somme des 2
 * lancers de dés.
 */
int dice_throw(int nb);

/**
 * @brief Affiche en ASCII une représentation des différentes cartes du
 * jeu de Minivilles.
 */
void details();
#endif
