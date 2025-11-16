#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  vector<int> arr;
  int ans = 0;

  cin >> N >> M;
  for(int i = 0; i < N ; i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  int left = 0;
  int right = 0;
  int sum = 0;
  while(true){
    if(sum == M) ans ++;
    
    if(sum >= M) { // 값을 줄여야 하므로 left를 이동하며 값을 뺀다
      sum -= arr[left++];
    }else if(right == N) { // 값을 더해야 하는데 더 이상 숫자가 없으니 break
      break;
    }else { // 값을 키워야 하므로 right를 이동하며 값을 더한다
      sum += arr[right++];
    }
  }

  cout << ans;

  return 0;
}