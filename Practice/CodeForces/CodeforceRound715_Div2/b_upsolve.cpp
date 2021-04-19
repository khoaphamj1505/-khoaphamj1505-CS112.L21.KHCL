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
#define NO "NO"
#define YES "YES"

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int T = 0, M = 0;
    for(auto x : s){
        if(x == 'T')
            ++T;
        else{
			++M;
			if(M > T){
				cout << NO << endl;
				return;
			}
        }
    }
    if(T != M*2){
		cout << NO <<endl;
		return;
	}
    T = M = 0;
    down(i, sz(s)-1, 0){
		//dbg(i) dbg(s[i]) endln
		if(s[i] == 'T')
			++T;
		else{
			++M;
			if(M > T){
				cout << NO << endl;
				return;
			}
		}
	}
	cout << YES << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t; cin >> t;
    while(t--)
	solve();
	
}
