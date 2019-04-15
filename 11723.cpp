#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int t;
string temp;
int arr;
int number;
int main()
{
	std::ios::sync_with_stdio(false);
	scanf("%d", &t);
	while (t--) {
		cin >> temp;
		if (temp[1] == 'd') {
			cin >> number; 
			arr = (arr | (1 << number));
		}
		else if (temp[1] == 'h') {
			cin>>number;
			cout<<arr[number]<<"\n";
		}
		else if (temp[1] == 'e') {
			cin >> number; 
			arr = (arr&~(1<<number));
		}
		else if (temp[1] == 'l') {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else if (temp[1] == 'm') {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
		else {
			cin >> number; 
			arr[number]++;
			arr[number] %= 2;
		}
	}
}