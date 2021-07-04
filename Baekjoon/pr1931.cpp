#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

//알고리즘 > 고를 수 있는 회의 중에서 회의가 끝나는 시간이 가장 이른 것을 고르면 된다.

int main(void) {
	int n, temp, min; //n: 회의의 수      temp: int 임시변수 
	int count = 0;//결과값
	vector<pair<int, int>> conference;//회의 <시작, 끝> pair
	int tempS, tempE;//회의 시작 끝 임시변수
	int confEndMin = 0;
	int confStartMax;
	
	cin >> n;//회의의 수 입력
	
	for (int i = 0; i < n; i++) {//회의 시작 끝 입력
		cin >> tempS >> tempE;
		conference.push_back(make_pair(tempS, tempE));
	}
	sort(conference.begin(), conference.end()); //pair의 first 기준으로 오름차순(default) 정렬

	int k = conference.size();
	confStartMax = conference[k - 1].first;

	temp = conference[0].second;
	//더이상 회의를 할 수 없을때까지 이를 반복한다.
	//즉, 현재 회의의 종료시간이 모든 회의 시작 시간(회의 시작 시간의 최댓값)보다 클 경우 반복을 종료한다.
	while (confEndMin <= confStartMax) {//회의 시간중에서 회의가 끝나는 시간이 가장 이른 것을 찾고 count 값을 증가시킨다.
		for (int i = 0; i < conference.size(); i++) {//모든 회의들 중
			if (conference[i].first >= confEndMin) {//회의 가능한 것들(앞선 회의 종료 시간이 회의 시작 시간보다 작거나 같아야함) 중
				if (conference[i].second < temp)//회의 종료 시간이 가장 이른 회의를 선택
					temp = conference[i].second;
			}
		}
		confEndMin = temp;
		count++;
	}

	cout << count;

	return 0;
}