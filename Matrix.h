#include <stdio.h>


typedef struct Matrix{
    int* mat_data;
    int rows, cols;
} Matrix;


void Print_Mat(Matrix *mat);


void Matrix_Input(Matrix *mat){

    printf("\nEnter the rows and columns of matrix: ");
    scanf("%d %d", &(mat->rows), &(mat->cols));

    mat->mat_data = (int*) malloc(sizeof(int) * mat->rows * mat->cols);

    printf("\nInput %d x %d Matrix:\n", mat->rows, mat->cols);
    for(int i = 0; i < mat->rows; i++){
        for(int j = 0; j < mat->cols; j++){
            scanf("%d", &(mat->mat_data[mat->rows * i + j]));
        }
    }

    Print_Mat(mat);

}


void Print_Mat(Matrix *mat){

    printf("\n%d x %d Matrix:\n", mat->rows, mat->cols);
    for(int i = 0; i < mat->rows; i++){
        for(int j = 0; j < mat->cols; j++){
            printf("%d ", mat->mat_data[mat->rows * i + j]);
        }
        printf("\n");
    }
    printf("\n");
}



