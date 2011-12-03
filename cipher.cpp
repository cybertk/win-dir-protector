#include "cipher.h"

cipher::cipher()
{
    exploreButton = new QPushButton("exploer");
    cipherButton = new QPushButton("cipher");
    dirLineEdit = new QLineEdit;

    QHBoxLayout *editLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    connect(exploreButton, SIGNAL(clicked()), this, SLOT(selectDir()));
    connect(cipherButton, SIGNAL(clicked()), this, SLOT(doCipher()));
    connect(dirLineEdit, SIGNAL(textChanged(QString)), this, SLOT(setName(QString)));

    editLayout->addWidget(exploreButton);
    editLayout->addWidget(cipherButton);
    mainLayout->addWidget(dirLineEdit);
    mainLayout->addLayout(editLayout);

    setLayout(mainLayout);
}

void cipher::setName(QString path)
{
    dir = new QDir(path);

    oldName = dir->dirName();
    if (!dir->cdUp())
        QMessageBox::warning(0, "", tr("cdUp failed"));

    if (oldName.endsWith(".")) {
        cipherButton->setText(tr("decode"));
        newName = oldName.left(oldName.length() - 1);
        oldName = QString(newName).append("..\\");

    } else {
        cipherButton->setText(tr("encode"));
        newName = QString(oldName).append("..\\");
    }
}

void cipher::selectDir()
{
    QString path = QFileDialog::getExistingDirectory(this,
            tr("Open Directory"), "",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    dirLineEdit->setText(path);
}

void cipher::doCipher()
{
    qDebug() << oldName << "\n" << newName;

    if (!dir->rename(oldName, newName)) {
        QMessageBox::warning(0, "", tr("Rename failed"));
    }

    dir->cd(newName);
    dirLineEdit->setText(dir->absolutePath());

}
