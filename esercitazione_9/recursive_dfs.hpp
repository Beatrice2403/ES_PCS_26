#include <iostream>
#include "unidirected_graph.hpp"
#include "classe_LIFO.hpp"   
#include "classe_FIFO.hpp"  
#include <set>


/*Helper ricorsivo per dfs
Parametri: 
-G:grafo
-current:nodo corrente
-visited:insieme nodi già visitati
-tree:albero DFS risultante*/ 
template<typename I>
void recursive_dfs_helper(const unidirected_graph<I>& G, I current,
                           std::set<I>& visited, unidirected_graph<I>& tree) {
    /*segno il nodo corrente come visitato*/
    visited.insert(current);

    /*scorro tutti i vicini del nodo corrente*/
    for (I neighbor : G.neighbours(current)) {
        /*se il vicino non è ancora stato visitato*/
        if (visited.count(neighbor) == 0) {
            /*aggiungo l'arco all'albero DFS*/
            tree.add_edge(unidirected_edge<I>(current, neighbor));
            /*Chiamata riscorsiva:continuo la DFS dal vicino*/
            recursive_dfs_helper(G, neighbor, visited, tree);
        }
    }
}



/*DFS RICORSIVA*/ 
template<typename I>
unidirected_graph<I> recursive_dfs(
    const unidirected_graph<I>& G,
    I source)
{

    /*Albero DFS risultante*/
    unidirected_graph<I> tree;
    /*insieme nodi visitati*/
    std::set<int> visited;
    /*avvio DFS ricorsiva*/
    recursive_dfs_helper(
        G,
        source,
        visited,
        tree
    );

    return tree;
}