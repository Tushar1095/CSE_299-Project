#include <QApplication> // Include QApplication
#include "mainwindow.h" // Include MainWindow header

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create the application object
    MainWindow w; // Create the main window object
    w.show(); // Show the main window
    return a.exec(); // Enter the application event loop
}