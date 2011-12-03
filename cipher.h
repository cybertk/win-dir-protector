#ifndef CIPHER_H
#define CIPHER_H

#include <QtGui>

class cipher : public QWidget
{
        Q_OBJECT;

public:
        cipher();

private slots:
        void selectDir();
        void doCipher();
        void setName(QString);

private:
        QLineEdit *dirLineEdit;
        QPushButton *exploreButton;
        QPushButton *cipherButton;

        QDir *dir;
        QString oldName;
        QString newName;

};
#endif
