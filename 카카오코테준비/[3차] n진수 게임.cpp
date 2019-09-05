#include <string>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;
map<int, string> checkMoreTen;
void init() {
	checkMoreTen[10] = "A";
	checkMoreTen[11] = "B";
	checkMoreTen[12] = "C";
	checkMoreTen[13] = "D";
	checkMoreTen[14] = "E";
	checkMoreTen[15] = "F";
}

string toNscaleConversion(int n, int curVal) {
	string conversionNumber = "";
	while (true) {
		
		if (curVal%n >= 10) {
			conversionNumber += checkMoreTen[curVal%n];
		}
		else {
			conversionNumber += to_string(curVal%n);
		}
		curVal /= n;
		if (curVal == 0)
			break;
	}
	reverse(conversionNumber.begin(), conversionNumber.end());
	return conversionNumber;
}
string totalGameStringNumber(int totalRond, int n) {
	string result = "";
	for (int i = 0; i <= totalRond; i++) {
		result += toNscaleConversion(n, i);
	}
	return result;
}
string makeSolution(string gameString, int t, int m, int p) {
	string result = "";
	for (int i = 0; i < t; i++) {
		result += gameString[i*m + p];
	}
	return result;
}
string solution(int n, int t, int m, int p) {
	init();
	string tempGameString = totalGameStringNumber(t*m, n);

	string answer = makeSolution(tempGameString, t,m,p-1);
	return answer;
}
int main() {
	solution(2, 4, 2, 1);
}