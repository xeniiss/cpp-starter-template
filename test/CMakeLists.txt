set(target tests)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

find_package(Catch2 CONFIG REQUIRED)

add_executable(${target}
    ${sources})

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        -Wno-unused-variable
    )
endif()

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)

target_compile_definitions(${target}
    PRIVATE
)

# Link libraries
target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
    template_lib
    Catch2::Catch2
)
