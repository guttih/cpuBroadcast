#include "mainwindow.h"
#include "QColorDialog"

#include "./ui_mainwindow.h"


MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnColor_clicked()
{
    QColor color = QColorDialog::getColor( ui->btnColor->palette().button().color(), this );
    if( color.isValid() )
    {
        ColorToFormButton( ui->btnColor, color.name() );
    }
}

float MainWindow::luma( QColor color )
{
    float f;
    f= 0.2126 * color.red() + 0.7152 * color.green(); +0.0722 * color.blue();
    return f;

}

void MainWindow::ColorToFormButton( QPushButton *btnColor, QString strHexidecimalColor )
{
    QColor op( strHexidecimalColor );
    QString strOppositeColor;
    if( luma( op ) > 40 )
    {
        strOppositeColor = "black";
    }
    else
    {
        strOppositeColor ="white";
    }
    op.setRed( 255 - op.red() );
    op.setGreen( 255 - op.green() );
    op.setBlue( 255 - op.blue() );
    //strOppositeColor = op.name();



    QString strStyle = QString( "QPushButton { background-color: grey; }\n"
                                "QPushButton:enabled { background-color: %0; color:%1; }\n" ).arg( strHexidecimalColor, strOppositeColor );
    btnColor->setStyleSheet( strStyle );
    btnColor->setText( QString( "%0" ).arg( strHexidecimalColor ) );
}
