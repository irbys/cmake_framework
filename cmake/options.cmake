option(CMAKE_USE_GOLD "Use gold linker" ON)
option(ENABLE_MULTITHREADING_LINKAGE "Enable multithreading linkage (gold only)" ON)

option(CMAKE_USE_CCACHE "Cmake use ccache" ON)

option(ENABLE_DIAGNOSTIC_COLORS "Enable diagnostic's colors" ON)

option(ENABLE_WERROR "Treats warnings as errors by default" ON)
option(DISABLE_ALL_WERROR "Disable treating warnings as errors for all targets" OFF)

option(ADDRESS_SANITIZER OFF)
option(UNDEFINED_SANITIZER OFF)
option(THREAD_SANITIZER OFF)
