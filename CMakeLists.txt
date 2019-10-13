# *******************************************************************************************
#/ <summary>
#/
#/ </summary>
#/ <created>ʆϒʅ,18.04.2019</created>
#/ <changed>ʆϒʅ,13.09.2019</changed>
# *******************************************************************************************


cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(TARGET_NAME LearningCplusPlus)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
  VERSION 1.0.0.1
  DESCRIPTION "Learning CplusPlus Notes"
  HOMEPAGE_URL "https://github.com/BirdSofts/LearningCplusPlus"
  LANGUAGES CXX
  )

if(MSVC)
  list(APPEND RESOURCES
    ${TARGET_NAME}.rc
    resource.h
    )
endif(MSVC)

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
message(${CMAKE_PREFIX_PATH}/bin/libgcc_s_seh-1.dll)
message(${CMAKE_CXX_COMPILER})
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

if(MINGW)
  add_custom_command(TARGET ${TARGET_NAME} PRE_BUILD
    COMMAND cmake -E copy_if_different
    ${CMAKE_PREFIX_PATH}/bin/libgcc_s_seh-1.dll
    ${CMAKE_PREFIX_PATH}/bin/libstdc++-6.dll
    ${CMAKE_PREFIX_PATH}/bin/libwinpthread-1.dll
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endif(MINGW)
