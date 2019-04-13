#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


using int64 = long long;

void exgcd(int64 a, int64 b, int64 &g, int64 &x, int64 &y){
    if(!b) x = 1, y = 0, g = a;
    else{
        exgcd(b, a % b, g, y, x);
        y -= x * (a / b);
    }
}

int64 crt(int n, int64 *c, int64 *m){
    int64 M = 1, ans = 0;
    for(int i = 0;i < n;i++) M *= m[i];
    for(int i = 0;i < n;i++){
        int64 x, y, g, tm = M / m[i];
        exgcd(tm, m[i], g, x, y);
        ans = (ans + tm * x * c[i] % M) % M;
    }
    return (ans + M) % M;
}

int64 m[7] = {4, 9, 5, 7, 11, 13, 17};
int64 c[7];
int main(){
    int T;
    int n, M;
    cin >> T >> n >> M;
    int cas = 0;
    while(T--){
        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 18;j++){
                printf("%lld%c", m[i], j == 17 ? '\n' : ' ');
            }
            fflush(stdout);
            c[i] = 0;
            for(int j = 0;j < 18;j++){
                int tmp;
                cin >> tmp;
                c[i] = (c[i] + tmp) % m[i];
            }
        }
        int64 ans = crt(7, c, m);
        printf("%lld\n", ans);
        fflush(stdout);
        int verdict;
        cin >> verdict;
        if(verdict == -1)
            break;
    }
    return 0;
}
