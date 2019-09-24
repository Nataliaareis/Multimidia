//Natália Araujo dos Reis
//RA:112247

#include <bits/stdc++.h> //biblioteca que contem libs standard
#include <fstream>
#include <stdio.h>


using namespace std;
#define pi 3.142857 //define pi
const int m = 8, n = 8; //define dimensoes iniciais

float T[m][n] = {        { 0.3536, 0.3536, 0.3536, 0.3536, 0.3536, 0.3536, 0.3536, 0.3536 },
                         { 0.4904, 0.4157, 0.2778, 0.0975, -0.0975, -0.2778, -0.4157, -0.4904},
                         { 0.4619, 0.1913, -0.1913, -0.4619, -0.4619, -0.1913, 0.1913, 0.4619},
                         { 0.4157, -0.0975, -0.4904, -0.2778, 0.2778, 0.4904, 0.0975, -0.4157},
                         { 0.3536, -0.3536, -0.3536, 0.3536, 0.3536, -0.3536, -0.3536, 0.3536},
                         { 0.2778, -0.4904, 0.0975, 0.4157, -0.4157, -0.0975, 0.4904, -0.2778},
                         { 0.1913, -0.4619, 0.4619, -0.1913, -0.1913, 0.4619, -0.4619, 0.1913},
                         { 0.0975, -0.2778, 0.4157, -0.4904, 0.4904, -0.4157, 0.2778, -0.0975} };


int main(){

    int i,j,k;

    //matrix é a matriz exemplo
    float matrix[m][n] = { { 154, 123, 123, 123, 123, 123, 123, 136 },
                         { 192, 180, 136, 154, 154, 154, 136, 110 },
                         { 254, 198, 154, 154, 180, 154, 123, 123 },
                         { 239, 180, 136, 180, 180, 166, 123, 123 },
                         { 180, 154, 136, 167, 166, 149, 136, 136 },
                         { 128, 136, 123, 136, 154, 180, 198, 154 },
                         { 123, 105, 110, 149, 136, 136, 180, 166 },
                         { 110, 136, 123, 123, 123, 136, 154, 136 } };

    float M1[m][n]; //Matriz da subtração de 128
    float M2[m][n]; //Resultado da multiplicação T*M
    float M3[m][n]; //Resultado da multiplicação M*T'
    float T1[m][n]; //transposta de T
    float D[m][n]; //Resultado das multiplicações
    float V1[m][n]; //Matrix de volta para a primeira multiplicação
    float N[m][n]; //MATRIX FINAL


    //For da subtração
     for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            M1[i][j] = matrix[i][j] - 128;
        }
    }

    //Multiplicação de matrizes T*M
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            M2[i][j] = 0;
            for (k = 0; k < 8; k++){
                M2[i][j] += T[i][k] * M1[k][j];
            }
        }
    }

    //Transposta de T
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            T1[i][j] = T[j][i];
        }
    }

    //Multiplicação de matrizes (T*M)*T' (que será D)
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            D[i][j] = 0;
            for (k = 0; k < 8; k++){
                D[i][j] += M2[i][k] * T1[k][j];
            }
        }
    }


     printf("Matrix original\n");
     for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    //Fazendo a volta para conferir o resultado
    //N=round(T'*D*T)+128

    //Multiplicação T'*D
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            V1[i][j] = 0;
            for (k = 0; k < 8; k++){
                V1[i][j] += T1[i][k] * D[k][j];
            }
        }
    }

    //Multiplicação (T'*D)*T
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            N[i][j] = 0;
            for (k = 0; k < 8; k++){
                N[i][j] += V1[i][k] * T[k][j];
            }
        }
    }

    //Fazendo o arredondamento
     //Multiplicação de matrizes (T*M)*T' (que será D)
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            N[i][j] = round(N[i][j]);
        }
    }

    //Somando 128
     for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            N[i][j] = N[i][j]+128;
        }
    }

     printf("\n\nMATRIX FINAL\n");
     for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%f\t", N[i][j]);
        }
        printf("\n");
     }
    return 0;
}
