#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int,null_type,less<int>,rb_tree_tag, \
tree_order_statistics_node_update> indexed_set;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

void solve(){
	int n, k;
	indexed_set s;

	cin >> n >> k;
	rep(i, 1, n){
		s.insert(i);
	}

	int index = k%n;
	while(n--){
		auto pos = s.find_by_order(index);
		cout << *pos << " " ;
		s.erase(pos);
		if(n>0)
		index = (index%n + k%n)%n;
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
