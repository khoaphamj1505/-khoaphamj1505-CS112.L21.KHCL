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

char cnv1(int x){
	if (x < 10)
		return char('0' + x);
	if(x == 10)
		return 'T';
	if(x == 11)
		return 'J';
	if(x == 12)
		return 'Q';
	if(x == 13)
		return 'K';
	return 'A';
}

char cnv2(int x){
	if(x == 4)
		return 'C';
	if(x == 3)
		return 'B';

	if(x == 2)
		return 'R';
	return 'N';

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));

	int n = rand(1, 10);

	cout << n << endl;
	rep(i, 1, n)
		cout << rand(1, int(1e8)) <<" ";

	cout << endl;

	n = rand(1, 10);
	cout << n << endl;
	rep(i, 1, n)
		cout << rand(1, int(1e8)) <<" ";

	cout << endl;
}
