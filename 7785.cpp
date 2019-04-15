#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>

using namespace std;
int t;
string name[1000001], state;
map<string, bool> company;
map<string, bool> visit;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> name[i] >> state;
		if (state == "enter") {
			company[name[i]] = true;
		}
		else {
			company[name[i]] = false;
		}
	}
	sort(name, name+t);
	reverse(name, name+t);
	for (int i = 0; i < t; i++) {
		if (company[name[i]] == true)
		{
			if (visit[name[i]] == false) {
				cout << name[i] << "\n";
				visit[name[i]] = true;
			}
			
		}
	}

}