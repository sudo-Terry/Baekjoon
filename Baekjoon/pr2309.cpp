#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10

int sum, n = 0;
int bundle[MAX];

void solve() {
  n = 9;

  for (int i = 0; i < n; i++) {
    cin >> bundle[i];
  }
  sort(bundle, bundle + 9);

  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (i == j) continue;
      
      sum = 0;
      for(int k = 0; k < n; k++){
        if(k != i && k != j)
          sum += bundle[k];
      }
      
      if (sum == 100){
        for (int l = 0; l < n; l++){
          if (l != i && l != j){
            cout << bundle[l] << endl;
          }          
        }
        return;
      }
    }
  }
}

int main() {
  // cout, cin의 연결을 해제
  // 입력한 숫자: 10 이런식으로 입력처리를 해야 하는 경우가 아니면 속도 개선에 사용
	cin.tie(0);
  // C++, C의 입출력 스트림이 같은 버퍼를 사용하지 않도록 처리 -> 속도 개선
	ios_base::sync_with_stdio(0);
	
  solve();
  
	return 0;
}
