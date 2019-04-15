#include<cstdio>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
#include<vector>
using namespace std;


int n;
map<string, int> keyarr;
string temp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (keyarr.count(temp) == 0) {
			keyarr.insert({ temp, 1 });
			
		}
		else {
			keyarr[temp]++;
		}

	}
	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		keyarr[temp]--;
		
	}
	for (auto it = keyarr.begin(); it != keyarr.end(); it++) {
		if (it->second == 0)
			continue;
		cout << it->first << endl;
	}
}