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
#define MAXN (int)1e5+10
array<int,MAXN>arr;
array<int64_t,MAXN>dp;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    fill(dp.begin() , dp.begin()+n , INT_MAX);
    dp[0] = 0;
    for(int i=0;i<n;++i){
        for(int j:{1,2}){
            if(i+j>n){
                continue;
            }
            dp[i+j] = min(dp[i+j] , dp[i]+(int64_t)abs(arr[i]-arr[i+j]));
        }
    }
    cout<<dp[n-1]<<'\n';
    return 0;
}
