#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QProcess>
#include "ui_display.h"


class Display : public QWidget, private Ui::Display
{
    Q_OBJECT

public:
    explicit Display(QString id, QString name = "", QWidget *parent = nullptr);

private slots:
    void on_rSlider_valueChanged(int value);
    void on_gSlider_valueChanged(int value);
    void on_bSlider_valueChanged(int value);
    void on_gammaSlider_valueChanged(int value);
    void on_resetGammaButton_clicked();
    void on_brightSlider_valueChanged(int value);
    void on_resetBrightnessButton_clicked();

private:
    QString _id;
    int _prevGamma;
    QProcess *_xrandr;
    bool _freezeUI;

    void sleep(int msecs);

    void setGamma();
};

#endif // DISPLAY_H
