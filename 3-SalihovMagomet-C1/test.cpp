#include "pch.h"
#include "labC1.h"

/*
IDE: Visual Studio 2019 Community Edition
OS: Windows 10 Home, Version 21H1, Build 19043.1526
CPU: Intel(R) Core(TM) i3-5005U CPU @ 2.00GHz   2.00 GHz
RAM: 4,00 GB
STRESSTEST RESULTS:
    GRAPH TRAVERSAL TIME: 19873 ms
    TOTAL: 77608 ms
    USED MEMORY: 693 MB
*/

#define TEST_NUM_OF_VERTICES 550000

TEST(LabSolution_StressTest, LabSolution_GraphGenerating) 
{
    const int maxDeltaNeighbour = TEST_NUM_OF_VERTICES;
    FILE* fileGraph = fopen("TestFile.txt", "w");
    ASSERT_TRUE(fileGraph);
    int i = 0;
    int neighbour = 0;
    fprintf(fileGraph, "%d\n", TEST_NUM_OF_VERTICES);
    for (; i < TEST_NUM_OF_VERTICES - 1; i++) 
    {
        fprintf(fileGraph, "%d ", i);
        for (neighbour = i + rand() % (maxDeltaNeighbour - 1) + 1; neighbour < TEST_NUM_OF_VERTICES; neighbour += rand() % (maxDeltaNeighbour - 1) + 1)
        {
            fprintf(fileGraph, "%d ", neighbour);
        }
        fprintf(fileGraph, "\n");
    }
    fprintf(fileGraph, "%d\n", TEST_NUM_OF_VERTICES - 1);
    fclose(fileGraph);
}


TEST(LabSolution_StressTest, LabSolution_FillingInFile) 
{
    int depthFirstTraversalResult;
    FILE* f = fopen("TestFile.txt", "r");
    ASSERT_TRUE(f);
    adjacency_list_t* graph = ReadAdjacencyList(f);
    fclose(f);
    ASSERT_TRUE(graph);
    FILE* fileOutput = fopen("Record.txt", "w");
    if (fileOutput == NULL) 
    {
        AdjacencyListDestroy(graph);
        ASSERT_TRUE(fileOutput);
    }
    depthFirstTraversalResult = DepthFirstSearch(graph, 0, fileOutput);
    if (depthFirstTraversalResult == 0) 
    {
        fclose(fileOutput);
        AdjacencyListDestroy(graph);
        ASSERT_TRUE(depthFirstTraversalResult);
    }
    fclose(fileOutput);
    AdjacencyListDestroy(graph);
}