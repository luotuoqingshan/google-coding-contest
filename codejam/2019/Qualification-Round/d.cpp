#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int T;
int n;
int b;
int f;
int ans[1050];
bool vis[1050];
int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> n >> b >> f;
        cas++;
        memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i < f;i++){
            string s = "";
            for(int j = 0;j < n;j++){
                if(j & (1 << i)){
                    s += '1';
                }else{
                    s += '0';
                }
            }
            cout << s << endl;
            fflush(stdout);
            string t;
            cin >> t;
            for(int j = 0;j < n - b;j++){
                if(t[j] == '1'){
                    ans[j] |= (1 << i);
                }
            }
        }
        if(f == 10){
            for(int j = 0;j < n - b;j++){
                vis[ans[j]] = true;
            } 
            bool first = true;
            for(int j = 0;j < n;j++){
                if(!vis[j]){
                    if(first)
                        first = false;
                    else
                        cout << " ";
                    cout << j;
                }
            }
            cout << endl;
            fflush(stdout);
            int verdict;
            cin >> verdict;
            if(verdict == -1)
                break;
        }else{
            int block = 0;
            for(int j = 0;j < n - b;j++){
                if(j > 0 && ans[j-1] >= ans[j])
                    block++;
                vis[block*32+ans[j]]=true;
            }
            bool first = true;
            for(int j = 0;j < n;j++){
                if(!vis[j]){
                    if(first)
                        first = false;
                    else
                        cout << " ";
                    cout << j;
                }
            }
            cout << endl;
            fflush(stdout);
            int verdict;
            cin >> verdict;
            if(verdict == -1)
                break;
        }
    }
    return 0;
}

