#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE * first_f;
    FILE * second_f;
    
    first_f = fopen("first_f.txt", "wt");

    int matrix[3][3] = { {1, 2, 3}, 
                       {4, 5, 6}, 
                       {7, 8, 9} };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(first_f," %d ", matrix[i][j]);
        }
    fprintf(first_f, "\n");} 
    fclose(first_f);
    
    second_f = fopen("second_f.txt", "wt");

    int matrix1[3][3] = { {3, 5, 5}, 
                        {7, 5, 2}, 
                        {8, 1, 0} };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(second_f," %d ", matrix1[i][j]);
        }
    fprintf(second_f, "\n");} 
    fclose(second_f);

    int matrix_rez[3][3];
    int m = 0;
    
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++ ){
                m = matrix[i][k] * matrix1[k][j];
                matrix_rez[i][j] = m;
            }
        }
    }
    FILE * rez_f;

    rez_f = fopen("rez_f.txt", "wt");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(rez_f," %d ", matrix_rez[i][j]);
        }
    fprintf(rez_f, "\n");} 
    fclose(rez_f);

    printf(" %d  %d  %d       %d  %d  %d       %d  %d  %d \n", matrix[0][0], matrix[0][1], matrix[0][2], matrix1[0][0], matrix1[0][1], matrix1[0][2], matrix_rez[0][0], matrix_rez[0][1], matrix_rez[0][2]);
    printf(" %d  %d  %d   x   %d  %d  %d   =   %d  %d  %d \n", matrix[1][0], matrix[1][1], matrix[1][2], matrix1[1][0], matrix1[1][1], matrix1[1][2], matrix_rez[1][0], matrix_rez[1][1], matrix_rez[1][2]);
    printf(" %d  %d  %d       %d  %d  %d       %d  %d  %d \n", matrix[2][0], matrix[2][1], matrix[2][2], matrix1[2][0], matrix1[2][1], matrix1[2][2], matrix_rez[2][0], matrix_rez[2][1], matrix_rez[2][2]);
}