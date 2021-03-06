cmake_minimum_required(VERSION 3.15)

project(mockups CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "..." FORCE)
endif()

if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
	set(QT_INCLUDE "/usr/include/x86_64-linux-gnu/qt5")
endif()

if(WIN32)
	# On Windows, the install dir must be specified, as it's not standardized
	if(DEFINED QT_BASEDIR)
		# Add it to the prefix path so find_package can find it
		list(APPEND CMAKE_PREFIX_PATH ${QT_BASEDIR})
		set(QT_INCLUDE ${QT_BASEDIR}/include)
		# CMake has an odd policy that links a special link lib for Qt on newer versions of CMake. Enable it so we don't get spammed, and I get to write less
		cmake_policy(SET CMP0020 NEW)
	else()
		message(FATAL_ERROR "--!@ Please define your QT install dir with -DQT_BASEDIR=C:/your/qt5/here")
	endif()
endif()	

message("Using ${QT_INCLUDE} as our Qt include dir")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SRC
src/main.cpp

src/stylemanager.h
src/stylemanager.cpp

src/controls/datamodel/dmecontrol.h
src/controls/datamodel/dmecontrol.cpp
src/controls/datamodel/texturecontrol.h
src/controls/datamodel/texturecontrol.cpp

src/widgets/titledgroupbox.h
src/widgets/titledgroupbox.cpp

src/tools/dmeshowcase.h
src/tools/dmeshowcase.cpp

src/tools/tooldialog.h
src/tools/tooldialog.cpp

src/tools/met/featurewidget.h
src/tools/met/featurewidget.cpp

src/tools/met/variablewidget.h
src/tools/met/variablewidget.cpp

src/tools/met/materialeditor.h
src/tools/met/materialeditor.cpp)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)
	
add_executable(mockups ${SRC} res/resource.qrc)
target_link_libraries(mockups PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)
target_include_directories(mockups PRIVATE ${QT_INCLUDE} ${QT_INCLUDE}/QtWidgets ${QT_INCLUDE}/QtGui ${QT_INCLUDE}/QtCore)

#add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
#					COMMAND ${CMAKE_COMMAND} -E copy_directory
#					${CMAKE_SOURCE_DIR}/resource $<TARGET_FILE_DIR:${PROJECT_NAME}>/resource)

add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/tools $<TARGET_FILE_DIR:${PROJECT_NAME}>/tools)

if(WIN32)
	# Set up the debugger so it can run the program without copying a million dlls
	set_target_properties(mockups PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=%PATH%;${QT_BASEDIR}/bin;")
endif()
