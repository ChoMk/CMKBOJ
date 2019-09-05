#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> checkIDX;

void initCheckIDX() {
	for (int i = 0; i < 26; i++) {
		string temp = "A";
		temp[0] = temp[0] + i;
		checkIDX[temp] = (i + 1);
	}
}
pair<int, pair<int, int>> returnConversionIDX_nextStartIDX(string msg, int curStartIDX, int lastIDX) {
	int conversionLength = 1;
	int conversionIDX = 0;
	while (true) {
		if ((curStartIDX + conversionLength - 1  == msg.size())||checkIDX[msg.substr(curStartIDX, conversionLength)] == NULL) {
			checkIDX[msg.substr(curStartIDX, conversionLength)] = lastIDX;
			break;
		}
		else {
			conversionIDX = checkIDX[msg.substr(curStartIDX, conversionLength)];
			conversionLength++;
		}
	}
	return { conversionIDX, {curStartIDX + conversionLength - 1, lastIDX + 1 } };
}//변환된 번호, 다음 변환 시작점, 마지막 문자의 IDX
vector<int> solveProplem(string msg) {
	vector<int> result;
	int curIDX = 0;
	int lastIDX = 27;
	while (true) {
		if (curIDX == msg.size())
			break;
		pair<int, pair<int, int>> curConversionIDX_nextStartIDX = returnConversionIDX_nextStartIDX(msg, curIDX, lastIDX);
		curIDX = curConversionIDX_nextStartIDX.second.first;
		lastIDX = curConversionIDX_nextStartIDX.second.second;
		result.push_back(curConversionIDX_nextStartIDX.first);
		
	}
	return result;
}
vector<int> solution(string msg) {
	vector<int> answer;
	initCheckIDX();
	answer = solveProplem(msg);

	return answer;
}
int main(){
	solution("KAKAO");
}