#include <iostream>
#include <queue>

using namespace std;

typedef struct s_node {
    int idx;
    int arv_t;
    int gar_t;
}   node;

struct i_cmp {
    bool operator()(node a, node b) {
        return a.idx > b.idx;
    }
};

struct a_cmp {
    bool operator()(node a, node b) {
        return a.arv_t > b.arv_t;
    }
};

int now_t;
int max_wtime;
priority_queue<node, vector<node>, a_cmp> pq;
priority_queue<node, vector<node>, i_cmp> waiting;

int main() {
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    int input;
    node here;

    cin >> input;
    for (int i = 1; i <= input; i++) {
        node tmp;
        tmp.idx = i;
        cin >> tmp.arv_t >> tmp.gar_t;
        pq.push(tmp);
    }

    here = pq.top();
    pq.pop();
    now_t = here.arv_t;
    int flag = 0;
    while (!pq.empty() || !waiting.empty())
    {
        now_t += here.gar_t;
        while (!pq.empty() && pq.top().arv_t < now_t)
        {
            waiting.push(pq.top());
            pq.pop();
            flag = 1;
        }
        if (waiting.empty() && flag == 0)
        {
            now_t = pq.top().arv_t;
            waiting.push(pq.top());
            pq.pop();
        }
        flag = 0;
        if (!waiting.empty() && now_t - waiting.top().arv_t > max_wtime)
            max_wtime = now_t - waiting.top().arv_t;
        here = waiting.top();
        waiting.pop();
    }
    cout << max_wtime;
    return 0;
}