#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int timePeopleCnt[24 * 60 + 1];
int startTime = 9 * 60;
vector<int> timePeopleIDX;
vector<int> busTime;

int translate_min(string time) {
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string makeResult(int minTime) {
	string h = to_string(minTime / 60);
	string m = to_string(minTime % 60);
	if (h.size() == 1) {
		h = '0' + h;
	}
	if (m.size() == 1) {
		m = '0' + m;
	}
	return h + ':' + m;
}
string solution(int n, int t, int m, vector<string> timetable) {

	string answer = "";
	for (int i = 0; i < timetable.size(); i++) {
		int tempTime = translate_min(timetable[i]);
		if (timePeopleCnt[tempTime] == 0) {
			timePeopleCnt[tempTime]++;
			timePeopleIDX.push_back(tempTime);
		}
		else {
			timePeopleCnt[tempTime]++;
		}
	}
	sort(timePeopleIDX.begin(), timePeopleIDX.end());
	for (int i = 0; i < n; i++) {
		busTime.push_back(startTime);
		startTime += t;
	}
	for (int i = 0; i < n - 1; i++) {
		int curSavePeople = 0;
		for (int j = 0; j < timePeopleIDX.size(); j++) {
			int curTime = timePeopleIDX[j];
			if (curTime <= busTime[i]) {

				if (curSavePeople + timePeopleCnt[curTime] <= m) {
					curSavePeople += timePeopleCnt[curTime];
					timePeopleCnt[curTime] = 0;
				}
				else {
					timePeopleCnt[curTime] -= (m - curSavePeople);
					curSavePeople = m;

				}
			}
			else {
				break;
			}
		}
	}
	int lastTime = busTime[n - 1];
	int curSavePeople = 0;
	for (int i = 0; i < timePeopleIDX.size(); i++) {
		int curTime = timePeopleIDX[i];
		if (curTime <= lastTime) {
			if (curSavePeople + timePeopleCnt[curTime] < m) {
				curSavePeople += timePeopleCnt[curTime];
				timePeopleCnt[curTime] = 0;
			}
			else {
				return makeResult(curTime - 1);
				timePeopleCnt[curTime] -= (m - curSavePeople);
				curSavePeople = m;

			}
		}
		else {
			break;
		}
	}
	return makeResult(lastTime);
}


