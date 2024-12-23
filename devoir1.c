#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int f(int n) 
{
    printf("Hello f(n) !\n");
    return pow(2, n);  
}

int g(int n) 
{
    printf("Hello g(n) !\n");
    return 2 * n;  
}

int main(int argc, char *argv[]) 
{
    if (argc < 3 || argc > 4) 
    {
        printf("Seules commandes autorisees :\n");
        printf("./prog -f <entier>\n");
        printf("./prog -g <entier>\n");
        printf("./prog -f <entier> -g\n");
        printf("./prog -g <entier> -f\n");
        return 1;
    }

    int n = -1;  
    int optf = 0;  
    int optg = 0;  
    int rang = 0; 
    int test = (rang == 0);
    
    for (int i = 1; i < argc; i++) 
    {
        switch (argv[i][0]) 
        {
            case '-':
                if (strcmp(argv[i], "-f") == 0) 
                {
                    optf++;
                    rang = test ? 1 : rang; 
                } 
                else 
                if (strcmp(argv[i], "-g") == 0) 
                {
                    optg++;
                    rang = test ? 2 : rang;  
                } 
                else 
                {
                    printf("Erreur : Option invalide \"%s\".\n", argv[i]);
                    return 1;
                }
                break;
            default:
                if (n != -1) 
                {
                    printf("Erreur : Plusieurs valeurs fournies.\n");
                    printf("Seules commandes valides :\n");
                    printf("./prog -f <entier>\n");
                    printf("./prog -g <entier>\n");
                    printf("./prog -f <entier> -g\n");
                    printf("./prog -g <entier> -f\n");
                    return 1;
                }
                n = atoi(argv[i]); 
                break;
        }
    }

    if (n == -1 || !(optf || optg)) 
    {
        printf("Erreur : Aucune valeur ou option valide fournie.\n");
        return 1;
    }

    int result = 0;
    switch (rang) 
    {
        case 1:  
            if (optf && optg) 
            {   
                printf ("Hello fog !\n");
                result = f(g(n));  
            } 
            else 
            if (optf) 
            {
                result = f(n); 
            }
            break;
        case 2:  
            if (optg && optf) 
            {
                printf (" Hello gof !\n");
                result = g(f(n));  
            } 
            else 
            if (optg) 
            {
                result = g(n);  // g(n)
            }
            break;
        default:
            printf("Erreur : Aucun calcul valide n'a pu être effectué.\n");
            return 1;
    }
    
    printf("Resultat : %d\n", result);

    return 0;
}