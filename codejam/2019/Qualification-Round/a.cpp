#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char s[105];
char a[105];
char b[105];
int main(){
    int T;
    cin >> T;
    for(int cas = 1;cas <= T;cas++){
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for(int i = 1;i <= len;i++){
            if(s[i] == '4')
                a[i] = '2', b[i] = '2';
            else
                a[i] = s[i], b[i] = '0';
        }
        printf("Case #%d: ", cas);
        bool first = false;
        for(int i = 1;i <= len;i++){
            if(a[i] != '0'){
                first = true;
                putchar(a[i]);
            }else{
                if(first)
                    putchar(a[i]);
            }
        }
        putchar(' ');
        first = false;
        for(int i = 1;i <= len;i++){
            if(b[i] != '0'){
                first = true;
                putchar(b[i]);
            }else{
                if(first)
                    putchar(b[i]);
            }
        }
        puts("");
    }
    
    return 0;
}
