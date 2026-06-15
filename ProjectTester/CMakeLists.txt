cmake_minimum_required(VERSION 3.10)

project(ProjectTester)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ../Project/headers
)

add_executable(RoomTest
        RoomTest.cpp
        ../Project/sources/model/Room.cpp
)

add_executable(AthleteTest
        AthleteTest.cpp
        ../Project/sources/model/User.cpp
        ../Project/sources/model/Athlete.cpp
        ../Project/sources/exceptions/InvalidDataException.cpp
)

add_executable(InstructorTest
        InstructorTest.cpp
        ../Project/sources/model/User.cpp
        ../Project/sources/model/Instructor.cpp
        ../Project/sources/exceptions/InvalidDataException.cpp
)

add_executable(ModalityTest
        ModalityTest.cpp
        ../Project/sources/model/Modality.cpp
)

add_executable(ClassSessionTest
        ClassSessionTest.cpp
        ../Project/sources/model/ClassSession.cpp
)