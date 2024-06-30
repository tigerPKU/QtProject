cmake_minimum_required(VERSION 3.5)

project(untitled3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    yonghu.h yonghu.cpp yonghu.ui
    help_me_take.h help_me_take.cpp help_me_take.ui
    ordermessage.h ordermessage.cpp
    dialogue_end.h dialogue_end.cpp dialogue_end.ui
    order_page.h order_page.cpp order_page.ui
    createdatabase.cpp database.cpp database.h
    help_me_buy.h help_me_buy.cpp help_me_buy.ui
    rider.h rider.cpp rider.ui
    rider_login.h rider_login.cpp rider_login.ui
    rider_rigister.h rider_rigister.cpp rider_rigister.ui
    rider_rigister_success.h rider_rigister_success.cpp rider_rigister_success.ui
    message_view.h message_view.cpp message_view.ui
    message_view2.h message_view2.cpp message_view2.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        user_login.h user_login.cpp user_login.ui
        current_user.h current_user.cpp
        user_register.h user_register.cpp user_register.ui
        user_register_success.h user_register_success.cpp user_register_success.ui
        location_choose.h location_choose.cpp location_choose.ui
        map.qrc
        Position.h
        cancel_success.h cancel_success.cpp cancel_success.ui

        pic2.qrc
        pic3.qrc
    )
    # Define target properties for Android with Qt 6 as:
    # set_property(TARGET untitled3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #              ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled3 SHARED
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled3)
endif()
set_target_properties(untitled3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS untitled3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled3)
endif()
