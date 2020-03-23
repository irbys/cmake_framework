Recommended:

mkdir build
cd build
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DADDRESS_SANITIZER=ON ..
ASAN_OPTIONS=halt_on_error=0:detect_stack_use_after_return=1:check_initialization_order=true:strict_init_order=true:verbosity=1 ./san-detector
