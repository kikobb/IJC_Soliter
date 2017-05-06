cmake_minimum_required(VERSION 3.7)
project(IJC_Soliter)

set(CMAKE_CXX_STANDARD 11)

set(MAIN_FILES  main.cpp
        )

set(MODEL_FILES     model/Color.h
                    model/Card.cpp model/Card.h
                    model/CardDeck.cpp model/CardDeck.h
                    model/CardStack.cpp model/CardStack.h
        )


add_executable(Sol_model ${MODEL_FILES})
add_executable(Sol_main ${MAIN_FILES})