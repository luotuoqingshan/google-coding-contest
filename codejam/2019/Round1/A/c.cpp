#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;


const int maxn = 1005 * 26;

int ch[maxn][26];
int val[maxn];
int T;
int n;
int sz;
string s[maxn];

int idx(char c){return c - 'A';}

void insert(string s){
    int u = 0;
    for(int i = 0;i < s.length();i++){
        int c = idx(s[i]);
        if(!ch[u][c]){
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
        val[u]++;
    }
}

int dfs(int u){
    int now =  val[u];
    int sum = 0;
    for(int i = 0;i < 26;i++){
        if(ch[u][i] != 0){
            int tmp = dfs(ch[u][i]);
            now -= tmp;
            sum += tmp;
        }
    }
    now = max(now, 0);
    if(now >= 2)
        return sum + 2;
    else
        return sum;
}


int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        for(int i = 1;i <= n;i++){
            insert(s[i]);
        }
        printf("Case #%d: %d\n", ++cas, dfs(0));
    } 
    return 0;
}
