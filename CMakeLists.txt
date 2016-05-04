#@note   Hikvision Digital Technology Co., Ltd. All Rights Reserved.
#@brief  CMake子目录配置文件
#@author Yaopei
#@date   2015/7/31
#@note   the CMakeLists.txt for src. directory


PROJECT(HMSProxy)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -O2 -Wall")

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

LINK_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/lib
)


SET(SRC_SRCS
  main.cpp
  Sqlite/CppSQLite3.cpp
  Sqlite/SqliteManager.cpp
  Sqlite/sqlite3.c
)

# shared library
#ADD_LIBRARY(BigdataStreamRecv SHARED ${SRC_SRCS} )

#static library
#ADD_LIBRARY(BigdataStreamRecv_static STATIC ${SRC_SRCS})

ADD_EXECUTABLE(logManager ${SRC_SRCS})
# link library
TARGET_LINK_LIBRARIES(logManager NetApp LogCore Encrypt CrossPlat TraceWorker CmdLineInter FileOpr 
						json dl pthread readline ncurses tinfo
						boost_atomic boost_atomic boost_atomic boost_regex boost_regex boost_thread boost_system)

# clean
#SET_TARGET_PROPERTIES(BigdataStreamRecv PROPERTIES CLEAN_DIRECT_OUTPUT 1)
#SET_TARGET_PROPERTIES(BigdataStreamRecv_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
