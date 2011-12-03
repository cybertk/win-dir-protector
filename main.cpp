/**
 *
 *
 *
 * Copyright 2010 Kantz  <cra4fizx@gmail.com> 
 */

#include <QApplication>

#include "cipher.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    cipher c;
    c.show();

    return app.exec();
}


