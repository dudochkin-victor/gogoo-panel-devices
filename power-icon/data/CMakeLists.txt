ADD_SUBDIRECTORY(theme)

########### Add .desktop target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/gogoo-power-icon.desktop.in"
  "${CMAKE_CURRENT_BINARY_DIR}/gogoo-power-icon.desktop"
  IMMEDIATE @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/gogoo-power-icon.desktop DESTINATION ${DATA_DIR}/panels)


