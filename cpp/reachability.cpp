#include <bits/stdc++.h>
using namespace std;

void explore(vector<vector<int> > &adj,int u,vector<int> &visited){
    visited[u] = 1;
    for(auto i: adj[u]){
      // cout << i << endl;
      if(!visited[i]){
        explore(adj,i,visited);
      }
    }
}
void dfs(vector<vector<int> > &adj,int n,int u,int v){
  vector<int> visited(n+1,0);
  visited[0]=1;
  explore(adj,u,visited);
  if(visited[v]==1)
      cout << 1;
  else
      cout << 0;
}
int main()
{
    int n,m,u,v;
    cin >> n >> m;
    vector<vector<int> > adj;
    adj.resize(n+1);
    for(int i=1;i<=m;i++){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cin >> u >> v;
    dfs(adj,n,u,v);
    // print_graph(adj);
    return 0;
}
