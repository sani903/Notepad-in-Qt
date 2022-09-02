#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionGrammar_Check_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a file");
    if(!file.isEmpty()){
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            mFile = file;
            QTextStream in(&sFile);
            QString text= in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionCLose_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionZoom_out_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFile);
    if(sFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&sFile);
        out << ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionZoom_in_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionDebug_triggered()
{
    mFile = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Open a file");
    if(!file.isEmpty()){
        mFile = file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionResume_triggered()
{
    QString about_t;
    about_t = "Name: Sanidhya Vijayvargiya\n";
    about_t+= "College: BITS Pilani\n";
    about_t+= "Major: Computer Science\n";
    about_t+= "Skills: Neural Machine Translation, Abstractive Summarization, Sentiment Analysis, Python, C++\n";
    QMessageBox::about(this,"My Resume", about_t);
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    checked ? ui->textEdit->setFontWeight(QFont::Bold):
              ui->textEdit->setFontWeight(QFont::Normal);

}

void MainWindow::on_actionSuperScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked){
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    }
    else{
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    }
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_actionSubScript_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked){
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    }
    else{
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    }
    ui->textEdit->mergeCurrentCharFormat(format);
}
