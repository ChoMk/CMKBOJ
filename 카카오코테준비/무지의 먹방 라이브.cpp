#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> sort_val;
	long long preSum = 0;
	vector<int> sort_idx;

	int answer = 0;
	for (int i = 0; i < food_times.size(); i++) {
		sort_val.push_back({ food_times[i], i });
	}
	sort(sort_val.begin(), sort_val.end());
	for (int i = 0; i < sort_val.size(); i++) {
		sort_val[i].first -= preSum;
		long long tempK = k - (long long)sort_val[i].first*(sort_val.size() - i);
		if (tempK < 0) {
			break;
		}
		else {
			k -= (long long)sort_val[i].first*(sort_val.size() - i);
			preSum += sort_val[i].first;
			sort_val[i].first = 0;
		}
	}
	for (int i = 0; i < sort_val.size(); i++) {
		if (sort_val[i].first == 0)
			continue;
		sort_idx.push_back(sort_val[i].second);
	}
	if (sort_idx.size() == 0) {
		return -1;
	}
	sort(sort_idx.begin(), sort_idx.end());
	k %= sort_idx.size();
	answer = sort_idx[k];
	return answer+1;
}

int main() {
	vector<int>arr;
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	solution(arr, 5);
}