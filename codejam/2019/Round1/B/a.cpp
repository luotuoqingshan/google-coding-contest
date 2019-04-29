#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
int X[maxn], Y[maxn];

int main(){
    int T;
    cin >> T;
    int P, Q;
    int cas = 0;
    while(T--){
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        cin >> P >> Q; 
        for(int i = 1;i <= P;i++){
            int nx, ny;
            char dir[5];
            scanf("%d%d%s", &nx, &ny, dir);
            if(dir[0] == 'N'){
                Y[ny + 1] += 1;
                Y[Q + 1] -= 1;
            }else if(dir[0] == 'S'){
                Y[0] += 1;
                Y[ny] -= 1;
            }else if(dir[0] == 'E'){
                X[nx + 1] += 1;
                X[Q + 1] -= 1;
            }else{
                X[0] += 1;
                X[nx] -= 1;
            }
        }
        for(int i = 1;i <= Q;i++){
            X[i] += X[i - 1];
            Y[i] += Y[i - 1];
        }
        int xid = 0, xval = X[0];
        int yid = 0, yval = Y[0];
        for(int i = 1;i <= Q;i++){
            if(X[i] > xval){
                xid = i;
                xval = X[i];
            }
            if(Y[i] > yval){
                yid = i;
                yval = Y[i];
            }
        }
        printf("Case #%d: %d %d\n", ++cas, xid, yid);
    }
    return 0;
}
