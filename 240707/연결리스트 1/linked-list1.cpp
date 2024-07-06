#include <iostream>
using namespace std;

struct Node {
    string data;
    Node *prev, *next;
    Node(string data) :
        data(data),
        prev(nullptr),
        next(nullptr) {}
};

void insert_next(Node *u, Node *singleton) {
    singleton->prev = u;
    singleton->next = u->next;

    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void insert_prev(Node *u, Node *singleton) {
    singleton->prev = u->prev;
    singleton->next = u;

    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void pop(Node *u) {
    if (nullptr != u->prev)
        u->prev->next = u->next;
    if (nullptr != u->next)
        u->next->prev = u->next;
    
    u->prev = u->next = nullptr;
}

void    ft_print(Node *cur)
{
    if (cur->prev)
        cout << cur->prev->data;
    else
        cout << "(Null)";
    
    cout << ' ' << cur->data << ' ';

    if (cur->next)
        cout << cur->next->data;
    else
        cout << "(Null)";
    cout << '\n';
}

int main() {
    string s_init;
    cin >> s_init;

    Node *cur = new Node(s_init);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cmd;
        string s_val;
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> s_val;
            Node *new_n = new Node(s_val);
            insert_prev(cur, new_n);
        }
        else if (cmd == 2)
        {
            cin >> s_val;
            Node *new_n = new Node(s_val);
            insert_next(cur, new_n);
        }
        else if (cmd == 3 && cur->prev)
            cur = cur->prev;
        else if (cmd == 4 && cur->next)
            cur = cur->next;
        ft_print(cur);
    }

    return 0;
}