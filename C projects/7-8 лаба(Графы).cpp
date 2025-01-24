#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int num_vertices;
    Node** adj_list;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    graph->adj_list = (Node**)malloc(num_vertices * sizeof(Node*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->weight = weight;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

void print_graph(const Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Вершина %d: ", i);
        Node* temp = graph->adj_list[i];
        while (temp != NULL) {
            printf("%d (%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void deikstra(const Graph* graph, int start, int end, int* path, int* path_length) {
    int* dist = (int*)malloc(graph->num_vertices * sizeof(int));
    int* prev = (int*)malloc(graph->num_vertices * sizeof(int));
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));

    for (int i = 0; i < graph->num_vertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < graph->num_vertices - 1; i++) {
        int min_dist = INT_MAX;
        int u = -1;

        for (int j = 0; j < graph->num_vertices; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        Node* temp = graph->adj_list[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }

            temp = temp->next;
        }
    }

    int curr = end;
    *path_length = 0;
    while (curr != -1) {
        path[*path_length] = curr;
        (*path_length)++;
        curr = prev[curr];
    }

    free(dist);
    free(prev);
    free(visited);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int num_vertices = 5;
    int num_edges = 6;
    int edges[6][3] = { {0, 1, 1}, {1, 0, 1}, {0, 2, 1}, {2, 0, 1}, {1, 3, 1}, {3, 1, 1} };

    Graph* graph = create_graph(num_vertices);

    for (int i = 0; i < num_edges; i++) {
        add_edge(graph, edges[i][0], edges[i][1], edges[i][2]);
    }

    print_graph(graph);

    int* path;
    int path_length = 0;
    path = (int*)malloc(num_vertices * sizeof(int));

    deikstra(graph, 0, 3, path, &path_length);

    printf("Кратчайший путь между 0 и 3: ");
    for (int i = path_length - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    free(path);

    for (int i = 0; i < graph->num_vertices; i++) {
        Node* current = graph->adj_list[i];
        while (current != NULL) {
            Node* temp = current->next;
            free(current);
            current = temp;
        }
    }
    free(graph->adj_list);
    free(graph);

    return 0;
}
