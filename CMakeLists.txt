cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
project("r-type_client" VERSION 0.1 LANGUAGES CXX)

#set(CXX_FLAGS "-fsanitize=address")
#set(CXX_FLAGS "-pthread")
#set(CMAKE_EXE_LINKER_FLAGS "-fsanitize=address")

set(EXECUTABLE_OUTPUT_PATH ../)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SFML_VERSION "2.5.1")

if (NOT sfml_FOUND)
        INCLUDE(FetchContent)
        FetchContent_Declare(sfml GIT_REPOSITORY "https://github.com/SFML/SFML.git" GIT_TAG "${SFML_VERSION}")
        FetchContent_GetProperties(sfml)
        if(NOT sfml_POPULATED)
            FetchContent_Populate(sfml)
            add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
            set(sfml_FOUND TRUE)
        endif()
endif()

set(INCLUDE_DIR
        Game/
        Game/Library/
        Game/Library/Window/
        Game/Library/SFMLSocket/
        Game/Library/CreatePackage/
        Game/Library/IdentifyPackage/
        Game/Client/
)

include(Game/CMakeLists.txt)
include(Game/Library/CMakeLists.txt)

add_executable(r-type_client ${CORE_SRC} ${CORE_LIB})

set_target_properties(r-type_client PROPERTIES PREFIX "")

target_compile_options(
        r-type_client
        PRIVATE
        ${CXX_FLAGS}
)

target_link_libraries(
        r-type_client
        PRIVATE
        sfml-graphics sfml-system sfml-window sfml-network sfml-audio
)

target_include_directories(
        r-type_client
        PUBLIC
        ${INCLUDE_DIR}
)


#----------------------------SERVER----------------------------------


project("r-type_server" VERSION 0.1 LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ../)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(INCLUDE_DIR
        Server/
        Server/Server/
        Server/GameServer/
        Server/Library/
        Server/Library/SFMLSocket/
        Server/Library/UserData/
        Server/Library/IdentifyPackage/
        Server/Library/CreatePackage/
)

include(Server/CMakeLists.txt)
include(Server/Library/CMakeLists.txt)


add_executable(r-type_server ${CORE_SRC} ${CORE_NETWORK})

set_target_properties(r-type_client PROPERTIES PREFIX "")

target_compile_options(
        r-type_server
        PRIVATE
        ${CXX_FLAGS}
)

target_link_libraries(
        r-type_server
        PRIVATE
        sfml-graphics sfml-system sfml-window sfml-network sfml-audio
)

target_include_directories(
        r-type_server
        PUBLIC
        ${INCLUDE_DIR}
)