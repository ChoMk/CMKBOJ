#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<int> useY;//사용된 y좌표 저장
vector<pair<int, int>> nodeY[100001];//y에 대한 x, id저장
int tree[10001][2];
vector<int> preorder;
vector<int> postorder;
long long saveDist[10001][10001];

int treeParent[10001];




void funPreorder(int curNode) {
	preorder.push_back(curNode);
	if (tree[curNode][0] == 0 && tree[curNode][1] == 0) {

		return;

	}
	if (tree[curNode][0] != 0) {
		funPreorder(tree[curNode][0]);
	}
	if (tree[curNode][1] != 0) {
		funPreorder(tree[curNode][1]);
	}
	return;
}
void funPostorder(int curNode) {
	if (tree[curNode][0] == 0 && tree[curNode][1] == 0) {

		postorder.push_back(curNode);
		return;
	}
	if (tree[curNode][0] != 0) {
		funPostorder(tree[curNode][0]);
	}
	if (tree[curNode][1] != 0) {
		funPostorder(tree[curNode][1]);
	}
	postorder.push_back(curNode);
	return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	for (int i = 0; i < nodeinfo.size(); i++) {
		nodeY[(nodeinfo[i][1])].push_back({ nodeinfo[i][0], i + 1 });
		if (nodeY[(nodeinfo[i][1])].size() == 1) {
			useY.push_back((nodeinfo[i][1]));
		}
	}
	sort(useY.begin(), useY.end());//아래서부터... 루트를 재외한 부모는 항생 존재
	
	int rootID = nodeY[useY[useY.size() - 1]][0].second;

	for (int i = useY.size() - 1; i> 0 ; --i) {
		int curLayerY = useY[i];
		vector<pair<long long, pair<int, int>>> tempDistVector;
		for (int j = 0; j < nodeY[curLayerY].size(); j++) {
			int curID = nodeY[curLayerY][j].second;
			int curX = nodeY[curLayerY][j].first;

			int parentLayerY = useY[i - 1];
			for (int k = 0; k<nodeY[parentLayerY].size(); k++) {
				int parentX = nodeY[parentLayerY][k].first;
				long long tempDist = (parentX - curX)*(parentX - curX) + (parentLayerY - curLayerY)*(parentLayerY - curLayerY);
				tempDistVector.push_back({ tempDist, { nodeY[parentLayerY][k].second, curID} });

			}
			
		}
		sort(tempDistVector.begin(), tempDistVector.end());
		for (int i = 0; i < tempDistVector.size(); i++) {
			int nodeAID = tempDistVector[i].second.first;
			int nodeBID = tempDistVector[i].second.second;//부모
			if (nodeinfo[nodeAID - 1][0] < nodeinfo[nodeBID - 1][0]) {
				if (tree[nodeBID][0] == 0 && treeParent[nodeAID] == 0 ) {
					if (nodeBID == rootID) {
						tree[nodeBID][0] = nodeAID;
						treeParent[nodeAID] = nodeBID;

					}
					else if ((tree[treeParent[nodeBID]][1] == nodeBID) && (nodeinfo[treeParent[nodeBID] - 1][0]<nodeinfo[nodeAID-1][0])) {
						tree[nodeBID][0] = nodeAID;
						treeParent[nodeAID] = nodeBID;
					}
					else if (tree[treeParent[nodeBID]][0] == nodeBID) {
						int curChildIDX = treeParent[nodeBID];
						int curTreeParentIDX = treeParent[curChildIDX];
						bool flagCurChildIDXRoot = false;
						while (true) {
							if (curChildIDX == rootID) {
								curTreeParentIDX = rootID;
								flagCurChildIDXRoot = true;
								break;
							}
							if (tree[curTreeParentIDX][1] == curChildIDX)
								break;
							curChildIDX = curTreeParentIDX;
							curTreeParentIDX = treeParent[curChildIDX];
						}
						if (curTreeParentIDX == rootID && flagCurChildIDXRoot) {
							tree[nodeBID][0] = nodeAID;
							treeParent[nodeAID] = nodeBID;

						}else if ((nodeinfo[curTreeParentIDX-1][0] < nodeinfo[nodeAID - 1][0])) {
							tree[nodeBID][0] = nodeAID;
							treeParent[nodeAID] = nodeBID;

						}

					}
					
				}
				
			}
			else {
				if (tree[nodeBID][1] == 0 && treeParent[nodeAID] == 0) {
					if (nodeBID == rootID) {
						tree[nodeBID][1] = nodeAID;
						treeParent[nodeAID] = nodeBID;

					}
					else if (tree[treeParent[nodeBID]][0] == nodeBID && nodeinfo[treeParent[nodeBID] - 1][0] > nodeinfo[nodeAID - 1][0]) {
						tree[nodeBID][1] = nodeAID;
						treeParent[nodeAID] = nodeBID;
					}
					else if (tree[treeParent[nodeBID]][1] == nodeBID) {

						int curChildIDX = treeParent[nodeBID];
						int curTreeParentIDX = treeParent[curChildIDX];
						bool flagCurChildIDXRoot = false;

						while (true) {
							if (curChildIDX == rootID) {
								curTreeParentIDX = rootID;
								flagCurChildIDXRoot = true;

								break;
							}
							if (tree[curTreeParentIDX][0] == curChildIDX)
								break;
							curChildIDX = curTreeParentIDX;
							curTreeParentIDX = treeParent[curChildIDX];
						}
						if (curTreeParentIDX == rootID && flagCurChildIDXRoot) {
							tree[nodeBID][1] = nodeAID;
							treeParent[nodeAID] = nodeBID;
						}
						else if (nodeinfo[curTreeParentIDX-1][0] > nodeinfo[nodeAID - 1][0]) {
							tree[nodeBID][1] = nodeAID;
							treeParent[nodeAID] = nodeBID;
						}
						

					}
					
				}
				
			}
			
		}

	}

	funPreorder(rootID);
	funPostorder(rootID);


	vector<vector<int>> answer;
	answer.push_back(preorder);
	answer.push_back(postorder);
	return answer;
}
int main() {
	vector<vector<int>> arr;
	vector<int> temp;
	temp.push_back(5);
	temp.push_back(3);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(11);
	temp.push_back(5);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(13);
	temp.push_back(3);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(3);
	temp.push_back(5);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(6);
	temp.push_back(1);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(3);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(8);
	temp.push_back(6);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(7);
	temp.push_back(2);
	arr.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(2);
	arr.push_back(temp);
	temp.clear();

	solution(arr);





}