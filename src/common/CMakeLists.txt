set(MODULE sv_common)

set(COMMON_SRC
    Logger.h
    Logger.cpp
    EventFdMutex.h
    EventFdMutex.cpp
)

add_library(${MODULE} STATIC
    ${COMMON_SRC}
)
