#include <iostream>
#define MAX 1000

using namespace std;
int n = 0;
int lastMax = 0;
int lastMax2 = 0;
int arr[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//dp[n]: n개의 수열 입력에 대해 가장 긴 증가하는 부분 수열의 길이 // lastMax: dp[n] 부분수열의 마지막 숫자
//알고리즘 > n번째 숫자가 lastMax값보다 클 경우 dp[n] = dp[n-1] + 1
//n번째 숫자가 lastMax 값보다 작은 경우에는 lastMax2 와 그 값을 비교하여 


int getArrlen(int n) {

}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	return 0;
}