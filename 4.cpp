#include "utils.hpp"
#include "md5.cpp"

using namespace std;

int main() {
    string key;
    string input;
    string hash;
    cin >> key;
    auto five_zeros = [](string s) -> bool {return s.substr(0, 5) == "00000";};
    auto six_zeros = [](string s) -> bool {return s.substr(0, 6) == "000000";};
    int64_t ans = 0;
    while (1) {
        input = key + to_string(ans);
        hash = GetMD5String(input);
        if (five_zeros(hash)) break;
        ans++;
    }
    cout << ans << endl;
    ans++;
    while(1) {
        input = key + to_string(ans);
        hash = GetMD5String(input);
        if (six_zeros(hash)) break;
        ans++;
    }
    cout << ans << endl;
}