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
#define yes "YES"
#define no "NO"
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

void solve(){
	ll ri, bi, d;
	cin >> ri >> bi >> d;
	if(d == 0){
		if(ri == bi)
			cout << yes << endl;
		else 
			cout << no << endl;
		return;
	}	
	++d;
	ll min_x = min(ri, bi);
	ll max_x = max(ri, bi);
	if((ll)min_x*d >= (ll)max_x)
		cout << yes << endl;
	else 
		cout << no << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	while(n--)
	solve();
}
