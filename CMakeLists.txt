cmake_minimum_required( VERSION 3.10 )

project( san-issue-detector )

include( ${CMAKE_SOURCE_DIR}/cmake/sanitizers.cmake  )

set( HEADERS
    ""
)

set( SOURCES
    "app/main.cpp"
    "src/uni/asan/collection.hpp"
    "src/uni/asan/collection.cpp"
    "src/uni/tsan/collection.hpp"
    "src/uni/tsan/collection.cpp"
    "src/uni/ubsan/collection.hpp"
    "src/uni/ubsan/collection.cpp"
)

add_executable( ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

set( CMAKE_THREAD_PREFER_PTHREAD TRUE )
set( THREADS_PREFER_PTHREAD_FLAG TRUE )

if( NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
    find_package( Threads REQUIRED )
    message( STATUS "Thread library - ${CMAKE_THREAD_LIBS_INIT}" )
endif( )

target_link_libraries( ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
