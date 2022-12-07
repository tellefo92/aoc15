#include "utils.hpp"

using namespace std;

void toggle(bool &lights, int x0, int x1, int y0, int y1) {
    
}

int main() {
    string line;
    vector<string> instructions;
    int x0, x1, y0, y1, lights_lit = 0;
    uint64_t total = 0;
    int mode; // 0=turn on, 1=turn off, 2=toggle
    bool lights[1000][1000];
    int lights2[1000][1000];
    for (int x=0; x<1000; x++) {
        for (int y=0; y<1000; y++) {
            lights[y][x] = 0;
            lights2[y][x] = 0;
        }
    }
    while (getline(cin, line)) {
        instructions = splitString<string>(line, ",");
        if (instructions.size() == 7) {
            mode = instructions[1] == "off" ? 0 : 1;
            x0 = stoi(instructions[2]);
            x1 = stoi(instructions[5]);
            y0 = stoi(instructions[3]);
            y1 = stoi(instructions[6]);
            for (int y=y0; y<=y1; y++) {
                for (int x=x0; x<=x1; x++) {
                    lights[y][x] = mode;
                    if (mode == 0 && lights2[y][x] > 0) {
                        lights2[y][x]--;
                    } else if (mode == 1) {
                        lights2[y][x]++;
                    }
                }
            }
        } else {
            mode = 2;
            x0 = stoi(instructions[1]);
            x1 = stoi(instructions[4]);
            y0 = stoi(instructions[2]);
            y1 = stoi(instructions[5]);
            for (int y=y0; y<=y1; y++) {
                for (int x=x0; x<=x1; x++) {
                    /*if (lights[k][i] == 1) {
                        lights[k][i] = 0;
                    } else {
                        lights[k][i] = 1;
                    }*/
                    lights[y][x] = !lights[y][x];
                    lights2[y][x] += 2;
                }
            }
        }
    }
    for (int y=0; y<1000; y++) {
        for (int x=0; x<1000; x++) {
            if (lights[y][x]) {
                lights_lit++;
            }
            total += lights2[y][x];
        }
    }
    cout << lights_lit << endl;
    cout << total << endl;
}