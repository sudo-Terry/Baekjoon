#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> cookies;

long long get_cookie_num(long long length){
  long long cnt = 0;
  for(long long c : cookies){
    cnt += (c / length);
  }
  return cnt;
}

// 모든 과자를 나누었을 때, 몫이 M 이상이어야 한다
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int M, N;
  cin >> M >> N;
  long long max_cookie = 0;
  for(int i = 0; i < N; i++) {
    long long temp;
    cin >> temp;
    max_cookie = max(max_cookie, temp);
    cookies.push_back(temp);
  }
  // sort(cookies.begin(), cookies.end());

  long long start = 1;
  long long end = max_cookie;
  long long answer = 0;

  while(start <= end){
    long long mid = (start + end) / 2;

    long long cnt = get_cookie_num(mid);

    if(cnt >= M){  
      answer = mid;
      start = mid + 1;
    }
    else{
      end = mid - 1;
    }
  }

  cout << answer;
  return 0;
}