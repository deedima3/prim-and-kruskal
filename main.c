#include <stdio.h>
#include <stdlib.h>

void header();
void insertmatriks(int vertex);
void prim();
void kruskal(int vertex);
int checkifcircuit(int array[50][50], int vertex);
void checkifconnected();

int array[50][50], hubung;

/* Utilities Function START*/

void insertmatriks(int vertex)
{
    printf("Enter the adjacency matrix : \n");
    for(int i=1; i<=vertex; i++){
        for(int j=1; j<=vertex; j++){
            if(i != j){
                printf("   vertex %d dan vertex %d   : ", i, j);
                scanf("%d", &array[i][j]);
                if(array[i][j] != 0){
                    hubung = 1;
                }
                else{
                    hubung = 0;
                }
            }else{
                array[i][j] = 0;
            }
        }
    }

    printf("\n");
    printf("Bentuk dalam matriks : \n");
    for(int i=1; i<=vertex; i++){
        for(int j=1; j<=vertex; j++){
			printf("  %d", array[i][j]);
        }
	printf("\n");
    }
}

void kruskal(int vertex){
	int awal, kecil=999, v=0;
 	int uji[vertex];
 	
 	for(int i=1; i<=vertex; i++)
 	{
  		for(int j=i; j<=vertex; j++)
  		{
   			if(array[i][j]<kecil && array[i][j]!=0)
   			{
    			kecil = array[i][j];
   			}
  		}
 	}
	awal = kecil;
 
	int batas=0, min=0, a, b, bobot=0;
 	for(int i=1; i<=vertex; i++)
 	{
  		uji[i] = 999;
 	}
 
 	printf("\n\n");
 	printf("Hasil : \n");
 	uji[awal]=awal;
 	while(1)
 	{
  		min = 999;
  		for(int i=1; i<=vertex; i++)
  		{
  			if(uji[i] == i)
   			{
    				for(int j=1; j<=vertex; j++)
    				{
     					if(array[i][j]<min && array[i][j]!=0)
     					{
     						min = array[i][j];
     						a=i;
     						b=j;
     					}
    				} 
   			}
  		}
  		array[a][b] = 0;
  		array[b][a] = 0;
  
  		int sama = 0;
  		for(int i=1; i<=vertex; i++)
  		{
   			if(uji[i]==b)
   			{
    			sama++;
   			}
    
  		}
 
  		if (sama == 0)
  		{
   			printf("%d - %d : %d\n",a,b,min);
   			bobot += min;
   			uji[b] = b;
   			v++;
  		}
  		if(v == vertex-1)
  		{
   			break;
  		}
  		batas++;
 	}
 	
 	printf("Total : %d", bobot);
}

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
    int vertex, pilihan;
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
            printf("\n\nMasukkan jumlah vertex     : ");
    	    scanf("%d", &vertex);
            insertmatriks(vertex);
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
            kruskal(vertex);
            break;
        default:
            printf("Maaf pilihan yang anda masukkan salah");
            break;
        }
    }
}
