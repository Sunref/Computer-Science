/**
*
* @author Fernanda Martins
* Grafos.
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{

    int vertice;
    struct Nodo* proximo;

} Nodo;

typedef struct Grafo{

    int num_vertices;
    Nodo** listas_adjacencia;

} Grafo;

Nodo* criar_nodo(int vertice);
Grafo* criar_grafo(int num_vertices);
void adicionar_aresta(Grafo* grafo, int origem, int destino);
void imprimir_grafo(Grafo* grafo);
void liberar_grafo(Grafo* grafo);

int main(){

    int num_vertices = 5;
    Grafo* grafo = criar_grafo(num_vertices);

    adicionar_aresta(grafo, 0, 1);
    adicionar_aresta(grafo, 0, 4);
    adicionar_aresta(grafo, 1, 2);
    adicionar_aresta(grafo, 1, 3);
    adicionar_aresta(grafo, 1, 4);
    adicionar_aresta(grafo, 2, 3);
    adicionar_aresta(grafo, 3, 4);

    imprimir_grafo(grafo);
    liberar_grafo(grafo);

    return 0;

}

Nodo* criar_nodo(int vertice) {

    Nodo* novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->vertice = vertice;
    novo_nodo->proximo = NULL;
    return novo_nodo;

}

Grafo* criar_grafo(int num_vertices){

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    grafo->listas_adjacencia = (Nodo**)malloc(num_vertices * sizeof(Nodo*));

    for(int i = 0; i < num_vertices; i++){
        grafo->listas_adjacencia[i] = NULL;
    }

    return grafo;

}

void adicionar_aresta(Grafo* grafo, int origem, int destino) {

    Nodo* novo_nodo = criar_nodo(destino);
    novo_nodo->proximo = grafo->listas_adjacencia[origem];
    grafo->listas_adjacencia[origem] = novo_nodo;

    novo_nodo = criar_nodo(origem);
    novo_nodo->proximo = grafo->listas_adjacencia[destino];
    grafo->listas_adjacencia[destino] = novo_nodo;

}

void imprimir_grafo(Grafo* grafo) {

    for(int i = 0; i < grafo->num_vertices; i++){
        Nodo* temp = grafo->listas_adjacencia[i];
        printf("Vértice %d:", i);

        while(temp){
            printf(" %d", temp->vertice);
            temp = temp->proximo;
        }

        printf("\n");

    }

}

void liberar_grafo(Grafo* grafo){

    for(int i = 0; i < grafo->num_vertices; i++){

        Nodo* temp = grafo->listas_adjacencia[i];
        while(temp){
            Nodo* aux = temp;
            temp = temp->proximo;
            free(aux);
        }
    }

    free(grafo->listas_adjacencia);
    free(grafo);

}