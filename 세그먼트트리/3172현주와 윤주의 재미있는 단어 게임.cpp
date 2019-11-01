#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;
string inputString[100001];
vector<pair<string, int>> reverseInputString;
long long tree[400001];
int startIDX = 1;
long long result;
void updateTree(int pos) {
	int currentPos = startIDX + pos;
	tree[currentPos] = 1;
	currentPos /= 2;
	while (currentPos>0) {
		tree[currentPos] = tree[currentPos * 2] + tree[currentPos * 2 + 1];
		currentPos /= 2;
	}
}
long long query(int leftBound, int rightBound, int left, int right, int pos) {
	if (leftBound > right || rightBound < left)
		return 0;
	if (leftBound <= left && right <= rightBound)
		return tree[pos];
	return query(leftBound, rightBound, left, (left + right) / 2, pos * 2) + query(leftBound, rightBound, (left + right) / 2 + 1, right, pos * 2 + 1);
	
}

int main() {
	cin >> n;
	while (startIDX<n) {
		startIDX *= 2;
	}
	for (int i = 0; i < n; i++) {
		cin >> inputString[i];
	}
	sort(inputString, inputString + n);
	for (int i = 0; i < n; i++) {
		reverse(inputString[i].begin(), inputString[i].end());
		reverseInputString.push_back({ inputString[i], i });
	}
	sort(reverseInputString.begin(), reverseInputString.end());
	for (int i = 0; i < n; i++) {
		int currentIDX = reverseInputString[i].second;
		result += query(currentIDX, n-1, 0, startIDX-1, 1);
		updateTree(currentIDX);
	}
	cout << result << "\n";
}