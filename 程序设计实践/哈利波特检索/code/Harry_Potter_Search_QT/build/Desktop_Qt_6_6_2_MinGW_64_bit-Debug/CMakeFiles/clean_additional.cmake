# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Harry_Potter_Search_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Harry_Potter_Search_autogen.dir\\ParseCache.txt"
  "Harry_Potter_Search_autogen"
  )
endif()
