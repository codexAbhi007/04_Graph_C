//Adjacency List representation of graph (Array of linked lists)

#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct Node{
    int vertex;
    struct Node* next;
}Node;

//Graph Structure
typedef struct Graph{
    int vertexCount;
    Node** adjList;
}Graph;

//Function prototypes
Graph* createGraph(int vertexCount);
void addEdge(Graph* graph,int src,int dest);
void printGraph(Graph* graph);
Node* createNode(int vertex);

int main(){
    int vertexCount;
    printf("Enter number of vertices: ");
    scanf("%d",&vertexCount);

    //Create graph
    Graph* graph = createGraph(vertexCount);

    //Input edges
    int edgeCount;
    printf("Enter number of edges: ");
    scanf("%d",&edgeCount);

    printf("Enter edges (u,v) [0 based indexing]:\n");
    int i;
    for(i=0;i<edgeCount;++i){
        int src,dest;
        printf("Enter Edge %d: ",i+1);
        scanf("%d %d",&src,&dest);

        addEdge(graph,src,dest);
    }

    //Display
    printf("\nAdjacency List:\n");
    printGraph(graph);

    //Free memory (optional)
    
    for(i = 0;i<vertexCount;++i){
        Node* current = graph->adjList[i];
        while(current){
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->adjList);
    free(graph);

    return 0;
}

//Function definitions
Graph* createGraph(int vertexCount){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjList = (Node**)malloc(vertexCount * sizeof(Node*)); //Array of linked list

    //Initialize adjacency List to NULL
    int i;
    for(i = 0;i<vertexCount;++i){
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph,int src,int dest){
    if(src >= 0 && src < graph->vertexCount && dest >=0  && dest < graph->vertexCount){
        Node* newNode = createNode(dest);
        newNode->next = graph->adjList[src];
        graph->adjList[src] = newNode;

        //add edge dest->src (only for undirected graph)
        newNode = createNode(src);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }else{
        printf("Invalid Vertex!\n");
    }
}

Node* createNode(int vertex){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void printGraph(Graph* graph){
    int i;
    for(i = 0;i<graph->vertexCount;++i){
        printf("Vertex %d: ",i);
        Node* current = graph->adjList[i];
        while(current){
            printf("%d ",current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

