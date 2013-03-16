project(hootsim)

cmake_minimum_required(VERSION 2.8)

# Set GCC flags to some sensible defaults
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O")

set(SIM_SOURCES
    src/SimulatableEntity.cpp
    src/Component.cpp
    src/VisibleComponent.cpp
    src/PositionComponent.cpp
    src/Stage.cpp
    src/Simulator.cpp
    
    src/Behaviour.cpp;
    src/RandomMovementBehaviour.cpp
    src/HootFactory.cpp
    
    src/Message.cpp
    src/PositionMessage.cpp
    src/MoveMessage.cpp
    
    src/main.cpp
)

set(SIM_HEADERS
    include/SimulatableEntity.h
    include/Component.h
    include/VisibleComponent.h
    include/PositionComponent.h
    include/Stage.h
    include/Simulator.h
    
    include/Behaviour.h
    include/RandomMovementBehaviour.h
    include/HootFactory.h
    
    include/Message.h
    include/PositionMessage.h
    include/MoveMessage.h
)

source_group("Header Files" FILES ${SIM_HEADERS})
source_group("Source Files" FILES ${SIM_SOURCES})
add_executable(hootsim ${SIM_SOURCES} ${SIM_HEADERS})

include_directories(${PROJECT_SOURCE_DIR}/include)

# Find SFML
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
find_package(SFML REQUIRED)
if(SFML_FOUND)
    target_link_libraries(hootsim ${SFML_LIBRARY})
    include_directories(${SFML_INCLUDE_DIR})
endif(SFML_FOUND)

install(TARGETS hootsim RUNTIME DESTINATION bin)
