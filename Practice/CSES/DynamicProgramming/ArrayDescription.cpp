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
const ll INF = 1e9+7;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/


void solve(){
	int n, m;
	cin >> n >> m;
	vt<vt<ll>> dp(n+1, vt<ll> (m + 1, 0));

	int x;
	cin >> x;
	if(x == 0)
		dp[1] = vt<ll> (m+1, 1);
	else
		dp[1][x] = 1;

	rep(i, 2, n){
		cin >> x;
		if (x == 0){
			rep(k, 1, m)
				for(auto j : {k-1, k, k+1})
					if(1 <= j && j <= m)
						(dp[i][k] += dp[i-1][j]) %= INF;
		}else{
			for(auto j : {x-1, x, x+1})
				if (1 <= j && j <= m)
					(dp[i][x] += dp[i-1][j]) %= INF;
		}
	}

	ll ans = 0;
	rep(i, 1, m){
		(ans += dp[n][i]) %= INF;
	}

	cout << ans << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
