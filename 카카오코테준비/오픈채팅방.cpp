#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<map>


using namespace std;
map<string, string> id_name;//id, name
vector<pair<string, string>> state_id;//상태, id

vector<string> solution(vector<string> record) {
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'E') {
			string id = "";
			string name = "";
			int start_name_idx = 0;
			for (int j = 6; j < record[i].size(); j++) {
				if (record[i][j] == ' ') {
					start_name_idx = j + 1;
					break;
				}

				id += record[i][j];
			}
			for (int j = start_name_idx; j < record[i].size(); j++) {

				name += record[i][j];
			}
			state_id.push_back({ "E", id });
			id_name[id] = name;
		}
		else if (record[i][0] == 'L') {
			string id = "";
			for (int j = 6; j < record[i].size(); j++) {
				
				id += record[i][j];
			}
			
			state_id.push_back({ "L", id });
			
		}
		else {
			string id = "";
			string name = "";
			int start_name_idx = 0;
			for (int j = 7; j < record[i].size(); j++) {
				if (record[i][j] == ' ') {
					start_name_idx = j + 1;
					break;
				}

				id += record[i][j];
			}
			for (int j = start_name_idx; j < record[i].size(); j++) {

				name += record[i][j];
			}
			id_name[id] = name;
		}
	
	}
	vector<string> answer;

	for (int i = 0; i < state_id.size(); i++) {
		if (state_id[i].first == "E") {
			answer.push_back(id_name[state_id[i].second] + "님이 들어왔습니다.");
		}
		else {

			answer.push_back(id_name[state_id[i].second] + "님이 나갔습니다.");
		}
	}



	return answer;
}


int main() {

}