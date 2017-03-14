#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ErrorMsg {
    string filename;
    string line_no;
    int count;
    ErrorMsg() = default;
    ErrorMsg(const string& fname, const string& num): filename(fname), line_no(num), count(1) {}
    friend bool operator==(const ErrorMsg& lhs, const ErrorMsg& rhs);
    friend ostream& operator<<(ostream& os, const ErrorMsg& rhs);
};

bool operator==(const ErrorMsg& lhs, const ErrorMsg& rhs) {
    return lhs.filename == rhs.filename
        && lhs.line_no == rhs.line_no;
}

ostream& operator<<(ostream& os, const ErrorMsg& rhs) {
    auto sz = rhs.filename.size();
    if (sz > 16) {
        os << rhs.filename.substr(sz - 16) << " ";
    } else {
        os << rhs.filename << " ";
    }
    os << rhs.line_no << " " << rhs.count;
    return os;
}

string path2name(string& path) {
    auto pos = path.find_last_of('\\');
    if (pos == string::npos) return path;
    else return path.substr(pos+1);
}

void combine(vector<ErrorMsg>& errors, const ErrorMsg& e) {
    for (auto &msg : errors) {
        if (msg == e) {
            msg.count += 1;
            return;
        }
    }
    errors.push_back(e);
}

int main() {
    string path, line_no;
    vector<ErrorMsg> errors;
    while (cin >> path >> line_no) {
        ErrorMsg curr_msg(path2name(path), line_no);
        combine(errors, curr_msg);
    }
    stable_sort(errors.begin(), errors.end(), [](const ErrorMsg& lhs, const ErrorMsg& rhs) {
            return lhs.count > rhs.count;
            });
    errors.resize(8);
    for (const auto &msg : errors) {
        cout << msg << endl;
    }

    return 0;

}
