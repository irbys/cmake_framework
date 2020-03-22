#include <sanitizer/address/issue/collection.hpp>

#include <iostream>

namespace sanitizer {
namespace address {
namespace issue {

void Collection::get_heap_use_after_free()
{
    uint32_t* array = new uint32_t[100];
    delete[] array;
    std::cout << array[55] << std::endl;
}

void Collection::get_heap_buffer_overflow()
{
    uint64_t* array = new uint64_t[100];
    array[0] = 0;
    int res = array[1 + 100];
    delete[] array;
    std::cout << res << std::endl;
}

void Collection::get_stack_buffer_overflow()
{
    uint32_t stack_array[100];
    stack_array[1] = 0;
    std::cout << stack_array[1 + 100] << std::endl;
}

} // namespace issue
} // namespace address
} // namespace sanitizer
