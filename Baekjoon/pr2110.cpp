#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAX 200100
#define HIGH 1000000010
using namespace std;

int n, c, ans;
vector<int> pos;
vector<int> dist; // 앞 좌표와의 거리
/*
공유기 n개를 설치 -> 거리를 n개의 부분합으로 표현
제일 최소인 거리를 앞이나 뒤의 부분합 중 작은 녀석에게 더한다?
1 2 3 4 5 에 3개를 설치하는 경우
dist  1 1 1 1
			2 1 1
			2 2
-> O(N*N) 시간초과 날듯
*/

int main() {
	ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		pos.push_back(temp);
	}
	sort(pos.begin(), pos.end());

	int before = 0;
	int high = 0;
	int low = HIGH;
	for(size_t i = 0; i < pos.size(); i++){
		dist.push_back(pos[i] - pos[i - 1]);
		low = min(low, pos[i] - pos[i - 1]);
	}
	high = pos[pos.size() - 1] - pos[0];

	int counter = 0; // 공유기 수 counter
	while(low <= high){
		counter = 0;
		int mid = (low + high) / 2;

		// 맨 앞에는 공유기를 둔다
		counter++;
		int partial_dist = 0;
		for(size_t i = 1; i < dist.size(); i++){
			partial_dist += dist[i];
			if(partial_dist >= mid){
				counter++;
				partial_dist = 0;
			}
		}

		// C개 이상 설치 가능하다면? -> 거리가 너무 좁거나 적당함 -> 거리를 늘려본다 (최대값을 찾기 위해)
		if (counter >= c) {
			ans = mid;     // 일단 현재 거리가 가능하므로 저장
			low = mid + 1; // 더 넓게 설치해보기
		} 
		// C개 미만 설치했다면? -> 거리가 너무 멂 -> 거리를 좁혀야 함
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}