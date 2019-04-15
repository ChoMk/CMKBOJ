#include<queue>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int n;
queue<string> q;
map<string, int> check;
string temp;
int result;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push(temp);
		check.insert({ temp, 1 });
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (check[temp] == 1) {
			string preTemp = q.front();
			while (true) {
				if (q.size() == 0 || check[preTemp] != 0)
					break;
				q.pop();
				preTemp = q.front();
			}
			if (preTemp == temp) {
				check[temp]--;
				q.pop();
			}
			else {
				check[temp]--;
				result++;
			}
		}
	}
	cout << result << "\n";
}