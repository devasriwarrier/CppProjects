#include "mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "New Application Name!");
    Mainwin win;
    return app->run(win);
}
