#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, m;
	cout << "Enter number of nodes in graph: ";
	cin >> N;
	cout << "Enter of number of edges in graph: ";
	cin >> n;
	
	vector<pair<int, int>> adj[N];

	int a, b, wt;
	for(int i = 0 ; i < m ; i++) {
		cout << "Enter the two adjacent nodes";
		cout << " and weight between them";
		cin >> a >> b >> wt;
	}
	// Taking input ends here
	// The adjacency matrix is complete

	int parent[N];
	int key[N];
	bool mstSet[N];

	for(int i = 0 ; i < N ; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}

	key[0] = 0;
	parent[0] = -1;

	for(int count = 0 ; count < N - 1 ; count++)
}