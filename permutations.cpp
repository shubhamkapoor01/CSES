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

	ll n;
	cin >> n;
	if (n <= 3 && n > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	vector<ll> even;
	vector<ll> odd;

	for (ll i = 1; i <= n; i += 2)
		odd.push_back(i);
	for (ll i = 2; i <= n; i += 2)
		even.push_back(i);

	for (ll i = 0; i < even.size(); i ++) 
		cout << even[i] << " ";
	for (ll i = 0; i < odd.size(); i ++) 
		cout << odd[i] << " ";	
	return 0;
}