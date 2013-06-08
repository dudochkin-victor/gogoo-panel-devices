SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 0)
SET(VERSION_PATCH 0)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${MX_INCLUDE_DIRS}
    ${DBUS_INCLUDE_DIRS}
    ${GCONF_INCLUDE_DIRS}
    ${PA_INCLUDE_DIRS}
    )

SET (LIBRARY gvc)

SET(LIBRARY_SRCS 
    gvc-channel-map.c 
    gvc-channel-map.c 
    gvc-channel-map.h 
    gvc-mixer-card.c 
    gvc-mixer-card.h 
    gvc-mixer-control.c 
    gvc-mixer-control.h 
    gvc-mixer-event-role.c 
    gvc-mixer-event-role.h 
    gvc-mixer-sink.c 
    gvc-mixer-sink.h 
    gvc-mixer-sink-input.c 
    gvc-mixer-sink-input.h 
    gvc-mixer-source.c 
    gvc-mixer-source.h 
    gvc-mixer-source-output.c 
    gvc-mixer-source-output.h 
    gvc-mixer-stream.c 
    gvc-mixer-stream.h 
    )

ADD_DEFINITIONS(-DLOCALEDIR="${LOCALEDIR}")
ADD_DEFINITIONS(-DMX_CACHE="${DATADIR}/mx.cache")
ADD_DEFINITIONS(-DGETTEXT_PACKAGE="${GETTEXT_PACKAGE}")
ADD_DEFINITIONS(-DLIBEXECDIR="${PKG_LIBEXECDIR}")
ADD_DEFINITIONS(-DPKG_DATA_DIR="${PKG_DATADIR}")
ADD_DEFINITIONS(-DPKG_VERSION="${PKG_VERSION}")
#ADD_DEFINITIONS(-DWITH_ONLINE_NM)

ADD_LIBRARY(${LIBRARY} ${LIBRARY_SRCS})

SET_TARGET_PROPERTIES( ${LIBRARY} PROPERTIES
     SOVERSION 0
     VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
   )


TARGET_LINK_LIBRARIES(${LIBRARY}
    ${MX_LIBRARIES}
    ${PA_LIBRARIES}
    )
