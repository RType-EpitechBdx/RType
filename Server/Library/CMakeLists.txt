set(CORE_DIRECTORY Server/Library/)

set(CORE_NETWORK
        SFMLSocket/SfmlSocket.cpp
        UserData/UserData.cpp
        CreatePackage/CreatePackage.cpp
        IdentifyPackage/IdentifyPackage.cpp
        )

list(TRANSFORM CORE_NETWORK PREPEND ${CORE_DIRECTORY})