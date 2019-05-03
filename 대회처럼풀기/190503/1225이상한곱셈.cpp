#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;
string a;
string b;
long long result;
int main() {
	cin >> a;
	cin >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			result += (a[i] - '0')*(b[j] - '0');
		}
	}
	cout << result << "\n";
}