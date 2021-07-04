#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//알고리즘 > 무게추를 오름차순으로 정렬하여 무게가 작은 순서부터 생각한다.
//우리가 무게추를 이용하여 측정할 수 있는 무게들은 구간으로 정의할 수 있다.
//우리가 측정할 수 있는 무게의 구간은 연속일 것이며 측정할 수 없는 가장 최소의 값에서 구간이 불연속할 것이다.
//만약 불연속인 구간이 발생할 경우 무게추가 오름차순으로 정렬되어 있음을 고려해보면 그 불연속인 구간은 다시는 메워질 수 없으므로 처음으로 불연속이 발생한 지점이 구하고자 하는 값이다.

//ex 가령 무게추 a를 사용하면서 불연속한 지점이 발생하여 A~B, (A+a)~(B+a)구간이 연속이게 되었다고 하자.
//다음으로 사용하는 무게추 b는 정렬 알고리즘에 의해 a보다 크거나 같으므로 구간은 A~B, (A+a)~(B+a), (A+b)~(B+b), (A+a+b)~(B+a+b)가 된다.
// 즉, 처음으로 불연속인 지점이 발생하면, 이는 메워질 수 없다.
//불연속이 발생하려면 B+1 < A+a 이어야 하며 이 경우 불연속인 지점은 B+1이다.

int main(void) {
	
	int n = 0;
	int begin = 0;
	int end = 0;
	int tempWeight = 0;
	vector<int> sinkers;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tempWeight;
		sinkers.push_back(tempWeight);
	}
	sort(sinkers.begin(), sinkers.end());

	if (sinkers[0] != 1) { //가장 가벼운 무게추가 1이 아니면 1은 측정할 수 없음
		cout << 1;
		return 0;
	}

	//가장 가벼운 무게추가 1인 경우
	end = 1; //초기값
	for (int i = 1; i < n; i++) {
		if (end + 1 < sinkers[i]) {
			break;
		}
		end += sinkers[i];
	}

	cout << end + 1 << endl;
	return 0;
}