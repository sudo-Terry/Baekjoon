#include <iostream>
#define MAX 1000

using namespace std;
int n = 0;
int arr[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//시작점이 되는 것은 Sk으로, 좌 우가 모두 작아진다.
//dp[n-2] 가 증가하기만 하는 바이토닉 부분수열일 경우를 생각해보자
//n번째 수가 n-1번째 수보다 클 경우 getArr(n-1) return dp[n-1] = dp[n-2] + 1
//n번재 수가 n-1번째 수보다 작을 경우에는 바이토닉의 감소부분이 될 수도 있고 바이토닉이 바뀔 수도 있다? getArr(n-1) return dp[n-1]= 
//dp[n-2]가 바이토닉 부분수열의 감소하는 부분에 해당하는데 n번째 수가 n-1보다 작으면 getArr(n-1) return dp[n-1] = dp[n-2] + 1
//반대로 n번째 수가 n-1보다 크다면 getArr(n-1) return dp[n-1]=

int getArr(int n) {

}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << dp[n - 1];
	return 0;
}