#include <string>
#include <vector>
#include<map>

using namespace std;

map<string, int> check;
bool PK[1<<10];
int checkKey[1<<10];//i로 시작하는 k개가 선택된키가 갖는 유니크한 수
int maxK;

vector<string> curP;
int totalP;
int totalA;
bool checkPKfun(vector<int> arr, int curIDX, int curState) {
	
	if (curIDX == arr.size()) {
		if (PK[curState])
			return true;
		return false;
	}
	if (checkPKfun(arr, curIDX+1, curState))
		return true;
	for (int i = curIDX; i < arr.size(); i++) {
		if (checkPKfun(arr, i+1, curState | (1<<arr[i])))
			return true;
	}
	return false;
}
void makeKey(int curIDX, int curState, string curKey, int k) {
	curState |= (1 << curIDX);
	if (k == maxK) {
		check[curKey]++;
		if (check[curKey] == 1) {
			checkKey[curState]++;
		}
		return;
	}
	if (curIDX >= totalA-1)
		return;
	
	for (int i = curIDX+1; i < totalA; i++) {
		
		makeKey(i, curState, curKey+curP[i]+to_string(i), k + 1);
		
	}
	return;
}
int checkPK(int curIDX, int curState, int k) {
	curState |= (1 << curIDX);
	if (k == maxK) {
		int currentIDX = 0;
		int tempCurState = curState;
		vector<int> saveIDX;
		while (true) {
			if (tempCurState == 0)
				break;
			if (tempCurState % 2 == 1) {
				saveIDX.push_back(currentIDX);
			}
			tempCurState /= 2;
			currentIDX++;
		}
		if (checkPKfun(saveIDX, 0, 0))
			return 0;
		currentIDX = 0;
		tempCurState = curState;
		if (checkKey[curState] == totalP) {
			
			PK[curState] = true;
			return 1;
		}
		return 0;
	}
	if (curIDX >= totalA - 1)
		return 0;
	int result = 0;
	for (int i = curIDX + 1; i < totalA; i++) {
		result += checkPK(i, curState, k + 1);
	}
	return result;
}
int solution(vector<vector<string>> relation) {

	int answer = 0;
	totalP = relation.size();//사람의 수
	totalA = relation[0].size();//속성의 수
	for (int i = 0; i < totalP; i++) {
		curP = relation[i];

		for (int j = 0; j < totalA; j++) {//시작 기준
			string startKey = curP[j];
			for (int k = 1; k <= totalA; k++) {//k개의 후보로 키 구성
				maxK = k;

				makeKey(j, 0, startKey+to_string(j), 1);
			}
		}
	}
	for (int pickKeyCnt = 1; pickKeyCnt <= totalA; pickKeyCnt++) {
		for (int keyStart = 0; keyStart < totalA; keyStart++) {
			maxK = pickKeyCnt;
			answer += checkPK(keyStart, 0, 1);

		}
	}
	


	return answer;
}
int main() {
	
}