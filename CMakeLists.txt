cmake_minimum_required(VERSION 3.22)
project(rsl_drive_sdk)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(yaml-cpp REQUIRED)

add_definitions(-DMELO_MIN_SEVERITY=MELO_SEVERITY_INFO)
add_definitions(-DMELO_USE_COUT)

find_package(ethercat_sdk_master REQUIRED)




file(GLOB_RECURSE  SRC_FILES CONFIGURE_DEPENDS ./src/*.c*)

add_library(${PROJECT_NAME} SHARED
  ${SRC_FILES}
)
add_library(${PROJECT_NAME}:${PROJECT_NAME} ALIAS ${PROJECT_NAME})


target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror=return-type)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)


# Support ros distros older than lyrical
if(COMMAND ament_target_dependencies)
    ament_target_dependencies(${PROJECT_NAME} ethercat_sdk_master)
else()
    target_link_libraries(${PROJECT_NAME}
    ethercat_sdk_master::ethercat_sdk_master)
endif()


target_link_libraries(${PROJECT_NAME}
  yaml-cpp 
)



install(
    DIRECTORY include/
    DESTINATION include
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT export_${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories(include)
ament_export_targets(export_${PROJECT_NAME})

ament_export_dependencies(
  ethercat_sdk_master
  yaml-cpp

)


ament_package()
