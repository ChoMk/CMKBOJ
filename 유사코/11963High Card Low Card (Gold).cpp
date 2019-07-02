#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int n;
bool visit[100001];
vector<int> Aarr1;
vector<int> Aarr2;

vector<int> BarrL;
vector<int> BarrS;
int a;
int result;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n/2; i++) {
		scanf("%d", &a);
		visit[a] = true;
		Aarr1.push_back(a);
	}
	
	for (int i = 0; i < n/2; i++) {
		scanf("%d", &a);
		visit[a] = true;
		Aarr2.push_back(a);
	}
	int cnt = 1;
	while (true) {
		if (cnt == 2 * n + 1)
			break;
		if (visit[cnt]) {
			cnt++;
			continue;
		}
			
		BarrS.push_back(cnt);
		cnt++;
	}
	for (int i = n - 1; i >= n / 2; i--) {
		BarrL.push_back(BarrS[i]);
		BarrS.pop_back();
		
	}
	reverse(BarrL.begin(), BarrL.end());
	for (int i = 0; i < n / 2; i++) {
		int idx = lower_bound(BarrL.begin(), BarrL.end(), Aarr1[i]) - BarrL.begin();
		if (idx != BarrL.size()) {
			result++;
			BarrL.erase(BarrL.begin() + idx, BarrL.begin() + idx + 1);
			
		}
	}
	for (int i = 0; i < n / 2; i++) {
		int idx = lower_bound(BarrS.begin(), BarrS.end(), Aarr2[i]) - BarrS.begin()-1;
		if (idx != -1) {
			result++;
			BarrS.erase(BarrS.begin() + idx, BarrS.begin() + idx + 1);

		}
	}


	printf("%d\n", result);

}