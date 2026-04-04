#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  unordered_map<long long, int> hmap;
  long long temp;
  long long most_card = 0, card_count_max = 0;
  for(int i = 0; i < N; i++){
    cin >> temp;
    hmap[temp]++;
    
    if(hmap[temp] > card_count_max){
      card_count_max = hmap[temp];
      most_card = temp;
    }else if(hmap[temp] == card_count_max){
      most_card = min(most_card, temp);
    }
  }

  cout << most_card;

  return 0;
}