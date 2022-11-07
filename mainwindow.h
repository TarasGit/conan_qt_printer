#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QProcess>
#include <QDebug>
#include <unistd.h>
#include <QProgressDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listview_main_doubleClicked(const QModelIndex &index);
    void enableDownloadButton();
    void on_button_download_clicked();
    void on_button_quit_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QListView *view;
    QProcess process;
};
#endif // MAINWINDOW_H
