#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXW (int)(1e5+10000)
#define MAXN (int)(203)
long long dp[MAXN][MAXW];
array<pair<long long, long long>, MAXN>arr;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    memset(dp, 0ll, sizeof(dp));
    long long n, w; cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (arr[i].first <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - arr[i].first] + arr[i].second);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << '\n';
    return 0;
}
