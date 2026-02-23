#include <iostream>
#include <vector>
using namespace std;

int N;
// N = 3 * a + 5 * b;
/*
3  8  13
6  11 16
9  14 19
12 17 22
*/
vector<int> arr;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  int a, b;
  if((N - 3) % 5 == 0 && N >= 3){
    int a = 1;
    int b = (N - 3) / 5;
    cout << a + b;
  }else if((N - 6) % 5 == 0 && N >= 6){
    int a = 2;
    int b = (N - 6) / 5;
    cout << a + b;
  }else if((N - 9) % 5 == 0 && N >= 9){
    int a = 3;
    int b = (N - 9) / 5;
    cout << a + b;
  }else if((N - 12) % 5 == 0 && N >= 12){
    int a = 4;
    int b = (N - 12) / 5;
    cout << a + b;
  }else if(N % 5 == 0){
    int a = 0;
    int b = N / 5;
    cout << a + b;
  }else{
    cout << "-1";
  }

  
  return 0;
}