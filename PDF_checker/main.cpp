#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "C:\\Qt\\Projects\\SubmitResetFormActions.pdf";

    //SubmitResetFormActions
    //JavaScriptAction.pdf

    QFile current_file(path);

    bool marker = false;

    QString line;
    QString text_to_find = "<</JS";

    int i = 1;

    if (!current_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Couldn\'t read file " << path; //на всякий случай
    }
    else
    {
        QTextStream accIn(&current_file);


        while (!accIn.atEnd())
        {
            line = accIn.readLine(); // с этой строчки

            marker = line.contains(text_to_find, Qt::CaseInsensitive);

            if(marker) break;

            i++;
        }
    }
    current_file.close();

    if(marker){
        std::cout << "Found on [" << i << "] line\n" << std::endl;
    }
    else
    {
        printf("Not found\n");
    }

    return a.exec();
}
