#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
const int maxn = 105;
int n;

int a[maxn][maxn];

struct KM{
    typedef long long cost_t;
    static const int N = 1000;
    static const cost_t inf = 1e9;
    cost_t lx[N], ly[N], w[N][N], slack[N];
    int n, left[N];
    bool S[N], T[N];
    bool match(int i){
        S[i] = true;
        for(int j = 1;j <= n;j++){
            if(T[j])
                continue;
            cost_t tmp = lx[i] + ly[j] - w[i][j];
            if(tmp == 0){
                T[j] = true;
                if(!left[j] || match(left[j])){
                    left[j] = i;
                    return true;
                }
            }else{
                slack[j] = min(slack[j], tmp);
            }
        }
        return false;
    }
    void update(){
        cost_t a = inf;
        for(int j = 1;j <= n;j++)
            if(!T[j])
                a = min(a, slack[j]);
        for(int i = 1;i <= n;i++){
            if(S[i]) lx[i] -= a;
            if(T[i]) ly[i] += a;
        }
    }
    void Solve(){
        for(int i = 1;i <= n;i++){
            left[i] = lx[i] = ly[i] = 0;
            for(int j = 1;j <= n;j++){
                lx[i] = max(lx[i], w[i][j]); 
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                slack[j] = inf;
            }
            for(;;){
                for(int j = 1;j <= n;j++)
                    S[j] = T[j] = 0;
                if(match(i))
                    break;
                else
                    update();
            }
        }
    }
}km;

int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                scanf("%d", &a[i][j]);
            }
        }
        int ans = 0;
        km.n = n;
        for(int val = -n;val <= n;val++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    km.w[i][j] = 0;
                    if(a[i][j] == val){
                        km.w[i][j] = 1;
                    }
                }
            }
            km.Solve();
            for(int j = 1;j <= n;j++){
                if(km.left[j] != 0){
                    ans += km.w[km.left[j]][j];
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, n * n - ans);
    }
    return 0;
}

