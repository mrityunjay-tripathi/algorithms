import numpy as np

class Graph:
    def __init__(self, vertex, edges):
        self.vertex = vertex
        self.edges = edges
        self.adj_matrix = np.inf*np.ones((vertex, vertex))

    '''
    Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm)
    is an algorithm for finding the shortest paths between nodes in a graph, 
    which may represent, for example, road networks. 
    It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.
    '''

    def add_edge(self, v1, v2, w):
        if v1 < self.vertex and v2 < self.vertex:
            self.adj_matrix[v1][v2] = w
            self.adj_matrix[v2][v1] = w
        else:
            print(f"Error: Vertex ({v1},{v2}) out of range.")


    def ShortestPath(self, source):
        i = 0
        vertex = source
        discovered = [source]
        while i < self.vertex - 1:
            MIN = np.inf
            idx = -1
            for j in range(self.vertex):
                if j not in discovered and MIN>self.adj_matrix[vertex][j]:
                    MIN = self.adj_matrix[vertex][j]
                    idx = j

            vertex = idx
            discovered.append(vertex)
            i+=1
        return discovered
    
    def show_adj_matrix(self):
        print(self.adj_matrix)


g = Graph(6, 7)
g.add_edge(1,3,13)
g.add_edge(1,0,1)
g.add_edge(1,5,2)
g.add_edge(0,5,9)
g.add_edge(2,5,5)
g.add_edge(2,3,7)
g.add_edge(0,4,4)
g.show_adj_matrix()    
print(g.ShortestPath(4))
