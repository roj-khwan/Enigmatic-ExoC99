cmake_minimum_required(VERSION 3.23)
set(CMAKE_C_STANDARD 99)

# Ensure debug symbols
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
project(Enigmatic-ExO C)

add_subdirectory(libs/exoc99)

add_library(
  enigma
  STATIC
  src/enigma.c
)
target_link_libraries(
  enigma
  PUBLIC
  game
)
target_include_directories(
  enigma
  PUBLIC include
)
add_executable(
  enigmaexo_main
  app/main.c
)
target_link_libraries(
  enigmaexo_main
  enigma
)

# ---tests---
enable_testing()

file(GLOB TESTS tests/*.c)

# add_library(test_common INTERFACE)
# target_include_directories(test_common INTERFACE
#   ${CMAKE_SOURCE_DIR}/tests/framework
# )

foreach(testfile ${TESTS})
    get_filename_component(testname ${testfile} NAME_WE)

    add_executable(${testname} ${testfile})
    # target_link_libraries(${testname} PRIVATE test_common)
    target_include_directories(
      ${testname}
      PRIVATE include
    )
    target_link_libraries(
      ${testname}
      PRIVATE
      game board
    )
    add_test(
      NAME ${testname}
      COMMAND ${testname}
    )
endforeach()

target_link_libraries(
  test_enigma
  PRIVATE enigma
)