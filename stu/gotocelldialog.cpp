#include "gotocelldialog.h"
#include <QPushButton>

GoToCellDialog::GoToCellDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(buttonBox,&QDialogButtonBox::accepted,this,&QDialog::accept);
    connect(buttonBox,&QDialogButtonBox::rejected,this,&QDialog::reject);
}

void GoToCellDialog::on_lineEdit_textChanged()
{
   buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
