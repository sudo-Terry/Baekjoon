#include <iostream>
#include <cstring>
#include <set>
#include <iomanip>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  multiset<string> trees;
  string tree;
  int counter = 0;
  while(getline(cin, tree)){
    counter++;
    trees.insert(tree);
  }

  while(!trees.empty()){
    string target = *trees.begin();
    auto start = trees.lower_bound(target);
    auto end = trees.upper_bound(target);

    int count = distance(start, end);

    double rate = (double)count / counter * 100;
    
    cout << target << " " << fixed << setprecision(4) << rate << "\n";

    trees.erase(target);
  }

  return 0;
}