#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string temp;


int main() {
	cin >> temp;
	while (true) {
		if (temp.size() % 3 == 0)
			break;
		temp = "0" + temp;
	}
	for (int i = 0; i < temp.size(); i = i + 3) {
		string subtemp = temp.substr(i, 3);
		if (subtemp == "000") {
			cout << 0;
		}
		else if (subtemp == "001") {
			cout << 1;
		}
		else if (subtemp == "010") {
			cout << 2;
		}
		else if (subtemp == "011") {
			cout << 3;
		}
		else if (subtemp == "100") {
			cout << 4;
		}
		else if (subtemp == "101") {
			cout << 5;
		}
		else if (subtemp == "110") {
			cout << 6;
		}
		else if (subtemp == "111") {
			cout << 7;
		}
	}
	cout << "\n";
}