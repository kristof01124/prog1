#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <list>

struct Item {
    std::string name;
    int iid;
    double value;
    void print(std::ostream& out) {
        out << name << " " << iid << " " << value << std::endl;
    }
};

struct Cmp {
    bool operator()(const Item& left, const Item& right) {
        return left.name < right.name;
    }
};

int main() {
    //Vector part
    {
    std::cout << "----- VECTOR PART -------------" << std::endl;
    std::vector<Item> vi;
    std::ifstream in("in.txt");
    for (int i = 0; i < 10; ++i) {
        std::string a;
        int b;
        double c;
        in>>a>>b>>c;
        vi.push_back({a,b,c});
        //std::cout<<vi[i].name<<" "<<vi[i].iid<<" "<<vi[i].value<<std::endl;
    }
    for (Item i:vi) 
        i.print(std::cout);
    sort(vi.begin(), vi.end(), Cmp());
    std::cout << "Sorted by name:\n";
    for (Item i:vi) 
        i.print(std::cout);
    sort(vi.begin(), vi.end(), [](Item left, Item right) {return left.iid < right.iid;});
    std::cout << "Sorted by iid:\n";
    for (Item i:vi) 
        i.print(std::cout);
    sort(vi.begin(), vi.end(), [](Item left, Item right) {return left.value > right.value;});
    std::cout << "Sorted by value(descending):\n";
    for (Item i:vi) 
        i.print(std::cout);
    vi.push_back({"horse shoe",99,12.34});
    vi.push_back({"Canon S400", 9988,499.95});
    for (auto i = vi.begin(); i != vi.end(); ++i) {
        if ((*i).name == "alma" || (*i).name == "korte" ) {
            vi.erase(i);
        }
    }
    std::cout << "After erasing alma and korte:\n";
    for (Item i:vi) 
        i.print(std::cout);
    for (auto i = vi.begin(); i != vi.end(); ++i) {
        if ((*i).iid == 2 ) {
            vi.erase(i);
        }
    }
    std::cout << "After erasing elements with iid of 2:\n";
    for (Item i:vi) 
        i.print(std::cout);
    }
    //List part
    {
    std::cout << "-------LIST PART ----------" << std::endl;
    std::list<Item> vi;
    std::ifstream in("in.txt");
    for (int i = 0; i < 10; ++i) {
        std::string a;
        int b;
        double c;
        in>>a>>b>>c;
        vi.push_back({a,b,c});
        //std::cout<<vi[i].name<<" "<<vi[i].iid<<" "<<vi[i].value<<std::endl;
    }
        for (Item i:vi) 
        i.print(std::cout);
    vi.sort([](Item left, Item right) {return left.name < right.name;});
    std::cout << "Sorted by name:\n";
    for (Item i:vi) 
        i.print(std::cout);
    vi.sort([](Item left, Item right) {return left.iid < right.iid;});
    std::cout << "Sorted by iid:\n";
    for (Item i:vi) 
        i.print(std::cout);
    vi.sort([](Item left, Item right) {return left.value < right.value;});
    std::cout << "Sorted by value(descending):\n";
    for (Item i:vi) 
        i.print(std::cout);
    vi.push_back({"horse shoe",99,12.34});
    vi.push_back({"Canon S400", 9988,499.95});
    for (auto i = vi.begin(); i != vi.end(); ++i) {
        if ((*i).name == "alma" || (*i).name == "korte" ) {
            i = vi.erase(i);
            i--;
        }
    }
    std::cout << "After erasing alma and korte:\n";
    for (Item i:vi) 
        i.print(std::cout);
    for (auto i = vi.begin(); i != vi.end(); ++i) {
        if ((*i).iid == 2 ) {
            i = vi.erase(i);
            i--;
        }
    }
    std::cout << "After erasing elements with iid of 2:\n";
    for (Item i:vi) 
        i.print(std::cout);
    }
}
