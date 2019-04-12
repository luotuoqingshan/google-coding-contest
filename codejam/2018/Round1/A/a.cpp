#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int r, c, h, v;
const int maxn = 105;
char s[105][105];
int a[maxn][maxn];
int b[maxn], d[maxn];
int main(){
    int T;
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> r >> c >> h >> v;
        h++, v++;
        for(int i = 1;i <= r;i++){
            scanf("%s", s[i] + 1);
        }
        memset(a, 0, sizeof(a));
        for(int i = 1;i <= r;i++){
            for(int j = 1;j <= c;j++){
                a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + (s[i][j] == '@');
            }
        }
        int n = 0, m = 0;
        b[0] = 0;
        d[0] = 0;
        for(int i = 1;i <= r;i++){
            if(a[i][c] * h == a[r][c] * (n + 1)){
                b[++n] = i;
            }
        }
        for(int i = 1;i <= c;i++){
            if(a[r][i] * v == a[r][c] * (m + 1)){
                d[++m] = i;
            }
        }
        bool flag = true;
        if(a[r][c] % (h * v))
            flag = false;
        if(n < h || m < v)
            flag = false;
        for(int i = 1;i <= h;i++){
            for(int j = 1;j <= v;j++){
                int val = a[b[i]][d[j]] - a[b[i - 1]][d[j]] - a[b[i]][d[j - 1]] + a[b[i - 1]][d[j - 1]];
                if(val != (a[r][c] / h / v))
                    flag = false;
            }
        }
        printf("Case #%d: ",++cas);
        if(flag)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

