#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct Item {
    std::string name;
    int iid;
    double value;
};

int main() {
    std::vector<Item> vi;
    std::ifstream in("in.txt");
    for (int i = 0; i < 10; ++i) {
        std::string a;
        int b;
        double c;
        vi.emplace_back(a,b,c);
    }
}