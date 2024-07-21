#include <stdio.h>

#define MAX_TERMS 10  // Maximum number of terms in each polynomial

// Structure for polynomial term
struct poly {
    int coeff;   // Coefficient
    int expo;    // Exponent
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[MAX_TERMS], p2[MAX_TERMS], p3[MAX_TERMS];  // Define arrays of type struct poly
    int t1, t2, t3;

    // Read and display first polynomial
    printf("\n Enter the first polynomial:");
    t1 = readPoly(p1);
    printf("\n First polynomial : ");
    displayPoly(p1, t1);

    // Read and display second polynomial
    printf("\n\n Enter the second polynomial:");
    t2 = readPoly(p2);
    printf("\n Second polynomial : ");
    displayPoly(p2, t2);

    // Add two polynomials and display resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\n Resultant polynomial after addition : ");
    displayPoly(p3, t3);
    printf("\n");

    return 0;
}

// Function to read polynomial terms
int readPoly(struct poly p[]) {
    int num_terms;

    printf("\n Enter the total number of terms in the polynomial: ");
    scanf("%d", &num_terms);

    printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (int i = 0; i < num_terms; i++) {
        printf(" Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf(" Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }

    return num_terms;
}

// Function to add two polynomials
int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // Copy remaining terms from polynomial 1
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms from polynomial 2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // Return the number of terms in the resultant polynomial
}

// Function to display polynomial
void displayPoly(struct poly p[], int terms) {
    for (int i = 0; i < terms - 1; i++) {
        printf("%dx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%dx^%d", p[terms - 1].coeff, p[terms - 1].expo);
}
