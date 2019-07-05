#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
int zeroGroup;
int oneGroup;
string arr;

int result;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr;
	
	for (int i = 0; i < arr.size(); i++) {
		
		while (true) {
			if (i == arr.size() - 1|| arr[i] != arr[i + 1]) {
				if (arr[i] == '1')
					oneGroup++;
				else
					zeroGroup++;
				break;
			}
			i++;
		}
	}
	cout << min(zeroGroup, oneGroup)<<"\n";
	return 0;
}