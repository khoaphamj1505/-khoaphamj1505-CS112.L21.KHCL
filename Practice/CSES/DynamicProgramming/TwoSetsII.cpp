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

ll p(ll x){
	if (x == 0)
		return 1;
	if (x == 1) 
		return 2;
	ll res = p(x /2);
	res = (res * res) % INF;
	if (x % 2)
		res = (res * 2) % INF;
	return res;
};

void solve(){
	int n;
	cin >> n;
	ll sum = (n+1)*n/2;
	if (sum % 2){
		cout << 0 << endl;
		return;
	}else{
		sum /= 2;
		vt<ll> dp(sum + 1, 0);
		dp[0] = 1;

		rep(i, 1, n){
			down(j, sum, 0){
				if(j - i >= 0)
					(dp[j] += dp[j-i])%=INF;
			}
		}
		// dbg(sum) endln
		cout << (dp[sum] * p(INF-2))% INF << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
