# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/SecretSanta_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SecretSanta_autogen.dir/ParseCache.txt"
  "SecretSanta_autogen"
  )
endif()
