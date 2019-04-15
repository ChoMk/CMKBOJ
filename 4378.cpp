#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

string temp;
char changeS[300];

int main()
{
	changeS['\\'] = ']';
	changeS[']'] = '[';
	changeS['['] = 'P';
	changeS['P'] = 'O';
	changeS['O'] = 'I';
	changeS['I'] = 'U';
	changeS['U'] = 'Y';
	changeS['Y'] = 'T';
	changeS['T'] = 'R';
	changeS['R'] = 'E';
	changeS['E'] = 'W';
	changeS['W'] = 'Q';


	changeS['='] = '-';
	changeS['-'] = '0';
	changeS['0'] = '9';
	changeS['9'] = '8';
	changeS['8'] = '7';
	changeS['7'] = '6';
	changeS['6'] = '5';
	changeS['5'] = '4';
	changeS['4'] = '3';
	changeS['3'] = '2';
	changeS['2'] = '1';
	changeS['1'] = '`';

	changeS[';'] = 'L';
	changeS['L'] = 'K';
	changeS['K'] = 'J';
	changeS['J'] = 'H';
	changeS['H'] = 'G';
	changeS['G'] = 'F';
	changeS['F'] = 'D';
	changeS['D'] = 'S';
	changeS['S'] = 'A';
	changeS['\''] = ';';
	changeS['"'] = ';';

	changeS['?'] = '.';
	changeS['/'] = '.';
	changeS['.'] = ',';
	changeS[','] = 'M';
	changeS['M'] = 'N';
	changeS['N'] = 'B';
	changeS['B'] = 'V';
	changeS['V'] = 'C';
	changeS['C'] = 'X';
	changeS['X'] = 'Z';
	
	while (getline(cin, temp)) {
		for (int i = 0; i<temp.size(); i++)
		{
			if (temp[i] == ' ')
				continue;
			temp[i] = changeS[temp[i]];
		}
		cout << temp << endl;
	}
	

}