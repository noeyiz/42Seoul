#include <iostream>

#include "Serializer.hpp"

int main() {
    // 1. Data 구조체 초기화
    Data data;
    data.value = 42;

    // 2. Data* -> uintptr_t
    uintptr_t data_ptr_int = Serializer::serialize(&data);
    // 3. uintptr_t -> Data*
    Data *data_ptr = Serializer::deserialize(data_ptr_int);

    // 4. 검증 !
    std::cout << "original data value = " << data.value << std::endl;
    std::cout << "reinterpreted data value = " << data_ptr->value << std::endl;

    data.value = 9;
    std::cout << std::endl;

    std::cout << "original data value = " << data.value << std::endl;
    std::cout << "reinterpreted data value = " << data_ptr->value << std::endl;

    return 0;
}
