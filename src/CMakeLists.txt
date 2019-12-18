set(target template_lib)

set(project_root ${CMAKE_CURRENT_SOURCE_DIR}/..)

include_directories(
    ${project_root}/thirdparty
)

file(GLOB_RECURSE headers
    ${project_root}/include/*.hpp)
file(GLOB_RECURSE sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${target} ${sources})

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

target_compile_options(${target}
    PRIVATE
    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}
    INTERFACE
)

target_link_libraries(${target}
    PRIVATE
    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}
    ${DEFAULT_LIBRARIES}
    INTERFACE
)

install(TARGETS ${target} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(DIRECTORY ${project_root}/include DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME})