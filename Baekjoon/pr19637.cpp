#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> titles;
  vector<int> powers;

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    string title; 
    int power;
    cin >> title >> power;
    
    titles.push_back(title);
    powers.push_back(power);
  }

  while(M--){
    int target_power;
    cin >> target_power;


    int left = 0;
    int right = powers.size() - 1;
    int answer = right;

    while(left <= right){
      int mid = (left + right) / 2;

      if(powers[mid] >= target_power){
        answer = mid;
        right = mid - 1;
      }else{
        left = mid + 1;
      }
    }

    cout << titles[answer] << '\n';
  }

  return 0;
}
