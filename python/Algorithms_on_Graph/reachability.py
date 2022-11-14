from collections import defaultdict
# Print Adjacency list
# def graph(adj):
#     for i in adj:
#         print(i, "->", adj[i])

def dfsutil(adj,visited,u):
	visited.add(u)
	for i in adj[u]:
		if i not in visited:
			dfsutil(adj,visited,i)

def dfs(adj,visited,u,v):
	dfsutil(adj,visited,u)
	if v in visited:
		print('1')
	else:
		print('0')


n,m = map(int,input().split())
adj = defaultdict(list)
visited = set()
for i in range(m):
	a,b = map(int,input().split())
	adj[a].append(b)
	adj[b].append(a)
u,v = map(int,input().split())

dfs(adj,visited,u,v)
