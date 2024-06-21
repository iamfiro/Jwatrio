#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#include "render.h"

int main() {
    int menuItems = 5;
    int screenX = 5, screenY = 4;
    char* menuText[] = {
        " 1-Player Game \n",
        " Network Game \n",
        " Options \n",
        " Highscores \n",
        " 좌호빈사진보기 \n",
    };

    ConsoleRender* render = createRender(5, 4, menuText, menuItems);
    movePos(screenX, screenY + 5); printf("      Yuchan Han, Seongju Cho"); Sleep(100);
    movePos(screenX + 6, screenY + 2); printf("J W A T R I O"); Sleep(100);
    render->start(render);

    int selectedMenu = render->getSelectedMenu(render); // 선택된 메뉴 확인
    printf("Selected Menu: %d\n", selectedMenu); // 선택된 메뉴 출력

    // 메모리 해제
    for (int i = 0; i < menuItems; i++) {
        free(render->menuSelectText[i]);
    }
    free(render->menuSelectText);
    free(render);

    return 0;
}
