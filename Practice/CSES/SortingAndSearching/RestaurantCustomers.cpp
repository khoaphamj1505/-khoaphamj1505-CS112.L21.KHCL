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
 
	set<array<int, 2>> s;
	rep(i, 1, n){
		int x, y;
		cin >> x >> y;
		s.insert({x, 1});
		s.insert({y+1, -1});
	}	
	int ans = 0;
	int cnt = 0;
	for(auto &x : s){
		cnt += x[1];
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}