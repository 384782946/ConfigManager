#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu * menu = new QMenu(this);
    int size = m_settings.beginReadArray("recent");
    for (int i = 0; i < size; ++i) {
        QString path = m_settings.value("path").toString();
        auto action = menu->addAction(path);
        m_rectProjects << path;

        connect(action,&QAction::trigger,this,[=](){

        });
    }

    if(menu->actions().size() == 0) {
        menu->addAction(QStringLiteral("空"));
    }

    ui->action_recent->setMenu(menu);
    m_settings.endArray();

    //ui->tableView->setEnabled(false);

    ui->tableView->setDragEnabled(true);
    ui->tableView->setDragDropMode(QAbstractItemView::DropOnly);
}

MainWindow::~MainWindow()
{
    m_settings.beginWriteArray("recent");
    for (int i = 0; i < m_rectProjects.size(); ++i) {
      m_settings.setArrayIndex(i);
      m_settings.setValue("path", m_rectProjects.at(i));
    }
    m_settings.endArray();

    delete ui;
}

void MainWindow::on_action_new_triggered()
{
   auto path = QFileDialog::getSaveFileName(this,QStringLiteral("新建文件"),QString(),"ConfigManager Projects (*.cmproject)");
   qDebug() << "on_action_new_triggered" << path;

   this->setWindowModified(true);
}

void MainWindow::on_action_recent_triggered()
{

}

void MainWindow::on_action_close_triggered()
{

}

void MainWindow::on_action_save_triggered()
{

}
