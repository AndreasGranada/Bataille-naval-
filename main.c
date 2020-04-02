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
void jeu ();
void fichierscore ();

int main() {
    //execution du menu du jeu 
    menu();
    return 0;
}
void menu()
{
// ajout de librérie windows pour la lecture des caractère spéciaux

    int choixdumenu = 0;

    printf("\nBonjour et bienvenue sur la bataille naval\n\n\n");
    do {
        // choix dans le menu et boucle pour les réponces diffèrantes
        printf("1) jouer\n2) voir les regles du jeu\n3) voir les scores\n");
        scanf("%d", &choixdumenu);
    }
    while (choixdumenu > 3 || choixdumenu <= 0);

    switch (choixdumenu) {
        //menu principal
        case 1:
            //jeu
            jeu();
            menu();
            system("cls");
            break;

        case 2:
            //régle du jeu
            system("cls");
            printf("Les regle du jeu sont simple, quand vous lansez le jeu un tableau avec des bateaux placer aleatoirement dans la grille.\nLe but c'est de couller tout les bateaux ennemis avec le minimum d'attaque possible.\nLes bateaux ne son pas visibles sur la grille,quand vous en touchez un la case apparet en rouge.\nSi vous ne touchez pas de bateaux lors de votres attaque la case attaquee devien bleu.\nPour attaquer il faut entrer des coordonnees en commencent par la lettre puis le chiffre");
            printf("1) revenir au menu");
            scanf("%d", &choixdumenu);
            //renvoye vers le menu prinsipal
            switch (choixdumenu) {
                default:
                    menu();
                    break;
            }
        case 3:
            fichierscore();
            break;
    }
}
//fonction d'identification
void fichierscore()
{
    int Choixdumenu = 0;

    printf("Voila tout les scores enregistes\n");
    //ouverture du fichier score
    FILE *fic = fopen("../Save scores/Score.save.txt","r");
    signed char Pseudonime[256];

    if(fic == NULL)
        exit(1);
    //boucle d'affichage de score
    while(fgets(Pseudonime, 255, fic) !=NULL)
        printf("%s\n", Pseudonime);
    //fermeture du fichier score
    fclose(fic);
    //revenir au menu du jeu
    printf("\n1) pour revenire au menu du jeu\n");
    scanf("%d", &Choixdumenu);

    switch (Choixdumenu)
    {
        default: menu();
            break;
    }

}


//fonction du jeu
void jeu()
{
    int Vertical = 0;
    int Horizontal = 0;
    int choixdumenu = 0;
    int Compteur = 0;
    int score = 0;
    //déclaration des bateau et de la grille
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
    //déclaration de la variable de nom
    signed char nom[256];
    //écriture du nom infini si il est égale à zero
    do {
        printf("attention pas de chiffres et de caracteres speciaux \n");
        printf("entrer votre nom de joueur\n");
        scanf("%s", &nom);
    } while(nom == NULL);

    do {
        system("cls");
        printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
        printf("   1 2 3 4 5 6 7 8 9 10\n");
        //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle
        for (int i = 0; i < 10; i++) {
            printf("%2d ", i + 1);
            for (int j = 0; j < 10; j++) {
                //vérifie si les bateaux sont coulés
                if ((Tableaubat1[4][4] == 3) && (Tableaubat1[5][4] == 3) && (Tableaubat1[6][4] == 3))
                {
                    Tableaubat1[4][4] = 5;
                    Tableaubat1[5][4] = 5;
                    Tableaubat1[6][4] = 5;
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
                if ((Tableaubat1[4][0] == 3) && (Tableaubat1[4][1] == 3) && (Tableaubat1[4][2] == 3))
                {
                    Tableaubat1[4][0] = 5;
                    Tableaubat1[4][1] = 5;
                    Tableaubat1[4][2] = 5;
                    Compteur++;
                }
                if ((Tableaubat1[9][2] == 3) && (Tableaubat1[9][3] == 3) && (Tableaubat1[9][4] == 3) &&
                    (Tableaubat1[9][5] == 3) && (Tableaubat1[9][6] == 3))
                {
                    Tableaubat1[9][2] = 5;
                    Tableaubat1[9][3] = 5;
                    Tableaubat1[9][4] = 5;
                    Tableaubat1[9][5] = 5;
                    Tableaubat1[9][6] = 5;
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
        //déclanchemant dans la victoire
        else {
            system("cls");
            printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
            printf("\n vous avez fait un score de %d\n",score);
            //ouverture du fichier score
            FILE *fic = fopen("../Save scores/Score.save.txt","r+");
            //écriture du pseudonime du joueur et son score à côté
            if (fic == NULL)
                exit(1);
            fseek(fic, 0, SEEK_END);
            fprintf(fic,"\n%s %d",nom ,score);

            fclose(fic);
            //revenir au menu du jeu ou fermer le programe
            scanf("%d", &choixdumenu);
            switch (choixdumenu) {
                case 1:
                    menu();
                    break;
                default:
                    exit(EXIT_SUCCESS);
                    break;
            }
        }
    } while ((Vertical < 11) && (Compteur < 6));
}



