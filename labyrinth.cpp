#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	ll r, c, x, y;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char> (m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> v[i][j];
			if (v[i][j] == 'A') {
				r = i;
				c = j;
			}
			if (v[i][j] == 'B') {
				x = i;
				y = j;
			}
		}
	}

	vector<vector<bool>> vis(n, vector<bool> (m, false));
	vector<vector<char>> from(n, vector<char> (m, ' '));
	queue<pair<ll, ll>> q;
	q.push({r, c});
	vis[r][c] = true;

	while (!q.empty()) {
		ll i = q.front().ff;
		ll j = q.front().ss;
		q.pop();

		if (i - 1 >= 0 && !vis[i - 1][j] && v[i - 1][j] != '#') {
			q.push({i - 1, j});
			from[i - 1][j] = 'D';
			vis[i - 1][j] = true;
		}

		if (j - 1 >= 0 && !vis[i][j - 1] && v[i][j - 1] != '#') {
			q.push({i, j - 1});
			from[i][j - 1] = 'R';
			vis[i][j - 1] = true;
		}
		if (i + 1 < n && !vis[i + 1][j] && v[i + 1][j] != '#') {
			q.push({i + 1, j});
			from[i + 1][j] = 'U';
			vis[i + 1][j] = true;
		}
		if (j + 1 < m && !vis[i][j + 1] && v[i][j + 1] != '#') {
			q.push({i, j + 1});
			from[i][j + 1] = 'L';
			vis[i][j + 1] = true;
		}
	}

	if (from[x][y] == ' ') {
		cout << "NO" << endl;
		return 0;
	}

	string path;
	while (true) {
		if (from[x][y] == 'D') path.pb('U');
		else if (from[x][y] == 'U') path.pb('D');
		else if (from[x][y] == 'L') path.pb('R');
		else if (from[x][y] == 'R') path.pb('L');

		if (x == r && y == c) break;

		if (from[x][y] == 'D') x ++;
		else if (from[x][y] == 'R') y ++;
		else if (from[x][y] == 'U') x --;
		else if (from[x][y] == 'L') y --;
	}
	
	reverse(path.begin(), path.end());
	cout << "YES" << endl;
	cout << path.size() << endl;
	cout << path << endl;
	return 0;
}
