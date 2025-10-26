#include "class_screen.h"
#include "class_window_mgr.h"

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

int main()
{
    Screen myScreen(5,3, ' ');
    const Screen blank(5,3, 'a');
    myScreen.set('#').display(std::cout);
    blank.display(std::cout);
    return 0;
}