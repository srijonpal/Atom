from collections import defaultdict
# +++++++++++++++++++++++++++++++++++++++
# IMPORTANT: = KOSARAJU's Algorithm
# +++++++++++++++++++++++++++++++++++++++
adj = defaultdict(list)
inv_adj = defaultdict(list)
visited = {}

def DFSUtil(v, visited):
    # Mark the current node as visited and print it
    visited[v] = True
    for i in inv_adj[v]:
        if visited[i] == False:
            DFSUtil(i, visited)

def fill(adj, visited, u, order):
    visited[u] = True
    for i in adj[u]:
        if visited[i] == False:
            fill(adj, visited, i, order)
    order.append(u)


def ssc(adj, visited):
    order = []
    for i in visited.keys():
        if visited[i] == False:
            fill(adj, visited, i, order)


    for i in visited.keys():
        visited[i] = False
    cc = 0
    while order:
        i = order.pop()
        if visited[i] == False:
            DFSUtil(i, visited)
            cc += 1
    print(cc)

if __name__ == '__main__':

    n, m = map(int, input().split())
    for i in range(1,n+1):
        visited[i] = False
    for i in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
        inv_adj[b].append(a)
ssc(adj, visited)

