#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> us;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input == "add") {
            int num;
            cin >> num;
            us.insert(num);
        }

        if (input == "remove") {
            int num;
            cin >> num;
            us.erase(num);
        }

        if (input == "find") {
            int num;
            cin >> num;
            if (us.find(num) == us.end()) {
                cout << "false\n";
            } else {
                cout << "true\n";
            }
        }
    }

    return 0;
}