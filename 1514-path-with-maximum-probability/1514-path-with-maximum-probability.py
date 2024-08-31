import math
import heapq

class Solution:
    def init(self, edges: List[List[int]], dist: List[float]):
        graph = {}
        for i, edge in enumerate(edges):
            if edge[0] not in graph:
                graph[edge[0]] = []
            graph[edge[0]].append([edge[1], dist[i]])
            
            if edge[1] not in graph:
                graph[edge[1]] = []
            graph[edge[1]].append([edge[0], dist[i]])
        return graph

    def dijkstra(self, start: int, end: int, graph: {}):
        priority = []
        nodeDist = {}

        heapq.heappush(priority, [0, start])
        nodeDist[start] = 0

        while priority:
            weight, node = heapq.heappop(priority)
            
            for nextNode, nextDist in graph[node]:
                if nextDist == 0.0:
                    continue
                nextWeight = weight - math.log(nextDist)
                if nextNode not in nodeDist or nextWeight < nodeDist[nextNode]:
                    nodeDist[nextNode] = nextWeight
                    heapq.heappush(priority, [nextWeight, nextNode])
        if end not in nodeDist:
            return 0.0
        return math.exp(-nodeDist[end])
        

    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = self.init(edges, succProb)
        if start_node not in graph:
            return 0.0
        return self.dijkstra(start_node, end_node, graph)

        