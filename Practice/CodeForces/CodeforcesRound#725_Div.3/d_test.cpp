#include <bits/stdc++.h>

// #pragma GCC optimize("O3")

#define Size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

// #define int long long

using namespace std;

vector<int> f(int n) {
	vector<int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n > 1)
		res.push_back(n);
	return res;
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	if (k == 1) {
		cout << ((a % b == 0 || b % a == 0) && a != b ? "YES\n" : "NO\n");
		return;
	}
	vector<int> fa = f(a), fb = f(b);
	int ans = Size(fa) + Size(fb);	

	cout << (k <= ans ? "YES\n" : "NO\n");
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	#ifdef TEST
		freopen("test.txt", "r", stdin);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}