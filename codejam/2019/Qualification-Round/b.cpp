#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];

int main(){
    int T;
    cin >> T;
    for(int cas = 1;cas <= T;cas++){
        int n;
        cin >> n;
        printf("Case #%d: ", cas);
        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0;j < len;j++){
            if(s[j] == 'E')
                putchar('S');
            else
                putchar('E');
        }
        puts("");
    }
    return 0;
}
