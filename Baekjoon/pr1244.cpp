#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int switch_count, student_count;
  vector<bool> switch_status;

  cin >> switch_count;
  switch_status.push_back(false); // index 0은 안씀
  for(int i = 0; i < switch_count; i++){
    int temp;
    cin >> temp;
    switch_status.push_back(temp == 1);
  }

  cin >> student_count;
  for(int i = 0; i < student_count; i++){
    int gender;
    int temp;
    cin >> gender >> temp;
    
    if(gender == 1){
      for(int j = 1; j * temp <= switch_count; j++){
        switch_status[temp * j] = !switch_status[temp * j];
      }
    }else {
      switch_status[temp] = !switch_status[temp];
      int left = temp - 1;
      int right = temp + 1;

      while(left >= 1 && right <= switch_count && 
            switch_status[left] == switch_status[right]){

        switch_status[left] = !switch_status[left];
        switch_status[right] = !switch_status[right];
        
        left--;
        right++;
      }
    }
  }

  for(int i = 1; i <= switch_count; i++){
    cout << (switch_status[i] ? 1 : 0 ) << ' ';

    if( i % 20 == 0 ) cout << '\n';
  }

  return 0;
}