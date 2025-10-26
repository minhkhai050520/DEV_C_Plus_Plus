#ifndef CLASS_WINDOW_MGR_H
#define CLASS_WINDOW_MGR_H
#include "class_screen.h"

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen{24, 28, ' '}};
};
#endif /* CLASS_WINDOW_MGR_H */