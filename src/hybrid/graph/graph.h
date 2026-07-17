#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

#define MAX_NODE_NAME_LENGTH 64

typedef struct GraphEdge
{
    char destination[MAX_NODE_NAME_LENGTH];

    uint32_t weight;

    struct GraphEdge *next;

} GraphEdge;

typedef struct GraphVertex
{
    char node_name[MAX_NODE_NAME_LENGTH];

    GraphEdge *edges;

    struct GraphVertex *next;

} GraphVertex;

typedef struct
{
    GraphVertex *vertices;

    uint32_t vertex_count;

    uint32_t edge_count;

} Graph;

typedef struct
{
    char source[MAX_NODE_NAME_LENGTH];
    char destination[MAX_NODE_NAME_LENGTH];
    uint32_t weight;
} TopCommunicationLink;

/* Graph Initialization */
void initialize_graph(Graph *graph);

/* Vertex Operations */
GraphVertex *find_vertex(Graph *graph,
                         const char *node);

GraphVertex *add_vertex(Graph *graph,
                        const char *node);

/* Edge Operations */

GraphEdge *find_edge(GraphVertex *vertex,
                     const char *destination);

void add_edge(Graph *graph,
              const char *source,
              const char *destination);

void print_graph(Graph *graph);

void free_graph(Graph *graph);

uint32_t total_communication_volume(Graph *graph);

GraphVertex *most_active_source(Graph *graph);

void print_graph_statistics(Graph *graph);

uint32_t incoming_traffic(Graph *graph,
                          const char *node);

GraphVertex *most_active_destination(Graph *graph);

TopCommunicationLink get_top_communication_link(Graph *graph);

uint32_t out_degree(Graph *graph,
                    const char *node);

uint32_t in_degree(Graph *graph,
                   const char *node);

#endif