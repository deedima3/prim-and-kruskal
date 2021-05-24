#include <stdio.h>
#include <stdlib.h>

void header();
void insertmatriks(int vertex);
int prim();
void kruskal(int vertex);
void spanningTree();
int checkifcircuit(int array[50][50], int vertex);
int checkifconnected(int startnumber);
void checkifconnectedrecur(int startnumber);

int array[50][50], hubung;
int vertex; 
int spanning[50][50];
int connect[50];

/* Utilities Function START*/

void insertmatriks(int vertex)
{
    printf("Enter the adjacency matrix : \n");
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            if(i != j){
                printf("   vertex %d dan vertex %d   : ", i+1, j+1);
                scanf("%d", &array[i][j]);
            }else{
                array[i][j] = 0;
            }
        }
    }

    printf("\n");
    printf("Bentuk dalam matriks : \n");
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
			printf("  %d", array[i][j]);
        }
	printf("\n");
    }
}

int prim(){
    int cost[50][50];
    int u,v,min_distance,distance[50],from[50];
    int visited[50],no_of_edges,i,min_cost,j;
    
    //create cost[][] matrix,spanning[][]
    for(i=0;i<vertex;i++)
        for(j=0;j<vertex;j++)
        {
            if(array[i][j]==0)
                cost[i][j]=9999;
            else
                cost[i][j]=array[i][j];
                spanning[i][j]=0;
        }
        
    //initialise visited[],distance[] and from[]
    distance[0]=0;
    visited[0]=1;
    
    for(i=1;i<vertex;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }
    
    min_cost=0;        //cost of spanning tree
    no_of_edges = vertex-1;        //no. of edges to be added
    
    while(no_of_edges>0)
    {
        //find the vertex at minimum distance from the tree
        min_distance=9999;
        for(i=1;i<vertex;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
            
        u=from[v];
        
        //insert the edge in spanning tree
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;
        
        //updated the distance[] array
        for(i=1;i<vertex;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }
        
        min_cost=min_cost+cost[u][v];
    }
    
    return(min_cost);
}	

void spanningTree(){
    int i, j;
    for(i=0;i<vertex;i++)
    {
        printf("\n");
        for(j=0;j<vertex;j++){
            printf("%d  ",spanning[i][j]);
        }    
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

void checkconnectedrecur(int startnumber){
    int i;
    for(i=1;i<=vertex;i++){
        if(array[startnumber][i] == 1 && connect[i] != 1){
            connect[i] == 1;
            checkconnectedrecur(i);
        }
    }
}

int checkifconnected()
{
    int counter, i;
    connect[1] == 1;
    checkconnectedrecur(1);
    for(i=1;i<=vertex;i++){
        if(connect[i] == 1){
            counter++;
        }
    }
    if(counter == vertex){
        return 1;
    }
    else{
        return 0;
    }
}

void header()
{
    printf("++++++++++++++++++++++++++++++++\n");
    printf("PROGRAM ALGORIMA PRIM DAN KRUSKAL\n");
    printf("+++++++++++++++++++++++++++++++++");
}
/* Utilities Function END*/


/* Main and Menu Function */

void main(){
    int pilihan;
    int total_cost;
    while(1){
        system("cls");
        header();
        printf("\n\n1. Masukkan Matriks");
        printf("\n2. Prim's Algorithm");
        printf("\n3. Kruskal's Algoritm\n\n");
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
            checkifconnected();
            getch();
            break;
        case 2:
            system("cls");
            header();
            total_cost = prim();
            printf("\n\nspanning tree :\n\n");
            spanningTree();
            printf("\n\nminimum spanning tree : %d", total_cost);
            getch();
            break;
        case 3:
            system("cls");
            header();
            kruskal(vertex);
            getch();
            break;
        default:
            printf("Maaf pilihan yang anda masukkan salah");
            break;
        }
    }
}
