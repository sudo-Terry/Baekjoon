#include<iostream>
#include<vector>
#include<cstring>
#include<string>

#define endl "\n"
#define MAX 510
#define INF 987654321
using namespace std;

int N, M, W;
int Dist[MAX];
string Answer;
vector<pair<pair<int, int>, int>> Edge;

void Solution()
{
    Dist[1] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < Edge.size(); j++)
        {
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;

            if (Dist[From] == INF) continue;
            if (Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
        }
    }
    for (int i = 0; i < Edge.size(); i++)
    {
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;

        if (Dist[From] == INF) continue;
        if (Dist[To] > Dist[From] + Cost)
        {
            Answer = "YES";
            return;
        }
    }
    Answer = "NO";
}


int main(void)
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        for (int i = 1; i < MAX; i++) Dist[i] = INF;
        memset(Dist, -1, sizeof(Dist));
        Edge.clear();
        cin >> N >> M >> W;
        for (int i = 0; i < M; i++)
        {
            int From, To, Cost;
            cin >> From >> To >> Cost;
            Edge.push_back(make_pair(make_pair(From, To), Cost));
            Edge.push_back(make_pair(make_pair(To, From), Cost));
        }
        for (int i = 0; i < W; i++)
        {
            int From, To, Cost;
            cin >> From >> To >> Cost;
            Edge.push_back(make_pair(make_pair(From, To), -Cost));
        }
        Solution();
        cout << Answer << endl;
    }
    return 0;
}
