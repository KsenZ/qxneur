#include <QTranslator>
#include <QLocale>
#include <QString>
#include <QDebug>
#include "QXNeur.h"

int main(int argc, char** argv)
{
    QXNeur app(argc, argv);

    QString fname = QString("qxneur_%1.qm").arg(QLocale::system().name().left(2));
    QTranslator translator;
    qDebug() << "TRANSLATIONS_DIR: Loading translation file" << fname << "from dir" << TRANSLATIONS_DIR;
    qDebug() << "load success:" <<translator.load(fname, TRANSLATIONS_DIR, "_");
    app.installTranslator(&translator);

    return app.exec();
}
