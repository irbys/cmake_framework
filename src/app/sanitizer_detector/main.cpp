#include <sanitizer/address/issue/collection.hpp>

int main()
{
    sanitizer::address::issue::Collection collection;
    collection.get_heap_use_after_free();
    collection.get_heap_buffer_overflow();
    return 0;
}
