#include<cstdio>
#include<algorithm>
#include<queue>


using namespace std;

int n;
deque<int> q;
int qFlag;
int main() {
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		q.push_back(i);
		
	}
	while (true)
	{
		if (q.size() == 1)
			break;
		if (!(qFlag &1)) {
			qFlag++;
			q.pop_back();

		}
		else {
			qFlag++;
			int temp = q.back();
			q.pop_back();
			q.push_front(temp);
		}

	}
	printf("%d\n", q.front());
}
