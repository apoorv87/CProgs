#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    int weight;
    struct node *next;
};


void add_edge(struct node **graphlist, int src, int dest, int edge)
{
    struct node *newNode;
   
    src = src-1; 
    newNode = (struct node *)malloc(sizeof(struct node)); 
    newNode->v = dest;
    newNode->weight = edge;
    if (graphlist[src] == NULL)    
    {
        graphlist[src] = newNode;
        graphlist[src]->next = NULL;
    }
    else
    {
        newNode->next =  graphlist[src]->next;
        graphlist[src]->next = newNode;
    }
}

void dfs_util(struct node **graphlist, int start, int *visited)
{
    int i;
    struct node *temp;

    if (!visited[start])
    { 
        visited[start] = 1;
        printf("vertex %d is visited\n", start+1); 
    }
    temp = graphlist[start];
    while(temp != NULL)
    {
        if (visited[temp->v - 1] == 0)
        {
            dfs_util(graphlist, (temp->v - 1), visited);   
        }
        temp = temp->next;
    }
}

void dfs(struct node **graphlist, int size)
{
    int i;
    int *visited = (int *)calloc(size, sizeof(int));
    for (i=0; i<size; i++)
    {
        dfs_util(graphlist, i, visited);
    }

}

int main() 
{
    struct node **graph_list;
    struct node *temp;
    int i, *queue;

    graph_list = (struct node **)calloc(5, sizeof(struct node *));
    add_edge(graph_list, 1, 2, 4);
    add_edge(graph_list, 1, 3, 6);
    add_edge(graph_list, 2, 4, 1);
    add_edge(graph_list, 3, 5, 7);
    add_edge(graph_list, 4, 5, 2);
    add_edge(graph_list, 2, 5, 11);
    add_edge(graph_list, 3, 4, 8);

        for (i=0; i<5; i++)
    {
        printf("\nedges of vertex %d are:\n", i+1);
        temp = graph_list[i];
        while(temp != NULL)
        {
            printf("\nEdge to vertex %d with weight %d", temp->v, temp->weight); 
            temp = temp->next;
        }
    }

    dfs(graph_list, 5);

}




