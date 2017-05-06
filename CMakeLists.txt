project(IJC_Soliter)

set(CMAKE_CXX_STANDARD 11)

set(GAME_FILES      game/Game.cpp game/Game.h
                    game/History.cpp game/History.h
                    game/Help.cpp game/Help.h
        model/CardStack.cpp model/CardStack.h
        model/Color.h
        model/Card.cpp model/Card.h
                    model/CardDeck.cpp model/CardDeck.h
                    model/WorkingPack.cpp model/WorkingPack.h
        model/TargetStack.cpp model/TargetStack.h

        )

set(MAIN_FILES  main.cpp
        )

set(MODEL_FILES     model/Color.h
                    model/Card.cpp model/Card.h
                    model/CardDeck.cpp model/CardDeck.h
                    model/CardStack.cpp model/CardStack.h
                    model/WorkingPack.cpp model/WorkingPack.h
                    model/TargetStack.cpp model/TargetStack.h
        )

set(CONTROLL_FILES  controller/Controller.cpp controller/Controller.h
        )

#set(VIEW_FILES view/ViewAbstractClass.h
#        )


add_executable(Sol_model ${MODEL_FILES} main.cpp)
add_executable(Sol_main ${MAIN_FILES})
add_executable(Sol_game ${GAME_FILES}  main.cpp)
add_executable(Sol_controll ${CONTROLL_FILES}  main.cpp)
#add_executable(Sol_view ${VIEW_FILES})
