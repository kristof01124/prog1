#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <list>

int main() {
    std::vector<double> vd;
    std::ifstream in("double.txt");
    double val;
    while (in>>val) {
        vd.push_back(val);
    }
    for (double i:vd)
        std::cout<<i<<"\n";
    std::vector<int> vi(vd.size());
    val = 0;
    int sum = 0;
    for (int i = 0;i < vd.size(); ++i) {
        vi[i] = vd[i];
        val += vd[i];
        sum += vi[i];
        std::cout<< "(" << vd[i] << "," <<  vi[i] << ")" << std::endl;
    }
    std::cout << "The sum of the double elements is : " << val << std::endl;
    std::cout << "The difference of the sums is :  " << val - double(sum) << std::endl;
    std::reverse(vd.begin(), vd.end());
    for (double i:vd)
        std::cout<<i<<"\n";
    val /= double(vd.size());
    std::cout << "The mean of the double elements is : " << val << std::endl;
    std::vector<double> vd2;
    for (double i: vd) {
        if (i < val)
            vd2.push_back(i);
    }
    std::sort(vd.begin(), vd.end());
    for (double i:vd)
        std::cout<<i<<"\n";
}