#include <limits>

#include <sanitizer/undefined/issue/collection.hpp>

#include <iostream>

namespace sanitizer {
namespace undefined {
namespace issue {
;

void Collection::get_signed_integer_overflow()
{
    std::cout << "Signed integer overflow" << std::endl;
    auto k = std::numeric_limits<int32_t>::max();
    ++k;
    std::cout << "~Signed integer overflow" << std::endl;
}

void Collection::get_misaligned_pointer()
{
    std::cout << "Misaligned integer pointer assignment" << std::endl;
    {
        auto buffer = static_cast<int8_t*>(malloc(8 * 8));
        int32_t* pointer = (int32_t*)(buffer + 1);
        *pointer = 42;
        delete buffer;
    }
    std::cout << "~Misaligned integer pointer assignment" << std::endl;

    std::cout << "Misaligned structure pointer assignment" << std::endl;
    struct A
    {
        int32_t i32;
        int64_t i64;
    };
    auto buffer = static_cast<int8_t*>(malloc(8 * 4));
    auto pointer = reinterpret_cast<struct A*>(buffer + 1);
    pointer->i32 = 7;
    std::cout << "~Misaligned structure pointer assignment" << std::endl;
}

void Collection::get_invalid_boolean()
{
    std::cout << "Invalid boolean" << std::endl;
    int32_t result = 2;
    auto predicate = (bool*)&result;
    if (*predicate)
    {
        std::cout << result << " after cast is true" << std::endl;
    }
    else
    {
        std::cout << result << " after cast is false" << std::endl;
    }
    std::cout << "~Invalid boolean" << std::endl;
}

void Collection::get_out_of_bounds_array()
{
    std::cout << "Out of bounds array" << std::endl;
    int32_t array[5] = {1};
    for (int32_t i{0}; i <= 5; ++i)
    {
        array[i] += 1;
    }
    std::cout << "~Out of bounds array" << std::endl;
}

void Collection::get_invalid_enumeration()
{
    std::cout << "Invalid enum" << std::endl;
    enum E
    {
        a = 1,
    };
    int value = 2;
    auto e = (enum E*)&value;
    std::cout << "Enum after cast " << *e << std::endl;
    std::cout << "~Invalid enum" << std::endl;
}

} // namespace issue
} // namespace undefined
} // namespace sanitizer
