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

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	ll currSum = INT_MIN;
	ll maxSum = INT_MIN;

	for (int i = 0; i < n; i ++) {
		currSum = max(currSum + v[i], v[i]);
		maxSum = max(maxSum, currSum);
	}

	cout << maxSum << endl;
	return 0;
}