#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const ld PI = acos((ld) -1);

void run() {
	ll n, l;
	cin >> n >> l;
	vector<string> A(n);
	for (ll i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(all(A));
	vi R(n, 1);
	for (ll i = 0; i < n-1; i++) {
		for (ll r = 1; A[i][r-1] == A[i+1][r-1]; r++, R[i]=max(R[i],r), R[i+1]=max(R[i+1],r)) {}
	}
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		res += R[i];
	}
	cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    run();
    return 0;
}