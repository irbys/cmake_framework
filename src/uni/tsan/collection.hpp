////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file uni/tsan/collection.hpp
/// @brief Declaration of Collection class for thread sanitizer issues.
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace uni
{
namespace tsan
{
class Collection
{
public:
    void get_normal_data_races( );
    void get_vptr_data_races( );
    void get_potential_deadlock( );
};

}  // namespace tsan
}  // namespace uni
