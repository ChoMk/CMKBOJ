#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string id_title[101];
string id_playSheet[101];
int id_playTime[101];
int conversionMin(string time) {
	int hour = stoi(time.substr(0, 2));
	int min = stoi(time.substr(3, 2));
	return hour * 60 + min;
}
vector<string> conversionNote(string sheet) {
	vector<string> note;
	for (int i = 0; i < sheet.size()-1; i++) {
		if (sheet[i] == '#')
			continue;
		if (sheet[i + 1] == '#') {
			string temp = "";
			temp += sheet[i];
			temp += '#';
			note.push_back(temp);
		}
		else {
			string temp = "";
			temp += sheet[i];
			note.push_back(temp);
		}
	}
	if (sheet[sheet.size() - 1] != '#') {
		string temp = "";
		temp += sheet[sheet.size() - 1];
		note.push_back(temp);
	}
	return note;
}
string playingNote(vector<string> note, int playTime) {
	string playingSheet = "";
	for (int i = 0; i < playTime; i++) {
		playingSheet += note[i%note.size()];
	}
	return playingSheet;
}
void parseMusicInfo(string musicInfo, int id) {
	string startTime = musicInfo.substr(0, 5);
	string endTime = musicInfo.substr(6, 5);
	int startTitleIDX = 12;
	int endTitleIDX = startTitleIDX;
	int startTimeMin = conversionMin(startTime);
	int endTimeMin = conversionMin(endTime);
	
	int playTime = endTimeMin - startTimeMin;
	id_playTime[id] = playTime;
	while (true) {
		if (musicInfo[endTitleIDX] == ',')
			break;
		endTitleIDX++;
	}

	string title = musicInfo.substr(startTitleIDX, endTitleIDX - startTitleIDX);
	id_title[id] = title;

	int startSheetIDX = endTitleIDX + 1;
	
	string sheet = musicInfo.substr(startSheetIDX, musicInfo.size() - startSheetIDX);
	vector<string> note = conversionNote(sheet);
	id_playSheet[id] = playingNote(note, playTime);
	return;

}

string search_title(string listenSheet, int musicInfoSize) {
	string result = "";
	vector<pair<int, int>> solutionSort;//재생신간, id
	for (int i = 0; i < musicInfoSize; i++) {
		string currentSheet = id_playSheet[i];
		for (int j = 0; j < currentSheet.size(); j++) {
			bool matchFlag = false;
			for (int k = 0; k < listenSheet.size(); k++) {
				if (k + j >= currentSheet.size()) {
					break;
				}
				if (k == listenSheet.size() - 1) {
					if (listenSheet[k] == currentSheet[j+k]) {
						if (j +k+ 1 == currentSheet.size() || currentSheet[j + k + 1] != '#') {
							matchFlag = true;
						}
					}
				}else if (listenSheet[k] == currentSheet[j+k]) {
					continue;
				}
				break;
			}
			if (matchFlag) {
				solutionSort.push_back({ -id_playTime[i],i });
			}
		}

	}
	
	if (solutionSort.size() == 0) {
		return result = "(None)";
	}
	sort(solutionSort.begin(), solutionSort.end());
	return result = id_title[solutionSort[0].second];
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	for (int i = 0; i < musicinfos.size(); i++) {
		parseMusicInfo(musicinfos[i], i);
	}
	answer = search_title(m, musicinfos.size());
	return answer;
}

int main() {
	vector<string> temp;
	temp.push_back("12:00,12:14,HELLO,C#DEFGAB");
	temp.push_back("13:00,13:05,WORLD,ABCDEF");
	solution("ABC", temp);
}