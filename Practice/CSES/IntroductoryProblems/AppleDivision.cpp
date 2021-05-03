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
	vt<int> arr(n);
	for(auto &x : arr)
		cin >> x;
	ll min_val = LLONG_MAX;
	rep(state, 0, (1<<n)-1){
		ll sum1 =0 ;
		ll sum2 = 0 ;
		rep(i, 0, n-1){
			if((state >> i) & 1)
				sum1 += arr[i];
			else
				sum2 += arr[i];
		}
		min_val = min(min_val, abs(sum1 - sum2));
	}	
	cout << min_val << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	cout.tie(0);
}
