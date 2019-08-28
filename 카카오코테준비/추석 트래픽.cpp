#include <string>
#include <vector>
#include<algorithm>
#include<map>

using namespace std;
int n;
int startTime[20001][8];
int endTime[20001][8];//id, 년, 월, 일, 시, 분, 초, 밀리초
int startSecTime[20001];
int endSecTime[20001];
int sec[20001][2];//초, 밀리초

int cnt[2][25][61][61][1001];//0 == 14, 1 == 15(일)
int curTime[8];



void parseDay(vector<string> lines) {
	for (int i = 0; i < lines.size(); i++) {
		endTime[i][2] = stoi(lines[i].substr(8, 2));
		endTime[i][3] = stoi(lines[i].substr(11, 2));
		endTime[i][4] = stoi(lines[i].substr(14, 2));
		endTime[i][5] = stoi(lines[i].substr(17, 2));
		endTime[i][6] = stoi(lines[i].substr(20, 3));
		
		string tempSec = lines[i].substr(24, lines[i].size() - 24);
		int dotIDX = -1;//점이 없으면 -1
		for (int j = 0; j < tempSec.size(); j++) {
			if (tempSec[j] == '.') {
				dotIDX = j;
				break;
			}
		}
		if (dotIDX == -1) {
			sec[i][0] = stoi(tempSec.substr(0, tempSec.size() - 1));
		}
		else {
			sec[i][0] = stoi(tempSec.substr(0, dotIDX));
			sec[i][1] = stoi(tempSec.substr(dotIDX + 1, tempSec.size() - 1 - dotIDX));
		}

	}
}
void makeStartTime(int linesSize) {
	for (int i = 0; i < linesSize; i++) {
		startTime[i][2] = endTime[i][2];
		startTime[i][3] = endTime[i][3];
		startTime[i][4] = endTime[i][4];
		startTime[i][5] = endTime[i][5] - sec[i][0];
		startTime[i][6] = endTime[i][6] - sec[i][1];
		startTime[i][6]++;
		if (startTime[i][6] < 0) {
			startTime[i][5]--;
			startTime[i][6] += 1000;
		}//밀리초
		if (startTime[i][5] < 0) {
			startTime[i][4]--;
			startTime[i][5] += 60;
		}//초
		if (startTime[i][4] < 0) {
			startTime[i][3]--;
			startTime[i][4] += 60;
		}//분
		if (startTime[i][3] < 0) {
			startTime[i][2]--;
			startTime[i][3] += 24;
		}//시

	}
	
}
void makeSecTime(int lineSize) {
	for (int i = 0; i < lineSize; i++) {
		startSecTime[i] = (startTime[i][2] % 14)*(1000 * 60 * 60 * 24) + (startTime[i][3])*(1000 * 60 * 60) + (startTime[i][4])*(1000 * 60) + (startTime[i][5])*(1000) + startTime[i][6];
		endSecTime[i] = (endTime[i][2] % 14)*(1000 * 60 * 60 * 24) + (endTime[i][3])*(1000 * 60 * 60) + (endTime[i][4])*(1000 * 60) + (endTime[i][5])*(1000) + endTime[i][6];
	}
}
int search_max(int lineSize) {
	int result = 0;
	for (int i = 0; i < lineSize; i++) {
		int tempCnt = 0;
		for (int j = i; j < lineSize; j++) {
			if (startSecTime[i]-1000 <= startSecTime[j] && startSecTime[j] < endSecTime[i]+1000) {
				tempCnt++;
			}
			else if (startSecTime[i]-1000 <= endSecTime[j] && endSecTime[j] < endSecTime[i] + 1000) {
				tempCnt++;
			}
			else if (startSecTime[j] < startSecTime[i] && endSecTime[i] < endSecTime[j]) {
				tempCnt++;
			}
		}
		result = max(result, tempCnt);
	}
	return result;
}
int solution(vector<string> lines) {
	int answer = 0;
	parseDay(lines);
	makeStartTime(lines.size());
	makeSecTime(lines.size());
	answer = search_max(lines.size());
	return answer;
}

int main() {
	vector<string> tempTest;
	tempTest.push_back("2016-09-15 01:00:04.001 2.0s");
	tempTest.push_back("2016-09-15 01:00:07.000 2s");
	



	solution(tempTest);
}