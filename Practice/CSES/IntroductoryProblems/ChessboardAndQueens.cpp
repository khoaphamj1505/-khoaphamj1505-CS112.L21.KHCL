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
	string b[8];
	rep(i, 0, 7)
		cin >> b[i];
	vt<int> pos(8, 0);
	iota(all(pos), 0);	
	int ans = 0;

	do{
		ll ok = 1;
		
		rep(i, 0, 7)
			ok = (ok & (b[i][pos[i]] != '*'));

		vt<int> check(15, 0);
		rep(i, 0, 7)
			if(check[i+pos[i]])
				ok = 0;
			else 
				check[i+pos[i]] = 1;

		rep(i, 0, 15)
			check[i] = 0;

		rep(i, 0, 7)
			if(check[i-pos[i]+7])
				ok = 0;
			else check[i - pos[i]+7] = 1;

		if(ok){
			++ans;
		}

	}while(next_permutation(all(pos)));
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
