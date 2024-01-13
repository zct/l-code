#include <bits/stdc++.h>
using namespace std;

class Soloution
{
public:
    int max_cost(vector<int> &servers, int k, int n)
    {
        sort(servers.begin(), servers.end());
        int capacity = 0;
        int cost = 0;
        // 相邻的最大
        for (int i = 0; i < n; i++)
        {
            capacity += servers[2 * i];
        }
        if (capacity >= k)
        {
            return 0;
        }
        // 如果小于k, 每次挑选差值最大的组合放进去，让capacity尽可能大;
        while (cost < n)
        {
            cout << capacity << endl;
            capacity += (servers[2 * n - 1 - cost] - servers[cost]);
            cost++;
            if (capacity >= k)
            {
                break;
            }
        }
        return cost;
    }
};

int main()
{
    Soloution s;
    vector<int> servers{1, 2, 3, 5, 7, 8};
    cout << s.max_cost(servers, 14, servers.size() / 2) << endl;
}