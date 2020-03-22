if(ADDRESS_SANITIZER)
   # https://clang.llvm.org/docs/AddressSanitizer.html
   message(STATUS "Enabled address sanitizer")
   set(ASAN_FLAGS "-fsanitize=address -fsanitize-recover=address")
   set(ASAN_ADDITIONAL_FLAGS "-fno-omit-frame-pointer -fno-optimize-sibling-calls")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ASAN_FLAGS} ${ASAN_ADDITIONAL_FLAGS}")
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ASAN_FLAGS}")
endif()

if(UNDEFINED_SANITIZER)
   message(STATUS "Enabled undefined behavior sanitizer")
   set(UBSAN_FLAGS "-fsanitize=undefined -fsanitize-recover=undefined")
   set(UBSAN_ADDITIONAL_FLAGS "-fno-omit-frame-pointer")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${UBSAN_FLAGS} ${UBSAN_ADDITIONAL_FLAGS}" PARENT_SCOPE)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${UBSAN_FLAGS}" PARENT_SCOPE)
endif()

if(THREAD_SANITIZER)
   # https://clang.llvm.org/docs/ThreadSanitizer.html
   message(STATUS "Enabled thread sanitizer")
   set(TSAN_FLAGS "-fsanitize=thread")
   set(TSAN_ADDITIONAL_FLAGS "-fno-omit-frame-pointer")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ASAN_FLAGS} ${TSAN_ADDITIONAL_FLAGS}" PARENT_SCOPE)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TSAN_FLAGS}" PARENT_SCOPE)
endif()

if(MEMORY_SANITIZER)
   # https://clang.llvm.org/docs/MemorySanitizer.html
   set(MSAN_ADDITIONAL_FLAGS "-fno-omit-frame-pointer -fno-optimize-sibling-calls")
endif()
