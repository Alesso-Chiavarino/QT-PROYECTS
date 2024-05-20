#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    botonAzul = new Boton;
    botonAzul->setNombre("Boton Azul");
    botonVerde = new Boton;
    botonVerde->setNombre("Boton Verde");
    botonMagenta = new Boton;
    botonMagenta->setNombre("Boton Magenta");

    connect(botonAzul, &Boton::clicked, this, &MainWindow::onBotonAzulClicked);
    connect(botonVerde, &Boton::clicked, this, &MainWindow::onBotonVerdeClicked);
    connect(botonMagenta, &Boton::clicked, this, &MainWindow::onBotonMagentaClicked);

    ui->verticalLayout->addWidget(botonAzul);
    ui->verticalLayout->addWidget(botonVerde);
    ui->verticalLayout->addWidget(botonMagenta);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBotonAzulClicked()
{
    ui->statusbar->showMessage("Boton Azul Clicked");
}

void MainWindow::onBotonVerdeClicked()
{
    ui->statusbar->showMessage("Boton Verde Clicked");
}

void MainWindow::onBotonMagentaClicked()
{
    ui->statusbar->showMessage("Boton Magenta Clicked");
}
