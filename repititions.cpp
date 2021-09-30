#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	ll ans = 0;
	for (ll i = 0; i < s.size(); i ++) {
		ll j = i;
		while (s[j] == s[i]) {
			j ++;
		}
		ans = max(ans, j - i);
		i = j - 1;
	}
	cout << ans << endl;
	return 0;
}