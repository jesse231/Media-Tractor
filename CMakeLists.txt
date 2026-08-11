cmake_minimum_required(VERSION 3.10.0)
project(Media-Tractor VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

# Set the options *before* downloading to keep the build fast
set(SQLITECPP_RUN_DOXYGEN OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(SQLITECPP_INTERNAL_SQLITE ON CACHE BOOL "" FORCE)

# Declare where to get the code. 
# Best Practice: Always pin a specific GIT_TAG (version) so your build never breaks unexpectedly!
FetchContent_Declare(
    sqlitecpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
    GIT_TAG        3.3.1 
)

# Download and make the library available
FetchContent_MakeAvailable(sqlitecpp)

add_executable(Media-Tractor 
    src/main.cpp 
    src/DatabaseService.cpp
)

target_include_directories(Media-Tractor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Media-Tractor
    PRIVATE
    SQLiteCpp
    sqlite3
    pthread
    dl
)

include(CTest)
enable_testing()