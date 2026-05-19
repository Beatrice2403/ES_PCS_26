#include <iostream>
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "classe_FIFO.hpp"
#include "classe_LIFO.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "to_dot.hpp"

int main() {

    unidirected_graph<int> G;

    /*Creo il grafo con 10 nodi*/ 
    G.add_edge(unidirected_edge<int>(1, 2));
    G.add_edge(unidirected_edge<int>(1, 5));
    G.add_edge(unidirected_edge<int>(1, 9));
    G.add_edge(unidirected_edge<int>(2, 3));
    G.add_edge(unidirected_edge<int>(2, 7));
    G.add_edge(unidirected_edge<int>(3, 4));
    G.add_edge(unidirected_edge<int>(3, 8));
    G.add_edge(unidirected_edge<int>(4, 5));
    G.add_edge(unidirected_edge<int>(4, 10));
    G.add_edge(unidirected_edge<int>(5, 6));
    G.add_edge(unidirected_edge<int>(6, 7));
    G.add_edge(unidirected_edge<int>(6, 10));
    G.add_edge(unidirected_edge<int>(7, 8));
    G.add_edge(unidirected_edge<int>(7, 1));
    G.add_edge(unidirected_edge<int>(8, 9));
    G.add_edge(unidirected_edge<int>(8, 2));
    G.add_edge(unidirected_edge<int>(9, 10));
    G.add_edge(unidirected_edge<int>(9, 4));
    G.add_edge(unidirected_edge<int>(10, 3));

    /*BFS*/ 
    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    to_dot(bfsG, "bfs.dot");

    /*DFS iterativo*/
    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    to_dot(dfsG, "dfs_iterativo.dot");

    /*DFS ricorsivo*/ 
    auto rdfsG = recursive_dfs(G, 1);
    to_dot(rdfsG, "dfs_ricorsivo.dot");

    return 0;
}