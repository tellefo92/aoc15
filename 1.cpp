#include "utils.hpp"

using namespace std;

int main() {
    int floor = 0, count = 1;
    bool found = false;
    string instructions;
    cin >> instructions;
    for (auto& c: instructions) {
        floor += c == '(' ? 1 : -1;
        if (! found) {
            if (floor == -1) {
                cout << count << endl;
                found = true;
            }
            count++;
        }
        
    }
    cout << floor << endl;
}