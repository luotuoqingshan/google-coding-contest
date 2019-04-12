#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T;
int n;
int p;

const int maxn = 105;

int w[maxn], h[maxn];
double d[maxn];

double dp[maxn][250 * maxn];

int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> n >> p;
        int sum = 0;
        int length = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &w[i], &h[i]);
            if(w[i] > h[i])
                swap(w[i], h[i]);
            d[i] = sqrt(1.0 * w[i] * w[i] + 1.0 * h[i] * h[i]);
            sum += w[i];
            length += 2 * (w[i] + h[i]);
        }
        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= sum;j++){
                dp[i][j] = -1;
            }
        } 
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= sum;j++){
                if(j >= w[i] && dp[i - 1][j - w[i]] != -1){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + d[i]); 
                }
                if(dp[i - 1][j] != -1){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
            }
        }
        double ans = length;
        for(int j = 0;j <= sum;j++){
            if(dp[n][j] != -1 && 2 * j + length <= p){
                ans = max(ans, min(dp[n][j] * 2 + length, 1.0 * p));
            }
        }
        printf("Case #%d: %.6lf\n", ++cas, ans);
    }
    return 0;
}
