#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string fname, sname;
int t;
string scorestring;
int main() {
	cin >> fname >> sname;
	cin >> t;

	cin.ignore();
	while (t--) {
		bool flagResult = true;
		int fw = 0;
		int sw = 0;
		bool samsamflag = false;
		int fsetscore = 0;
		int ssetscore = 0;
		getline(cin,scorestring);
		int spaceIDX = 0;
		int startIDX = 0;
		string onesetsocre;
		int setcnt = 1;
		while (true) {
			
			if (spaceIDX == scorestring.size()) {
				onesetsocre = scorestring.substr(startIDX, spaceIDX);
				int cIDX = 0;
				while (true) {
					if (abs(fw - sw) > 2) {
						flagResult = false;
					}
					if (samsamflag == true && setcnt == 3) {
						samsamflag = false;
					}
					if (onesetsocre[cIDX] == ':') {
						fsetscore = atoi(onesetsocre.substr(0, cIDX).c_str());
						ssetscore = atoi(onesetsocre.substr(cIDX + 1, onesetsocre.size()).c_str());
						//������ ���

						int scoredist = abs(fsetscore - ssetscore);
						int maxScore = max(fsetscore, ssetscore);
						if ((maxScore == 6 && scoredist >= 2) || (maxScore > 6&&scoredist>=1)) {
							if (maxScore == fsetscore) {
								fw++;
							}
							else {
								sw++;
							}
						}
						else if (maxScore == 6 && scoredist == 6) {
							//���º�
							fw++;
							sw++;
						}
						else {
							flagResult = false;
						}


						break;
					}
					cIDX++;
				}
				
				break;
			}
				
			if (scorestring[spaceIDX] == ' ') {
				onesetsocre = scorestring.substr(startIDX, spaceIDX);
				int cIDX = 0;
				if (abs(fw - sw) > 2) {
					flagResult = false;
				}
				while (true) {
					if (onesetsocre[cIDX] == ':') {
						fsetscore = atoi(onesetsocre.substr(0, cIDX).c_str());
						ssetscore = atoi(onesetsocre.substr(cIDX + 1, onesetsocre.size()).c_str());
						
						int scoredist = abs(fsetscore - ssetscore);
						int maxScore = max(fsetscore, ssetscore);
						if ((maxScore == 6 && scoredist >= 2) || (maxScore > 6 && scoredist >= 1)) {
							if (maxScore == fsetscore) {
								fw++;
							}
							else {
								sw++;
							}
						}
						else if (maxScore == 6 && scoredist == 6) {
							//���º�
							if(setcnt ==1 || setcnt == 2)
								samsamflag = true;
						}
						else {
							flagResult = false;
						}
						break;
					}
					cIDX++;
				}

				setcnt++;

				startIDX = spaceIDX+1;
			}


			spaceIDX++;
		}
		if (fw == sw || abs(fw - sw)>2 || samsamflag == true) {
			flagResult = false;
		}
		if ((fname == "federer"&&sw > 0) || (sname == "federer"&&fw > 0))
			flagResult = false;
		if (flagResult == true) {
			
			cout << "da\n";
		}
		else {
			cout << "ne\n";
		}

		//6�� �޼� 2�� ����
		//�Ǵ� 7�� �̻� �޼�
		
		//2��Ʈ ������ ���Ǵ�
		//1��Ʈ 1��Ʈ �̱�� ���Ǵ�


	}
}
