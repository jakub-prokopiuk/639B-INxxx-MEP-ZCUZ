#include <QApplication>
#include "PuzzleWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PuzzleWindow window;
    window.show();

    return app.exec();
}
