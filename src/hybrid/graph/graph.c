#include "graph.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Initialize an empty graph.
 */
void initialize_graph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    graph->vertices = NULL;
    graph->vertex_count = 0;
    graph->edge_count = 0;
}

/*
 * Search for a vertex by node name.
 */
GraphVertex *find_vertex(Graph *graph,
                         const char *node)
{
    if (graph == NULL || node == NULL)
    {
        return NULL;
    }

    GraphVertex *current = graph->vertices;

    while (current != NULL)
    {
        if (strcmp(current->node_name, node) == 0)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

/*
 * Add a new vertex if it does not already exist.
 */
GraphVertex *add_vertex(Graph *graph,
                        const char *node)
{
    if (graph == NULL || node == NULL)
    {
        return NULL;
    }

    /* Check if vertex already exists */
    GraphVertex *existing = find_vertex(graph, node);

    if (existing != NULL)
    {
        return existing;
    }

    /* Allocate memory */
    GraphVertex *new_vertex =
        (GraphVertex *)malloc(sizeof(GraphVertex));

    if (new_vertex == NULL)
    {
        return NULL;
    }

    /* Initialize vertex */
    strcpy(new_vertex->node_name, node);

    new_vertex->edges = NULL;

    /* Insert at beginning of linked list */
    new_vertex->next = graph->vertices;

    graph->vertices = new_vertex;

    graph->vertex_count++;

    return new_vertex;
}

GraphEdge *find_edge(GraphVertex *vertex,
                     const char *destination)
{
    if (vertex == NULL || destination == NULL)
    {
        return NULL;
    }

    GraphEdge *current = vertex->edges;

    while (current != NULL)
    {
        if (strcmp(current->destination, destination) == 0)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void add_edge(Graph *graph,
              const char *source,
              const char *destination)
{
    if (graph == NULL || source == NULL || destination == NULL)
    {
        return;
    }

    /* Ensure both vertices exist */
    GraphVertex *source_vertex = add_vertex(graph, source);

    add_vertex(graph, destination);

    if (source_vertex == NULL)
    {
        return;
    }

    /* Check if edge already exists */
    GraphEdge *edge =
        find_edge(source_vertex, destination);

    if (edge != NULL)
    {
        edge->weight++;
        return;
    }

    /* Create new edge */
    GraphEdge *new_edge =
        (GraphEdge *)malloc(sizeof(GraphEdge));

    if (new_edge == NULL)
    {
        return;
    }

    strcpy(new_edge->destination, destination);

    new_edge->weight = 1;

    new_edge->next = source_vertex->edges;

    source_vertex->edges = new_edge;

    graph->edge_count++;
}

void print_graph(Graph *graph)
{
    if (graph == NULL)
        return;

    printf("\n========== TELECOM GRAPH ==========\n");

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        printf("%s\n", vertex->node_name);

        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            printf("    -> %s (weight = %u)\n",
                   edge->destination,
                   edge->weight);

            edge = edge->next;
        }

        vertex = vertex->next;
    }

    printf("===================================\n");
}

void print_graph_statistics(Graph *graph)
{
    if (graph == NULL)
        return;

    printf("\n========== GRAPH STATISTICS ==========\n");
    printf("Total Vertices : %u\n", graph->vertex_count);
    printf("Total Edges    : %u\n", graph->edge_count);
    printf("======================================\n");
}

void free_graph(Graph *graph)
{
    if (graph == NULL)
        return;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            GraphEdge *next_edge = edge->next;
            free(edge);
            edge = next_edge;
        }

        GraphVertex *next_vertex = vertex->next;
        free(vertex);
        vertex = next_vertex;
    }

    graph->vertices = NULL;
    graph->vertex_count = 0;
    graph->edge_count = 0;
}

uint32_t total_communication_volume(Graph *graph)
{
    if (graph == NULL)
        return 0;

    uint32_t total = 0;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            total += edge->weight;
            edge = edge->next;
        }

        vertex = vertex->next;
    }

    return total;
}

GraphVertex *most_active_source(Graph *graph)
{
    if (graph == NULL)
        return NULL;

    GraphVertex *best = NULL;
    uint32_t max_packets = 0;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        uint32_t packets = 0;

        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            packets += edge->weight;
            edge = edge->next;
        }

        if (packets > max_packets)
        {
            max_packets = packets;
            best = vertex;
        }

        vertex = vertex->next;
    }

    return best;
}

uint32_t incoming_traffic(Graph *graph,
                          const char *node)
{
    if (graph == NULL || node == NULL)
        return 0;

    uint32_t total = 0;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            if (strcmp(edge->destination, node) == 0)
            {
                total += edge->weight;
            }

            edge = edge->next;
        }

        vertex = vertex->next;
    }

    return total;
}

GraphVertex *most_active_destination(Graph *graph)
{
    if (graph == NULL)
        return NULL;

    GraphVertex *best = NULL;
    uint32_t maximum = 0;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        uint32_t traffic =
            incoming_traffic(graph, vertex->node_name);

        if (traffic > maximum)
        {
            maximum = traffic;
            best = vertex;
        }

        vertex = vertex->next;
    }

    return best;
}

TopCommunicationLink get_top_communication_link(Graph *graph)
{
    TopCommunicationLink top = {"", "", 0};

    if (graph == NULL)
        return top;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            if (edge->weight > top.weight)
            {
                strcpy(top.source, vertex->node_name);
                strcpy(top.destination, edge->destination);
                top.weight = edge->weight;
            }

            edge = edge->next;
        }

        vertex = vertex->next;
    }

    return top;
}

uint32_t out_degree(Graph *graph,
                    const char *node)
{
    if (graph == NULL || node == NULL)
        return 0;

    GraphVertex *vertex = find_vertex(graph, node);

    if (vertex == NULL)
        return 0;

    uint32_t degree = 0;

    GraphEdge *edge = vertex->edges;

    while (edge != NULL)
    {
        degree++;
        edge = edge->next;
    }

    return degree;
}

uint32_t in_degree(Graph *graph,
                   const char *node)
{
    if (graph == NULL || node == NULL)
        return 0;

    uint32_t degree = 0;

    GraphVertex *vertex = graph->vertices;

    while (vertex != NULL)
    {
        GraphEdge *edge = vertex->edges;

        while (edge != NULL)
        {
            if (strcmp(edge->destination, node) == 0)
            {
                degree++;
            }

            edge = edge->next;
        }

        vertex = vertex->next;
    }

    return degree;
}