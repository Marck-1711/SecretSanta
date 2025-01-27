#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void loadFile(QString, QString);
    void updateScrollArea(QString, QString);
    void readList();
    void deleteRow(QWidget*);
    void on_InviaEmail_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *contentLayout;
};
#endif // MAINWINDOW_H
