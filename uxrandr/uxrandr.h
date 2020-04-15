#ifndef UXRANDR_H
#define UXRANDR_H

#include <QMainWindow>
#include <QProcess>
#include <QRegularExpression>

#include "display.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UXRandR; }
QT_END_NAMESPACE

class UXRandR : public QMainWindow
{
    Q_OBJECT

public:
    UXRandR(QWidget *parent = nullptr);
    ~UXRandR();

private:
    Ui::UXRandR *ui;
};
#endif // UXRANDR_H
