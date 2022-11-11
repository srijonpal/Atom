#include<bits/stdc++.h>
using namespace std;

int main(){
int s, n, temp1,temp2;
vector <int > arr;
vector <int > pro;
cin >> s >> n;

for(int i = 0; i < n; i++){
  cin >> temp1 >> temp2;
  arr.push_back(temp1);
  pro.push_back(temp2);
}
vector<int> res;
deque <int> time;
for(int i = 0; i < n; i++){

  while (!time.empty() && time.front() <= arr[i]) {
    time.pop_front();
  }
  if(!time.empty() && time.size() < s){
    res.push_back(time.back());
    time.push_back(pro[i]+time.back());
  }
  else if(time.empty()){
    res.push_back(arr[i]);
    time.push_back(arr[i] + pro[i]);
  }
  else if(time.size() == s){
    res.push_back(-1);
  }
}
  for(int i = 0; i < n; i++){
    cout << res[i] <<"\n";
  }
  return 0;
}
