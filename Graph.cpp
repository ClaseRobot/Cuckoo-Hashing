#include <iostream>
#include "Graph.h"

using namespace UndavGraph;

enum TypeGraph{Directed, Undirected};

struct NodeAdjacent {
    int vertexAdjacent;
    NodeAdjacent* next;
};

struct ListAdjacent {
    int grade;
    NodeAdjacent* firstAdjacent;
};

struct Vertex {
    int vertex;
    ListAdjacent* adjacent;
};

struct UndavGraph::Graph{
    TypeGraph type;
    int vertexSize;
    Vertex* vertexes;
};

UndavGraph::Graph* CreateGraph(int vertexSize, TypeGraph type){
    UndavGraph::Graph* newGraph = NULL;
    if(vertexSize >= 0){
        newGraph = new UndavGraph::Graph;
        newGraph->vertexSize = vertexSize;
        newGraph->vertexes = new Vertex[vertexSize];
        newGraph->type = type;
        for(int i = 0; i < vertexSize; i++) {
            newGraph->vertexes[i].vertex = i;
            newGraph->vertexes[i].adjacent = CreateListAdjacentEmpty();
        }
    }
    return newGraph;
}

UndavGraph::Graph* CreateDirectedGraph(int vertexSize){
    return CreateGraph(vertexSize, Directed);
}

UndavGraph::Graph* CreateUndirectedGraph(int vertexSize){
    return CreateGraph(vertexSize, Undirected);
}

void Connect(UndavGraph::Graph* graph, int sourceVertex, int targetVertex){
    if(IsVertexValid(sourceVertex, graph->vertexSize) && IsVertexValid(targetVertex, graph->vertexSize)){
        if(!Contains(graph->vertexes[sourceVertex].adjacent, sourceVertex)){
            Add(graph->vertexes[sourceVertex].adjacent, targetVertex);
            if (graph->type == Undirected){
                Add(graph->vertexes[sourceVertex].adjacent, sourceVertex);
            }
        }
    }
}

bool AreAdjacent(const UndavGraph::Graph* graph, int sourceVertex, int targetVertex){

}

void DestroyGraph(UndavGraph::Graph* graph){
    for(int i = 0; i<graph->vertexSize; ++i){
        DestroyAdjacents(graph->vertexes[i].adjacent);
    }
}

ListAdjacent* CreateListAdjacentEmpty(){
    ListAdjacent* newList = new ListAdjacent;
    newList->grade = 0;
    newList->firstAdjacent = NULL;
    return newList;
}

bool IsVertexValid(int vertex, int vertexSize){
    return vertex >= 0 && vertex < vertexSize;
}

void Add(ListAdjacent* list, int vertex){
    list->firstAdjacent = CreateNodeAdjacent(vertex, list->firstAdjacent);
    list->grade++;
}

NodeAdjacent* CreateNodeAdjacent(int vertex, NodeAdjacent* next){
    NodeAdjacent* node = new NodeAdjacent;
    node->vertexAdjacent = vertex;
    node->next = next;
    return node;
}

bool Contains(ListAdjacent* list, int vertex){
    NodeAdjacent* iterator = list->firstAdjacent;
    bool contains = false;
    while(iterator != NULL && !contains){
        contains = iterator->vertexAdjacent == vertex;
        iterator = iterator->next;
    }
    return contains;
}

void DestroyAdjacents(ListAdjacent* list){
    NodeAdjacent* iterator;
    NodeAdjacent* auxiliar;
    while(iterator!=NULL){
        auxiliar = iterator;
        iterator = iterator->next;
        delete auxiliar;
    }
    delete list;
}