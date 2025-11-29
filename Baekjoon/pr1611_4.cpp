#include <iostream>
#include <cmath>
using namespace std;

/*
나이트 이동 -> 1 2, 1 -2, -2 -1 이런식.. 1 2 조합인데 부호 자유롭게 -3, -1, 1, 3
킹 이동 -> 1 0, 0 1, 1 1 이고 마찬가지로 부호 자유 -2 -1 0 1 2
나이트가 승리하려면 위상차의 합이 3 차이나는 상태로 턴을 받아야 함
킹이 승리하려면 위상차의 합이 2이하인 상태로 턴을 받아야 함 -> 나이트가 승리하는 상황은 어차피 안줄거
즉, 나이트

첫 좌표에 바로 결정된다..?
dx dy 위상차 합이 짝수면 로하가 이걸 홀수로 만들수가 없다 -> 한양 승
dx dy 위상차가 홀수면 가 이걸 위상차 1로 만들수가 없다 -> 로하 승
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, M;
  int x1, y1, x2, y2;
  cin >> N >> M;
  cin >> x1 >> y1 >> x2 >> y2;

  int dy = abs(y2 - y1);
  int dx = abs(x2 - x1);

  if(abs(dy - dx) % 2 == 0) cout << "HANYANG";
  else cout << "LOHA";

  return 0;
}