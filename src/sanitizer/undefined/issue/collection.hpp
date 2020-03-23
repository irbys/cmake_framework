////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file sanitizer/undefined/issue/collection.hpp
/// @brief Declaration of Collection class for undefined behavior sanitizer issues.
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 23.03.2020
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace sanitizer {
namespace undefined {
namespace issue {

class Collection
{
 public:
    void get_signed_integer_overflow();
    void get_misaligned_pointer();
    void get_invalid_boolean();
    void get_out_of_bounds_array();
    void get_invalid_enumeration();
};


} // namespace issue
} // namespace undefined
} // namespace sanitizer
