project(IJC_Soliter)

set(CMAKE_CXX_STANDARD 11)

set(GAME_FILES Game.cpp Game.h
        History.cpp History.h
        Help.cpp Help.h
        CardStack.cpp CardStack.h
        Color.h
        Card.cpp Card.h
        CardDeck.cpp CardDeck.h
        WorkingPack.cpp WorkingPack.h
        TargetStack.cpp TargetStack.h

        Controller.cpp Controller.h
        ConsoleView.cpp ConsoleView.h)

set(MODEL_FILES Color.h
        Card.cpp Card.h
        CardDeck.cpp CardDeck.h
        CardStack.cpp CardStack.h
        WorkingPack.cpp WorkingPack.h
        TargetStack.cpp TargetStack.h
        )

set(CONTROLL_FILES Controller.cpp Controller.h
        )

#set(VIEW_FILES view/ViewAbstractClass.h
#        )


add_executable(Sol_model ${MODEL_FILES} moj_main.cpp)
add_executable(Sol_main moj_main.cpp)
add_executable(Sol_game ${GAME_FILES} moj_main.cpp ViewAbstractClass.h)
add_executable(Sol_controll ${CONTROLL_FILES} moj_main.cpp)
#add_executable(Sol_view ${VIEW_FILES})
