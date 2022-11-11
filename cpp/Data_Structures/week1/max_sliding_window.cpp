#include<bits/stdc++.h>
using namespace std;

int window_slide(vector<int> ar, int k){
  deque < int> q(k);
  int i;
  for (i = 0;i < k; i++){
    while(!q.empty() && ar[i] >= ar[q.back()]){
      q.pop_back();
    }
      q.push_back(i);
  }

  for (;i < ar.size(); i++){

    cout << ar[q.front()] << " ";
    if(!q.empty() && q.front() <= i-k){
      q.pop_front();
    }
    while(!q.empty() && ar[i] >= ar[q.back()]){
      q.pop_back();
    }
      q.push_back(i);
  }

  cout << ar[q.front()] <<endl;
  return 0;
}

int main(){

int n,tmp,k;
vector <int> ar;
cin >> n;
for (int i=0; i<n; i++){
  cin >> tmp;
  ar.push_back(tmp);
}
cin >> k;
window_slide(ar,k);
return 0;
}
