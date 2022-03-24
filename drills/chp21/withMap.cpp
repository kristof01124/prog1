#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <list>
#include <map>

void read_to_map(std::map<std::string,int>& m) {
    std::string key;
    std::cin>>key;
    std::cin>>m[key];
}   

int main() {
    std::map<std::string, int> msi;
    msi["alma"] = 10;
    msi["korte"] = 31;
    msi["dinnye"] = 69;
    msi["padlizsan"] = 420;
    msi["cukkini"] = 4356;
    msi["narancs"] = 7657;
    msi["eper"] = 657;
    msi["szolo"] = 6543;
    msi["uborka"] = 354;
    msi["gyomber"] = 4;
    msi["paradicsom"] = 45;
    for (std::pair<std::string, int> i:msi) {
        std::cout<<i.first<<" "<<i.second<<std::endl;
    }
    msi.clear();
    for (int i = 0; i < 10;++i)
        read_to_map(msi);
    int sum = 0;
    for (std::pair<std::string, int> i:msi) {
        std::cout<<i.first<<" "<<i.second<<std::endl;
        sum+=i.second;
    }
    std::cout<<"The sum of the integer values is: " << sum << std::endl;
    std::map<int, std::string> mis;
    for (std::pair<std::string, int> i:msi) {
        mis[i.second] = i.first;
    }
    for (std::pair<int, std::string> i:mis) {
        std::cout<<i.first<<" "<<i.second<<std::endl;
    }
}