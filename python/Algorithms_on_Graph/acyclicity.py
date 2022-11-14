from collections import defaultdict
# Print Adjacency list
adj = defaultdict(list)
visited = {}


def dfsutil(adj, visited, u, curr):
    curr.add(u)
    visited[u] = True
    for i in adj[u]:
        if i in curr:
            return 0
        else:
            if visited[i] == False:
                return dfsutil(adj, visited, i, curr)
    return 1


def dfs(adj, visited):
    for i in visited.keys():
        curr = set()
        if visited[i] == False:
            if dfsutil(adj, visited, i, curr) == 0:
                return 1
    return 0


if __name__ == '__main__':

    n, m = map(int, input().split())
    for i in range(1, n+1):
        visited[i] = False
    for i in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)

print(dfs(adj, visited))
