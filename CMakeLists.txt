cmake_minimum_required(VERSION 3.0.2)
project(template_package)


find_package(catkin REQUIRED COMPONENTS
    std_msgs
    nodelet
    roscpp
    rospy
    mrs_lib
    mrs_msgs
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES TemplateClass
    CATKIN_DEPENDS rospy roscpp std_msgs mrs_lib mrs_msgs 
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_library(TemplateClass src/TemplateClass.cpp)
add_dependencies(TemplateClass ${catkin_EXPORTED_TARGETS})

target_link_libraries(TemplateClass
    ${catkin_LIBRARIES}
)