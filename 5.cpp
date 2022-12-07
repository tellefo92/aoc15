#include "utils.hpp"

using namespace std;

bool p1(string line) {
    auto double_letters = [](string line) {
        for (size_t i=0; i < line.length()-1; i++) {
            if (line[i] == line[i+1]) return true;
        }
        return false;
    };
    auto three_vowels = [](string line) {
        string vowels = "aeiou";
        int counter = 0;
        size_t found = line.find_first_of(vowels);
        while (found != string::npos) {
            counter++;
            if (counter == 3) return true;
            line[found] = '.';
            found = line.find_first_of(vowels);
        }
        return false;
    };
    auto allowed = [](string line) {
        vector<string> forbidden = {"ab", "cd", "pq", "xy"};
        for (auto& s: forbidden) {
            if (line.find(s) != string::npos) return false;
        }
        return true;
    };
    return double_letters(line) && three_vowels(line) && allowed(line);
}

bool p2(string line) {
    auto twice_appearing = [](string line) {
        string s, ss;
        for (size_t i=0; i < line.length()-2; i++) {
            s = line.substr(i, 2);
            ss = line.substr(i+2);
            if (ss.find(s) != string::npos) return true;
        }
        return false;
    };
    auto one_between = [](string line) {
        for (size_t i=0; i < line.length()-2; i++) {
            if (line[i] == line[i+2]) return true;
        }
        return false;
    };
    return twice_appearing(line) && one_between(line);
}

int main() {
    string line;
    int counter = 0, counter2 = 0;
    
    while (cin >> line) {
        if (p1(line)) counter++;
        if (p2(line)) counter2++;
    }
    cout << counter << endl;
    cout << counter2 << endl;
}