#include "utils.hpp"

using namespace std;

int main() {
    int l, w, h, area, sq_feet = 0, min_area, ribbon = 0;
    string line;
    while (cin >> line) {
        vector<int> v = splitString<int>(line, "x");
        l = v[0];
        w = v[1];
        h = v[2];
        sort(v.begin(), v.end());
        auto area = [](int l, int w, int h){return 2*l*w + 2*w*h + 2*h*l;};
        sq_feet += area(l, w, h) + v[0]*v[1];
        ribbon += 2*v[0] + 2*v[1] + l*w*h;
    }
    cout << sq_feet << endl;
    cout << ribbon << endl;
}