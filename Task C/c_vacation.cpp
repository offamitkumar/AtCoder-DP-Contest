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
#define MAXN (int)(1e5+10)
int dp[MAXN][3];
int arr[MAXN][3];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    memset(dp, 0, sizeof(dp));
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    for (int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    printf("%d\n",max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}
