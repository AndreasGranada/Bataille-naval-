/* Créateur : Andreas Granada
 * Classe :  SI-C1b
 * Projet : Bataille navale
 * version : 1.0
 * deadligne : 08.04.2020
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//déclaration des fonctions
void menu ();
void jeu ();
void fichierscore ();
void temporalite (int tiement);
void lancement();
void joueur();
void lireregle();
void lirescore();

//execute le programme
int main() {
    //execution du menu du jeu
    menu();
    return 0;
}
//c'est une fonction de date dans les logs qui s'affiche avant chaque messages
void temporalite(int appelation)
{
    FILE* log = NULL;
    char buffer[256] = {""};
    time_t timestamp = time(NULL);
    strftime(buffer, sizeof(buffer), "%A %d %B %Y - %X.", localtime(&timestamp));
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "[%s]", buffer);
    fclose(log);
}
// fonction de création d'un log qui dira que l'utilisateur est dans le menu
void lancement()
{
    temporalite(1);
    FILE*log = NULL;
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "L'utilisateur est dans le menu\n");
    fclose(log);
}
// fonction de création d'un log qui dira que l'utilisateur est entrain de rentrer son pseudonime
void joueur()
{
    temporalite(1);
    FILE*log = NULL;
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "L'utilisateur entre son pseudonime\n");
    fclose(log);
}
// fonction de création d'un log qui dira que l'utilisateur est dans les régle du jeu
void lireregle()
{
    temporalite(1);
    FILE*log = NULL;
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "L'utilisateur lit les regle\n");
    fclose(log);
}
// fonction de création d'un log qui dira que l'utilisateur regarde les score dans la section score du menu
void lirescore()
{
    temporalite(1);
    FILE*log = NULL;
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "L'utilisateur regarde les scores\n");
    fclose(log);
}

void menu()
{
    int choixdumenu = 0;

    lancement();
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
            //déclanche le prosesuce de jeu
            joueur();
            jeu();
            menu();
            system("cls");
            break;

        case 2:
            //régle du jeu
            system("cls");
            lireregle();
            printf("Les regle du jeu sont simple, quand vous lansez le jeu un tableau avec des bateaux placer aleatoirement dans la grille.\nLe but c'est de couller tout les bateaux ennemis avec le minimum d'attaque possible.\nLes bateaux ne son pas visibles sur la grille,quand vous en touchez un la case apparet en rouge.\nSi vous ne touchez pas de bateaux lors de votres attaque la case attaquee devien bleu.\nPour attaquer il faut entrer des coordonnees en commencent par la lettre puis le chiffre\n");
            printf("\n1) revenir au menu");
            scanf("%d", &choixdumenu);
            //renvoye vers le menu principal
            switch (choixdumenu) {
                default:
                    menu();
                    break;
            }
        case 3:
            //renvoye ver une liste de tout les score enregister à la fin d'une partie
            lirescore();
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
    int grille [10][10] = {0};
    int Vertical = 0;
    int Horizontal = 0;
    int choixdumenu = 0;
    int Compteur = 0;
    int score = 0;
    int aleatoire = 0;
    //déclaration des bateau et de la grille avec leur bateau prédéfinie
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

    int Tableaubat2[10][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 1, 1, 1, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                               0, 0, 1, 1, 0, 0, 0, 0, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 1, 1, 1, 1, 0, 0, 0, 0, 0};

    int Tableaubat3[10][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                               0, 1, 0, 0, 0, 0, 1, 1, 1, 0,
                               0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int Tableaubat4[10][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                               0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                               0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                               0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
                               1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

    int Tableaubat5[10][10] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 1, 1, 0};
    //détermine un nombre aléatoir entre 1 et 5 pour le choix de la carte de jeu
    srand((unsigned) time(NULL));
    aleatoire = rand() %5 +1;
    //déclaration de la variable de nom
    signed char nom[256];
    //écriture du nom infini si il est égale à zero
    do {
        printf("attention pas de chiffres et de caracteres speciaux \n");
        printf("entrer votre nom de joueur\n");
        scanf("%s", &nom);
    } while(nom == NULL);
    //envoie un log qui écrit que l'utilisateur s'est appeler ... (le nom qu'il à écrit)
    temporalite(1);
    FILE*log = NULL;
    log = fopen("../Logs/Logs.game.txt", "a");
    fprintf(log, "L'utilisateur c'est appelé %s\n", nom);
    fclose(log);
    //choix aléatoire de la carte charger avec les diffèrente condition de victoire
        switch (aleatoire)
        {
            case 1:
                do {
                    system("cls");
                    printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
                    printf("   1 2 3 4 5 6 7 8 9 10\n");
                    //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle

                for (int i = 0; i < 10; i++)
                {
                    printf("%2d ", i + 1);
                    for (int j = 0; j < 10; j++)
                    {
                        //vérifie si les bateaux sont coulés
                        if ((Tableaubat1[4][4] == 3) && (Tableaubat1[5][4] == 3) && (Tableaubat1[6][4] == 3)) {
                            Tableaubat1[4][4] = 5;
                            Tableaubat1[5][4] = 5;
                            Tableaubat1[6][4] = 5;
                            Compteur++;
                        }
                        if ((Tableaubat1[1][0] == 3) && (Tableaubat1[1][1] == 3) && (Tableaubat1[1][2] == 3) &&
                            (Tableaubat1[1][3] == 3)) {
                            Tableaubat1[1][0] = 5;
                            Tableaubat1[1][1] = 5;
                            Tableaubat1[1][2] = 5;
                            Tableaubat1[1][3] = 5;
                            Compteur++;
                        }
                        if ((Tableaubat1[4][0] == 3) && (Tableaubat1[4][1] == 3) && (Tableaubat1[4][2] == 3)) {
                            Tableaubat1[4][0] = 5;
                            Tableaubat1[4][1] = 5;
                            Tableaubat1[4][2] = 5;
                            Compteur++;
                        }
                        if ((Tableaubat1[9][2] == 3) && (Tableaubat1[9][3] == 3) && (Tableaubat1[9][4] == 3) &&
                            (Tableaubat1[9][5] == 3) && (Tableaubat1[9][6] == 3)) {
                            Tableaubat1[9][2] = 5;
                            Tableaubat1[9][3] = 5;
                            Tableaubat1[9][4] = 5;
                            Tableaubat1[9][5] = 5;
                            Tableaubat1[9][6] = 5;
                            Compteur++;
                        }
                        if ((Tableaubat1[1][8] == 3) && (Tableaubat1[2][8] == 3)) {
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
                if (Compteur < 5) {
                    // demande la valeur d'attaque vertical
                    printf("Ou voulez vous tirer ?\nVertical:\n");
                    scanf("%d", &Vertical);
                    if (Vertical < 11 || Horizontal < 11)
                        //renvoie les coordonées enregister pour attaqué dans les logs
                        temporalite(1);
                    FILE *log = NULL;
                    log = fopen("../Logs/Logs.game.txt", "a");
                    fprintf(log, "L'utilisateur %s à tier sur %d en vertical\n", nom, Vertical);
                    fclose(log);
                    {
                        // demande la valeur d'attaque horizontal
                        printf("Horizontal:\n");
                        scanf("%d", &Horizontal);
                        //renvoie les coordonées enregister pour attaqué dans les logs
                        temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à tier sur %d en Horizontal\n", nom, Horizontal);
                        fclose(log);
                        score += 1;
                        Tableaubat1[Vertical - 1][Horizontal - 1] += 2;
                    }
                }
                    //déclanchemant dans la victoire
                else {
                    system("cls");
                    //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                    temporalite(1);
                    FILE *log = NULL;
                    log = fopen("../Logs/Logs.game.txt", "a");
                    fprintf(log, "L'utilisateur %s à gagné la partie avec un score de %d\n", nom, score);
                    fclose(log);
                    printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
                    printf("\n vous avez fait un score de %d\n", score);
                    //ouverture du fichier score
                    FILE *fic = fopen("../Save scores/Score.save.txt", "r+");
                    //écriture du pseudonime du joueur et son score à côté
                    if (fic == NULL)
                        exit(1);
                    fseek(fic, 0, SEEK_END);
                    fprintf(fic, "\n%s %d", nom, score);

                    fclose(fic);
                    //revenir au menu du jeu ou fermer le programe
                    scanf("%d", &choixdumenu);
                    switch (choixdumenu) {
                        case 1:
                            menu();
                            break;
                        default:
                            //renvoie un log qui dit que l'utilisateur à fermer le programme
                            temporalite(1);
                            FILE *log = NULL;
                            log = fopen("../Logs/Logs.game.txt", "a");
                            fprintf(log, "L'utilisateur %s à fermé le programme\n", nom);
                            fclose(log);
                            exit(EXIT_SUCCESS);
                            break;
                    }
                    }
                    }while ((Vertical < 11) && (Compteur < 6));
                break;
            case 2:
                do {
                    system("cls");
                    printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
                    printf("   1 2 3 4 5 6 7 8 9 10\n");
                    //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle

                    for (int i = 0; i < 10; i++)
                    {
                        printf("%2d ", i + 1);
                        for (int j = 0; j < 10; j++)
                        {
                            //vérifie si les bateaux sont coulés
                            if ((Tableaubat2[2][3] == 3) && (Tableaubat2[2][4] == 3) && (Tableaubat2[2][5] == 3)) {
                                Tableaubat2[2][3] = 5;
                                Tableaubat2[2][4] = 5;
                                Tableaubat2[2][5] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat2[9][1] == 3) && (Tableaubat2[9][2] == 3) && (Tableaubat2[9][3] == 3) &&
                                (Tableaubat2[9][4] == 3)) {
                                Tableaubat2[9][1] = 5;
                                Tableaubat2[9][2] = 5;
                                Tableaubat2[9][3] = 5;
                                Tableaubat2[9][4] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat2[7][5] == 3) && (Tableaubat2[7][6] == 3) && (Tableaubat2[7][7] == 3)) {
                                Tableaubat2[7][5] = 5;
                                Tableaubat2[7][6] = 5;
                                Tableaubat2[7][7] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat2[1][8] == 3) && (Tableaubat2[2][8] == 3) && (Tableaubat2[3][8] == 3) &&
                                (Tableaubat2[4][8] == 3) && (Tableaubat2[5][8] == 3)) {
                                Tableaubat2[1][8] = 5;
                                Tableaubat2[2][8] = 5;
                                Tableaubat2[3][8] = 5;
                                Tableaubat2[4][8] = 5;
                                Tableaubat2[5][8] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat2[5][2] == 3) && (Tableaubat2[5][3] == 3)) {
                                Tableaubat2[5][2] = 5;
                                Tableaubat2[5][3] = 5;
                                Compteur++;
                            }
                            //change les couleur des case quand toucher ou pas
                            if (Tableaubat2[i][j] == 0) printf("%c ", 219);
                            if (Tableaubat2[i][j] == 1) printf("%c ", 219);
                            if (Tableaubat2[i][j] == 2) printf("\033[34m%c \033[0m", 219);
                            if (Tableaubat2[i][j] == 3) printf("\033[31m%c \033[0m", 219);
                            if (Tableaubat2[i][j] == 5) printf("\033[32m%c \033[0m", 219);
                        }
                        printf("\n");
                    }
                    //affichage de question suite à une attaque
                    if (Compteur < 5) {
                        // demande la valeur d'attaque vertical
                        printf("Ou voulez vous tirer ?\nVertical:\n");
                        scanf("%d", &Vertical);
                        if (Vertical < 11 || Horizontal < 11)
                            temporalite(1);
                        //renvoie les coordonées enregister pour attaqué dans les logs
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à tier sur %d en vertical\n", nom, Vertical);
                        fclose(log);
                        {
                            // demande la valeur d'attaque horizontal
                            printf("Horizontal:\n");
                            scanf("%d", &Horizontal);
                            //renvoie les coordonées enregister pour attaqué dans les logs
                            temporalite(1);
                            FILE *log = NULL;
                            log = fopen("../Logs/Logs.game.txt", "a");
                            fprintf(log, "L'utilisateur %s à tier sur %d en Horizontal\n", nom, Horizontal);
                            fclose(log);
                            score += 1;
                            Tableaubat2[Vertical - 1][Horizontal - 1] += 2;
                        }
                    }
                        //déclanchemant dans la victoire
                    else {
                        system("cls");
                        //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                        temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à gagné la partie avec un score de %d\n", nom, score);
                        fclose(log);
                        printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
                        printf("\n vous avez fait un score de %d\n", score);
                        //ouverture du fichier score
                        FILE *fic = fopen("../Save scores/Score.save.txt", "r+");
                        //écriture du pseudonime du joueur et son score à côté
                        if (fic == NULL)
                            exit(1);
                        fseek(fic, 0, SEEK_END);
                        fprintf(fic, "\n%s %d", nom, score);

                        fclose(fic);
                        //revenir au menu du jeu ou fermer le programe
                        scanf("%d", &choixdumenu);
                        switch (choixdumenu) {
                            case 1:
                                menu();
                                break;
                            default:
                                //renvoie un log qui dit que l'utilisateur à fermer le programme
                                temporalite(1);
                                FILE *log = NULL;
                                log = fopen("../Logs/Logs.game.txt", "a");
                                fprintf(log, "L'utilisateur %s à fermé le programme\n", nom);
                                fclose(log);
                                exit(EXIT_SUCCESS);
                                break;
                        }
                    }
                }while ((Vertical < 11) && (Compteur < 6));
                break;
            case 3:
                do {
                    system("cls");
                    printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
                    printf("   1 2 3 4 5 6 7 8 9 10\n");
                    //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle

                    for (int i = 0; i < 10; i++)
                    {
                        printf("%2d ", i + 1);
                        for (int j = 0; j < 10; j++)
                        {
                            //vérifie si les bateaux sont coulés
                            if ((Tableaubat3[5][1] == 3) && (Tableaubat3[6][1] == 3) && (Tableaubat3[7][1] == 3)) {
                                Tableaubat3[5][1] = 5;
                                Tableaubat3[6][1] = 5;
                                Tableaubat3[7][1] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat3[7][4] == 3) && (Tableaubat3[7][5] == 3) && (Tableaubat3[7][6] == 3) &&
                                (Tableaubat3[7][7] == 3)) {
                                Tableaubat3[7][4] = 5;
                                Tableaubat3[7][5] = 5;
                                Tableaubat3[7][6] = 5;
                                Tableaubat3[7][7] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat3[5][6] == 3) && (Tableaubat3[5][7] == 3) && (Tableaubat3[5][8] == 3)) {
                                Tableaubat3[5][6] = 5;
                                Tableaubat3[5][7] = 5;
                                Tableaubat3[5][8] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat3[4][3] == 3) && (Tableaubat3[4][4] == 3) && (Tableaubat3[4][5] == 3) &&
                                (Tableaubat3[4][6] == 3) && (Tableaubat3[4][7] == 3)) {
                                Tableaubat3[4][3] = 5;
                                Tableaubat3[4][4] = 5;
                                Tableaubat3[4][5] = 5;
                                Tableaubat3[4][6] = 5;
                                Tableaubat3[4][7] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat3[2][3] == 3) && (Tableaubat3[2][4] == 3)) {
                                Tableaubat3[2][3] = 5;
                                Tableaubat3[2][4] = 5;
                                Compteur++;
                            }
                            //change les couleur des case quand toucher ou pas
                            if (Tableaubat3[i][j] == 0) printf("%c ", 219);
                            if (Tableaubat3[i][j] == 1) printf("%c ", 219);
                            if (Tableaubat3[i][j] == 2) printf("\033[34m%c \033[0m", 219);
                            if (Tableaubat3[i][j] == 3) printf("\033[31m%c \033[0m", 219);
                            if (Tableaubat3[i][j] == 5) printf("\033[32m%c \033[0m", 219);
                        }
                        printf("\n");
                    }
                    //affichage de question suite à une attaque
                    if (Compteur < 5) {
                        // demande la valeur d'attaque vertical
                        printf("Ou voulez vous tirer ?\nVertical:\n");
                        scanf("%d", &Vertical);
                        if (Vertical < 11 || Horizontal < 11)
                            temporalite(1);
                        //renvoie les coordonées enregister pour attaqué dans les logs
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à tier sur %d en vertical\n", nom, Vertical);
                        fclose(log);
                        {
                            // demande la valeur d'attaque horizontal
                            printf("Horizontal:\n");
                            scanf("%d", &Horizontal);
                            //renvoie les coordonées enregister pour attaqué dans les logs
                            temporalite(1);
                            FILE *log = NULL;
                            log = fopen("../Logs/Logs.game.txt", "a");
                            fprintf(log, "L'utilisateur %s à tier sur %d en Horizontal\n", nom, Horizontal);
                            fclose(log);
                            score += 1;
                            Tableaubat3[Vertical - 1][Horizontal - 1] += 2;
                        }
                    }
                        //déclanchemant dans la victoire
                    else {
                        system("cls");
                        //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                        temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à gagné la partie avec un score de %d\n", nom, score);
                        fclose(log);
                        printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
                        printf("\n vous avez fait un score de %d\n", score);
                        //ouverture du fichier score
                        FILE *fic = fopen("../Save scores/Score.save.txt", "r+");
                        //écriture du pseudonime du joueur et son score à côté
                        if (fic == NULL)
                            exit(1);
                        fseek(fic, 0, SEEK_END);
                        fprintf(fic, "\n%s %d", nom, score);

                        fclose(fic);
                        //revenir au menu du jeu ou fermer le programe
                        scanf("%d", &choixdumenu);
                        switch (choixdumenu) {
                            case 1:
                                menu();
                                break;
                            default:
                                //renvoie un log qui dit que l'utilisateur à fermer le programme
                                temporalite(1);
                                FILE *log = NULL;
                                log = fopen("../Logs/Logs.game.txt", "a");
                                fprintf(log, "L'utilisateur %s à fermé le programme\n", nom);
                                fclose(log);
                                exit(EXIT_SUCCESS);
                                break;
                        }
                    }
                }while ((Vertical < 11) && (Compteur < 6));
                break;
            case 4:
                do {
                    system("cls");
                    //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                    printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
                    printf("   1 2 3 4 5 6 7 8 9 10\n");
                    //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle

                    for (int i = 0; i < 10; i++)
                    {
                        printf("%2d ", i + 1);
                        for (int j = 0; j < 10; j++)
                        {
                            //vérifie si les bateaux sont coulés
                            if ((Tableaubat4[2][3] == 3) && (Tableaubat4[3][3] == 3) && (Tableaubat4[4][3] == 3)) {
                                Tableaubat4[2][3] = 5;
                                Tableaubat4[3][3] = 5;
                                Tableaubat4[4][3] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat4[1][7] == 3) && (Tableaubat4[2][7] == 3) && (Tableaubat4[3][7] == 3) &&
                                (Tableaubat4[4][7] == 3)) {
                                Tableaubat4[1][7] = 5;
                                Tableaubat4[2][7] = 5;
                                Tableaubat4[3][7] = 5;
                                Tableaubat4[4][7] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat4[8][5] == 3) && (Tableaubat4[8][6] == 3) && (Tableaubat4[8][7] == 3)) {
                                Tableaubat4[8][5] = 5;
                                Tableaubat4[8][6] = 5;
                                Tableaubat4[8][7] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat4[9][0] == 3) && (Tableaubat4[9][1] == 3) && (Tableaubat4[9][2] == 3) &&
                                (Tableaubat4[9][3] == 3) && (Tableaubat4[9][4] == 3)) {
                                Tableaubat4[9][0] = 5;
                                Tableaubat4[9][1] = 5;
                                Tableaubat4[9][2] = 5;
                                Tableaubat4[9][3] = 5;
                                Tableaubat4[9][4] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat4[7][1] == 3) && (Tableaubat4[7][2] == 3)) {
                                Tableaubat4[7][1] = 5;
                                Tableaubat4[7][2] = 5;
                                Compteur++;
                            }
                            //change les couleur des case quand toucher ou pas
                            if (Tableaubat4[i][j] == 0) printf("%c ", 219);
                            if (Tableaubat4[i][j] == 1) printf("%c ", 219);
                            if (Tableaubat4[i][j] == 2) printf("\033[34m%c \033[0m", 219);
                            if (Tableaubat4[i][j] == 3) printf("\033[31m%c \033[0m", 219);
                            if (Tableaubat4[i][j] == 5) printf("\033[32m%c \033[0m", 219);
                        }
                        printf("\n");
                    }
                    //affichage de question suite à une attaque
                    if (Compteur < 5) {
                        // demande la valeur d'attaque vertical
                        printf("Ou voulez vous tirer ?\nVertical:\n");
                        scanf("%d", &Vertical);
                        if (Vertical < 11 || Horizontal < 11)
                            //renvoie les coordonées enregister pour attaqué dans les logs
                            temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à tier sur %d en vertical\n", nom, Vertical);
                        fclose(log);
                        {
                            // demande la valeur d'attaque horizontal
                            printf("Horizontal:\n");
                            scanf("%d", &Horizontal);
                            //renvoie les coordonées enregister pour attaqué dans les logs
                            temporalite(1);
                            FILE *log = NULL;
                            log = fopen("../Logs/Logs.game.txt", "a");
                            fprintf(log, "L'utilisateur %s à tier sur %d en Horizontal\n", nom, Horizontal);
                            fclose(log);
                            score += 1;
                            Tableaubat4[Vertical - 1][Horizontal - 1] += 2;
                        }
                    }
                        //déclanchemant dans la victoire
                    else {
                        system("cls");
                        //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                        temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à gagné la partie avec un score de %d\n", nom, score);
                        fclose(log);
                        printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
                        printf("\n vous avez fait un score de %d\n", score);
                        //ouverture du fichier score
                        FILE *fic = fopen("../Save scores/Score.save.txt", "r+");
                        //écriture du pseudonime du joueur et son score à côté
                        if (fic == NULL)
                            exit(1);
                        fseek(fic, 0, SEEK_END);
                        fprintf(fic, "\n%s %d", nom, score);

                        fclose(fic);
                        //revenir au menu du jeu ou fermer le programe
                        scanf("%d", &choixdumenu);
                        switch (choixdumenu) {
                            case 1:
                                menu();
                                break;
                            default:
                                //renvoie un log qui dit que l'utilisateur à fermer le programme
                                temporalite(1);
                                FILE *log = NULL;
                                log = fopen("../Logs/Logs.game.txt", "a");
                                fprintf(log, "L'utilisateur %s à fermé le programme\n", nom);
                                fclose(log);
                                exit(EXIT_SUCCESS);
                                break;
                        }
                    }
                }while ((Vertical < 11) && (Compteur < 6));
                break;
            case 5:
                do {
                    system("cls");
                    printf("si vous entrez une valeur differante le programme vous renvera au menu du jeu\n");
                    printf("   1 2 3 4 5 6 7 8 9 10\n");
                    //affichage du tableau et condition de bateau toucher selon la valeur des case dans une boucle

                    for (int i = 0; i < 10; i++)
                    {
                        printf("%2d ", i + 1);
                        for (int j = 0; j < 10; j++)
                        {
                            //vérifie si les bateaux sont coulés
                            if ((Tableaubat5[0][2] == 3) && (Tableaubat5[1][2] == 3) && (Tableaubat5[2][2] == 3)) {
                                Tableaubat5[0][2] = 5;
                                Tableaubat5[1][2] = 5;
                                Tableaubat5[2][2] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat5[8][1] == 3) && (Tableaubat5[8][2] == 3) && (Tableaubat5[8][3] == 3) &&
                                (Tableaubat5[8][4] == 3)) {
                                Tableaubat5[8][1] = 5;
                                Tableaubat5[8][2] = 5;
                                Tableaubat5[8][3] = 5;
                                Tableaubat5[8][4] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat5[6][2] == 3) && (Tableaubat5[6][3] == 3) && (Tableaubat5[6][4] == 3)) {
                                Tableaubat5[6][2] = 5;
                                Tableaubat5[6][3] = 5;
                                Tableaubat5[6][4] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat5[4][4] == 3) && (Tableaubat5[4][5] == 3) && (Tableaubat5[4][6] == 3) &&
                                (Tableaubat5[4][7] == 3) && (Tableaubat5[4][8] == 3)) {
                                Tableaubat5[4][4] = 5;
                                Tableaubat5[4][5] = 5;
                                Tableaubat5[4][6] = 5;
                                Tableaubat5[4][7] = 5;
                                Tableaubat5[4][8] = 5;
                                Compteur++;
                            }
                            if ((Tableaubat5[9][7] == 3) && (Tableaubat5[9][8] == 3)) {
                                Tableaubat5[9][7] = 5;
                                Tableaubat5[9][8] = 5;
                                Compteur++;
                            }
                            //change les couleur des case quand toucher ou pas
                            if (Tableaubat5[i][j] == 0) printf("%c ", 219);
                            if (Tableaubat5[i][j] == 1) printf("%c ", 219);
                            if (Tableaubat5[i][j] == 2) printf("\033[34m%c \033[0m", 219);
                            if (Tableaubat5[i][j] == 3) printf("\033[31m%c \033[0m", 219);
                            if (Tableaubat5[i][j] == 5) printf("\033[32m%c \033[0m", 219);
                        }
                        printf("\n");
                    }
                    //affichage de question suite à une attaque
                    if (Compteur < 5) {
                        // demande la valeur d'attaque vertical
                        printf("Ou voulez vous tirer ?\nVertical:\n");
                        scanf("%d", &Vertical);
                        if (Vertical < 11 || Horizontal < 11)
                            temporalite(1);
                        //renvoie les coordonées enregister pour attaqué dans les logs
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à tier sur %d en vertical\n", nom, Vertical);
                        fclose(log);
                        {
                            // demande la valeur d'attaque horizontal
                            printf("Horizontal:\n");
                            scanf("%d", &Horizontal);
                            //renvoie les coordonées enregister pour attaqué dans les logs
                            temporalite(1);
                            FILE *log = NULL;
                            log = fopen("../Logs/Logs.game.txt", "a");
                            fprintf(log, "L'utilisateur %s à tier sur %d en Horizontal\n", nom, Horizontal);
                            fclose(log);
                            score += 1;
                            Tableaubat5[Vertical - 1][Horizontal - 1] += 2;
                        }
                    }
                        //déclanchemant dans la victoire
                    else {
                        system("cls");
                        //renvoie un log pour dire que l'utilisateur à gagner la partie avec ... (le score qu'il ou elle à fait)
                        temporalite(1);
                        FILE *log = NULL;
                        log = fopen("../Logs/Logs.game.txt", "a");
                        fprintf(log, "L'utilisateur %s à gagné la partie avec un score de %d\n", nom, score);
                        fclose(log);
                        printf("Bravo Vous avez gagne !\n1) Menu principal\n2) Arreter le programme\n");
                        printf("\n vous avez fait un score de %d\n", score);
                        //ouverture du fichier score
                        FILE *fic = fopen("../Save scores/Score.save.txt", "r+");
                        //écriture du pseudonime du joueur et son score à côté
                        if (fic == NULL)
                            exit(1);
                        fseek(fic, 0, SEEK_END);
                        fprintf(fic, "\n%s %d", nom, score);

                        fclose(fic);
                        //revenir au menu du jeu ou fermer le programe
                        scanf("%d", &choixdumenu);
                        switch (choixdumenu) {
                            case 1:
                                menu();
                                break;
                            default:
                                //renvoie un log qui dit que l'utilisateur à fermer le programme
                                temporalite(1);
                                FILE *log = NULL;
                                log = fopen("../Logs/Logs.game.txt", "a");
                                fprintf(log, "L'utilisateur %s à fermé le programme\n", nom);
                                fclose(log);
                                exit(EXIT_SUCCESS);
                                break;
                        }
                    }
                }while ((Vertical < 11) && (Compteur < 6));
                break;
        }

}



