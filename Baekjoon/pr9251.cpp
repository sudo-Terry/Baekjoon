#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000

using namespace std;

int dp[MAX + 1][MAX + 1] = { 0, };
//dp테이블 정의 dp[i][j] = i길이의 문자열과 j길이의 문자열의 LCS 길이
//LCS길이가 변하는 시점은 i+1, j+1에 같은 문자가 나타나는 경우
//i와 j번째 문자가 같을 경우 dp[i+1][j+1] = dp[i][j] + 1;
//이후 dp[i+1][j+2]~ dp[i+1][끝까지] 와 dp[i+2][0]~dp[i+2][j+1]까지는 dp[i+1][j+1]값으로 채우고
//dp[i+2][j+2]부터 다시 j+2~부터 i+1번째와 j+1번째 문자가 같아지는 시점을 찾아 이를 반복한다. 


int main(void) {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i < str1.length() + 1; i++) {
		for (int j = 1; j < str2.length() + 1; j++) {
			if (str1.at(i - 1) == str2.at(j - 1))
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[str1.length()][str2.length()];

	return 0;
}