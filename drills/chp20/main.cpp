#include <iostream>
#include <vector>
#include <list> 
#include <algorithm>

template<typename Iter1, typename Iter2>
    //requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2) {
    for (; f1 != e1; f1 ++) {
        *f2 = *f1;
        f2++;
    }
    return f2;
}

int main() {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array2[10];
    for (int i = 0; i<10;++i)
        array2[i] = array[i];
    std::vector<int> vector2(vector);
    std::list<int> list2(list);
    for (int& i:array) 
        i += 2;
    for (int& i: vector) 
        i+= 3;
    for (int& i:list)
        i+= 5;
    myCopy(array, array + 10, vector.begin());
    myCopy(list.begin(), list.end(), array);
    std::cout<<"array:";
    for (int i:array)
        std::cout << i << " ";
    std::cout<<std::endl;
    std::cout<<"vector:";
    for (int i:vector)
        std::cout << i << " ";
    std::cout<<std::endl;
    // *list.begin() = 27;
    std::cout<<"list:";
    for (int i:list)
        std::cout << i << " ";
    std::cout<<std::endl;
    if (std::find(vector.begin(), vector.end(), 3) != vector.end()) {
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i] == 3) {
                std::cout<<i<<std::endl;
                break;
            }
        }
    }
    else {
        std::cout << "3 not found!" << std::endl;
    }
    if (std::find(list.begin(), list.end(), 27) != list.end()) {
        int index = 0;
        for (int i:list) {
            if (i == 27) {
                std::cout<<index<<std::endl;
                break;
            }
            index ++;
        }
    }
    else {
        std::cout << "27 not found!" << std::endl;
    }
}