#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define endl "\n"

ll solve(ll n) {
	ll ans = 0;
	ll curr = 5;
	while (curr <= n) {
		ans += n / curr;
		curr *= 5;
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}