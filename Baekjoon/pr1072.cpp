#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long X, Y;
  cin >> X >> Y;
  long long Z = (Y * 100) / X;

  if(Z >= 99){
    cout << -1;
    return 0;
  }

  int left = 1;
  int right = 1000000000;
  int mid, ans;
  while(left <= right){
    mid = (left + right) / 2;

    long long acc = ((Y + mid) * 100) / (X + mid);

    if(acc > Z){ // 게임수가 부족함
      right = mid - 1;
      ans = mid;
    }else{
      left = mid + 1;
    }
  }

  cout << ans;

  return 0;
}