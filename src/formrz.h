#ifndef FORMRZ_H
#define FORMRZ_H

#include "ui_formrz.h"

class Formrz : public QWidget, private Ui::Formrz
{
    Q_OBJECT

public:
    explicit Formrz(QWidget *parent = nullptr);
};

#endif // FORMRZ_H
