#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		int temp = arr1[i] | arr2[i];
		string tempResult = "";
		for (int j = 0; j < n; j++) {
			if (temp % 2 == 1) {
				tempResult += "#";
			}
			else {
				tempResult += " ";
			}
			temp /= 2;
		}
		reverse(tempResult.begin(), tempResult.end());
		answer.push_back(tempResult);
	}
	return answer;
}



