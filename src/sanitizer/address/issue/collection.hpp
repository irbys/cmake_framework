////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file asan/issue/collection.hpp
/// @brief Declaration of Collection class for address sanitizer issues.
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 22.03.2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace sanitizer {
namespace address {
namespace issue {

class Collection
{
 public:
    void get_heap_use_after_free();
    void get_heap_buffer_overflow();
    void get_stack_buffer_overflow();
};

} // namespace issue
} // namespace address
} // namespace sanitizer
