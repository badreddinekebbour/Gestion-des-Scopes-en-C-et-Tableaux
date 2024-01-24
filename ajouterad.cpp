#include <stdio.h>

#define MAX_PRODUCTS 100

void ajouterP(int id[], int quantities[], int numProducts) {
    int codeid, quantity;

    printf("Entrez le produit codeid: ");
    scanf("%d", &codeid);

    printf("Entrez la quantite a ajouter: ");
    scanf("%d", &quantity);

    for (int i = 0; i < numProducts; i++) {
        if (id[i] == codeid) {
            quantities[i] += quantity;
            printf("Quantite ajoutee avec succes.\n");
            return;
        }
    }

    id[numProducts] = codeid;
    quantities[numProducts] = quantity;
    printf("Produit ajoute avec succes.\n");
}

void supprimer (int id[], int quantities[], int numProducts) {
    int codeid, quantity;

    printf("Enter the product codeid: ");
    scanf("%d", &codeid);

    for (int i = 0; i < numProducts; i++) {
        if (id[i] == codeid) {
            printf("Saisissez la quantite a supprimer : ");
            scanf("%d", &quantity);

        
            if (quantity > quantities[i]) {
                printf("Erreur : La quantite à supprimer depasse le stock disponible.\n");
            } else {
                quantities[i] -= quantity;
                printf("Quantite supprimee avec succes.\n");
            }
            return;
        }
    }

    printf("Erreur : Produit introuvable.\n");
}


int main() {
    int productid[MAX_PRODUCTS];
    int productQuantities[MAX_PRODUCTS];
    int numProducts = 0;
    char choice;

    do {
    
        printf("1. Ajouter un produit au stock\n");
        printf("2. Supprimer un produit du stock\n");

       
        printf("Choisissez une opération (1-2): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                ajouterP(productid, productQuantities, numProducts);
                numProducts++;
                break;
            case '2':
                supprimer (productid, productQuantities, numProducts);
                break;
           
            default:
                printf("Choix invalide. Veuillez choisir une operation valide.\n");
        }
    } while (choice != '2');

    return 0;
}

