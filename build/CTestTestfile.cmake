# CMake generated Testfile for 
# Source directory: /home/london-femboy/Projects/CFool/Enigmatic-ExO
# Build directory: /home/london-femboy/Projects/CFool/Enigmatic-ExO/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[dummy-tests]=] "/home/london-femboy/Projects/CFool/Enigmatic-ExO/build/tests_dummy")
set_tests_properties([=[dummy-tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;53;add_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;0;")
add_test([=[enigma-tests]=] "/home/london-femboy/Projects/CFool/Enigmatic-ExO/build/tests_enigma_logic")
set_tests_properties([=[enigma-tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;54;add_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;0;")
subdirs("libs/exoc99")
