class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.graph = []

    def addEdge(self,u,v,w):
        self.graph.append([u,v,w])
    
    def BellmanFord(self,src):
        distFromSrc = [float('Inf')]*self.v
        distFromSrc[src] = 0
        for i in range(self.v - 1) :
            for u,v,w in self.graph:
                if distFromSrc[u] != float('Inf') and distFromSrc[u] + w < distFromSrc[v]:
                    distFromSrc[v] = distFromSrc[u] + w
        for u,v,w in self.graph:
            if distFromSrc[u] != float('Inf') and distFromSrc[u] + w < distFromSrc[v]:
                print('Negative cycle')
        self.printSPT(distFromSrc)
    
    def printSPT(self,distFromSrc):
        print('VERTEX :: DISTFROMSRC')
        for i in range(self.v):
            print("%d  ::  %d"%(i,distFromSrc[i]))


g = Graph(5)
g.addEdge(0, 1, -1)
g.addEdge(0, 2, 4)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 2)
g.addEdge(1, 4, 2)
g.addEdge(3, 2, 5)
g.addEdge(3, 1, 1)
g.addEdge(4, 3, -3)
 
#Print the solution
g.BellmanFord(0)
