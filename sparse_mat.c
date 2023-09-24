#include "Matrix.h"


void Print_Sparse_Mat(int* mat, int size){
    printf("R C V\n");
    for (int i=0; i<size; i++){
        for (int j=0; j<3; j++)
            printf("%d ", mat[j * 3 + i]);
        printf("\n");
    }
}



int main(){

    Matrix mat1;
    Matrix_Input(&mat1);

    Print_Mat(&mat1);
    int size = 0;

    for(int i = 0; i < mat1.rows; i++)
        for(int j = 0; j < mat1.cols; j++)
            if(mat1.mat_data[mat1.rows * i + j] != 0)
                size++;

    printf("Size found: %d", size);

    int* sparseMat= (int*) malloc(sizeof(int) * size * 3);

    printf("\nArray allocated\n");

    int k = 0;

    for(int i = 0; i < mat1.rows; i++)
        for(int j = 0; j < mat1.cols; j++)
            if(mat1.mat_data[mat1.rows * i + j] != 0){
                sparseMat[0 * 3 + k] = i;
                sparseMat[1 * 3 + k] = j;
                sparseMat[2 * 3 + k] = mat1.mat_data[mat1.rows * i + j];
                k++;
            }

    Print_Sparse_Mat(sparseMat, size);

}