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
template <class T> using ordered_set = tree<T, null_type, \
less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

template <class K, class V> using ordered_map = tree<K, V, \
less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): k-th largest element (from 0)
// order_of_key(x): the number of items that strictly smaller than x

const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void solve(){
	int n, m;
	cin >> n >> m;
	vt<vt<int>> arr(n, vt<int> (m));
	vt<vt<int>> grid(n, vt<int> (m));

	rep(i, 0, n-1){
		string str;
		cin >> str;
		rep(j, 0, m - 1){
			if(str[j] == '.')
				grid[i][j] = 0;
			if(str[j] == 'R')
				grid[i][j] = 1;
			if(str[j] == 'W')
				grid[i][j] = -1;
		}
	}

	vt<vt<int>> ans(n, vt<int> (m));
	int flag = 0;

	for(auto val : {-1, 1}){
		flag = 1;
		rep(i, 0, n-1){
			int x = val;
			if(i % 2)
				x = val * -1;
			rep(j, 0, m-1){
				arr[i][j] = x;
				x *= -1;
			}
		}
		ans = arr;
		rep(i, 0, n-1){
			rep(j, 0, m-1){
				if(grid[i][j] && arr[i][j] != grid[i][j]){
					flag = 0;  break;
				}
				if (!flag)
					break;
			}

		}
		if(flag)
			break;
	}

	if(flag){
		cout << "YES" << endl;
		for(auto x : ans){
			for(auto y : x){
				if(y == 1)
					cout << 'R';
				else
					cout << 'W';
			}
			cout << endl;
		}
	}else
	cout << "NO" << endl;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test_case;
	cin >> test_case;
	while(test_case--)
	solve();
}
