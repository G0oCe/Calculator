#include <mainwindow.h>
#include <QFile>
#include <QString>

int main(int argc,char*argv[]){
    QApplication app(argc,argv);
    MainWindow window;

    window.setFixedSize(346, 560);
    window.setWindowTitle("IbragimCoder");


    QFile file(":/calculator.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    //Set the application's stylesheet
    window.setStyleSheet(styleSheet);

    window.show();

    return app.exec();
}
