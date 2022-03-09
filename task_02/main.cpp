//
// Created by Егор Чистяков on 09.03.2022.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <cassert>

struct Payload {
    int weight = 0;
    int volume = 0;
};

class IVehicle {
public:
    virtual bool CheckPayload(const Payload&) const = 0;
};

class RegularTruck : public IVehicle {
public:
    explicit RegularTruck(int weight, int volume) : tonnage_(weight), capacity_(volume) {}

    bool CheckPayload(const Payload& payload) const override {
        return tonnage_ <= payload.weight && capacity_ <= payload.volume;
    }

    friend std::ostream &operator<<(std::ostream &os, const RegularTruck& t)  {
        return os << "{ tonnage: " << t.tonnage_ << " capacity: " << t.capacity_ << " }";
    }

private:
    int tonnage_ = 0;
    int capacity_ = 0;
};

class EndlessTruck : public IVehicle {
public:
    explicit EndlessTruck(int weight) : tonnage_(weight) {}

    bool CheckPayload(const Payload& payload) const override {
        return tonnage_ <= payload.weight;
    }
    friend std::ostream &operator<<(std::ostream &os, const EndlessTruck& t)  {
        return os << "{ tonnage: " << t.tonnage_ << " }";
    }

private:
    int tonnage_ = 0;
};


using VehicleHolder = std::shared_ptr<IVehicle>;

std::shared_ptr<RegularTruck> CreateRegularTruck(int weight, int volume) {
    return std::make_shared<RegularTruck>(weight, volume);
}

std::shared_ptr<EndlessTruck> CreateEndlessTruck(int weight) {
    return std::make_shared<EndlessTruck>(weight);
}

void RemoveByPayload(std::vector<VehicleHolder>& trucks, const Payload& payload) {
    auto it = std::stable_partition(trucks.begin(), trucks.end(),
                          [&payload](const VehicleHolder t) {return t->CheckPayload(payload);});
    trucks.erase(it, trucks.end());
}

std::vector<VehicleHolder> MakeTrucks(int n) {
    std::vector<VehicleHolder> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(CreateRegularTruck(i, n - i));
    }

    for (int i = 0; i < n; ++i) {
        result.push_back(CreateEndlessTruck(i));
    }

    return result;
}


int main() {
    auto trucks = MakeTrucks(10);
    const auto kPayload = Payload{5, 5};
    std::cout << trucks.size() << std::endl; // 20
    RemoveByPayload(trucks, kPayload);
    std::cout << trucks.size() << std::endl; // 7
    assert(trucks.size() == 7U);
}