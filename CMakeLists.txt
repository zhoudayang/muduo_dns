cmake_minimum_required(VERSION 3.6)
project(muduo_dns)

set(CMAKE_CXX_STANDARD 11)

link_libraries(muduo_net_cpp11 muduo_base_cpp11 pthread)

add_compile_options(-Wall -Werror -O2 -g)

add_executable(dns_test dns_test.cc dns_channel.cc)
