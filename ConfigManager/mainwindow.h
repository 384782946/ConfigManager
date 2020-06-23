#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_new_triggered();

    void on_action_recent_triggered();

    void on_action_close_triggered();

    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;

    QSettings m_settings;
    QStringList m_rectProjects;
};

#endif // MAINWINDOW_H
