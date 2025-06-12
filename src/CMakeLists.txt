target_sources(${PROJECT_NAME}
    PUBLIC
    # SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cc

    #LIBS
    ${CMAKE_CURRENT_SOURCE_DIR}/drawEngine/drawEngine.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/drawEngine/drawEngine.cc

    ${CMAKE_CURRENT_SOURCE_DIR}/inputEngine/inputEngine.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/inputEngine/inputEngine.cc

#   ${SRC_DIR}/name.cc
)