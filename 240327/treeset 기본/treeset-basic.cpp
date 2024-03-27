#include <iostream>
#include <set>
// 아무 값도 없을 때 rbegin, begin, rend, end 주소값 찍어보기
using namespace std;

void    add(set<int> *s) {
    int num;

    cin >> num;
    s->insert(num);
}

void    remove(set<int> *s) {
    int num;

    cin >> num;
    s->erase(num);
}

void    find(set<int> *s) {
    int num;

    cin >> num;
    if (s->find(num) != s->end())
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
}

void    lower_bound(set<int> *s) {
    int num;

    cin >> num;

    if (s->lower_bound(num) != s->end())
        cout << *(s->lower_bound(num)) << '\n';
    else
        cout << "None" << '\n';
}

void    upper_bound(set<int> *s) {
    int num;

    cin >> num;
    if (s->upper_bound(num) != s->end())
        cout << *(s->upper_bound(num)) << '\n';
    else
        cout << "None" << '\n';
}

void    largest(set<int> *s) {
    if (s->rbegin() != s->rend())
        cout << *(s->rbegin()) << '\n';
    else
        cout << "None" << '\n';
}

void    smallest(set<int> *s) {
    if (s->begin() != s->end())
        cout << *(s->begin()) << '\n';
    else
        cout << "None" << '\n';
}

int main() {
    int N;
    string input;
    set<int> s;

    cin >> N;
    while (N-- > 0)
    {
        cin >> input;
        if (input == "add")
            add(&s);
        else if (input == "remove")
            remove(&s);
        else if (input == "find")
            find(&s);
        else if (input == "lower_bound")
            lower_bound(&s);
        else if (input == "upper_bound")
            upper_bound(&s);
        else if (input == "largest")
            largest(&s);
        else if (input == "smallest")
            smallest(&s);
        else
            cout << "~~~~WHILE LOOP ERROR~~~~\n";
    }
    return 0;
}