﻿cmake_minimum_required(VERSION 3.5)

project(OS_QtWindows VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES OS_QtWindows_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        os_qtwindows.cpp
        os_qtwindows.h
        os_qtwindows.ui
        icons.qrc
        ${TS_FILES}
)

# # 新增子目录
# include_directories(
#     ${PROJECT_SOURCES_DIR}/protobufData
# )

# add_subdirectory(protobufData)

# link_libraries(protobufData)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OS_QtWindows
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        application/OS.cpp application/OS.h
        disk/disk_info.txt disk/disk.cpp disk/disk.h
        memory/memory_for_file.h memory/memory_for_process.h memory/memory.cpp memory/MemoryManager.h
        file/tree_directory.cpp file/tree_directory.h
        process/process_manager.h
        process/ProcessManager.cpp
        UI/filewindow_txt/txt_window.cpp UI/filewindow_txt/txt_window.h
        UI/mycomputer/tip.txt
        UI/status_bar/status_bar_window.cpp UI/status_bar/status_bar_window.h UI/status_bar/status_bar.cpp UI/status_bar/status_bar.h
        UI/task_manager/tab_disk.cpp UI/task_manager/tab_disk.h UI/task_manager/tab_groupblock.cpp UI/task_manager/tab_groupblock.h UI/task_manager/tab_memory.cpp UI/task_manager/tab_memory.h UI/task_manager/tab_process.cpp UI/task_manager/tab_process.h UI/task_manager/task_manager.cpp UI/task_manager/task_manager.h
        UI/win/date_time_Label.cpp UI/win/date_time_Label.h UI/win/win_window.cpp UI/win/win_window.h UI/win/win.cpp UI/win/win.h
        UI/ui.h
        ui_controller/os_ui_controller.cpp
        OSThread/OSThread.cpp OSThread/OSThread.h
        protobufData/MyTest.cpp protobufData/MyTest.h protobufData/t1.pb.cc protobufData/t1.pb.h protobufData/t1.proto
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET OS_QtWindows APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(OS_QtWindows SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(OS_QtWindows
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(OS_QtWindows PRIVATE Qt${QT_VERSION_MAJOR}::Widgets protobuf)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.OS_QtWindows)
endif()
set_target_properties(OS_QtWindows PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS OS_QtWindows
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OS_QtWindows)
endif()
