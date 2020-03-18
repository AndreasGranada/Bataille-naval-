/* Créateur : Andreas Granada
 * Classe :  SI-C1b
 * Projet : Bataille navale
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
//déclaration des fonctions
void menu ();
void jeux ();

int main() {

    menu();
    return 0;
}
void menu()
{
// ajout de librérie windows pour la lecture des caractère spéciaux

    int choixdumenu;

    printf("\nBonjour et bienvenue sur la bataille naval\n\n\n");
    do {
        // choix dans le menu et boucle pour les réponces diffèrantes
        printf("1) jouer\n2) voir les regles du jeu\n3) voir les scores\n");
        scanf("%d", &choixdumenu);
    }
    while (choixdumenu > 3 || choixdumenu <= 0);

    switch (choixdumenu)
    {
        //menu principal
        case 1:
            jeux();
            menu();
            system("cls");
            break;

        case 2:
            //régle du jeu
            printf("Les regle du jeu sont simple, quand vous lansez le jeu un tableau avec des bateaux placer aleatoirement dans la grille.\nLe but c'est de couller tout les bateaux ennemis avec le minimum d'attaque possible.\nLes bateaux ne son pas visibles sur la grille,quand vous en touchez un la case apparet en rouge.\nSi vous ne touchez pas de bateaux lors de votres attaque la case attaquee devien bleu.\nPour attaquer il faut entrer des coordonnees en commencent par la lettre puis le chiffre");
            printf("1) revenir au menu");
            scanf("%d",&choixdumenu);
            //renvoye vers le menu prinsipal
            switch(choixdumenu)
            {
                default:
                    menu();
                    break;
            }
            break;

        case 3:
            printf("futur scores");
            menu();
            break;
    }
}
//fonction du jeu
void jeux()
{
    int Vertical = 0;
    int Horizontal = 0;
    int choixdumenu = 0;
    int Compteur = 0;
    int score = 0;
    //déclaration des bateau dans la grille
    int Tableaubat1[10][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 1, 1, 1, 1, 0, 0, 0};
    do {
        system("cls");
        printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
        printf("   1 2 3 4 5 6 7 8 9 10\n");
        //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle
        for (int i = 0; i < 10; i++) {
            printf("%2d ", i + 1);
            for (int j = 0; j < 10; j++) {
                //cange les valeur des case selon la contenance
                if ((Tableaubat1[4][7] == 3) && (Tableaubat1[4][8] == 3) && (Tableaubat1[4][9] == 3))
                {
                    Tableaubat1[4][7] = 5;
                    Tableaubat1[4][8] = 5;
                    Tableaubat1[4][9] = 5;
                    Compteur++;
                }
                if ((Tableaubat1[1][0] == 3) && (Tableaubat1[1][1] == 3) && (Tableaubat1[1][2] == 3) &&
                    (Tableaubat1[1][3] == 3))
                {
                    Tableaubat1[1][0] = 5;
                    Tableaubat1[1][1] = 5;
                    Tableaubat1[1][2] = 5;
                    Tableaubat1[1][3] = 5;
                    Compteur++;
                }
                if ((Tableaubat1[0][6] == 3) && (Tableaubat1[1][6] == 3) && (Tableaubat1[2][6] == 3))
                {
                    Tableaubat1[0][6] = 5;
                    Tableaubat1[1][6] = 5;
                    Tableaubat1[2][6] = 5;
                    Compteur++;
                }
                if ((Tableaubat1[8][4] == 3) && (Tableaubat1[8][5] == 3) && (Tableaubat1[8][6] == 3) &&
                    (Tableaubat1[8][7] == 3) && (Tableaubat1[8][8] == 3))
                {
                    Tableaubat1[8][4] = 5;
                    Tableaubat1[8][5] = 5;
                    Tableaubat1[8][6] = 5;
                    Tableaubat1[8][7] = 5;
                    Tableaubat1[8][8] = 5;
                    Compteur++;
                }
                if ((Tableaubat1[1][8] == 3) && (Tableaubat1[2][8] == 3))
                {
                    Tableaubat1[1][8] = 5;
                    Tableaubat1[2][8] = 5;
                    Compteur++;
                }
                //change les couleur des case quand toucher ou pas
                if (Tableaubat1[i][j] == 0) printf("%c ", 219);
                if (Tableaubat1[i][j] == 1) printf("%c ", 219);
                if (Tableaubat1[i][j] == 2) printf("\033[34m%c \033[0m", 219);
                if (Tableaubat1[i][j] == 3) printf("\033[31m%c \033[0m", 219);
                if (Tableaubat1[i][j] == 5) printf("\033[32m%c \033[0m", 219);
            }
            printf("\n");
        }
        //affichage de question suite à une attaque
        if (Compteur < 5)
        {
            // demande la valeur d'attaque vertical
            printf("Ou voulez vous tirer ?\nVertical:\n");
            scanf("%d", &Vertical);
            if (Vertical < 11 || Horizontal < 11)
            {
                // demande la valeur d'attaque horizontal
                printf("Horizontal:\n");
                scanf("%d", &Horizontal);
                score += 1;
                Tableaubat1[Vertical - 1][Horizontal - 1] += 2;
            }
        }
        //déclanchemant dans la victoir
        else {
            system("cls");
            printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
            scanf("%d", &choixdumenu);
            switch (choixdumenu) {
                case 1:
                    menu();
                    break;
                case 2:
                    exit(EXIT_SUCCESS);
            }
        }
    } while ((Vertical < 11) && (Compteur < 61));
}



