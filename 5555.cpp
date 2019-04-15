#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string cmpString;
string tempS;
int n;
int result;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> cmpString;
	cin >> n;
	while (n--) {
		cin >> tempS;
		for (int i = 0; i < tempS.size(); i++) {
			int sw = 0;
			for (int j = i; j < i + cmpString.size(); j++) {
				if (tempS[j%tempS.size()] != cmpString[j-i])
				{
					sw = 1;
					break;
				}
			}
			if (sw == 0) {
				result++;
				break;
			}
		}
	}
	printf("%d\n", result);
}