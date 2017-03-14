#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric> 

using namespace std;

void print_vector(ostream& out, const vector<int>& v) {
    copy(v.begin(), v.end(), ostream_iterator<int>(out, " "));
    out << endl;
}

vector<int> get_input(istream& in, size_t n) {
    vector<int> ret;
    int x;
    while (n-- != 0 && cin >> x) {
        ret.push_back(x);
    }
    return ret;
}

int max_fish(vector<int>& fishes, unsigned min_size, unsigned max_size) {
    auto n = max_size - min_size + 1;
    vector<int> candidate(n);
    iota(candidate.begin(), candidate.end(), min_size);
    auto it = candidate.begin();
    while (it != candidate.end()) {
        for (auto sz : fishes) {
            for (int i = 2; i <= 10; ++i) {
                if (*it * i == sz) {
                    it = candidate.erase(it);
                    break;
                }
            }
        }
    }
    return candidate.size();
}

int main() {
    unsigned min_size, max_size, n;
    while (cin >> min_size >> max_size) {
        cin >> n;
        auto fishes = get_input(cin, n);
        max_fish(fishes, min_size, max_size);        
    }

}

