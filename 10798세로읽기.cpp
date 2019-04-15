#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<string> arr;
string temp;
int maxLen = -1;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		arr.push_back(temp);
		maxLen = max(maxLen, (int)temp.size());
	}
	for (int i = 0; i < maxLen; i++) {
		for (int j = 0; j < 5; j++) {
			
			if (i >= arr[j].size())
				continue;
			cout << arr[j][i];
			
		}
		
	}
	cout << "\n";
}