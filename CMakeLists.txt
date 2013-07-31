cmake_minimum_required(VERSION 2.6)

project(libifa)

option(LIBIFA_WITH_SHARED
  "Build shared library."
  OFF)

if(LIBIFA_WITH_SHARED)
  add_library(ifa SHARED ifa.c)
  set_target_properties(ifa PROPERTIES SOVERSION "0.0.1")
else(LIBIFA_WITH_SHARED)
  add_library(ifa STATIC ifa.c)
endif(LIBIFA_WITH_SHARED)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-keywords")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -pipe")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")
endif(CMAKE_COMPILER_IS_GNUCC)

install(FILES ifa.h ifa.hpp DESTINATION include)
install(TARGETS ifa DESTINATION lib)
