#include <stdio.h>
#include <stdlib.h>

void header();
void prim();
void kruskal();
int checkifcircuit(int array[50][50], int vertex);
void insertmatriks();
void checkifconnected();

int array[50][50],n, i, j, hubung;

/* Utilities Function START*/

void checkifconnected()
{
    if (hubung == 1)
    {
        printf("\nMatriks ini termasuk Graph Terhubung");
    }
    else
    {
        printf("\nMatriks ini termasuk Graph Tidak Terhubung");
    }
}

int checkifcircuit(int array[50][50], int vertex)
{
    int degreeIn = 0, degreeOut = 0, i,j, count;
    int arrayDegreeIn[50];
    int arrayDegreeOut[50];
    int temp, countercircuit;

    for(i=0;i<vertex;i++){
        for (j = 0; j < vertex; j++){
            if (array[i][j] != 0)
            {
                degreeOut++;
            }
            if (array[j][i] != 0){
                degreeIn++;
            }
        }
        arrayDegreeIn[count] = degreeIn;
        arrayDegreeOut[count] = degreeOut;
        degreeOut = 0;
        degreeIn = 0;
        count++;
    }
    for(i=0;i<vertex;i++){
       temp = arrayDegreeIn[i] - arrayDegreeOut[i];
       if(temp != 0){
           countercircuit++;
       }
       if(countercircuit > 2){
           return 0;
       }
    }
    return 1;
}

void header()
{
    printf("+++++++++++++++++++++++++++++++++");
    printf("PROGRAM ALGORIMA PRIM DAN KRUSKAL");
    printf("+++++++++++++++++++++++++++++++++");
}
/* Utilities Function END*/


/* Main and Menu Function */

void main(){
    int pilihan;
    while(1){
        system("cls");
        header();
        printf("1. Masukkan Matriks");
        printf("2. Prim's Algorithm");
        printf("3. Kruskal's Algoritm");
        printf("Masukkan pilihan yang anda inginkan:");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            system("cls");
            header();
            insertmatriks();
            checkconnected();
            break;
        case 2:
            system("cls");
            header();
            prim();
            break;
        case 3:
            system("cls");
            header();
            kruskal();
            break;
        default:
            printf("Maaf pilihan yang anda masukkan salah");
            break;
        }
    }
}

void insertmatriks()
{

    printf("\n\nMasukkan jumlah vertek     : ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix : \n");
    for(i=1;i<=n;i++){
        for(j=1; j<=n;j++){
            if(i!= j){
                printf("   vertek %d dan vertek %d   : ", i, j);
                scanf("%d", &array[i][j]);
                if(array[i][j] != 0){
                    hubung = 1;
                }
                else{
                    hubung = 0;
                }
            }else{
                array[i][j]=0;
            }
        }
    }

    printf("\n");
    for(i=1; i<=n;i++){
        for(j=1;j<=n;j++){
			printf(" %d", array[i][j]);
        }
		printf("\n");
    }

}
