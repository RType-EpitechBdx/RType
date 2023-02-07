set(CORE_DIRECTORY Game/Library/)

set(CORE_LIB
        Window/Window.cpp
        SFMLSocket/SfmlSocket.cpp
        CreatePackage/CreatePackage.cpp
        IdentifyPackage/IdentifyPackage.cpp)

list(TRANSFORM CORE_LIB PREPEND ${CORE_DIRECTORY})