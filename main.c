#include <stdio.h>
#include <stdlib.h>

void header();
void prim();
void kruskal();
void checkifcircuit();
void insertmatriks();
void checkifconnected();

int array[50][50],n, i, j, hubung;

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

void header(){
    printf("+++++++++++++++++++++++++++++++++");
    printf("PROGRAM ALGORIMA PRIM DAN KRUSKAL");
    printf("+++++++++++++++++++++++++++++++++");
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

void checkconnected()
{

    if(hubung == 1){
        printf("\nMatriks ini termasuk Graph Terhubung");
    }
    else{
        printf("\nMatriks ini termasuk Graph Tidak Terhubung");
    }
}
