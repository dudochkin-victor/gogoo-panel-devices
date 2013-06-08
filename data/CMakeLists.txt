ADD_SUBDIRECTORY(theme)
ADD_SUBDIRECTORY(icons)

########### Add .desktop target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/gogoo-panel-devices.desktop.in"
  "${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-devices.desktop"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/gogoo-panel-devices.desktop DESTINATION ${DATA_DIR}/panels)


