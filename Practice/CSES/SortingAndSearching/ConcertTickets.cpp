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
	int n, m;
	cin >> n >> m;
	set<array<int, 2>> s;
 
	rep(i, 0, n-1){
		int x;
		cin >> x;
		s.insert({x, i});
	}
 
	while(m--){
		int x;
		cin >> x;
		auto pos = s.lower_bound({x+1, 0});
		if(pos == s.begin())
			cout << -1 << endl;
		else{
			--pos;
			cout << (*pos)[0] << endl;
 
			s.erase(pos);
		}
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}