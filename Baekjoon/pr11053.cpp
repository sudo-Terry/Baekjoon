#include <iostream>
#define MAX 1000

using namespace std;
int n = 0;
int lastMax = 0;
int lastMax2 = 0;
int arr[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//dp[n]: n���� ���� �Է¿� ���� ���� �� �����ϴ� �κ� ������ ���� // lastMax: dp[n] �κм����� ������ ����
//�˰��� > n��° ���ڰ� lastMax������ Ŭ ��� dp[n] = dp[n-1] + 1
//n��° ���ڰ� lastMax ������ ���� ��쿡�� lastMax2 �� �� ���� ���Ͽ� 


int getArrlen(int n) {

}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	return 0;
}