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
	string a, b;
	cin >> a >> b;
	int n = sz(a);
	int m = sz(b);

	vt<vt<ll>> dp(n + 1, vt<ll> (m + 1, INF));

	rep(i, 0, n){
 		dp[i][0] = i;
	}

	rep(j, 0, m)
		dp[0][j] = j;

	rep(i, 1, n){
		rep(j, 1, m)
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = min({dp[i-1][j], \
					dp[i][j-1], \
					dp[i-1][j-1]}) + 1;

			}
	}
	cout << dp[n][m] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
