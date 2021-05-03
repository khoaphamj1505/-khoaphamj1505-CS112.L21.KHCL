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
	ll n;
	cin >> n;
	rep(state, 0, (1<<n)-1){
		
		ll val = (state ^ (state >> 1));
		// state 	: 1001
		// state shl: 0100
		// xor 		: 1101
		
		// state 	: 1010
		// state shl: 0101
		// xor 		: 1111
		 
		down(i, n-1, 0){
			cout << ((val >> i) & 1) ;
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
