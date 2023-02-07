set(CORE_DIRECTORY Server/)

set(CORE_SRC
        main.cpp
        Server/Server.cpp
        GameServer/GameServer.cpp)

list(TRANSFORM CORE_SRC PREPEND ${CORE_DIRECTORY})