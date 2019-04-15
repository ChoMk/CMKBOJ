#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int n;
string temp;
vector<pair<int, pair<int, string>>> arr;
int age;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> temp;
		arr.push_back({ age, {i, temp} });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].first << " " << arr[i].second.second << "\n";
	}
}