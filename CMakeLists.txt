cmake_minimum_required(VERSION 3.10.0)
project(Media-Tractor VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

# Asio, a crow dependency
FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG asio-1-30-2
)
FetchContent_MakeAvailable(asio)

FetchContent_GetProperties(asio SOURCE_DIR ASIO_SOURCE_DIR)
set(ASIO_INCLUDE_DIR "${ASIO_SOURCE_DIR}/asio/include" CACHE PATH "Asio include dir" FORCE)

FetchContent_Declare(
    Crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.2.0
)
FetchContent_MakeAvailable(Crow)

FetchContent_Declare(
    glaze
    GIT_REPOSITORY https://github.com/stephenberry/glaze.git
    GIT_TAG main 
)
FetchContent_MakeAvailable(glaze)

FetchContent_Declare(
    sqlitecpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
    GIT_TAG 3.3.1
)

set(SQLITECPP_RUN_DOXYGEN OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SQLITECPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(sqlitecpp)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS 
    "src/*.cpp"
    "include/*.hpp"
)

add_executable(Media-Tractor ${SOURCES})

target_include_directories(Media-Tractor PRIVATE include)

target_link_libraries(Media-Tractor PRIVATE
    Crow::Crow
    glaze::glaze
    SQLiteCpp
    sqlite3
)

include(CTest)
enable_testing()