#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string arr;
int result = 1;

int main() {
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 'A') {
			if (result == 1) {
				result = 2;
			}
			else if (result == 2) {
				result = 1;
			}
		}
		else if (arr[i] == 'B') {
			if (result == 2) {
				result = 3;
			}
			else if(result == 3){
				result = 2;
			}

		}
		else {
			if (result == 1) {
				result = 3;
			}
			else if (result == 3) {
				result = 1;
			}
		}
	}
	cout << result << "\n";
}