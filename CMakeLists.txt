# *******************************************************************************************
#/ <summary>
#/ 
#/ </summary>
#/ <created>ʆϒʅ,18.04.2019</created>
#/ <changed>ʆϒʅ,10.09.2019</changed>
# *******************************************************************************************

# CMakeList.txt : CMake project for LearningCplusPlus, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME LearningCplusPlus)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
          VERSION 1.0.0.1
          DESCRIPTION "Learning CplusPlus Notes"
          HOMEPAGE_URL "https://github.com/BirdSofts/LearningCplusPlus"
          LANGUAGES CXX
)

list(APPEND RESOURCES
          ${TARGET_NAME}.rc
          resource.h
)

list(APPEND HEADER_FILES
          LearningCplusPlus.h
          _1_Introduction.h
          _2_BasicsOfCplusPlus.h
          _3_ProgramStructure.h
          _4_CompoundDataTypes.h
          _5_Classes.h
          _6_OtherLanguageFeatures.h
          _7_cPlusPlusStandardLibrary.h
          Console.h
)

list(APPEND SOURCE_FILES
          LearningCplusPlus.cpp
          _1_Introduction.cpp
          _2_BasicsOfCplusPlus.cpp
          _3_ProgramStructure.cpp
          _4_CompoundDataTypes.cpp
          _5_Classes.cpp
          _6_OtherLanguageFeatures.cpp
          _7_cPlusPlusStandardLibrary.cpp
          Console.cpp
)

if(WIN32)
          list(APPEND SOURCE_FILES ${HEADER_FILES})
endif()

# Add source to this project's executable.
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${RESOURCES})

# TODO: Add tests and install targets if needed.
