cmake_minimum_required(VERSION 3.10.0)
project(Media-Tractor VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

# Set the options *before* downloading to keep the build fast
set(SQLITECPP_RUN_DOXYGEN OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(SQLITECPP_INTERNAL_SQLITE ON CACHE BOOL "" FORCE)

# Fetch the SQLiteCpp library from github
FetchContent_Declare(
    sqlitecpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
    GIT_TAG        3.3.1 
)

# Fetch JSON handler
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
)

FetchContent_MakeAvailable(sqlitecpp json)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS 
    "src/*.cpp"
    "include/*.hpp"
)

add_executable(Media-Tractor ${SOURCES})

target_include_directories(Media-Tractor PRIVATE include)

target_link_libraries(Media-Tractor
    PRIVATE
    SQLiteCpp
    sqlite3
    pthread
    dl
    nlohmann_json::nlohmann_json
)

include(CTest)
enable_testing()