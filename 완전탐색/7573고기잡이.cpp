#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int rec;
int m;
int a, b;
vector<pair<int, int>>arr;
vector<pair<int, int>>arrsize;
vector<pair<int, int>>newArr;
int result;
int main() {
	scanf("%d %d %d", &n, &rec, &m);
	rec /= 2;
	for (int i = 1; i < (rec); i++) {
		arrsize.push_back({ i, (rec) - i });
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr.push_back({ a,b });
	}
	for (int i = 0; i < m; i++) {
		newArr.push_back({ arr[i].first, arr[i].second });
		for (int j = i+1; j < m; j++) {
			newArr.push_back({ arr[j].first, arr[j].second });
			newArr.push_back({ arr[i].first, arr[j].second });
			newArr.push_back({ arr[j].first, arr[i].second });
		}
	}
	for (int i = 0; i < newArr.size(); i++) {
		int sx = newArr[i].first;
		int sy = newArr[i].second;
		for (int j = 0; j < arrsize.size(); j++) {
			int ex = sx + arrsize[j].first;
			int ey = sy + arrsize[j].second;
			if (ex > n) {
				ex = n;
			}
			if (ey > n) {
				ey = n;
			}
				
			int tempR = 0;
			for (int k = 0; k < arr.size(); k++) {
				int curx = arr[k].first;
				int cury = arr[k].second;
				if (curx <= ex && curx >= sx && cury <= ey && cury >= sy)
					tempR++;
			}
			result = max(tempR, result);
		}

	}
	printf("%d\n", result);
}