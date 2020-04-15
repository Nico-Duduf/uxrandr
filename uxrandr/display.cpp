#include "display.h"

#include <QtDebug>

Display::Display(QString id, QString name, QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    _id = id;
    if (name != "") nameLabel->setText(name);
    else nameLabel->setText(id);

    _prevGamma = 100;
    _freezeUI = false;

    _xrandr = new QProcess();
    _xrandr->setProgram("xrandr");
}

void Display::on_rSlider_valueChanged(int value)
{
    rBox->setValue( value/100.0 );
    if (_freezeUI) return;
    setGamma();
}

void Display::on_gSlider_valueChanged(int value)
{
    gBox->setValue( value/100.0 );
    if (_freezeUI) return;
    setGamma();
}

void Display::on_bSlider_valueChanged(int value)
{
    bBox->setValue( value/100.0 );
    if (_freezeUI) return;
    setGamma();
}

void Display::on_gammaSlider_valueChanged(int value)
{
    double v = value / 100.0;
    gammaBox->setValue(v);

    int dif = value - _prevGamma;
    _prevGamma = value;

    if (_freezeUI) return;

    _freezeUI = true;
    rSlider->setValue( rSlider->value() + dif );
    gSlider->setValue( gSlider->value() + dif );
    bSlider->setValue( bSlider->value() + dif );
    _freezeUI = false;
    setGamma();
}

void Display::on_resetGammaButton_clicked()
{
    _freezeUI = true;
    gammaSlider->setValue(100);
    rSlider->setValue(100);
    gSlider->setValue(100);
    bSlider->setValue(100);
    setGamma();
    _freezeUI = false;
}

void Display::on_brightSlider_valueChanged(int value)
{
    if (_freezeUI) return;
    brightBox->setValue(value);
    _xrandr->setArguments(QStringList() << "--output" << _id << "--brightness" << QString::number( brightSlider->value()/100.0 ));
    _xrandr->start();
}

void Display::on_resetBrightnessButton_clicked()
{
    brightSlider->setValue(100);
}

void Display::sleep(int msecs)
{
    struct timespec ts = { msecs / 1000, (msecs % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void Display::setGamma()
{
    _xrandr->setArguments(QStringList() << "--output" << _id << "--gamma" << QString::number(rSlider->value()/100.0) + ":" + QString::number(gSlider->value()/100.0) + ":" + QString::number(bSlider->value()/100.0) );
    _xrandr->start();
}
