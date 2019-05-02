#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int k;
int d;
vector<pair<pair<int, int>,int>> arr;

int a, b, c;

int bs(int left, int right) {
	if ((left > right)) {
		return left;
	}
	int mid = (left + right) / 2;
	long long tempD = 0;
	for (int i = 0; i < arr.size(); i++) {
		int temp = min(arr[i].first.second, mid);
		if(temp>=arr[i].first.first)
			tempD += (temp - arr[i].first.first) / arr[i].second + 1;
			
		
	}
	if (tempD >= d) {
		return bs(left, mid-1);
	}
	else if (tempD < d) {
		return bs(mid+1, right);
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &d);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr.push_back({ {a,b},c });
	}
	
	printf("%d\n", bs(1, n));

}