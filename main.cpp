//
// Created by Егор Чистяков on 09.03.2022.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

struct Foo {
    int i;
    char a;
};

template <typename RandomIterator>
void Reverse(RandomIterator begin, RandomIterator end) {
    while (begin != end && begin != --end) {
        std::iter_swap(begin++, end);
    }
}

int main() {
    std::string s = "asdf";
    std::vector<int> v {1, 2, 3};
    Reverse(v.begin(), v.end());
    std::cout << v ;
}