#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string temp;
int pickR =1;
int pickC;
int tempR =1;
char result[101][101];
int main() {
	cin >> temp;
	while (true) {
		if (temp.size()/tempR < tempR)
			break;
		if ((temp.size() % tempR) == 0)
			pickR = tempR;
			
		tempR++;
	}
	pickC = temp.size() / pickR;
	int stringcnt = 0;
	for (int i = 0; i < pickC; i++) {
		for (int j = 0; j < pickR; j++) {
			result[i][j] = temp[stringcnt];
			stringcnt++;
		}
	}
	for (int i = 0; i < pickR; i++) {
		for (int j = 0; j < pickC; j++) {
			cout << result[j][i];
		}
	}
	cout << "\n";
}