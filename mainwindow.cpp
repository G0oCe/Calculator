#include "mainwindow.h"
#include <QGridLayout>
#include <QSound>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    QPushButton *num0 = new QPushButton("0", this);
    QPushButton *num1 = new QPushButton("1", this);
    QPushButton *num2 = new QPushButton("2", this);
    QPushButton *num3 = new QPushButton("3", this);
    QPushButton *num4 = new QPushButton("4", this);
    QPushButton *num5 = new QPushButton("5", this);
    QPushButton *num6 = new QPushButton("6", this);
    QPushButton *num7 = new QPushButton("7", this);
    QPushButton *num8 = new QPushButton("8", this);
    QPushButton *num9 = new QPushButton("9", this);

    QPushButton *percentBtn = new QPushButton("%", this);
    QPushButton *pmBtn = new QPushButton("+\\-", this);
    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *mnsBtn = new QPushButton("-", this);
    QPushButton *mult = new QPushButton("x", this);
    QPushButton *iqvl = new QPushButton("=", this);
    QPushButton *dev = new QPushButton("/", this);
    QPushButton *dot = new QPushButton(".", this);
    QPushButton *CE = new QPushButton("CE", this);

    std::vector<QPushButton*> numbtns;

    numbtns.push_back(num0);
    numbtns.push_back(num1);
    numbtns.push_back(num2);
    numbtns.push_back(num3);
    numbtns.push_back(num4);
    numbtns.push_back(num5);
    numbtns.push_back(num6);
    numbtns.push_back(num7);
    numbtns.push_back(num8);
    numbtns.push_back(num9);


    num0->setObjectName("zeroButton");
    num1->setObjectName("numButton");
    num2->setObjectName("numButton");
    num3->setObjectName("numButton");
    num4->setObjectName("numButton");
    num5->setObjectName("numButton");
    num6->setObjectName("numButton");
    num7->setObjectName("numButton");
    num8->setObjectName("numButton");
    num9->setObjectName("numButton");

    plsBtn->setObjectName("opButton");
    mnsBtn->setObjectName("opButton");
    mult->setObjectName("opButton");
    iqvl->setObjectName("opButton");
    dev->setObjectName("opButton");


    percentBtn->setObjectName("otherButton");
    pmBtn->setObjectName("otherButton");
    dot->setObjectName("otherButton");
    CE->setObjectName("otherButton");



    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();

    // Iterate over the list and resize each button
    for(QPushButton *button : allButtons) {
        button->setStyleSheet("margin:0px; padding:0px;"); // Remove margins and padding
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        connect(button, &QPushButton::clicked, this, &MainWindow::playClickSound);
    }

    for(QPushButton *num : numbtns) {
         connect(num, &QPushButton::clicked, this, &MainWindow::numPressed);
    }



    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lbl->setFixedHeight(131);
    QGridLayout *grid = new QGridLayout(this);

    grid->setSpacing(0); // Remove spacing between widgets
    grid->setContentsMargins(0, 0, 0, 0); // Remove margins around the layout

    // Place the widgets on the grid layout
    grid->addWidget(num0, 5, 0, 1, 2);
    grid->addWidget(num1, 4, 0);
    grid->addWidget(num2, 4, 1);
    grid->addWidget(num3, 4, 2);
    grid->addWidget(num4, 3, 0);
    grid->addWidget(num5, 3, 1);
    grid->addWidget(num6, 3, 2);
    grid->addWidget(num7, 2, 0);
    grid->addWidget(num8, 2, 1);
    grid->addWidget(num9, 2, 2);

    grid->addWidget(percentBtn, 1, 2);
    grid->addWidget(pmBtn, 1, 1);
    grid->addWidget(plsBtn, 4, 3);
    grid->addWidget(mnsBtn, 3, 3);
    grid->addWidget(mult, 2, 3);
    grid->addWidget(iqvl, 5, 3);
    grid->addWidget(dev, 5, 2);
    grid->addWidget(dev, 1, 3);
    grid->addWidget(dot, 5, 2);
    grid->addWidget(CE, 1, 0);

    // Create a list of all widgets in the layout
    QList<QWidget*> allWidgets = this->findChildren<QWidget*>();

    // Iterate over the list and apply the style to each widget
    for(QWidget *widget : allWidgets) {
        widget->setStyleSheet("border: 1px solid black;"); // Apply a thin black border to each widget
    }


    grid->addWidget(lbl, 0, 0, 1, 4);

    this->setLayout(grid);

    // For QLineEdit
    connect(lbl, &QLineEdit::textEdited, this, &MainWindow::playClickSound);

    //connect(num0, &QPushButton::clicked, this, &MainWindow::numPressed);
    //connect(num1, &QPushButton::clicked, this, &MainWindow::numPressed);

}

void MainWindow::playClickSound() { // not work
    QSound::play(":/click.wav");
}

void MainWindow::numPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString buttonText = button->text();
    QString labelText = lbl->text();

    lbl->setText(buttonText);
}
