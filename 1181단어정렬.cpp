#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int n;
string temp;
vector<pair<int,string>> arr;
map<string, int> key;
int main() {
	cin >> n;
	while (n--) {
		cin >> temp;
		if (key.count(temp) == 0) {
			key[temp]++;
			arr.push_back({temp.size(), temp });
		}
			
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].second << "\n";
	}
}