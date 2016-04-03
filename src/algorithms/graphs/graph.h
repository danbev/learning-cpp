#include "../datastructures/int-iterator.h"
#ifndef GRAPH
#define GRAPH
/*
 * Terminology:
 * Vertex: a point where two or more curves, lines, or edges meet. Like nodes in trees
 * Edge: a line that connects two vertices.
 * Graph: a set of vertices and a collection of edges that connect each pair of vertices.
 * Subgraph: a subset of a graph's edges
 * Connected: if there is a path from every vertex to every other vertex in the graph.
 * Path: a sequence of vertices connected by edges.
 * Cycle: a path whose first and last vertices are the same.
 * Acyclic: a graph with no cycles.
 * Tree: is an acyclic graph connected graph.
 * Forest: a disjoint set of trees. Like a group of binary trees.
 * Adjacent: if there is an edge connecting both vertices.
 * Incident: if there is an edge connecting two vertices, the edge is said to be indicent
 *           to the vertices.
 * Degree: the degree of a vertex is the number of edges incident to it.
 *
 *
 *         [vertex]     [edge]   [vertex]
 *               (a)---------------(b)
 *                +-----[path]----+
 *
 * Vertex a is adjacent to vertex b and vice versa
 * The edge connecting a-b is incident to a-b. edge = {a,b}
 * The degree of a is 1.
 *
 * Spanning tree:
 *                   Original graph
 *               (a)---------------(b)
 *                |                 |
 *                |                 |
 *               (c)---------------(d)
 *
 *                   Spanning tree
 *               (a)---------------(b)
 *                |                 |
 *                |                 |
 *               (c)               (d)
 * Contains all the vertices of the original, so it's a subgraph of a graph but
 * it cannot be cyclic so one edge has bee removed.
 * A subgraph of a graph G that contains every vertex of G and is a tree.
 *
 * Properties of trees:
 * A graph G with V vertices is a tree if G has V-1 edges an no cycles.
 * A graph G with V vertices is a tree if G has V-1 edges and is connected.
 * G is connected but removing an edge disconnects it.
 * G is acyclic but adding any edge creates a cycle.
 *
 * Bipartite: a graph whose vertices we can divide into two sets so that all
 *            edges connect a vertex in one set with a vertex in the other set.
 *
 * [V={a,b,c,d,f}]
 *               (a)---------------(b)
 *
 * [V1={a,b,c}]  (c)---------------(d)  [V2={b,d}]
 *                                /
 *               (f)-------------/
 * Any vertices that have an edge betwwen them have to go into separate subsets.
 * There is an edge between a and b so they have to be in different subsets.
 * There is an edge between c and d so they have to be in different subsets.
 * There is an edge between f and d so they have to be in different subsets.
 * V1 ∩ V2 = 0    The two set should not have any vertices in common.
 * V1 u V2 = V    The union of both sets should include all vertices.
 *
 * ∩ = intersection, all the members of both sets
 * u = union, all the members contained in either set or both
 *
 */
class Graph {
    public:
        virtual int vertices() const = 0;
        virtual int edges() const = 0;
        virtual void addEdge(int v, int w) = 0;
        virtual const IntIterator* adjacent(int v) const = 0;
};
#endif
