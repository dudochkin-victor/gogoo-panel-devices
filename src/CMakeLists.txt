INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${MPL_INCLUDE_DIRS}
    ${GCONF_INCLUDE_DIRS}
    ${UPOWER_INCLUDE_DIRS}
    ${CLUTTER_INCLUDE_DIRS}
    ${NOTIFY_INCLUDE_DIRS}
    ${PA_INCLUDE_DIRS}
    )

SET (PROGRAMS gogoo-panel-devices)

ADD_DEFINITIONS(-DLOCALEDIR="${LOCALEDIR}")
ADD_DEFINITIONS(-DMX_CACHE="${PKG_DATADIR}/mx.cache")
ADD_DEFINITIONS(-DTHEMEDIR="${PKG_DATADIR}/${PROGRAMS}/theme")
ADD_DEFINITIONS(-DGETTEXT_PACKAGE="${GETTEXT_PACKAGE}")
ADD_DEFINITIONS(-DDATADIR="${PKG_DATADIR}")

ADD_DEFINITIONS(-DPKGDATADIR="${PKG_DATADIR}")
ADD_DEFINITIONS(-DPKGICONDIR="${PKG_DATADIR}/${PROGRAMS}/icons")
ADD_DEFINITIONS(-DPKGTHEMEDIR="${PKGTHEMEDIR}")
ADD_DEFINITIONS(-DI_KNOW_THE_DEVICEKIT_POWER_API_IS_SUBJECT_TO_CHANGE)

ADD_DEFINITIONS(-std=c99)

SET(PROGRAM_SRCS
  meego-panel-devices.c 
  mpd-battery-device.c 
  mpd-battery-device.h 
  mpd-battery-icon.c 
  mpd-battery-icon.h 
  mpd-battery-tile.c 
  mpd-battery-tile.h 
  mpd-brightness-tile.c 
  mpd-brightness-tile.h 
  mpd-computer-pane.c 
  mpd-computer-pane.h 
  mpd-computer-tile.c 
  mpd-computer-tile.h 
  mpd-conf.c 
  mpd-conf.h 
  mpd-default-device-tile.c 
  mpd-default-device-tile.h 
  mpd-devices-pane.c 
  mpd-devices-pane.h 
  mpd-devices-tile.c 
  mpd-devices-tile.h 
  mpd-display-device.c 
  mpd-display-device.h 
  mpd-disk-tile.c 
  mpd-disk-tile.h 
  mpd-folder-button.c 
  mpd-folder-button.h 
  mpd-folder-tile.c 
  mpd-folder-tile.h 
  mpd-gobject.c 
  mpd-gobject.h 
  mpd-panel.c 
  mpd-panel.h 
  mpd-shell.c 
  mpd-shell.h 
  mpd-shell-defines.h 
  mpd-storage-device.c 
  mpd-storage-device.h 
  mpd-storage-device-tile.c 
  mpd-storage-device-tile.h 
  mpd-text.h 
  mpd-volume-tile.c 
  mpd-volume-tile.h 

    )

SET(PROGRAM_HEADERS
    )

ADD_EXECUTABLE(${PROGRAMS} ${PROGRAM_SRCS} ${PROGRAM_HEADERS})

   
TARGET_LINK_LIBRARIES(${PROGRAMS}
    ${MPL_LIBRARIES}
    ${GCONF_LIBRARIES}
    ${UPOWER_LIBRARIES}
#    ${CLUTTER_LIBRARIES}
    ${NOTIFY_LIBRARIES}
    gpm
    gvc
    )

INSTALL(TARGETS ${PROGRAMS} RUNTIME DESTINATION ${PKG_LIBEXECDIR})

########### Add .desktop target ###############
#CONFIGURE_FILE(
#  "${CMAKE_CURRENT_SOURCE_DIR}/gogoo-panel-internet.desktop.in"
#  "${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-internet.desktop"
#  IMMEDIATE @ONLY)
#INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-internet.desktop DESTINATION share/mutter-netbook/panels)

########### Add .service target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/com.meego.UX.Shell.Panels.devices.service.in"
  "${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.devices.service"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.devices.service DESTINATION share/dbus-1/services)


