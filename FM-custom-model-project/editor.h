#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

class Editor : public QDialog
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = 0);
    
    void setString(QString s);
    QString getString(){ return stringEdit->text(); }
    void setInt(int i);
    int getInt(){ return intSpinBox->value(); }

private:
    QLineEdit *stringEdit;
    QSpinBox *intSpinBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
    
};

#endif // EDITOR_H
