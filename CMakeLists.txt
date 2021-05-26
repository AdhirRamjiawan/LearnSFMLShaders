# CMakeList.txt : CMake project for LearnSFMLShaders, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LearnSFMLShaders")


if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)


# Add source to this project's executable.
add_executable (LearnSFMLShaders "LearnSFMLShaders.cpp" "LearnSFMLShaders.h" )

# TODO: Add tests and install targets if needed.
include_directories(LearnSFMLShaders "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/include")

target_link_libraries(LearnSFMLShaders LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-main-d.lib")
target_link_libraries(LearnSFMLShaders LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-system-d.lib")
target_link_libraries(LearnSFMLShaders LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-window-d.lib")
target_link_libraries(LearnSFMLShaders LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-graphics-d.lib")
target_link_libraries(LearnSFMLShaders LINK_PUBLIC "C:/Users/adhir/Downloads/libs/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/sfml-audio-d.lib")

if (MSVC)
#target_link_options(LearnSFMLShaders PRIVATE /SUBSYSTEM:WINDOWS)
endif(MSVC)