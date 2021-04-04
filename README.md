mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# Recommended environment variables. Could be added to the /etc/environment
# UBSAN_OPTIONS=print_stacktrace=1
# MSAN_OPTIONS=poison_in_dtor=1
ASAN_OPTIONS=halt_on_error=0:detect_stack_use_after_return=1:check_initialization_order=true:strict_init_order=true:verbosity=0
TSAN_OPTIONS=second_deadlock_stack=1

