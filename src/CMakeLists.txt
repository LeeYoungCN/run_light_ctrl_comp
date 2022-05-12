target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/stub)

add_subdirectory(run_light_behavior_ctrl)
add_subdirectory(run_light_ctrl_comp)

FILE(GLOB HEAD_LIST ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)
install(FILES ${HEAD_LIST} DESTINATION ${HEAD_INSTALL_PATH} COMPONENT ${PROJECT_NAME})