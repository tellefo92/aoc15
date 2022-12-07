#include "utils.hpp"

using namespace std;

set<pair<int,int>> visited(string line) {
    int x=0, y=0;
    pair<int,int> p = {x, y};
    set<pair<int,int>> coords = {p};
    for (auto& c: line) {
        if (c == '^') y--;
        if (c == 'v') y++;
        if (c == '<') x--;
        if (c == '>') x++;
        p = {x, y};
        if (coords.find(p) == coords.end()) {
            coords.insert(p);
        }
    }
    return coords;
}

int main() {
    string line, s1, s2;
    cin >> line;
    cout << visited(line).size() << endl;
    for (size_t i=0; i < line.length(); i++) {
        if (i%2==0) {
            s1 += line[i];
        } else {
            s2 += line[i];
        }
    }
    set<pair<int,int>> v1 = visited(s1), v2 = visited(s2);
    int counter = v2.size();
    for (auto& p: v1) {
        if (v2.find(p) == v2.end()) counter++;
    }
    cout << counter << endl;
}
