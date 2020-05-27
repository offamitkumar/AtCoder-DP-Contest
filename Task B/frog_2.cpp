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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n, k;
    scanf("%d %d",&n,&k);
    vector<int>v(n) , dp(n+1 , INT_MAX);
    for(auto&itr:v){
        cin>>itr;
    }
    dp[0] =0;
    for(int i=0; i < n; ++i ) {
        for( int j=i+1; j < i+k+1 && j<n; ++j ){ 
            dp[j] = min(dp[j] , dp[i]+abs(v[i]-v[j]));
        }
    }
    cout << dp[n-1] << '\n';
    return 0;
}
