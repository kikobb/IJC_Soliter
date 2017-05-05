cmake_minimum_required(VERSION 3.7)
project(IJC_Soliter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES    main.cpp
                    model/Color.h
                    model/Card.cpp model/Card.h
                    model/CardDeck.cpp model/CardDeck.h
                    model/CardStack.cpp model/CardStack.h
        )
add_executable(IJC_Soliter ${SOURCE_FILES})