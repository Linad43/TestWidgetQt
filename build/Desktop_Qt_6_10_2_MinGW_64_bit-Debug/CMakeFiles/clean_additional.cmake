# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NewWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NewWidget_autogen.dir\\ParseCache.txt"
  "NewWidget_autogen"
  )
endif()
