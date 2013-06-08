INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${MPL_INCLUDE_DIRS}
    ${GCONF_INCLUDE_DIRS}
    ${UPOWER_INCLUDE_DIRS}
    ${CLUTTER_INCLUDE_DIRS}
    ${NOTIFY_INCLUDE_DIRS}
    )

SET (PROGRAMS gogoo-power-icon)

ADD_DEFINITIONS(-DLOCALEDIR="${LOCALEDIR}")
ADD_DEFINITIONS(-DMX_CACHE="${PKG_DATADIR}/mx.cache")
ADD_DEFINITIONS(-DTHEMEDIR="${PKG_DATADIR}/${PROGRAMS}/theme")
ADD_DEFINITIONS(-DGETTEXT_PACKAGE="${GETTEXT_PACKAGE}")
ADD_DEFINITIONS(-DDATADIR="${PKG_DATADIR}")

ADD_DEFINITIONS(-DPKGTHEMEDIR="${PKGTHEMEDIR}/power-icon")
ADD_DEFINITIONS(-DI_KNOW_THE_DEVICEKIT_POWER_API_IS_SUBJECT_TO_CHANGE)

SET(PROGRAM_SRCS
  ${CMAKE_SOURCE_DIR}/src/mpd-conf.c 
  ${CMAKE_SOURCE_DIR}/src/mpd-battery-device.c 
  ${CMAKE_SOURCE_DIR}/src/mpd-display-device.c 
  ${CMAKE_SOURCE_DIR}/src/mpd-gobject.c 
  meego-power-icon.c 
  mpd-global-key.c 
  mpd-global-key.h 
  mpd-idle-manager.c 
  mpd-idle-manager.h 
  mpd-lid-device.c 
  mpd-lid-device.h 
  mpd-power-icon.c 
  mpd-power-icon.h 
  mpd-shutdown-notification.c 
  mpd-shutdown-notification.h 

    )

SET(PROGRAM_HEADERS
    )

ADD_EXECUTABLE(${PROGRAMS} ${PROGRAM_SRCS} ${PROGRAM_HEADERS})

   
TARGET_LINK_LIBRARIES(${PROGRAMS}
    ${MPL_LIBRARIES}
    ${GCONF_LIBRARIES}
    ${UPOWER_LIBRARIES}
    ${CLUTTER_LIBRARIES}
    ${NOTIFY_LIBRARIES}
    gpm
    egg-console-kit
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
  "${CMAKE_CURRENT_SOURCE_DIR}/com.meego.UX.Shell.Panels.power.service.in"
  "${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.power.service"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/com.meego.UX.Shell.Panels.power.service DESTINATION share/dbus-1/services)


