project(000_boost)

set(CMAKE_PREFIX_PATH $ENV{BOOST_DIR})

find_package(Boost COMPONENTS filesystem system REQUIRED)
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")

my_add_target(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})