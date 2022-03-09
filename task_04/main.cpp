//
// Created by Егор Чистяков on 09.03.2022.
//

#include <iostream>
#include <iterator>
#include <vector>

struct Truck {
    Truck(int weight, int volume)
            : tonnage(weight), capacity(volume) {}

    int tonnage = 0;
    int capacity = 0;

    Truck& operator ++() {
        ++tonnage;
        ++capacity;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Truck& t)  {
    return os << "{ tonnage: " << t.tonnage << " capacity: " << t.capacity << " }";
}

struct Payload {
    Payload(int weight, int volume)
            : weight(weight), volume(volume) {}

    int weight = 0;
    int volume = 0;

    Payload& operator ++() {
        ++weight;
        ++volume;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Payload& p)  {
    return os << "{ weight: " << p.weight << " volume: " << p.volume << " }";
}

template <typename Object>
std::vector<Object> MakeObjects(int n) {
    std::vector<Object> result;
    result.reserve(n);

    for (int i = 0; i < n; ++i) {
        result.emplace_back(i, n - i);
    }
    return result;
}

template<typename It>
void Increment(It first, It last) {
    std::transform(first, last, first, [](auto i) { return ++i; });
}

template<typename T>
void PrintVector(const std::vector<T>& container) {
    for (const auto& item : container) {
        std::cout << item << std::endl;
    }
}

int main() {
    {
        std::vector<int> t{1, 2, 3, 4, 5};
        PrintVector(t);
        Increment(t.begin(), t.end());
        std::cout << std::endl;
        PrintVector(t);
    }
        std::cout << std::endl;
    {
        auto t = MakeObjects<Truck>(10);
        PrintVector(t);
        Increment(t.begin(), t.end());
        std::cout << std::endl;
        PrintVector(t);
    }
        std::cout << std::endl;
    {
        auto t = MakeObjects<Payload>(10);
        PrintVector(t);
        Increment(t.begin(), t.end());
        std::cout << std::endl;
        PrintVector(t);
    }
}
