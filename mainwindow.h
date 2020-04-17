#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QTextEdit>
#include "password.h"

class MainWindow : public QWidget {

    Q_OBJECT

    public:
    MainWindow();
    ~MainWindow();

    public slots:
    void generate_password();

    private:
    QFormLayout *option_layout;
    QVBoxLayout *main_layout, *button_layout, *result_layout;

    QGroupBox *option_box, *result_box;

    QSpinBox *b_length;

    QCheckBox *b_letter, *b_number, *b_spe, *b_low, *b_upp;

    QPushButton *b_newPass;

    QTextEdit *display_pass;

    Password *password;
};

#endif // MAINWINDOW_H
