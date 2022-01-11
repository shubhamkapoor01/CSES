#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(vector<vector<char>> grid, ll i, ll j, vector<vector<ll>> &dp) {
	if (i >= 7 || j >= 7 || i < 0 || j < 0) {
		return 0;
	}

	if (i == 6 && j == 0) {
		return 1;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	dp[i][j] = 0;

	if (grid[i][j] == 'U') {
		dp[i][j] = solve(grid, i - 1, j, dp);
	
	} else if (grid[i][j] == 'D') {
		dp[i][j] = solve(grid, i + 1, j, dp);
		
	} else if (grid[i][j] == 'L') {
		dp[i][j] = solve(grid, i, j - 1, dp);
		
	} else if (grid[i][j] == 'R') {
		dp[i][j] = solve(grid, i, j + 1, dp);
	
	} else if (grid[i][j] == '?') {
		dp[i][j] += solve(grid, i + 1, j, dp);
		dp[i][j] += solve(grid, i - 1, j, dp);
		dp[i][j] += solve(grid, i, j + 1, dp);
		dp[i][j] += solve(grid, i, j - 1, dp);
	}

	return dp[i][j];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	ll cnt = 0;
	ll ans = 0;

	vector<vector<char>> grid(7, vector<char> (7));
	vector<vector<ll>> dp(7, vector<ll> (7, -1));

	for (ll i = 0; i < 7; i ++) {
		for (ll j = 0; j < 7; j ++) {
			if (i == 6 && j == 0) {
				continue;
			}
			grid[i][j] = s[cnt];
			cnt ++;
		}
	}

	cout << solve(grid, 0, 0, dp) << endl;
	return 0;
}