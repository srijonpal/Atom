from collections import defaultdict
# comments added
def graph(adj):
    for i in adj:
        print(i, "->", adj[i])
n,e = map(int,input().split())
adj = defaultdict(list)
for i in range(e):
	a,b = map(str,input().split())
	adj[a].append(b)
	adj[b].append(a)

graph(adj)
