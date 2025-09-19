set(GUI_MODULE rv_gui)

set(GUI_SRC
)

set(GUI_MODEL_SRC
)

set(GUI_VIEWMODEL_SRC
    # viewmodel/StreamImagerProvider.h
    # viewmodel/StreamImagerProvider.cpp
)

set(GUI_VIEW_SRC
)

set(GUI_QML_SRC
)

qt6_add_qml_module(${GUI_MODULE}
    URI rv.gui
    VERSION 1.0
    RESOURCE_PREFIX /
    OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rv/gui
    QML_FILES
        ${GUI_QML_SRC}
    SOURCES
        ${GUI_SRC}
        ${GUI_MODEL_SRC}
        ${GUI_VIEWMODEL_SRC}
        ${GUI_VIEW_SRC}
)

target_include_directories(${GUI_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)