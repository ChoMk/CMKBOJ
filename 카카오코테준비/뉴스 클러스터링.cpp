#include <string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

string lowCha(string temp) {
	string result = "";
	for (int i = 0; i < temp.size(); i++) {
		if ('A' <= temp[i] && temp[i] <= 'Z') {
			result += ('a'+temp[i]-'A');
		}
		else {
			result += temp[i];
		}
	}
	return result;
}
vector<string> pairString(string temp) {
	vector<string>result;
	for (int i = 0; i < temp.size() - 1; i++) {
		string curString = "";
		curString += temp[i];
		curString += temp[i + 1];
		result.push_back(curString );
	}

	return result;
}
vector<string> subNotA(vector<string> temp1) {
	vector<string> result;
	for (int i = 0; i < temp1.size(); i++) {
		if (!('a' <= temp1[i][0] && temp1[i][0] <= 'z')) {
			continue;
		}
		if (!('a' <= temp1[i][1] && temp1[i][1] <= 'z')) {
			continue;
		}
		result.push_back(temp1[i]);
	}
	return result;
}
vector<pair<string, int>> makePairStr(vector<string> temp) {
	map<string, int> check;
	vector<pair<string, int>> result;
	for (int i = 0; i < temp.size(); i++) {
		check[temp[i]]++;
		if (check[temp[i]] == 1) {
			result.push_back({ temp[i], 0 });
		}
	}
	for (int i = 0; i < result.size(); i++) {
		result[i].second = check[result[i].first];
	}
	return result;
}
int compareString(vector<pair<string, int>> temp1, vector<pair<string, int>> temp2) {

	map<string, int> visit1;
	map<string, int> visit2;
	map<string, int> Comvisit;

	double total = 0;
	double common = 0;
	if (temp1.size() == 0 && temp2.size() == 0)
		return 65536;
	if (temp1.size() == 0 || temp2.size() == 0) {
		return 0;
	}
	for (int i = 0; i < temp1.size(); i++) {
		
		for (int j = 0; j < temp2.size(); j++) {
			
			if (temp1[i].first == temp2[j].first && Comvisit[temp1[i].first] == NULL) {
				Comvisit[temp1[i].first] = 1;
				common+= min(temp1[i].second, temp2[j].second);
				total -= temp1[i].second;
				total -= temp2[j].second;
				total+= max(temp1[i].second, temp2[j].second);
			}
			
				if (visit1[temp1[i].first] == 0) {
					visit1[temp1[i].first]++;
					total += temp1[i].second;
				}
					
				if (visit2[temp2[j].first] == 0) {
					visit2[temp2[j].first]++;
					total += temp2[j].second;
				
				}
				
			
			
		}
			
	}
	
	
	return (int)(common / total * 65536);
}


int solution(string str1, string str2) {
	int answer = 0;
	str1 = lowCha(str1);
	str2 = lowCha(str2);
	vector<string> str1Pair = pairString(str1);
	vector<string> str2Pair = pairString(str2);
	str1Pair = subNotA(str1Pair);
	str2Pair = subNotA(str2Pair);
	vector<pair<string, int>> str1R = makePairStr(str1Pair);
	vector<pair<string, int>> str2R = makePairStr(str2Pair);
	answer = compareString(str1R, str2R);
	return answer;
}

int main() {
	solution("aa1+aa2", "AAAA12");
}