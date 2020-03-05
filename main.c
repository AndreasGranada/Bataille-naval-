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
    printf("1) jouer\n2) voir les régles du jeu\n3) voir les scores\n");
    scanf("%d", &choixdumenu);

    switch (choixdumenu) {
        case 1:
            printf("Test 1");
            break;

        case 2:
            printf("Test 2");
            break;

        case 3:
            printf("Test 3");
            break;

        default:
            while (choixdumenu > 3 || choixdumenu <= 0) {
                printf("entrez une selection valide\n\n");
                printf("1) jouer\n2) voir les régles du jeu\n3) voir les scores\n");
                scanf("%d", &choixdumenu);
            }
            switch (choixdumenu) {
                case 1:
                    printf("Test 1");
                    break;

                case 2:
                    printf("Test 2");
                    break;

                case 3:
                    printf("Test 3");
                    break;
            }

            break;
    }
    return 0;
}
