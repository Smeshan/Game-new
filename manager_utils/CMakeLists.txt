cmake_minimum_required(VERSION 3.5.1)

project(manager_utils LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_INC_DIR ${_BASE_DIR}/manager_utils)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(
    ${PROJECT_NAME} STATIC

    ${_INC_DIR}/managers/MgrBase.h
    ${_INC_DIR}/managers/DrawMgr.h
    ${_INC_DIR}/managers/RsrcMgr.h
    ${_INC_DIR}/managers/MediaMgr.h
    ${_INC_DIR}/managers/ManagerHandler.h
    
    ${_INC_DIR}/drawing/Widget.h
    ${_INC_DIR}/drawing/Image.h
    ${_INC_DIR}/drawing/Text.h

    ${_INC_DIR}/audio/Sound.h
    ${_INC_DIR}/audio/Audio.h

    ${_INC_DIR}/config/DrawMgrConfig.h
    ${_INC_DIR}/config/RsrcMgrConfig.h
    ${_INC_DIR}/config/MediaMgrConfig.h
    ${_INC_DIR}/config/ManagerHandlerConfig.h
	

	${_SRC_DIR}/managers/DrawMgr.cpp
	${_SRC_DIR}/managers/RsrcMgr.cpp
	${_SRC_DIR}/managers/MediaMgr.cpp
	${_SRC_DIR}/managers/ManagerHandler.cpp

	${_SRC_DIR}/drawing/Widget.cpp
	${_SRC_DIR}/drawing/Image.cpp
	${_SRC_DIR}/drawing/Text.cpp

	${_SRC_DIR}/audio/Sound.cpp
	${_SRC_DIR}/audio/Audio.cpp

)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
	${PROJECT_NAME} 
        PUBLIC 
		    ${_BASE_DIR}
)

target_link_libraries(
	${PROJECT_NAME} 
        PUBLIC 
		    sdl_utils
)