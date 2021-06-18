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


void solve(){
	int n, m;
	cin >> n >> m;

	vt<ll> arr(n);
	for(auto &x : arr)
		cin >> x;

	vt<ll> dp(m+1, LLONG_MAX);

	dp[0] = 0ll;
	rep(val, 1, m){
		for(auto x : arr)
			if(val >= x && dp[val - x] != LLONG_MAX)
				dp[val] = min(dp[val], dp[val - x] + 1);
	}

	if (dp[m] == LLONG_MAX )
		cout << -1 << endl;
	else
		cout << dp[m] << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
