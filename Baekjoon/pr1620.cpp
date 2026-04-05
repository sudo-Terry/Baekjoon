#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  unordered_map<int, string> pokemons_is;
  unordered_map<string, int> pokemons_si;
  string pokemon_name;
  for(int i = 1; i <= N; i++){
    cin >> pokemon_name;
    pokemons_is.insert({i, pokemon_name});
    pokemons_si.insert({pokemon_name, i});
  }
  string query;
  for(int i = 0; i < M; i++){
    cin >> query;
    if(query[0] >= '0' && query[0] <= '9'){
      cout << pokemons_is[stoi(query)] << '\n';
    }else{
      cout << pokemons_si[query] << '\n';
    }
  }

  return 0;
}