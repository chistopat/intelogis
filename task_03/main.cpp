//
// Created by Егор Чистяков on 09.03.2022.
//

#include <iostream>
#include <iterator>
#include <vector>

template<typename It>
void Increment(It first, It last) {
    std::transform(first, last, first, [](auto i) { return ++i; });
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    Increment(v.begin(), v.end());
    std::cout << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
