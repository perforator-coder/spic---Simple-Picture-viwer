cmake_minimum_required(VERSION 3.19)
project(spic LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools )

qt_standard_project_setup()
set(CMAKE_AUTORCC ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

qt_add_executable(spic
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    info_window.h info_window.cpp info_window.ui
    rec.qrc
    file_info.h file_info.cpp file_info.ui
    settings.h settings.cpp settings.ui

)

qt_add_translations(
    TARGETS spic
    TS_FILES spic_ru_RU.ts
)

target_link_libraries(spic
    PRIVATE
        Qt::Core
        Qt::Widgets
        #KF6::IconWidgets

)

install(TARGETS spic
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET spic
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
