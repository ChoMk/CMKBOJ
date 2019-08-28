#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int stayStage[502];
vector<pair<double, int>> result;
vector<int> solution(int N, vector<int> stages) {
	for(int i = 0; i < stages.size(); i++) {
		stayStage[stages[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		int curStay = stayStage[i];
		int totallP = stayStage[i];
		for (int j = i+1; j <= N+1; j++) {
			totallP += stayStage[j];
		}
		result.push_back({ -((double)curStay / (double)totallP), i });
	}
	sort(result.begin(), result.end());
	vector<int> answer;
	for (int i = 0; i < result.size(); i++) {
		answer.push_back(result[i].second);
	}
	return answer;
}