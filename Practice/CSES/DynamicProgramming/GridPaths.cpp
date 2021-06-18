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
const int N = 1001;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/


void solve(){
	int n;
	cin >> n;

	vt<vt<ll>> dp(n+1, vt<ll> (n+1, 0));
	vt<string> a(n);

	rep(i, 0, n-1)
		cin >> a[i];

	if(a[0][0] != '*')
		dp[1][1] = 1;

	rep(i, 1, n){
		rep(j, 1, n)
			if (a[i-1][j-1] != '*')
				dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % INF;
	}

	cout << dp[n][n] << endl;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
