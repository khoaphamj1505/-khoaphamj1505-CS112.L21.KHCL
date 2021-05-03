#include <bits/stdc++.h>

using namespace std;

string solve(string str){
	unordered_map<char, int> m;
	for(auto x : str)
		++m[x];
	
	int count_odd = 0;
	char odd_char = ' ';
	for(auto x : m)
		if(x.second % 2){
			++count_odd;
			odd_char = x.first;
		}
		
	if(count_odd > 1)
		return "NO SOLUTION";
		
	string firstHalf;
	for(auto x : m){
		string s(x.second/2, x.first);
		firstHalf = s + firstHalf;
	}
	
	string secondHalf = firstHalf;
	reverse(secondHalf.begin(), secondHalf.end());
	
	if(count_odd)
		firstHalf = firstHalf + odd_char + secondHalf;
	else 
		firstHalf = firstHalf + secondHalf;
	return firstHalf;
	
}
int main(){
	string s;
	cin >> s;
	cout << solve(s) << endl;
}
