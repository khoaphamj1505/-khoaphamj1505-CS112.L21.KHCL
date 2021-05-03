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
const ll INF = 1e9+7;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

ll pow_mod(ll val, ll p){
    if(p == 0)
        return 1;
    if(p == 1)
        return val % INF;
    ll res = pow_mod(val, p/2);
    res = ((res * res)% INF * pow_mod(val, p%2))%INF;
    return res;
}

void solve(){
    ll n;
    cin >> n;
    cout << pow_mod(2ll, n) << endl; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
