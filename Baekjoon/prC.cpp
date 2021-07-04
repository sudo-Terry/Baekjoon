#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;

typedef long long ll;
ll verNum[MAX], a[MAX], b[MAX];
ll tc = 0, n, ans = 0, len = 0;

int main() {
	cin >> tc;
	while (tc--) {
		ans = 0;
		cin >> n; //number of chains
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
		memset(verNum, 0, sizeof(verNum));
		for (int i = 1; i <= n; i++) cin >> verNum[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 2; i <= n; i++) {
			if (i == 2 || a[i] == b[i]) //강제로 닫힘
				len = 2 + (verNum[i] - 1) + abs(b[i] - a[i]);
			else {
				ll route1 = len + 2 + (verNum[i] - 1) - abs(b[i] - a[i]); //체인에서 닫지 않을 경우
				ll route2 = 2 + (verNum[i] - 1) + abs(b[i] - a[i]); //체인에서 닫을 경우
				len = max(route1, route2);//큰거 선택
			}
			if (len > ans) ans = len;
		}
		cout << ans << '\n';
	}
	return 0;
}


/*
1번 n번 체인 이외의 체인에서 a값과 b값의 중복이 있는지 살핀다
중복이 일어나는 체인 사이의 거리가 가장 큰 두 체인을 고른다 n1 n2
(n2 - n1)*2 는 각 체인을 건너가는데 필요한 수이다
각 체인 내에서는 (verNum[i] - b[i + 1]) + (a[i + 1] - 1)만큼 거리를 이동한다
사이클의 양 끝이 c1이거나 cn이 아닐 경우에는 양끝 체인에서의 추가 거리는 없으나
사이클의 양 끝이 c1이거나 cn이면 해당 체인에서 b[i - 1] - a[i - 1]만큼을 사이클 길이에 더한다

체인의 각 단계에서 닫을지 말지를 판단한다
현재 체인에서 닫는 경우와 여는 경우중 최댓값인 것을 계속 고른다
닫아서 체인이 더 크기 위해서는 뒤에 a[i] == b[i] 시점에서 강제로 닫힐 때의 최댓값보다 커야함
*/