#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<iostream>

using namespace std;

int n, q;
vector<pair<int, int>> arr;
int tree[400001];
int treeDis[400001];
int bottomStartIDX = 1;
int x, y;
int preDis[100001];
int twoSumDis[100001];
char qq;
int a, b, c;

void constructTree() {
	for (int i = bottomStartIDX - 1; i > 0; i--) {
		if (twoSumDis[tree[i * 2]] > twoSumDis[tree[i * 2 + 1]]) {
			tree[i] = tree[i * 2];
		}
		else {
			tree[i] = tree[i * 2 + 1];
		}
		 
	}
}


int searchTreeIDX(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound)
		return tree[pos];
	int idx1 = searchTreeIDX(leftBound, rightBound, left, (right + left) / 2, pos * 2);
	int idx2 = searchTreeIDX(leftBound, rightBound, (right + left) / 2 + 1, right, pos * 2 + 1);
	int dis1 = twoSumDis[idx1];
	int dis2 = twoSumDis[idx2];
	if (dis1 > dis2)
		return idx1;
	return idx2;

}

void updateTree(int idx) {
	idx += bottomStartIDX;

	while (idx>1) {
		idx /= 2;
		int idx1 = tree[idx * 2];
		int idx2 = tree[idx * 2 + 1];
		int dis1 = twoSumDis[idx1];
		int dis2 = twoSumDis[idx2];

		if (dis1 > dis2) {
			tree[idx] = idx1;
		}
		else {
			tree[idx] = idx2;
		}
	}
}
void constructTreeDist() {
	for (int i = bottomStartIDX - 1; i > 0; i--) {
		treeDis[i] = treeDis[i * 2] + treeDis[i * 2 + 1];
	}
}
void updateTreeDist(int idx, int val) {
	idx += bottomStartIDX;
	treeDis[idx] = val;
	while (idx > 1) {
		idx /= 2;
		treeDis[idx] = treeDis[idx * 2] + treeDis[idx * 2 + 1];
	}
}
int searchTreeDsit(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left) {
		return 0;
	}
	if (leftBound <= left && right <= rightBound)
		return treeDis[pos];

	return searchTreeDsit(leftBound, rightBound, left, (right + left) / 2, pos * 2)
		+searchTreeDsit(leftBound, rightBound, (right+left)/2+1, right, pos*2+1);
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	while (bottomStartIDX < n)
		bottomStartIDX *= 2;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	for (int i = 1; i < n; i++) {
		preDis[i] = abs(arr[i].first - arr[i - 1].first) + abs(arr[i].second - arr[i - 1].second);
		
		tree[i + bottomStartIDX] = i;
		treeDis[i + bottomStartIDX] = preDis[i];
	}//현제 위치 전 위치에서와의 거리가 저장
	for (int i = 1; i < n-1; i++) {
		twoSumDis[i] = preDis[i] + preDis[i + 1] - (abs(arr[i + 1].first - arr[i - 1].first) + abs(arr[i + 1].second - arr[i - 1].second));
	}
	constructTree();
	constructTreeDist();

	for (int i = 0; i < n; i++) {
		
		cin >> qq;
		if (qq == 'Q') {
			cin >> a >> b;
			a--;
			b--;
			if (a == b) {
				cout << 0 << "\n";
				continue;
			}
			if (a + 1 == b) {
				cout << preDis[b]<<"\n";
				continue;
			}
			int subIDX = searchTreeIDX(a +1, b - 1, 0, bottomStartIDX - 1, 1);
			int result = searchTreeDsit(a+1, b, 0, bottomStartIDX - 1, 1);
			result -= preDis[subIDX];
			result -= preDis[subIDX + 1];
			result += abs(arr[subIDX + 1].first - arr[subIDX - 1].first) + abs(arr[subIDX + 1].second - arr[subIDX - 1].second);
			cout << result << "\n";
		}
		else {
			cin >> a >> b >> c;
			a--;
			arr[a].first = b;
			arr[a].second = c;

			if (a != 0) {
				preDis[a] = abs(arr[a].first - arr[a - 1].first) + abs(arr[a].second - arr[a-1].second);
				updateTreeDist(a, preDis[a]);
			}
			if (a != n - 1) {
				preDis[a+1] = abs(arr[a+1].first - arr[a].first) + abs(arr[a+1].second - arr[a].second);

				updateTreeDist(a+1, preDis[a+1]);
			}
			if (a != 0 && a != n - 1) {
				twoSumDis[a] = preDis[a] + preDis[a + 1] - (abs(arr[a + 1].first - arr[a - 1].first) + abs(arr[a + 1].second - arr[a - 1].second));
				updateTree(a);
			}
			if (a < n-2) {
				twoSumDis[a + 1] = preDis[a + 1] + preDis[a + 2] - (abs(arr[a].first - arr[a + 2].first) + abs(arr[a].second - arr[a + 2].second));
				updateTree(a + 1);
			}
			if(a >1) {
				twoSumDis[a - 1] = preDis[a - 1] + preDis[a] - (abs(arr[a - 2].first - arr[a].first) + abs(arr[a - 2].second - arr[a].second));
				updateTree(a - 1);
			}
		}
	}
}