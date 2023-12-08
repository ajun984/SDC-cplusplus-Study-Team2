#include <iostream>
#include <memory>
#include "board/controller/BoardController.h"
#include "board/controller/request/RequestToEdit.h"
#include "board/controller/request/RequestToWrite.h"
#include "board/controller/response/ResponseFoundPostForEdit.h"
#include "board/controller/response/ResponseRead.h"
#include "board/controller/response/ResponseList.h"
#include "board/entity/manager/BoardManager.h"
#include "board/service/BoardServiceImpl.h"
#include "board/repository/BoardRepository.h"
#include "board/repository/BoardRepositoryImpl.h"

#include "ui/console/window/console_window.h"
#include "ui/console/service/ConsoleUiServiceImpl.h"
#include "mysql/DbProcess.h"



int main() {


//    BoardRepository *boardRepository = new BoardRepositoryImpl();
//    BoardService* boardService = new BoardServiceImpl();
// make::shared : 공유 포인터 선언
// 다른곳에서 헤더참조만 하면 언제든 사용 할 수 있음
    auto boardRepository = std::make_shared<BoardRepositoryImpl>();
    auto boardService = std::make_shared<BoardServiceImpl>(boardRepository);
    auto boardController = std::make_shared<BoardController>(boardService);
    boardManager = BoardManager(boardController);

    boardManager.startBoard();
    boardController->boardRead(boardManager.getBoardList()[0].getBoardUID());


    RequestToWrite request("아아","이거","되냐");
    boardController->boardWrite(request);


    const char* DB_HOST = "localhost";
    const char* DB_USER = "eddi";
    const char* DB_PASS = "eddi@123";
    const char* DB_NAME = "test_db";

    DbProcess db(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    db.connect();
    std::string accountID = "qwe";
    std::string password = "123";
    db.insertAccountData(accountID, password);

/*    boardController->boardWrite(request);

    boardController->boardList();
    RequestToEdits requestFormEdit(boardManager.getBoardList()[0].getBoardUID(),"이거도","되냐");
    boardController->boardEdit(requestFormEdit);
    boardController->boardList();
    boardController->boardRemove(boardManager.getBoardList()[0].getBoardUID());
    boardController->boardList();
    //console_window _console_window;*/
//    std::make_shared<UiServiceCreateHandler>();
//    _console_window.start_console_ui_window();
//    ConsoleUiServiceImpl ConsoleUiService;
//    Board *board;
//
//    board = ConsoleUiService.creatPost();
//    ConsoleUiService.postExit();


    return 0;


}
