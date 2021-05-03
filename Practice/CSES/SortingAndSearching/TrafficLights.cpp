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
	int x, n;
	cin >> x >> n;
	set<int> s;
	multiset<int> ans;

	s.insert(0);
	s.insert(x);
	ans.insert(x);

	while(n--){
		int pos;
		cin >> pos;
		auto it = s.upper_bound(pos);
		int r = *it;
		int l = *(--it);
		ans.erase(ans.lower_bound(r-l));
		ans.insert(r-pos);
		ans.insert(pos-l);
		s.insert(pos);
		auto res = ans.end();
		--res;
		cout << *res << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
