cmake_minimum_required(VERSION 3.23)
project(Assignment2 C)

set(CMAKE_C_STANDARD 11)

include_directories(headers)
include_directories(sources)

add_executable(Assignment2
        headers/airline.h
        headers/airport.h
        headers/airport_manager.h
        headers/date.h
        headers/def.h
        headers/flight.h
        headers/functions.h
        sources/airline.c
        sources/airport.c
        sources/airport_manager.c
        sources/date.c
        sources/flight.c
        sources/functions.c
        main.c cmake-build-debug/Passengers.c headers/Passengers.h)
