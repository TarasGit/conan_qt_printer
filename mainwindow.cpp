#include "mainwindow.h"
#include "./ui_mainwindow.h"

const char conan_url[] = "https://github.com/conan-io/conan.git";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button_download->setEnabled(false);

    connect(ui->lineedit_adress, &QLineEdit::textChanged,
            this, &MainWindow::enableDownloadButton);


    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *EditMenu = menuBar()->addMenu(tr("Edit"));
}

void MainWindow::enableDownloadButton(){
    this->ui->button_download->setEnabled(not ui->lineedit_adress->text().isEmpty());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listview_main_doubleClicked(const QModelIndex &index)
{
    qDebug() << index.data().toString();
}

void MainWindow::on_button_download_clicked()
{

}

void MainWindow::on_button_quit_clicked()
{
    qDebug() << "Quit";
    QStringList package_lst;

    process.start("conan search");
    process.waitForFinished();
    usleep(1000);

    QByteArray result = process.readAllStandardOutput();
    QString string_result = QString(result);
    QStringList result_list = string_result.split("\n");

    // remove 2 first description lines
    result_list.removeFirst();
    result_list.removeFirst();
    // remove last empty line
    result_list.removeLast();

    qDebug() << "Result:" << result_list;
    package_lst << result_list;

    //ui->label_download->setText(result);

    model = new QStringListModel(this);
    model->setStringList(package_lst);
    ui->listview_main->setModel(model);

    ui->label_download->setText("Conan Download canceled.");
    ui->button_download->setEnabled(true);

    QProgressDialog *progressDialog = new QProgressDialog(this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
}
