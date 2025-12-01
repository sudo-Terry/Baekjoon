#include <iostream>
#include <vector>
using namespace std;

/**
 * 1 -> 제일 작은데 2라는건 자신이 index 2에 있다 (3번째)
 * 2 -> 다음으로 작은데 1이라는건 자신이 index 1에 있다
 * 3 -> 그 다음으로 작은데 1이라는건 자신이 index 
*/
int order[11];
bool visited[11];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  vector<int> left_taller_count;
  cin >> N;
  for(int i = 1; i <=N; i++){
    int taller_count;
    cin >> taller_count;
    left_taller_count.push_back(taller_count);
  }
  for(int i = 1; i <= N; i++){
    int counter = 0;
    for(int j = 0; j < N; j++){
      if(!visited[j]){
        if(counter == left_taller_count[i - 1]) {
          order[j] = i;
          visited[j] = true;
        }
        counter++;
      }
    }
  }

  for(int i = 0; i < N; i++){
    cout << order[i] << ' ';
  }

  return 0;
}