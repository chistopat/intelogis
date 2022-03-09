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

    void print() const {
        std::cout << "{ tonnage: " << tonnage << " capacity: " << capacity << " }";
    }
};


struct Payload {
    Payload(int weight, int volume)
            : weight(weight), volume(volume) {}

    int weight = 0;
    int volume = 0;

    void print() const {
        std::cout << "{ weight: " << weight << " volume: " << volume << " }";
    }
};

template<typename T>
class PrintWrapper {
public:
    explicit PrintWrapper(std::unique_ptr<T> object, std::string type)
        : object_(std::move(object))
        , type_(std::move(type)) {}

    void print() {
        std::cout << type_;
        object_->print();
    }

private:
    std::unique_ptr<T> object_;
    std::string type_;
};


int main() {
    auto truck = std::make_unique<Truck>(1, 2);
    auto named_truck = PrintWrapper<Truck>(std::move(truck), "машина с названием: ");
    auto payload = std::make_unique<Payload>(3, 4);
    auto named_payload = PrintWrapper<Payload>(std::move(payload), "груз с названием: ");

    named_truck.print();
    std::cout << std::endl;
    named_payload.print();
}
