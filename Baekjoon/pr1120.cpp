#include <iostream>
#include <cstring>
using namespace std;
#define INF 100

/*
A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
추가하는 알파벳은 인덱스에 맞게 추가한다고 가정
그럼 A를 슬라이딩하면서 B와의 차이 최솟값을 구하면댐
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string A, B;
  cin >> A >> B;

  int ans = INF;
  for(size_t i = 0; i <= B.size() - A.size(); i++){
    int counter = 0;
    for(size_t j = 0; j < A.size(); j++){
      if(B[i + j] != A[j]) counter++;
    }

    ans = min(ans, counter);
  }

  cout << ans;

  return 0;
}