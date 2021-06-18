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
	int n, x;
	cin >> n >> x;
 
	vt<vt<int>> dp(n + 1, vt<int> (x + 1, 0));
	vt<int> a(n), b(n);
 
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
 
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
 
	rep(i, 1, n){
		rep(j, 0, x){
			dp[i][j] = dp[i-1][j];
			if (j >= a[i - 1])
				dp[i][j] = max(dp[i][j], dp[i-1][j - a[i-1]] + b[i-1]);
		}
	}
	cout << dp[n][x] << endl;
}	
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}