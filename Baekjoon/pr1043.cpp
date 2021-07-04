#include <iostream>
#include <vector>
#define MAX 60
using namespace std;

int n, m, knowsNum, knowsIndex, partyMemNum;
bool knowsT[MAX];
vector<int> partyMem[MAX];
bool flag = false;
bool changeflag = true;

int main() {
	int ans = 0;
	cin >> n >> m;
	cin >> knowsNum;
	for (int i = 0; i < knowsNum; i++) {
		cin >> knowsIndex;
		knowsT[knowsIndex] = true;
	}
	for (int i = 0; i < m; i++) {
		partyMemNum = 0;
		cin >> partyMemNum;
		for (int j = 0; j < partyMemNum; j++) {
			int partyMemIndex;
			cin >> partyMemIndex;
			partyMem[i].push_back(partyMemIndex);
		}
	}
	while (changeflag) {
		changeflag = false;
		for (int i = 0; i < m; i++) {
			flag = false;
			for (int j = 0; j < partyMem[i].size(); j++) {
				if (knowsT[partyMem[i][j]])
					flag = true;
			}
			if (flag) {
				for (int j = 0; j < partyMem[i].size(); j++) {
					if (!knowsT[partyMem[i][j]])//¹Ù²ï°Ô ÀÖÀ½
						changeflag = true;
					knowsT[partyMem[i][j]] = true;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (!knowsT[partyMem[i][0]])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}