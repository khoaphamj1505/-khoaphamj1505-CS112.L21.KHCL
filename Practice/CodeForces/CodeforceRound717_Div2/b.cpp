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
	int n;
	cin >> n;
	vt<ll> arr(n);
	for(auto &x : arr)
		cin >> x;
	
	function<int(int, int)> dp = [&](int l, int r){
		if(l == r-1)
			return (a[l] ^ a[r]);
		
		int res1 = dp(l, r-1) ^ a[r];
		int res2 = dp(l+1, r) ^ a[l];
		return (res1)
	};
	
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
}
