from collections import defaultdict
# Print Adjacency list
# def graph(adj):
#     for i in adj:
#         print(i, "->", adj[i])

def dfsutil(adj,visited,u):
	visited[u] = True
	for i in adj[u]:
		if visited[i] == False:
			dfsutil(adj,visited,i)

def dfs(adj,visited):
    cc = 0
    for i in visited:
        if visited[i] == False:
            cc +=1
            dfsutil(adj,visited,i)
    print(cc)




n,m = map(int,input().split())
adj = defaultdict(list)
visited = {}
for i in range(1,n+1):
    visited[i] = False
for i in range(m):
	a,b = map(int,input().split())
	adj[a].append(b)
	adj[b].append(a)

dfs(adj,visited)
