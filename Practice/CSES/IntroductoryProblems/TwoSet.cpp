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
#define NO "NO\n"
#define YES "YES\n"

void print(vt<int> arr){
    cout << sz(arr) << endl;
    for(auto x : arr)
        cout << x << " ";
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    vt<int> set1, set2;
    if(n%2 == 0){
        if((n/2)%2) {
            cout << NO;
            return;
        }
        cout << YES;
        int l = 1, r = n;
        rep(i, 1, n/2){
            if(i%2)
                set1.pb(l), set1.pb(r);
            else 
                set2.pb(l), set2.pb(r);
            ++l, --r;
        }
        print(set1);
        print(set2);
    }else{
        if(n-3 < 0 || ((n-3)/2) % 2){
            cout << NO;
            return;
        }
        cout << YES;
        set1.pb(1);
        set1.pb(2);
        set2.pb(3);

        int l = 4, r = n;
        rep(i, 1, (n-3)/2){
            if(i%2) 
                set1.pb(l), set1.pb(r);
            else 
                set2.pb(l), set2.pb(r);
            ++l, --r;
        }
        print(set1);
        print(set2);
    }

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    solve();
}
