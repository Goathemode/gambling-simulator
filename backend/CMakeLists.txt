# Add core library
add_library(Core STATIC
    core/RNG.cpp
    core/Statistics.cpp
)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add plinko subdirectory
add_subdirectory(games/plinko)

# Add main executable if needed
add_executable(PlinkoDemo main.cpp)
target_link_libraries(PlinkoDemo Core games/plinko)