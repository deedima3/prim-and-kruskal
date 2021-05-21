#include <stdio.h>
#include <stdlib.h>

void header();
void prim();
void kruskal();
void checkifcircuit();
void insertmatriks();
void checkifconnected();

int array[50][50];

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