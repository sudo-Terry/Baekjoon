#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  long long W, H, f, c, x1, y1, x2, y2;

  cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

  long long color_count = 0;
  // 포갰을 때 더 넓은 영역
  color_count = (x2 - x1) * (y2 - y1) * (c + 1);

  // 포갰을 때 더 좁은 영역
  if(2 * f <= W){ // 접혀서 다 못포개는 경우
    if(x2 >= f){
      if(x1 <= f) color_count += (f - x1) * (y2 - y1) * (c + 1);
    }else{ // 전체가 겹침
      color_count *= 2;
    }
  }else{ // 접었을 때 다 덮고도 남는 경우
    long long limit = W - f;
    if(x2 >= limit){
      // x1이 겹치는 구간(limit)보다 왼쪽에 있으면, 겹치는 부분만큼(limit - x1) 더해줌
      if(x1 <= limit) color_count += (limit - x1) * (y2 - y1) * (c + 1);
    }else{ // 전체가 겹침
      color_count *= 2;
    }
  }

  cout << W * H - color_count << '\n';

  return 0;
}