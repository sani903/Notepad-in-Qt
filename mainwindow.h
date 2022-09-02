#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QFileDevice>
#include <QMessageBox>
#include "ui_mainwindow.h"

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
    void on_actionGrammar_Check_triggered();

    void on_actionCLose_triggered();

    void on_actionZoom_out_triggered();

    void on_actionSave_triggered();

    void on_actionZoom_in_triggered();

    void on_actionDebug_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_As_triggered();

    void on_actionResume_triggered();

    void on_actionBold_triggered(bool checked);

    void on_actionSuperScript_triggered(bool checked);

    void on_actionSubScript_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    QString mFile;
};
#endif // MAINWINDOW_H
