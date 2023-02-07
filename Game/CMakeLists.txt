set(CORE_DIRECTORY Game/)

set(CORE_SRC
        Client/Game.cpp
        main.cpp)

list(TRANSFORM CORE_SRC PREPEND ${CORE_DIRECTORY})