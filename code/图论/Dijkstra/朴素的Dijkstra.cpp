void dij(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0; //初始化dis数组
    for(int k = 1, t; k <= n; ++k) { //一共n轮，每次找不在S集合中的点中dis值最小的点，将其放入S集合中并用它去松弛其他点
        t = -1;
        for(int i = 1; i <= n; ++i)
            if(!flag[i] && (t == -1 || dis[i] < dis[t])) t = i; //如果（不在S中 && （ t还没有赋值 || i的dis值比t更小）），那么t = i
        flag[t] = true; //标记t在S集合中
        for(int i = 1; i <= n; ++i) //松弛操作
            dis[i] = min(dis[i], dis[t] + a[t][i]);
    }
}

