#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

map<string, int> cntAns1;
map<string, int> cntAns2;
map<string, bool>visit;
string state1[100001];
string state2[100001];
int t;
int main() {

	std::ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> state1[i];
		cntAns1[state1[i]]++;

	}
	for (int i = 0; i < t; i++) {
		cin >> state2[i];
		cntAns2[state2[i]]++;

	}
	int result = 0;
	for (int i = 0; i < t; i++) {
		if (visit[state1[i]] == true)
			continue;
		visit[state1[i]] = true;
		result += min(cntAns1[state1[i]], cntAns2[state1[i]]);
	}
	for (int i = 0; i < t; i++) {
		if (visit[state2[i]] == true)
			continue;
		visit[state2[i]] = true;
		result += min(cntAns1[state2[i]], cntAns2[state2[i]]);

	}
	cout << result << endl;
}