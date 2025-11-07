#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;



int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  string iolog;
  string name, value;
  unordered_set<string> table;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> iolog;
    cin.ignore();
    istringstream iss(iolog);
    iss >> name >> value;

    if(value == "enter") table.insert(name);
    else table.erase(name);
  }


  vector<string> result(table.begin(), table.end());
  sort(result.begin(), result.end(), greater<string>()); // 역순 정렬

  for (string str : result)
    cout << str << '\n';

  return 0;
}