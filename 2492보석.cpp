#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int x;
int y;
int t;
int k;
int tempx;
int tempy;
vector<pair<int, int>>arr;
vector<pair<int, int>> newArr;
int maxX;
int maxY;
int result;


int main() {
	scanf("%d %d %d %d", &x, &y, &t, &k);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &tempx, &tempy);
		arr.push_back({ tempx, tempy });

	
	}

	for (int i = 0; i < arr.size(); i++) {
		newArr.push_back({ arr[i].first, arr[i].second });
		for (int j = i + 1; j < arr.size(); j++) {
			newArr.push_back({ arr[i].first, arr[j].second });
			newArr.push_back({ arr[j].first, arr[i].second });
		}
	}
	for (int i = 0; i < newArr.size(); i++) {
		int presentY = newArr[i].second;
		int rightbotY = presentY - k;
		int presentX = newArr[i].first;
		int rightbotX = presentX + k;
		if (rightbotY < 0)
			rightbotY =0;
		if (rightbotX > x)
			rightbotX = x;
		
		int tempCnt = 0;

		for (int cntT = 0; cntT < t; cntT++) {
			int checkX = arr[cntT].first;
			int checkY = arr[cntT].second;
			
			if (checkX >= presentX && checkY <= presentY) {
				if (checkY >= rightbotY && checkX <= rightbotX) {
					tempCnt++;
				}
			}
		}
		if (result < tempCnt) {
			result = tempCnt;
			maxX = presentX;
			maxY = presentY;
		}
	}
	if (maxX + k > x) {
		maxX -= (maxX + k) - x;
	}
	if (maxY - k < 0) {
		maxY += -(maxY - k);
	}
	printf("%d %d\n", maxX, maxY);
	printf("%d\n", result);

}