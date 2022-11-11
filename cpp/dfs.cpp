#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int> > &adj){
      for( int i = 1; i <= adj.size() ; i++ ){
          for( int j = 0 ; j < adj[i].size(); j++){
              cout << adj[i][j] << " ";
          }
          cout<<endl;
      }
}

void dfs(vector<vector<int> > &adj,int u,vector<int> &visited){

    for(auto i: adj[u]){
      // cout << i << endl;
      if(!visited[i]){
        visited[i] = 1;
        dfs(adj,i,visited);
      }
    }
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
    vector<int> visited(n+1,0);
    visited[u]=1;
    dfs(adj,u,visited);
    if(visited[v]==1)
        cout << 1;
    else
        cout << 0;
    // print_graph(adj);
    return 0;
}
