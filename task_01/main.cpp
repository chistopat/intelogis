//
// Created by Егор Чистяков on 09.03.2022.
//

#include <algorithm>
#include <vector>
#include <iostream>

struct Truck {
    Truck(int weight, int volume)
            : tonnage(weight), capacity(volume) {}

    int tonnage = 0;
    int capacity = 0;


};

std::vector<Truck> MakeTrucks(int n) {
    std::vector<Truck> result;
    result.reserve(n);

    for (int i = 0; i < n; ++i) {
        result.emplace_back(i, n - i);
    }
    return result;
}

template<typename By>
void SortBy(std::vector<Truck> &v, By field) {
    std::stable_sort(v.begin(), v.end(),
                     [field](const Truck &lhs, const Truck &rhs) { return lhs.*field > rhs.*field; });
}

std::ostream &operator<<(std::ostream &os, const Truck& t)  {
    return os << "{ tonnage: " << t.tonnage << " capacity: " << t.capacity << " }";
}

void PrintTrucks(const std::vector<Truck>& trucks) {
    for (const auto& t : trucks) {
        std::cout << t << std::endl;
    }
    std::cout << std::endl;
}
int main() {
    auto trucks = MakeTrucks(10);
    SortBy(trucks, &Truck::tonnage);
    PrintTrucks(trucks);
    SortBy(trucks, &Truck::capacity);
    PrintTrucks(trucks);
}