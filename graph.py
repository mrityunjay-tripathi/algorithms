import numpy as np
import queue


class Graph:
    def __init__(self, vertex, edges):
        self.vertex = vertex
        self.edges = edges
        self.adj_matrix = np.zeros((vertex, vertex))
    
    def add_edge(self, v1, v2):
        if v1 < self.vertex and v2 < self.vertex:
            self.adj_matrix[v1][v2] = 1
            self.adj_matrix[v2][v1] = 1
        else:
            print(f"Error: Vertex ({v1},{v2}) out of range.")
    
    '''
    procedure DFS-iterative(G,v):
        let S be a stack
        S.push(v)
        while S is not empty
            v = S.pop()
            if v is not labeled as discovered:
                label v as discovered
                for all edges from v to w in G.adjacentEdges(v) do 
                    S.push(w)
    '''

    def DFS(self, v):
        S = []
        S.append(v)
        discovered = []
        while S:
            v = S.pop()
            if v not in discovered:
                discovered.append(v)
                for i in range(self.vertex):
                    if self.adj_matrix[v][i]==1:
                        S.append(i)
        return discovered

    '''
    procedure BFS(G,start_v):
        let Q be a queue
        label start_v as discovered
        Q.enqueue(start_v)
        while Q is not empty
            v = Q.dequeue()
            if v is the goal:
                return v
            for all edges from v to w in G.adjacentEdges(v) do
                if w is not labeled as discovered:
                    label w as discovered
                    w.parent = v
                    Q.enqueue(w) 
    '''

    def BFS(self, v):
        Q = []
        discovered = [v]
        Q.append(v)
        while Q:
            v = Q.pop(0)
            for i in range(self.vertex):
                if i not in discovered:
                    discovered.append(i)
                    Q.append(i)
        return discovered

    def show_adj_matrix(self):
        print(self.adj_matrix)


g = Graph(5,4)
g.add_edge(0,3)
g.add_edge(0,4)
g.add_edge(1,3)
g.add_edge(2,4)
dfs = g.DFS(0)
bfs = g.BFS(0)
print("Depth First Search :", dfs)
print("Breadth First Search :", bfs)