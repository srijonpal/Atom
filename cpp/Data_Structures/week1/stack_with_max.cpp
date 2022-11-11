#include<bits/stdc++.h>
using namespace std;

int main(){

  int num_queries = 0;
  cin >> num_queries;
  int m = -1;
  stack <int> s;
  stack <int> max_s;

  string query;
  string value;

  for (int i = 0; i < num_queries; ++i) {
      cin >> query;
      if (query == "push") {
          cin >> value;
          s.push(stoi(value));
          m = max(m,stoi(value) );
          max_s.push(m);
      }
      else if (query == "pop") {
          s.pop();
          max_s.pop();
      }
      else if (query == "max") {
          cout << max_s.top() << "\n";
      }
      else {
      }
  }
return 0;
}
