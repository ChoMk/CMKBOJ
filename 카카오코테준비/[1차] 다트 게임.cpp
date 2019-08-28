#include <string>
#include<algorithm>
#include<vector>

using namespace std;

int initScore[11];
char initSDT[4];
char initOption[4];
vector<int> SDTIDX;


void parseOption_Score(int idx, string temp) {
	if (temp[temp.size()-1] == '#' || temp[temp.size() - 1] == '*') {
		initOption[idx] = temp[temp.size() - 1];
		initScore[idx] = stoi(temp.substr(0, temp.size() - 1));
	}
	else {
		initOption[idx] = 'x';
		initScore[idx] = stoi(temp.substr(0, temp.size()));
	}
	return;
}

int calScore() {
	for (int i = 0; i < 3; i++) {
		
		if (initSDT[i] == 'D') {
			initScore[i] *= initScore[i];
		}
		if (initSDT[i] == 'T') {

			initScore[i] = initScore[i]* initScore[i]* initScore[i];

		}
	}
	if (initOption[0] == '*') {
		initScore[0] *= 2;
	}
	for (int i = 1; i < 3; i++) {
		if (initOption[i] == '*') {
			initScore[i-1] *= 2;
			initScore[i] *= 2;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (initOption[i] == '#') {
			initScore[i] *= -1;
		}
	}
	int result = 0;
	for (int i = 0; i < 3; i++) {
		result += initScore[i];
	}
	return result;
}

int solution(string dartResult) {
	
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			SDTIDX.push_back(i);
			initSDT[SDTIDX.size() - 1] = dartResult[i];
		}
	}
	string firstParse ;
	if (dartResult[SDTIDX[0] + 1] != '#' && dartResult[SDTIDX[0] + 1] != '*') {
		firstParse = dartResult.substr(0, SDTIDX[0]);
	}
	else {
		firstParse = dartResult.substr(0, SDTIDX[0])+ dartResult[SDTIDX[0] + 1];
	}
	string secondParse;
	if (dartResult[SDTIDX[0] + 1] != '#' && dartResult[SDTIDX[0] + 1] != '*') {
		if (dartResult[SDTIDX[1] + 1] != '#' && dartResult[SDTIDX[1] + 1] != '*') {

			secondParse = dartResult.substr(SDTIDX[0] + 1, SDTIDX[1] - SDTIDX[0]-1);
		}
		else {
			secondParse = dartResult.substr(SDTIDX[0] + 1, SDTIDX[1] - SDTIDX[0] - 1) + dartResult[SDTIDX[1] + 1];

		}
	}
	else {
		if (dartResult[SDTIDX[1] + 1] != '#' && dartResult[SDTIDX[1] + 1] != '*') {

			secondParse = dartResult.substr(SDTIDX[0] + 2, SDTIDX[1] - SDTIDX[0] - 2);
		}
		else {
			secondParse = dartResult.substr(SDTIDX[0] + 2, SDTIDX[1] - SDTIDX[0] - 2) + dartResult[SDTIDX[1] + 1];

		}
	}
	string thirdParse;
	if (dartResult[SDTIDX[1] + 1] != '#' && dartResult[SDTIDX[1] + 1] != '*') {
		if (SDTIDX[2] + 1==dartResult.size()) {

			thirdParse = dartResult.substr(SDTIDX[1] + 1, SDTIDX[2] - SDTIDX[1] - 1);
		}
		else {
			thirdParse = dartResult.substr(SDTIDX[1] + 1, SDTIDX[2] - SDTIDX[1] - 1) + dartResult[SDTIDX[2] + 1];

		}
	}
	else {
		if (SDTIDX[2] + 1 == dartResult.size()) {

			thirdParse = dartResult.substr(SDTIDX[1] + 2, SDTIDX[2] - SDTIDX[1] - 2);
		}
		else {
			thirdParse = dartResult.substr(SDTIDX[1] + 2, SDTIDX[2] - SDTIDX[1] - 2) + dartResult[SDTIDX[2] + 1];

		}
	}
	parseOption_Score(0, firstParse);
	parseOption_Score(1, secondParse);
	parseOption_Score(2, thirdParse);

	

	int answer = calScore();
	return answer;
}

int main() {
	solution("1S2D*3T");
}