#include <string>
#include <vector>
#include<map>
#include<queue>

using namespace std;

map<string, int> save;
string chache[31];

string lowCha(string temp) {
	string result = "";
	for (int i = 0; i < temp.size(); i++) {
		if ('A' <= temp[i] && temp[i] <= 'Z') {
			result += ('a' + temp[i] - 'A');
		}
		else {
			result += temp[i];
		}
	}
	return result;
}
int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) {
		return cities.size() * 5;
	}
	int answer = 0;
	for (int i = 0; i < cities.size(); i++) {
		cities[i] = lowCha(cities[i]);
	}
	int curSize = 0;
	for (int i = 0; i < cities.size(); i++) {
		string curcity = cities[i];
		if (curSize < cacheSize) {
			bool checkCaching = false;

			for (int j = 0; j < curSize; j++) {
				if (chache[j] == curcity)
					checkCaching = true;
				
			}
			if (!checkCaching) {
				chache[curSize] = curcity;
				curSize++;
				answer += 4;
			}

			save[curcity] = i + 1;
			answer += 1;
			
		}
		else {
			bool checkCaching = false;
			int removeID = 0;
			int useDay = 987654321;
			for (int j = 0; j < cacheSize; j++) {
				if (chache[j] == curcity)
					checkCaching = true;
				if (useDay > save[chache[j]]) {
					removeID = j;
					useDay = save[chache[j]];
				}
			}
			if (!checkCaching) {
				chache[removeID] = curcity;
				answer += 4;

			}
			answer++;
			save[curcity] = i + 1;
			
		}
	}

	return answer;
}