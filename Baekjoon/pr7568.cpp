#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> height_v; 
vector<int> weight_v;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++){
    int weight, height;
    cin >> weight >> height;
    weight_v.push_back(weight);
    height_v.push_back(height);
  }

  for(int i = 0; i < N; i++){
    int counter = 1;

    for (int j = 0; j < N; j++){
      if (i == j) continue;

      if (weight_v[i] < weight_v[j] && height_v[i] < height_v[j]) counter++;
    }
    cout << counter << ' ';
  }

  return 0;
}