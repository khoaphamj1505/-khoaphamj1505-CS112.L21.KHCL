#include <bits/stdc++.h>

using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)
#define dbg(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";
#define fi first 
#define sec second

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

// di = max(a1, a2, .. ai) - min(a1, a2, ... ai)

// minimize S = (d1 + d2 + d3 + ... + dn)
// dn = max(ai) - min(ai) 
// S = dn + minimize Si = (d1 + d2 + d3 + ... + d(n-1))

void solve(){
	int n; cin >> n;
	vt<ll> arr(n);
	for(auto &x : arr)
		cin >> x;
	sort(all(arr));
	vt<vt<ll>> mem(n, vt<ll> (n, -1));
	function<ll(int, int)> dp = [&](int l, int r){
		if(l >= r)
			return 0ll;
		if(mem[l][r] != -1)
			return mem[l][r];
		return mem[l][r] = arr[r] - arr[l] + min(dp(l+1, r), dp(l, r-1));
	};
	cout << dp(0, n-1) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
