#include "Array.h"



float* add(float a[], float b[], int size_a, int size_b, int *size){

    *size = (size_a > size_b) ? size_a : size_b;   // Assign maximum size between size_a and size_b
    float* sum = (float*) malloc(sizeof(float) * (*size));     

    for (int i = 0; i < size_a; i++)
        sum[i] = a[i];
        
    for (int i = 0; i < size_b; i++)
        sum[i] += b[i];        

    return sum;
}



void Print_Polynomial(float poly[], int size){
    for (int i = 0; i < size; i++){
        printf("%0.2f", poly[i]);
        if(i != size-1)
            printf("x^%d", (size - i - 1));
        if (i != size-1)
            printf(" + ");
    }
    printf("\n");
}


int main(){

    float poly1[100], poly2[100];
    int poly1_size = 0, poly2_size = 0, sum_size; 

    Input_Array(poly1, &poly1_size, "Enter the 1st polnomials variable: ");
    Input_Array(poly2, &poly2_size, "Enter the 2nd polnomials variable: ");
    
    printf("\nPolynomial 1 : ");
    Print_Polynomial(poly1, poly1_size);
    
    printf("\nPolynomial 2 : ");
    Print_Polynomial(poly2, poly2_size);

    float* sum = add(poly1, poly2, poly1_size, poly2_size, &sum_size);

    printf("\nSum of Polynomial 1 and 2 is: \n");
    Print_Polynomial(sum, sum_size);
    

}