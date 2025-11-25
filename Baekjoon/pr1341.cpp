#include <iostream>
#include <cmath>
using namespace std;

bool check[70];
/*
8 4 2 1
이런식으로 먹은 양을 정수화 할 수 있다
전체 합은 2^4 - 1 이고 이게 분모 b의 값
a는 영식(*)이가 먹은 부분들
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  long long a, b;
  cin >> a >> b;

  if (a == 0) {
		cout << "-";
		return 0;
	}

  if(a == b){
    cout << "*";
    return 0;
  }

  // n 구하기
  long long val = 1; 
  int n = 1;
  while (n <= 60) {
    val = (val * 2) % b;   // 2^n % b
    if (val == 1) break;   // 2^n == 1 (mod b)
    n++;
  }

  if (n > 60) {
    cout << "-1";
    return 0;
  }

  long long total = (1LL << n) - 1;  // 2^n - 1
  // total * a / b -> 오버플로우나서 안댐
  long long target = (total / b) * a; // 영식 실제 합

  for(int i = n - 1; i >=0; i--){
    if (target >= (1LL << i)) {
      check[i] = true;
      target -= (1LL << i);
    }
  }

  for(int i = n - 1; i >=0; i--){
    if(check[i]) cout << '*';
    else cout <<'-';
  }

  return 0;
}
