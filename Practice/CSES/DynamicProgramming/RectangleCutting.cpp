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
	int dp[501][501];

	memset(dp, INF, sizeof(dp));

	rep(i, 1, n)
		dp[i][1] = i-1;

	rep(j, 1, m)
		dp[1][j] = j-1;

	rep(i, 2, n){
		rep(j, 2, m)
			if (i == j)
				dp[i][j] = 0;
			else{
				rep(k, 1, i-1)
					dp[i][j] = min(dp[i][j], \
						dp[k][j] + dp[i-k][j] + 1);
				rep(k, 1, j - 1)
					dp[i][j] = min(dp[i][j], \
						dp[i][k] + dp[i][j-k] + 1);
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
