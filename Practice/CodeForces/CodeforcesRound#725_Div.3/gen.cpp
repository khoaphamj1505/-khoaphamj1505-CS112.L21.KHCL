#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)

const int N = 1e5+1;
typedef long long ll;
typedef pair<int, int> ii;

ll rand(ll a, ll b){
	return rand() % (b-a+1) +a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));

	int t = 1;
	int n = rand(1, 5);
	int k = rand(1, 10);

	cout << t << endl;
	cout << n << " " << k << endl;
	rep(i, 1, k){
		int u = rand(1, n);
		int v = rand(1, n);
		int eq = rand(0, 1);
		cout << u << " ";
		if(eq == 1)
			cout << "= ";
		else 
			cout << "!= ";
		cout << v << endl;
	}

}
