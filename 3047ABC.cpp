#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

priority_queue <int>pq;
vector<int> arr;
int a;
string temp;
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a);
		pq.push(a);
	}
	sort(arr.begin(), arr.end());
	cin >> temp;
	for (int i = 0; i < temp.size(); i++) {
		printf("%d ", arr[temp[i] - 'A']);
	}

}