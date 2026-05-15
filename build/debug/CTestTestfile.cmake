# CMake generated Testfile for 
# Source directory: /home/london-femboy/Projects/CFool/Enigmatic-ExO
# Build directory: /home/london-femboy/Projects/CFool/Enigmatic-ExO/build/debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_dummy]=] "/home/london-femboy/Projects/CFool/Enigmatic-ExO/build/debug/test_dummy")
set_tests_properties([=[test_dummy]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;66;add_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;72;add_game_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;0;")
add_test([=[test_enigma]=] "/home/london-femboy/Projects/CFool/Enigmatic-ExO/build/debug/test_enigma")
set_tests_properties([=[test_enigma]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;66;add_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;73;add_game_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;0;")
add_test([=[test_minimax]=] "/home/london-femboy/Projects/CFool/Enigmatic-ExO/build/debug/test_minimax")
set_tests_properties([=[test_minimax]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;66;add_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;74;add_game_test;/home/london-femboy/Projects/CFool/Enigmatic-ExO/CMakeLists.txt;0;")
subdirs("libs/exoc99")
