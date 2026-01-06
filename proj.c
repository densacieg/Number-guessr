#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Jeu du nombre à deviner

int main() {
    char nom[20];
    printf("                Bienvenue !\n");
    printf("            C'est quoi ton nom ?\n ");
    scanf("%19s", nom);

    while (1) { // boucle principale pour rejouer
        char rep1[10], rep2[10];
        printf("\n                  Menu principal\n");
        printf("   jouer  / ordi (ordi devine) / quitter ? \n");
        scanf("%9s", rep1);

        if (strcmp(rep1, "jouer") == 0) {
            printf("\n   Choisis une difficulté : facile / normal / difficile\n");
            scanf("%9s", rep2);

            srand(time(NULL));
            int secret, essais;
                            // difficulté du jeux
            if (strcmp(rep2, "facile") == 0) {
                secret = rand() % 50 + 1;
                essais = 10;
            } else if (strcmp(rep2, "normal") == 0) {
                secret = rand() % 100 + 1;
                essais = 10;
            } else if (strcmp(rep2, "difficile") == 0) {
                secret = rand() % 500 + 1;
                essais = 20;
            } else {
                printf("Je n'ai pas compris.\n");
                continue;
            }

            printf("\nJ'ai choisi un nombre.\nEssaie de le deviner !\n");

            while (essais > 0) {
                char entree[20];
                int proposition;

                printf("\nEssais restants: %d\n", essais);
                printf("Propose un nombre ou 'recommencer' ");
                scanf("%19s", entree);

                if (strcmp(entree, "recommencer") == 0) {
                    printf("On recommence une nouvelle partie !\n");
                    break;
                }

                proposition = atoi(entree);

                if (proposition == secret) {
                    printf("Bravo %s, tu as trouvé le nombre: %d\n", nom, secret);
                    break;
                } else if (proposition < secret) {
                    printf("C'est plus grand !\n");
                } else {
                    printf("C'est plus petit !\n");
                }

                essais--;
                if (essais == 0) {
                    printf("Raté ! Le nombre était %d\n", secret);
                }
            }
        }                           // partie de l'ordi
        else if (strcmp(rep1, "ordi") == 0) {
            printf("\nChoisis une difficulté pour moi : facile / normal / difficile\n");
            printf("Une fois la difficulté choisie, tu ne pourras pas réinitialiser ma partie, car je suis abonnée à Masdak.");
            scanf("%9s", rep2);
                                // difficulté du jeux
            int min, max, essais;
            if (strcmp(rep2, "facile") == 0) {
                min = 1; max = 50; essais = 10;
            } else if (strcmp(rep2, "normal") == 0) {
                min = 1; max = 100; essais = 10;
            } else if (strcmp(rep2, "difficile") == 0) {
                min = 1; max = 500; essais = 20;
            } else {
                printf("Je n'ai pas compris.\n");
                continue;
            }

            printf("\nPense à un nombre entre %d et %d, %s.\n", min, max, nom);
            printf("Je vais essayer de le deviner !\n");
            printf("Réponds par 'plus', 'moins', 'bravo'.\n");

            while (essais > 0) {
                int guess = (min + max) / 2;
                printf("\nJe propose: %d\n", guess);

                char reponse[10];
                printf("Ta réponse: ");
                scanf("%9s", reponse);

                if (strcmp(reponse, "bravo") == 0) {
                    printf("Yes ! J'ai trouvé ton nombre: %d\n", guess);
                    break;
                } else if (strcmp(reponse, "plus") == 0) {
                    min = guess + 1;
                } else if (strcmp(reponse, "moins") == 0) {
                    max = guess - 1;
                } else if (strcmp(reponse, "recommencer") == 0) {
                    printf("On recommence une nouvelle partie !\n");
                    break;
                } else {
                    printf("Réponds seulement par 'plus', 'moins', 'bravo'.\n");
                    continue;
                }

                essais--;
                if (essais == 0) {
                    printf("Je n'ai pas réussi à deviner ton nombre au nom t'es trop fort\n");
                }
            }
        }
        else if (strcmp(rep1, "quitter") == 0) {
            printf("De toute façon, tu n’allais pas gagner %s (°u°) aller circule \n", nom);
            break;
        }
        else {
            printf("Écris 'jouer' pour jouer, 'ordi' pour me laisser deviner ou 'quitter' pour quitter.\n");
        }
    }

    return 0;
}