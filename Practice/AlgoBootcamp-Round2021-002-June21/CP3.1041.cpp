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


void solve(int n, int p, int t){
	cout << "RFP #" << t << endl;
	map<string, int> mp;

	string dummy;
	getline(cin, dummy);

	rep(i, 1, n){
		string str;
		getline(cin, str);
		mp[str] = 1;
	}

	int count_ = -1;
	string name_final;
	double val = double(1e9);

	while(p--){
		string name;

		getline(cin, name);
		double money;
		int c, cnt = 0;

		cin >> money >> c;
		getline(cin, dummy);

		while(c--){
			string s;
			getline(cin, s);
			cnt += mp[s];
		}

		if(cnt > count_ || (cnt == count_ && val > money)){
			count_ = cnt;
			val = money;
			name_final = name;
		}
	}

	cout << name_final << endl;

		cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	int n, p;
	while(cin >> n >> p){
		if (n == 0 && p == 0)
			break;
		else{
			solve(n, p, t);
			++t;
		}
			
	}
}
