#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
  int x;
  int y;
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<Pos> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec[i].x >> vec[i].y;
  }

  sort(vec.begin(), vec.end(), [](const Pos& a, const Pos& b){
    if(a.x == b.x){
      return a.y < b.y;
    }else{
      return a.x < b.x;
    }
  });

  for(size_t i = 0 ; i < vec.size(); i++){
    cout << vec[i].x << ' ' << vec[i].y << '\n';
  }

  return 0;
}