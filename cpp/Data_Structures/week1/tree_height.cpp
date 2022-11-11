#include <bits/stdc++.h>
using namespace std;

int rec(int i, int p[], vector<int> h)
{
	if (p[i] == -1) {
		return 1;
	}

	if (h[i] != -1) {
		return h[i];
	}

	h[i] = rec(p[i], p, h) + 1;

  	return h[i];
}

int findHeight(int* parent, int n)
{
	int res = 0;

	vector<int> height(n, -1);

	for (int i = 0; i < n; i++) {
		res = max(res, rec(i, parent, height));
	}

	return res;
}

// Driver program
int main()
{
int n,tmp;
cin >> n;
int parent[n];
for (int i=0; i<n; i++){
  cin >> parent[i] ;
}
int height = findHeight(parent, n);
cout << height << endl;

return 0;
}
