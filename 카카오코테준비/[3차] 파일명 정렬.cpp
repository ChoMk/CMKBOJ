#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string id_tail[1001];
string id_number[1001];
string id_head[1001];

vector<pair<pair<string, int>, int>> smallHead_number_id;

string toLowChar(string headName) {
	for (int i = 0; i < headName.size(); i++) {
		if (headName[i] >= 'A' && headName[i] <= 'Z') {
			headName[i] = (headName[i] - 'A') + 'a';
		}
	}
	return headName;
}

void parseFile(string fileName, int id) {
	int startNumIDX = 0;
	while (true) {
		if (fileName[startNumIDX] >= '0' && fileName[startNumIDX] <= '9') {
			break;
		}
		startNumIDX++;
	}
	id_head[id] = fileName.substr(0, startNumIDX);
	int endNumIDX = startNumIDX;
	while (true) {
		if (!(fileName[endNumIDX] >= '0' && fileName[endNumIDX] <= '9') || endNumIDX == fileName.size()) {
			break;
		}
		endNumIDX++;
	}
	id_number[id] = fileName.substr(startNumIDX, endNumIDX - startNumIDX);
	if (endNumIDX == fileName.size()) {
		id_tail[id] = "";
	}
	int startTailIDX = endNumIDX;
	int endTailIDX = fileName.size();
	id_tail[id] = fileName.substr(startTailIDX, endTailIDX - startNumIDX);
	return;
}

vector<pair<pair<string, int>, int>> makeFileVectorForSort(int filesSize) {
	vector<pair<pair<string, int>, int>> fileVectorForSort;
	for (int i = 0; i < filesSize; i++) {
		string lowHead = toLowChar(id_head[i]);
		int num = stoi(id_number[i]);
		fileVectorForSort.push_back({ {lowHead, num}, i });
	}
	return fileVectorForSort;
}

void init(vector<string> files) {
	for (int i = 0; i < files.size(); i++) {
		parseFile(files[i], i);
	}
}

vector<string> solveFunction(int filesSzie) {
	vector<string> result;
	vector<pair<pair<string, int>, int>> fileVectorForSort = makeFileVectorForSort(filesSzie);
	sort(fileVectorForSort.begin(), fileVectorForSort.end());

	for (int i = 0; i < fileVectorForSort.size(); i++) {
		string tempFileName = id_head[fileVectorForSort[i].second]+id_number[fileVectorForSort[i].second]+id_tail[fileVectorForSort[i].second];
		result.push_back(tempFileName);
	}
	return result;
}


vector<string> solution(vector<string> files) {
	init(files);
	vector<string> answer = solveFunction(files.size());
	return answer;
}

int main() {
	vector<string> temp;
	temp.push_back("img12.png");
	temp.push_back("img10.png");
	temp.push_back("img02.png");
	temp.push_back("img1.png");
	temp.push_back("IMG01.GIF");
	temp.push_back("img2.JPG");
	solution(temp);
}