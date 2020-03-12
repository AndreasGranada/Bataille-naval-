/* Créateur : Andreas Granada
 * Classe :  SI-C1b
 * Projet : Bataille navale
 */
#include <stdio.h>
#include <windows.h>



int main() {
    // ajout de librérie windows pour la lecture des caractère spéciaux
    SetConsoleOutputCP(65001);
    int choixdumenu = 0;

    printf("\nBonjour et bienvenue sur la bataille naval\n\n\n");
    do {
        printf("1) jouer\n2) voir les régles du jeu\n3) voir les scores\n");
        scanf("%d", &choixdumenu);
    }
    while (choixdumenu > 3 || choixdumenu <= 0);

    switch (choixdumenu) {
        case 1:
            printf("Test 1");
            break;

        case 2:
            printf("Les régle du jeu sont simple, quand vous lansez le jeu un tableau avec des bateaux placer aléatoirement dans la grille.\nLe but c'est de couller tout les bateaux ennemis avec le minimum d'attaque possible.\nLes bateaux ne son pas visibles sur la grille,quand vous en touchez un la case apparet en rouge.\nSi vous ne touchez pas de bateaux lors de votres attaque la case attaquée devien bleu.\nPour attaquer il faut entrer des coordonnées en commencent par la lettre puis le chiffre");
            break;

        case 3:
            printf("Test 3");
            break;
    }
    return 0;
}
void menu (int choixdumenu){

}


