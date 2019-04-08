#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int T;
int R, B;

int dp[2][501][501][33];

void upd(int &x, int y){
    if(y > x)
        x = y;
}

int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        memset(dp, -1, sizeof(dp));
        cin >> R >> B;
        int ans = 0;
        for(int i = 0;1 * i * (i + 1) / 2 <= B;i++){
            dp[0][R][B - i * (i + 1) / 2][i] = i;
            ans = max(ans, i);
        }
        for(int k = 0;1 * k * (k + 1) / 2 <= R;k++){
            memset(dp[(k+1)&1], -1, sizeof(dp[(k+1)&1]));
            for(int i = R;i >= 0;i--){
                for(int j = B;j >= 0;j--){
                    for(int l = 0;1 * l * (l + 1) / 2 <= B;l++){
                        if(dp[k&1][i][j][l] == -1) continue;
                        ans = max(ans, dp[k&1][i][j][l]);
                        if(i >= k && j >= l + 1){
                            upd(dp[k&1][i - k][j - (l + 1)][l + 1], dp[k&1][i][j][l] + 1);
                        }
                        if(i >= (k + 1)){
                            upd(dp[(k+1)&1][i-(k+1)][j][0], dp[k&1][i][j][l] + 1);
                        }
                    }
                }
            }
        }
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
    return 0;
}

