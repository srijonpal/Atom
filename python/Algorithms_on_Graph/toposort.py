from collections import defaultdict
# Print Adjacency list
adj = defaultdict(list)
visited = {}

def graph(adj):
    for i in adj:
        print(i, "->", adj[i])


def dfsutil(adj, visited, u, curr):
    visited[u] = True
    for i in adj[u]:
        if visited[i] == False:
            dfsutil(adj, visited, i, curr)
            # curr.append(i)
    curr.append(u)


def dfs(adj, visited):
    curr = []
    for i in visited.keys():
        if visited[i] == False:
            dfsutil(adj, visited, i, curr)
    print(curr)


if __name__ == '__main__':

    n, m = map(int, input().split())
    for i in range(1, n+1):
        visited[i] = False
    for i in range(m):
        a, b = map(int, input().split())
        adj[b].append(a)
dfs(adj, visited)
