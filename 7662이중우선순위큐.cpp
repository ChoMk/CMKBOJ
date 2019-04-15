#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<map>
using namespace std;


int t;
int n;
long long b;
char a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		priority_queue<long long> maxpq;
		priority_queue<long long> minpq;
		map<long long, long long> check;
		cin >> n;
		for (int i = 0; i < n; i++) {
			
			cin >> a >> b;
			if (a == 'I') {
				maxpq.push(b);
				minpq.push(-b);
				if (check.count(b) == 0) {
					check.insert({ b, 1 });
				}
				else {
					check[b]++;
				}
			}
			else if (a == 'D') {
				if (b == 1) {
					
					int temp = 0;
					while (true) {
						if (maxpq.empty()) {
				
							break;
						}
						temp = maxpq.top();
						if (check[temp] <= 0) {
							maxpq.pop();
						}
						else {
							check[temp]--;
							maxpq.pop();
							break;
						}

					}
				}
				else {
					int temp = 0;
					while (true) {
						if (minpq.empty()) {

							break;
						}
						temp = -minpq.top();
						if (check[temp] <= 0) {
							minpq.pop();
						}
						else {
							check[temp]--;
							minpq.pop();
							break;
						}

					}
				}
			}


		}
		while (true) {
			if (maxpq.empty()) {
				break;
			}
			if (check[maxpq.top()] <= 0) {
				maxpq.pop();
			}
			else {
				break;
			}
				

		}
		while (true) {
			if (minpq.empty()) {
				break;
			}
			if (check[-minpq.top()] <= 0) {
				minpq.pop();
			}
			else {
				break;
			}


		}
		if (minpq.empty()&& maxpq.empty()) {
			cout<<"EMPTY\n";
		}
		else {
			cout<<maxpq.top()<<" "<<-minpq.top()<<"\n";
		}

	}
}