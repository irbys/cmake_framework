#include <sanitizer/address/issue/collection.hpp>

int main()
{
    sanitizer::address::issue::Collection collection;
    collection.get_heap_use_after_free();
    collection.get_heap_buffer_overflow();
    collection.get_stack_buffer_overflow();
    collection.get_global_buffer_overflow();
    collection.get_stack_use_after_return();
    collection.get_stack_use_after_scope();
    collection.get_memory_leaks();
    return 0;
}
