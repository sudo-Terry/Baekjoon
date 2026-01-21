#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 200010

unordered_map<string, int> uid; // 아이디 매핑
int friend_count[MAX]; // 트리 크기
int root[MAX]; // 노드가 포함된 트리의 루트 노드 번호
int id_counter = 0;

int find_parent(int x) { // 루트 갱신
  if (root[x] == x) return x;
  return root[x] = find_parent(root[x]);
}

int add_friend(int x, int y) {
  x = find_parent(x);
  y = find_parent(y);

  if (x != y) {
    root[y] = x;
    friend_count[x] += friend_count[y];
  }
  return friend_count[x];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc, F;
  cin >> tc;

  while(tc--){
    uid.clear();
    string friend1, friend2;
    id_counter = 0;
    cin >> F;

    for (int i = 0; i <= F * 2; i++) {
      root[i] = i;
      friend_count[i] = 1;
    }

    while(F--){
      cin >> friend1 >> friend2;
      
      if (uid.find(friend1) == uid.end()) uid[friend1] = id_counter++;
      if (uid.find(friend2) == uid.end()) uid[friend2] = id_counter++;

      cout << add_friend(uid[friend1], uid[friend2]) << "\n";
    }
  }

  return 0;
}