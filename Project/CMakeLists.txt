cmake_minimum_required(VERSION 3.10)

project(Project)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(Project

        main.cpp

        sources/model/User.cpp
        sources/model/Athlete.cpp
        sources/model/Instructor.cpp

        sources/exceptions/InvalidDataException.cpp

        sources/containers/AthleteContainer.cpp

        sources/services/AthleteService.cpp
)