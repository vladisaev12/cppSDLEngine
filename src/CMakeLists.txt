add_executable(${PROJECT_NAME}
    # SRC
    src/main.cc

    #LIBS
    src/drawEngine/drawEngine.hh
    src/drawEngine/drawEngine.cc

    src/inputEngine/inputEngine.hh
    src/inputEngine/inputEngine.cc

#   ${SRC_DIR}/name.cc
)