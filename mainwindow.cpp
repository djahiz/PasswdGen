#include "mainwindow.h"

MainWindow::MainWindow() : QWidget() {

    //---------------------------------
    // Options Choice
    //---------------------------------

    option_box = new QGroupBox("Password options");

    b_length = new QSpinBox;
    b_length->setValue(8);
    b_length->setMinimum(1);
    b_length->setMaximum(32);

    b_letter = new QCheckBox;
    b_letter->setChecked(true);
    b_number = new QCheckBox;
    b_number->setChecked(true);
    b_spe = new QCheckBox;
    b_spe->setChecked(true);
    b_low = new QCheckBox;
    b_low->setChecked(true);
    b_upp = new QCheckBox;
    b_upp->setChecked(true);

    option_layout = new QFormLayout;
    option_layout->addRow("Length", b_length);
    option_layout->addRow("Letter", b_letter);
    option_layout->addRow("Number", b_number);
    option_layout->addRow("Special", b_spe);
    option_layout->addRow("Lower", b_low);
    option_layout->addRow("Upper", b_upp);

    option_box->setLayout(option_layout);
    option_box->setFixedSize(200, 150);

    //---------------------------------
    //Generate Password
    //---------------------------------

    b_newPass = new QPushButton("New Password");

    button_layout = new QVBoxLayout;
    button_layout->addWidget(b_newPass);

    QObject::connect(b_newPass, SIGNAL(clicked()), this, SLOT(generate_password()));

    //---------------------------------
    //Result Display
    //---------------------------------

    display_pass = new QTextEdit;
    display_pass->setReadOnly(true);

    result_layout = new QVBoxLayout;
    result_layout->addWidget(display_pass);

    //---------------------------------
    //Main layout
    //---------------------------------

    main_layout = new QVBoxLayout;
    main_layout->addWidget(option_box);
    main_layout->addLayout(button_layout);
    main_layout->addLayout(result_layout);

    this->setLayout(main_layout);
    this->setFixedSize(260, 280);

    password = new Password();

}

MainWindow::~MainWindow(){
    delete password;
}

void MainWindow::generate_password(){
    password->setLength(b_length->value());
    password->setLetter(b_letter->isChecked());
    password->setNumber(b_number->isChecked());
    password->setLowerCase(b_low->isChecked());
    password->setUpperCase(b_upp->isChecked());
    password->setSpecialChar(b_spe->isChecked());

    password->resetPassword();
    password->generatePassword();

    display_pass->setText(password->getPassword());
}
