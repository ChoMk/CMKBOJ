#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int n;
string arr;
int preS;
int score;

int main() {
	cin >> n;
	cin >> arr;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 'O') {
			score+=i;
			score++;
			
			score += preS;
			preS++;
		}
		else {
			preS = 0;
		}
	}
	cout << score<<"\n";
}