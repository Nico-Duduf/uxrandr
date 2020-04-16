#include "uxrandr.h"
#include "ui_uxrandr.h"

UXRandR::UXRandR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UXRandR)
{
    ui->setupUi(this);

    // Get displays and add them
    QProcess xrandr;
    xrandr.start("xrandr");
    if (xrandr.waitForFinished(1000))
    {
        QString output = xrandr.readAllStandardOutput();
        QRegularExpression re("(\\S+) ((?:dis)?connected)");
        QRegularExpressionMatchIterator i = re.globalMatch(output);
        while ( i.hasNext() )
        {
            QRegularExpressionMatch match = i.next();
            if (match.captured(2) == "connected")
            {
                Display *d = new Display(match.captured(1));
                ui->verticalLayout->addWidget(d);
            }
        }
    }
    else
    {
        ui->verticalLayout->addWidget(new QLabel("Could not find xrandr"));
    }
}

UXRandR::~UXRandR()
{
    delete ui;
}

