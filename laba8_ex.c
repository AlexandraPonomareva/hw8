#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double DependencyCount();

int main(){
    
    DependencyCount();
    return 0;

}

long double DependencyCount(){
    
    FILE * home_work8;
    home_work8 = fopen("home_work8.txt", "wt");
    
    //We set known variables for calculating velocities
    
    int Colomns = 6000;
    int Rows = 2;
    int matrix[Colomns][Rows];
    int matrix1[Colomns][Rows];
    int Ra = 45000;
    
    double P = 3.1415926535;
    double i = 63.4 * (P / 180.0);
    double constanta = 398600.4; 
    double  We = 7.2921159 * pow(10, -5); 

    //We calculate Rp for Ra equal to 45000 and i equal to 63.4 degrees (previously converted to radians)
    
    double Rp = ((pow((We),2) * pow(Ra, 4) * (pow(cos(i), 2))) / ((2 * constanta) - (pow((We), 2) * pow(Ra, 3) * (pow(cos(i), 2)))));

    //We enumerate Ra from 0 to 60000 in increments of 10
    
    for(int Ra = 0; Ra <= 60000; Ra += 10){
        
        double Va = sqrt((2 * constanta * Rp)/(Ra * (Ra + Rp)));
        matrix[Colomns][0] = Va;
        double Vw = (We * Ra * cos(i));
        matrix[Colomns][1] = Vw;
        fprintf(home_work8, "%.12lf %.12lf %d\n", Va, Vw, Ra);
    }
    
    fclose(home_work8);
    
    FILE *home_work8_1;
    home_work8_1 = fopen("home_work8_1.txt", "wt");

    //We implement the algorithm for counting two dependencies

    for(int i = 0; i < Colomns; i++){
        for(int j = 0; j < Rows; j++){
            if(matrix[i][j] || matrix[i][j]){
                
                matrix1[i][j] = 1;
            
            }
            else{
                
                matrix1[i][j]= 0;
            
            }
            
            printf("%d\n", matrix1[i][j]);
            fprintf(home_work8_1, "%d %d\n", matrix1[i][0], matrix1[i][1]);}
            printf("\n");
            
            }
        
        fclose(home_work8_1);
        
    }
