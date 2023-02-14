void dij(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0; //初始化dis数组
    priority_queue<pair<int, int>> q; //一个优先队列
    q.push({0, s}); //c++中的pair<int, int>默认先按第一维比较，所以把dis值放在第一维
    while(!q.empty()) {
        int x = q.top().second; q.pop(); //取堆顶
        if(flag[x]) continue; //判断是否已经在S集合中，如果已经在S集合中，那么直接continue
        flag[x] = true; //标记x在S集合中
        for(int i = fr[x], y; i; i = nxt[i]) { //遍历所有与x相连的边
            y = to[i];
            if(dis[y] > dis[x] + w[i]) { //判断是否可以松弛。
                dis[y] = dis[x] + w[i];
                if(!flag[y]) q.push({-dis[y], y}); //c++中的优先队列默认为大根堆，而我们需要小根堆，为了方便可以直接取相反数
            }
        }
    }
}

