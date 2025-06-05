//BFS and DFS Graph traversals

#include <stdio.h>
#include <stdlib.h>

//Function prototypes

int** createMatrix(int vertexCount);
void freeMatrix(int** matrix,int vertexCount);
void addEdge(int vertexCount,int src, int dest,int** matrix);
void printMatrix(int vertexCount,int** matrix);
void BFS(int vertexCount,int** matrix, int start);
void DFS(int vertexCount,int** matrix,int start);

//main function
int main(){
    int vertexCount;
    printf("Enter no of vertices: ");
    scanf("%d",&vertexCount);

    int** matrix = createMatrix(vertexCount);

    int edges; 
    printf("Enter no of edges: ");
    scanf("%d",&edges);

    printf("Enter edges (u v) [0 indexing]:\n");
    int i;
    for(i=0;i<edges;++i){
        int src,dest;
        scanf("%d %d",&src,&dest);
        addEdge(vertexCount,src,dest,matrix);
    }

    printf("\nAdjacency Matrix:\n");
    printMatrix(vertexCount,matrix);

    int start;
    printf("\nEnter starting node for BFS and DFS: ");
    scanf("%d",&start);

    printf("\nBFS Traversal: ");
    BFS(vertexCount,matrix,start);

    printf("\nDFS Traversal: ");
    DFS(vertexCount,matrix,start);
    printf("\n");

    freeMatrix(matrix,vertexCount);

    return 0;
}

//Function definitions

int** createMatrix(int vertexCount){
    int** matrix = (int**)malloc(vertexCount * sizeof(int*));
    int i;
    for(i = 0;i<vertexCount;++i){
        matrix[i] = (int*)calloc(vertexCount, sizeof(int)); //initialized to 0
    }

    return matrix;
}

void freeMatrix(int** matrix,int vertexCount){
    int i;
    for(i= 0;i < vertexCount;++i){
        free(matrix[i]);
    }
    free(matrix);
}

void addEdge(int vertexCount,int src,int dest,int** matrix){
    matrix[src][dest] = 1;
    matrix[dest][src] = 1; //for directed graph remove
}

void printMatrix(int vertexCount,int** matrix){
    int i,j;
    for(i = 0;i<vertexCount;++i){
        for(j=0;j<vertexCount;++j){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void BFS(int vertexCount,int** matrix, int start){
    int* visited = (int*)calloc(vertexCount, sizeof(int));
    int* queue = (int*)malloc(vertexCount * sizeof(int));

    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear){
        int current = queue[front++];
        printf("%d ",current);

        int i;
        for(i = 0;i<vertexCount;++i){
            if(matrix[current][i] == 1 && !visited[i]){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    free(queue);
    free(visited);

}

void DFS(int vertexCount,int** matrix,int start){
    int* visited = (int*)calloc(vertexCount, sizeof(int));
    int* stack = (int*)malloc(vertexCount * sizeof(int));

    int top = -1;

    stack[++top] = start;

    while(top >= 0){
        int current = stack[top--];

        if(!visited[current]){
            printf("%d ",current);
            visited[current] = 1;

            int i;
            for(i = vertexCount - 1; i >= 0; --i){
                if(matrix[current][i] == 1 && !visited[i]){
                    stack[++top] = i;
                }
            }
        }
    }

    free(stack);
    free(visited);
}