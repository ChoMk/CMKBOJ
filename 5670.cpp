#include<cstdio>

using namespace std;

const int ALPHA = 26;
char saveStr[100001][81];
int n, m;



class TrieNode {
private:
	TrieNode * children[ALPHA];
	
public:
	int cntCild;
	bool check;
	TrieNode() {
		for (int i = 0; i < ALPHA; i++) {
			children[i] = nullptr;
		}
		cntCild = 0;
		check = false;
	}
	~TrieNode() {
		for (int i = 0; i < ALPHA; i++) {
			if (children[i]) delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == NULL) {
			check = true;
			return;
		}
		else {
			int next = (*key) - 'a';
			if (children[next] == nullptr) {
				cntCild++;
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
	int isCheck(const char * key) {
		if (*key == NULL) {
			return 0;
		}
		else {
			int next = (*key) - 'a';
			if (cntCild == 1) {
				if (check) {
					return 1 + children[next]->isCheck(key + 1);
				}//³¡
				else {
					return children[next]->isCheck(key + 1);
				}
			}
			else if(cntCild>1){
				
				return 1 + children[next]->isCheck(key + 1);
			
			}
			return 0;
		}
	}
};
int t;
int main() {
	while (scanf("%d", &n) != EOF) {
		float result = 0;
		TrieNode *root = new TrieNode();
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%s", &saveStr[i]);
			root->insert(saveStr[i]);
			
		}
		root->check = true;
		for (int i = 0; i < n; i++) {
			result += root->isCheck(saveStr[i]);
		}
		printf("%.2f\n", result / n);
		delete root;
	}
}