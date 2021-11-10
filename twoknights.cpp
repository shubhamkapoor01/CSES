#include <bits/stdc++.h>
using namespace std;
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

	ll n, f = 1;
	ll k = 1;
	cin >> n;

	if(n >= 1) cout << 0 << endl;
	if(n >= 2) cout << 6 << endl;
	//if(n >= 3) cout << 28 << endl;
	if(n < 3) return 0; 
	for(int i = 3; i <= n; i++) {
	    ll j = i * i;
		f = j;
		f *= (j - 1);
		f /= 2;
        //cout << f << " " ;
		k = 8;
		k += 6 * ((i - 2) * 2 - 2);
		k += 4 * (i - 3) * (i - 3);
        //cout << k << " " ;
		cout << f - k << endl;

	}
}