#include <uni/tsan/collection.hpp>

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>

namespace
{
class A
{
public:
    A( ) = default;
    virtual ~A( )
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 5000ms );
    }

    virtual void
    F( )
    {
    }
};

class B : public A
{
public:
    ~B( ) override = default;

    void
    F( ) override
    {
    }
};

void
remove_object( A* ptr )
{
    delete ptr;
}

std::mutex mutex1{};
std::mutex mutex2{};

void
deadlock1( )
{
    std::lock_guard< std::mutex > lock1( mutex1 );
    {
        std::lock_guard< std::mutex > lock2( mutex2 );
        // Change some data2
    }
    // Change some data1
}
void
deadlock2( )
{
    std::lock_guard< std::mutex > lock2( mutex2 );
    {
        std::lock_guard< std::mutex > lock1( mutex1 );
        // Change some data1
    }
    // Change some data2
}


}  // namespace

void
simple_increment( int32_t& var )
{
    ++var;
};

namespace uni
{
namespace tsan
{
void
Collection::get_normal_data_races( )
{
    std::cout << "NORMAL_DATA_RACES" << std::endl;
    int32_t counter{ 0U };

    std::thread thread1( simple_increment, std::ref( counter ) );
    std::thread thread2( simple_increment, std::ref( counter ) );

    thread1.join( );
    thread2.join( );
    std::cout << "~NORMAL_DATA_RACES" << std::endl;
}

void
Collection::get_vptr_data_races( )
{
    std::cout << "VPTR_DATA_RACES" << std::endl;
    A* ptr = new B;

    std::thread thread( remove_object, ptr );
    ptr->F( );
    thread.join( );

    std::cout << "~VPTR_DATA_RACES" << std::endl;
}

void
Collection::get_potential_deadlock( )
{
    std::cout << "POTENTIAL DEADLOCK" << std::endl;

    std::thread thread1( deadlock1 );
    std::thread thread2( deadlock2 );

    thread1.join( );
    thread2.join( );
    std::cout << "~POTENTIAL DEADLOCK" << std::endl;
}

}  // namespace tsan
}  // namespace uni
