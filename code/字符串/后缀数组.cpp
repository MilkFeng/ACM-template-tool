struct SA {
    static const int MAXN = 1e5 + 50;
    static char tmpStr[MAXN];
    static int n, sa[MAXN], rk[MAXN], cnt[MAXN], x[MAXN], y[MAXN];
    static int height[MAXN], st[MAXN][35]; // 不需要可以删除，注意必须连同下面初始化一起删除 
    static void work(string s) {
        strcpy(tmpStr + 1, s.c_str());
        work(tmpStr);
    }
    static void work(char s[]) {
        int m = 255; n = strlen(s + 1);
        for(int i = 1; i <= n; ++i) ++cnt[x[i] = s[i]];
        for(int i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
        for(int i = n; i >= 1; --i) sa[cnt[x[i]]--] = i;
        for(int k = 1, p = 0; k <= n; k <<= 1, m = p, p = 0) {
            for(int i = n - k + 1; i <= n; ++i) y[++p] = i;
            for(int i = 1; i <= n; ++i) if(sa[i] > k) y[++p] = sa[i] - k;
            for(int i = 1; i <= m; ++i) cnt[i] = 0;
            for(int i = 1; i <= n; ++i) ++cnt[x[i]];
            for(int i = 2; i <= m; ++i) cnt[i] += cnt[i - 1];
            for(int i = n; i >= 1; --i) sa[cnt[x[y[i]]]--] = y[i], y[i] = 0;
            swap(x, y), x[sa[1]] = p = 1;
            for(int i = 2; i <= n; ++i)
                x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p : ++p;
            if(p == n) break;
        }
        for(int i = 1; i <= n; ++i) rk[sa[i]] = i;
        // height数组：引理 height[rk[i]] >= height[rk[i - 1]] - 1
        for(int i = 1, k = 0; i <= n; ++i) {
            if(rk[i] == 1) continue;
            if(k) --k;
            int j = sa[rk[i] - 1];
            while(j + k <= n && i + k <= n && s[i + k] == s[j + k]) ++k;
            height[rk[i]] = k;
        }
        // lcp数组的ST表：lcp(sa[i], sa[j]) = min(height[i......j])
        for(int i = 1; i <= n; ++i) st[i][0] = height[i];
        for(int i = n; i >= 1; --i)
            for(int j = 1; i + (1 << j) - 1 <= n; ++j)
                st[i][j] = min(st[i][j - 1], st[i + (1 << j) - 1][j - 1]);
    }
    static int lcp(int i, int j) { // ST表求LCP 
        int a = rk[i], b = rk[j];
        if(a == b) return 1;
        if(a > b) swap(a, b);
        int len = log2(b - a);
        return min(st[a + 1][len], st[b - (1 << len) + 1][len]);
    }
};
char SA::tmpStr[MAXN];
int SA::n, SA::sa[MAXN], SA::rk[MAXN], SA::cnt[MAXN], SA::x[MAXN], SA::y[MAXN];
int SA::height[MAXN], SA::st[MAXN][35]; // 这里
