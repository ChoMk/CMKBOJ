#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string arr1;
string arr2;
int result = 987654321;
int distSize;
int main() {
	cin >> arr1;
	cin >> arr2;
	distSize = arr2.size() - arr1.size();
	for (int i = 0; i <= distSize; i++) {
		int idx = 0;
		int tempResult = 0;
		while (true) {
			if (arr1.size() == idx || arr2.size() == idx)
				break;
			if (arr1[idx] != arr2[idx+i])
				tempResult++;
			idx++;
		}
		result = min(result, tempResult);
	}
	
	printf("%d\n", result);
}