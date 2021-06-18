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

vt<int> cnt_digit(int n){
	vt<int> ans;
	while(n){
		if (n % 10)
			ans.pb(n % 10);
		n /= 10;
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vt<ll> dp(n+1, LLONG_MAX);

	dp[0] = 0;

	rep(i, 1, n){
		vt<int> digits = cnt_digit(i);
		for(auto x : digits){
			if (i >= x){
				dp[i] = min(dp[i], dp[i-x] + 1);
			}
		}
	}

	cout << dp[n] << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
