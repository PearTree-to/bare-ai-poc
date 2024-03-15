cmake_minimum_required(VERSION 3.25)

project(bare_whisper CXX)

include(bare)

add_bare_module(bare_whisper)

target_sources(
  ${bare_whisper}
  PRIVATE
    binding.cpp
)
