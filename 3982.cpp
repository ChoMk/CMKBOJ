#include<iostream>
#include<map>
#include<string>

using namespace std;

int n;
map<string, int> teamState;
map<string, bool> visit;
string teamList[40];
string temp1, temp2;
int g1, g2;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		teamState.clear();
		visit.clear();
		for (int i = 0; i < 32; i=i+2) {
			cin >> temp1 >> temp2 >> g1 >> g2;
			if (g1 > g2) {
				if (teamState[temp1] == 0) {
					teamState[temp1] = 1;
				}
				teamState[temp2] = 2;
			}
			else {
				if (teamState[temp2] == 0) {
					teamState[temp2] = 1;
				}
				teamState[temp1] = 2;

			}
			teamList[i] = temp1;
			teamList[i + 1] = temp2;
		}

		for (int i = 0; i < 32; i++) {
			if (visit[teamList[i]] == true)
				continue;
			visit[teamList[i]] = true;
			if (teamState[teamList[i]] == 1)
			{
				cout << teamList[i] << endl;
				break;
			}
		}
	}

}