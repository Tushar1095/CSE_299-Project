#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qwidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // Enable Qt's meta-object system

public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructor
    ~MainWindow(); // Destructor

    private slots:
        void on_loginButton_clicked(); // Slot for handling login button click

private:
    Ui::MainWindow *ui; // Pointer to the UI class
};

#endif // MAINWINDOW_H