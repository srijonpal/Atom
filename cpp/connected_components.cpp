#include <bits/stdc++.h>
using namespace std;

void explore(vector<vector<int> > &adj,int u,vector<int> &visited,vector<int> &comp,int cc){
    visited[u] = 1;
    comp[u] = cc;
    for(auto i: adj[u]){
      // cout << i << endl;
      if(!visited[i]){
        explore(adj,i,visited,comp,cc);
      }
    }
}
void dfs(vector<vector<int> > &adj,int n){
  vector<int> visited(n+1,0);
  vector<int> comp(n+1,0);
  visited[0]=1;
  comp[0]=0;
  int i=1,cc=1;
  while(i<=n)
  {
    explore(adj,i,visited,comp,cc);
    cc++;
    while(visited[i]){
      i++;
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(ans,comp[i]);
  }
  cout << ans;
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
    dfs(adj,n);
    // print_graph(adj);
    return 0;
}
