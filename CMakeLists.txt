CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
CMAKE_POLICY(VERSION 2.6)
SET(CMAKE_BUILD_TYPE Debug)
PROJECT(gogoo-panel-devices)
SET(PKG_VERSION 0.2.0)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)
INCLUDE( ${CMAKE_SOURCE_DIR}/CMake/Modules/TargetDistclean.cmake)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

FIND_PACKAGE(PkgConfig)

PKG_CHECK_MODULES(MX mx-1.0 REQUIRED)
PKG_CHECK_MODULES(MPL meego-panel REQUIRED)
PKG_CHECK_MODULES(DBUS dbus-glib-1 REQUIRED)
PKG_CHECK_MODULES(GCONF gconf-2.0 REQUIRED)
PKG_CHECK_MODULES(UPOWER upower-glib REQUIRED)
PKG_CHECK_MODULES(CLUTTER clutter-gtk-1.0 REQUIRED)
PKG_CHECK_MODULES(NOTIFY libnotify REQUIRED)
PKG_CHECK_MODULES(PA libpulse-mainloop-glib REQUIRED)

FIND_PACKAGE(Gettext)
SET(GETTEXT_PACKAGE "gogoo-panel-devices")

SET(PKG_DATADIR ${CMAKE_INSTALL_PREFIX}/share)
SET(LOCALEDIR ${CMAKE_INSTALL_PREFIX}/share/locale)
SET(PKG_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
SET(PKG_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
SET(PKG_LIBEXECDIR ${CMAKE_INSTALL_PREFIX}/libexec)
SET(DATA_DIR ${CMAKE_INSTALL_PREFIX}/share)

ADD_SUBDIRECTORY(egg-console-kit)
ADD_SUBDIRECTORY(gpm)
ADD_SUBDIRECTORY(gvc)
ADD_SUBDIRECTORY(data)
ADD_SUBDIRECTORY(po)
ADD_SUBDIRECTORY(power-icon)
ADD_SUBDIRECTORY(src)

IF (ENABLE_DOC)
    ADD_SUBDIRECTORY(doc)
ENDIF()

########### Add uninstall target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/CMake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake") 

