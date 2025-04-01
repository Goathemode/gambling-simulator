add_library(Plinko STATIC
    Plinko.cpp
    PlinkoWrapper.cpp
)

target_include_directories(Plinko PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Plinko Core)