#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

string startT;
string endT;
int startH;
int startM;
int startS;
int endH;
int endM;
int endS;
int resultH;
int resultM;
int resultS;


int main() {
	cin >> startT>>endT;
	startH = atoi(startT.substr(0, 2).c_str());
	startM = atoi(startT.substr(3, 5).c_str());
	startS = atoi(startT.substr(6, 8).c_str());
	

	endH = atoi(endT.substr(0, 2).c_str());
	endM = atoi(endT.substr(3, 5).c_str());
	endS = atoi(endT.substr(6, 8).c_str());

	resultS = endS - startS;
	if (resultS < 0) {
		resultS += 60;
		endM--;
	} 
	resultM = endM - startM;
	if (resultM < 0) {
		resultM += 60;
		endH--;
	}
	resultH = endH - startH;
	if (resultH < 0) {
		resultH += 24;
	}
	if (resultH == 0 && resultM == 0 && resultS == 0) {
		printf("24:00:00\n");
	}
	else {
		printf("%02d:%02d:%02d\n", resultH, resultM, resultS);
	}
	
}