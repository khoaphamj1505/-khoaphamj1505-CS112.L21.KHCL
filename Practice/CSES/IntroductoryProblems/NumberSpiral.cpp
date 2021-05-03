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
    ll y, x;
    cin >> x >> y;

    ll z = max(x, y);
    ll val = 1 + z*(z-1);
    if(z > x){
        if(y%2)
            val += (z-x);
        else 
            val -= (z-x);
    }else{
        if(x%2)
            val -= (z-y);
        else 
            val += (z-y);
    }
    cout << val << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	    solve();
}
