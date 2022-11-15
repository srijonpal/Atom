from collections import defaultdict
# Print Adjacency list
adj = defaultdict(list)
visited = {}

def graph(adj):
    for i in adj:
        print(i, "->", adj[i])

def dfsutil(adj, visited, u, curr):
    curr.add(u)
    for i in adj[u]:
        if i in curr:
            return False
        if visited[i] == False:
            visited[i] = True
            if dfsutil(adj, visited, i, curr) == False:
                return False
    curr.remove(u)
    return True


def dfs(adj, visited):
    for i in visited.keys():
        curr = set()
        if visited[i] == False:
            visited[i] = True
            if dfsutil(adj, visited, i, curr) == False:
                return 1
    return 0


if __name__ == '__main__':

    n, m = map(int, input().split())
    for i in range(1, n+1):
        visited[i] = False
    for i in range(m):
        a, b = map(int, input().split())
        adj[b].append(a)

print(dfs(adj, visited))
