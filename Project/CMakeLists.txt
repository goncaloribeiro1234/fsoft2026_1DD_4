cmake_minimum_required(VERSION 3.10)

project(Project)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(Project

        main.cpp

        sources/model/User.cpp
        sources/model/Athlete.cpp
        sources/model/Instructor.cpp
        sources/model/Gym.cpp
        sources/model/Modality.cpp
        sources/model/Room.cpp

        sources/exceptions/InvalidDataException.cpp

        sources/containers/AthleteContainer.cpp
        sources/containers/InstructorContainer.cpp
        sources/containers/ModalityContainer.cpp
        sources/containers/RoomContainer.cpp

        sources/services/AthleteService.cpp
        sources/services/InstructorService.cpp
        sources/services/ModalityService.cpp
        sources/services/RoomService.cpp

        sources/repo/GymRepositoryMemory.cpp

        headers/services/InstructorService.h
        headers/services/ModalityService.h

        headers/views/AdminView.h
        headers/views/MainView.h

        headers/controllers/AthleteController.h
        headers/controllers/InstructorController.h
        headers/controllers/RoomController.h

        sources/views/AdminView.cpp
        sources/views/MainView.cpp

        sources/controllers/AthleteController.cpp
        sources/controllers/RoomController.cpp
        sources/controllers/InstructorController.cpp
        sources/controllers/ModalityController.cpp





)