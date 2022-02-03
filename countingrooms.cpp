#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


void dfs(vector<vector<char>>& v, int i, int j) {
	if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size()) return;
	if (v[i][j] == '#') return;
	
	v[i][j] = '#';
	dfs(v, i + 1, j);
	dfs(v, i - 1, j);
	dfs(v, i, j + 1);
	dfs(v, i, j - 1);
	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char> (m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> v[i][j];
		}
	}

	ll rooms = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (v[i][j] == '.') {
				dfs(v, i, j);
				rooms ++;
			}
		}
	}

	cout << rooms << endl;
	return 0;
}