#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct s_node {
    s_node  *prev;
    s_node  *next;
    int     idx;

    s_node(int idx) :
        idx(idx),
        prev(nullptr),
        next(nullptr) {}
}   Node;

unordered_map<int, Node *> map;

void    init_nodes(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Node *node = new Node(i);
        map.insert(make_pair(i, node));
    }
}

void    pop(int i)
{
    Node    *node = map.at(i);

    if (node->prev && node->next)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
    else if (node->prev)
    {
        node->prev->next = nullptr;
        node->prev = nullptr;
    }
    else if (node->next)
    {
        node->next->prev = nullptr;
        node->next = nullptr;
    }
}

void    insert_front(int j, int i) // j번 노드를 i 번 노드 앞에 삽입
{
    Node    *i_node = map.at(i);
    Node    *j_node = map.at(j);

    if (i_node->prev)
    {
        i_node->prev->next = j_node;
        j_node->prev = i_node->prev;
    }
    i_node->prev = j_node;
    j_node->next = i_node;
}

void    insert_behind(int j, int i) // j번 노드를 i 번 노드 뒤에 삽입
{
    Node    *i_node = map.at(i);
    Node    *j_node = map.at(j);

    if (i_node->next)
    {
        i_node->next->prev = j_node;
        j_node->next = i_node->next;
    }
    i_node->next = j_node;
    j_node->prev = i_node;
}

void    print(int i)
{
    Node *node = map.at(i);

    if (node->prev)
        cout << node->prev->idx << ' ';
    else
        cout << 0 << ' ';

    if (node->next)    
        cout << node->next->idx << ' ';
    else
        cout << 0 << ' ';

    cout << '\n';
}

void    finish_print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Node *node = map.at(i);

        if (node->next)
            cout << node->next->idx << ' ';
        else
            cout << 0 << ' ';
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int N, Q;
    cin >> N >> Q;
    init_nodes(N);
    while (Q--)
    {
        int cmd, i, j;
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> i;
            pop(i);
        }
        else if (cmd == 2)
        {
            cin >> i >> j;
            insert_front(j, i);
        }
        else if (cmd == 3)
        {
            cin >> i >> j;
            insert_behind(j, i);
        }
        else if (cmd == 4)
        {
            cin >> i;
            print(i);
        }
    }
    finish_print(N);
    return (0);
}