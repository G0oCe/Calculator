#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    QLineEdit *lbl = new QLineEdit(this);
    explicit MainWindow(QWidget *parent = nullptr);
    void numPressed();
    void operationPressed();
    void equalsPressed();
    void playClickSound();
    void CEpressed();
    void changeSign();
    void calculatePercentage();
    void addDecimalPoint();
    void add();
    void subtract();
    void multiply();
    void divide();
    void equal();
    void setPendingOperation();
signals:

};

#endif // MAINWINDOW_H
