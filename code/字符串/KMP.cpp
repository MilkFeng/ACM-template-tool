// 未经验证 
int nxt[MAXN];
void getNext(char s[]) { // 模式串next数组 
    int n = strlen(s + 1);
    for(int i = 0; i <= n; ++i) nxt[i] = 0;
    for(int i = 2, j = 0; i <= n; ++j) {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) ++j;
        nxt[i] = j;
    }
}
int kmp(char s[], char t[]) { //返回第一次匹配的地方，否则返回-1 
    int n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 1, j = 0; i <= m; ++j) {
        while(j && t[i] != s[j + 1]) j = nxt[j];
        if(t[i] == s[j + 1]) ++j;
        if(j == n) return i - m + 1;
    }
    return -1;
}
