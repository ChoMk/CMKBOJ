#include<string>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string temp;

int main() {
	cin >> temp;
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());
	cout << temp<<endl;

}