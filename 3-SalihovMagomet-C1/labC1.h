#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  

#define MAX_INT_LENGTH 10

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct 
    {
        int* neighbour;
        int quantOfNeighb;
    } array_of_neighbours_t;

    typedef struct 
    {
        array_of_neighbours_t* arrayOfVert;
        int quantOfVertices;
    } adjacency_list_t;

    typedef struct node_t 
    {
        int vertex;
        struct node_t* next;
    } node_t;

    typedef struct 
    {
        node_t* top;
    } stack_t;

    stack_t* StackInit();
    stack_t* StackPush(stack_t* stack, int vertex);
    int StackIsEmpty(stack_t* stack);
    int StackPop(stack_t* stack);
    void StackDestroy(stack_t* stack);
    int StackPushAllNeighboursOfVertex(stack_t* stack, adjacency_list_t* graph, int vertex);
    int DepthFirstSearch(adjacency_list_t* graph, int vertex, FILE* stream);
    adjacency_list_t* ReadAdjacencyList(FILE* stream);
    void AdjacencyListDestroy(adjacency_list_t* adjacencyList);
    int LengthOfNumber(int num);
    int LabSolution();

#ifdef __cplusplus
}
#endif