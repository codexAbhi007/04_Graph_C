//Adjacency Matrix Representation of a graph 

#include <stdio.h>

//Function prototypes
void addEdge(int vertexCount,int src,int dest,int matrix[][vertexCount]);
void printMatrix(int vertextCount, int matrix[][vertextCount]);

//main

int main(){
    int vertexCount;
    printf("Enter no of vertices: ");
    scanf("%d",&vertexCount);

    //Declare and initialize adjacency matrix
    int adjMatrix[vertexCount][vertexCount];
    int i;
    int j;
    for(i=0;i<vertexCount;++i){
        for(j=0;j<vertexCount;++j){
            adjMatrix[i][j] = 0;
        }
    }

    //Input edges
    int edgeCount;
    printf("Enter no of edges: ");
    scanf("%d",&edgeCount);

    printf("Enter edges (u v) [0 based indexing]: \n");
    for(i=0;i<edgeCount;++i){
        int src, dest;
        printf("Enter Edge %d: ",i+1);
        scanf("%d %d",&src,&dest);

        //Add edge
        addEdge(vertexCount,src,dest,adjMatrix);
    }

    //Display
    printf("\nAdjacency Matrix:\n");
    printMatrix(vertexCount,adjMatrix);
    return 0;
}

//Function definitions
void addEdge(int vertexCount, int src,int dest, int matrix[][vertexCount]){
    if(src >= 0 && src < vertexCount && dest >= 0 && dest < vertexCount){
        matrix[src][dest] = 1;
        matrix[dest][src] = 1; //Only for undirected graph,, skip for directed graph
    }else{
        printf("Invalid vertex! Use 0 to %d\n", vertexCount -1);
    }
}

void printMatrix(int vertexCount,int matrix[][vertexCount]){
    int i,j;
    for(i=0;i<vertexCount;++i){
        for(j=0;j<vertexCount;++j){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
