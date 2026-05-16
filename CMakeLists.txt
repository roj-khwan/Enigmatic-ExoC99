cmake_minimum_required(VERSION 3.23)
set(CMAKE_C_STANDARD 99)

# Ensure debug symbols
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
# Release flags
set(CMAKE_C_FLAGS_RELEASE "-O2 -Wall -Wextra")

project(Enigmatic-ExO C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(libs/exoc99)

function(add_project_library libname)
  add_library(
    ${libname}
    STATIC src/${libname}.c
  )
  target_link_libraries(
    ${libname} 
    PUBLIC ${ARGN}
  )
  target_include_directories(
    ${libname}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
endfunction()

add_project_library(minimax game board)
add_project_library(enigma game board minimax)

add_executable(
  enigmaexo_main
  app/main.c
)
target_link_libraries(
  enigmaexo_main
  PRIVATE enigma
)
add_executable(
  enigmaexo_benchmark
  app/benchmark.c
)
target_link_libraries(
  enigmaexo_benchmark
  PRIVATE enigma
)

# ---tests---
# enable_testing()

# function(add_game_test testname)
#   add_executable(${testname} tests/${testname}.c)

#   target_include_directories(
#     ${testname}
#     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
#   )

#   target_link_libraries(
#     ${testname}
#     PRIVATE
#     ${ARGN}
#   )

#   add_test(
#     NAME ${testname}
#     COMMAND ${testname}
#   )
# endfunction()

# add_game_test(test_dummy)
# add_game_test(test_enigma game board enigma)
# add_game_test(test_minimax board game enigma minimax)