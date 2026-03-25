#include <iostream>
#include <algorithm>
using namespace std;

// 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.
// 첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

int serialize(int x, int y){
  int ans = 0;

  if(x > 2) ans += 28;

  if(x > 1) ans += 31;
  if(x > 3) ans += 31;
  if(x > 5) ans += 31;
  if(x > 7) ans += 31;
  if(x > 8) ans += 31;
  if(x > 10) ans += 31;
  if(x > 12) ans += 31;

  if(x > 4) ans += 30;
  if(x > 6) ans += 30;
  if(x > 9) ans += 30;
  if(x > 11) ans += 30;

  return ans + y;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int X, Y;
  cin >> X >> Y;

  int day_count = serialize(X, Y);
  int offset = (day_count - 1) % 7 ;

  if(offset == 0) cout << "MON";
  if(offset == 1) cout << "TUE";
  if(offset == 2) cout << "WED";
  if(offset == 3) cout << "THU";
  if(offset == 4) cout << "FRI";
  if(offset == 5) cout << "SAT";
  if(offset == 6) cout << "SUN";

  return 0;
}