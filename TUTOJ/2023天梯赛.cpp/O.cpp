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

ll floordiv(ll a, ll b) {
	if (a >= 0 || a%b == 0) {
		return a/b;
	} else {
		return a/b-1;
	}
}

struct S {
	ll a, b, c;

	ll getStart() {
		return floordiv(a-b,2*a);
	}

	ll getScore() {
		ll x = getStart();
		return a*x*x + b*x + c;
	}
	
	bool intersect(S s) {
		return getStart()+a >= s.getStart();
	}

	S merge(S s) {
		return S{a+s.a, b+2*a*s.a+s.b, c+a*a*s.a+a*s.b+s.c};
	}
};

void run() {
	ll n;
	cin >> n;
	vi A(n);
	for (ll i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<S> B;
	for (ll a : A) {
		S as = S{1, -2*a, a*a};
		while (B.size() > 0 && B.back().intersect(as)) {
			as = B.back().merge(as);
			B.pop_back();
		}
		B.pb(as);
	}

	ll res = 0;
	for (S s : B) {
		res += s.getScore();
	}
	cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    run();
    return 0;
}