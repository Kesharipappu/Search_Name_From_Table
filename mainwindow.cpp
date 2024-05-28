#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up the table
    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Column 1" << "Column 2" << "Column 3" << "Column 4" << "Colunn 5" << "Column 6");

    // Add names to the table
    QStringList namesColumn1 = {"Rahul", "Ganesh", "Anjali", "Sonali", "Ajay", "Avinash"};
    QStringList namesColumn2 = {"Golu", "Pappu", "Shimpi", "Anupam", "Asha", "Vijay"};
    QStringList namesColumn3 = {"Pawan", "Rajeev", "Ashish", "Rajatesh", "Sujeet","Rohan"};
    QStringList namesColumn4 = {"Pradeep", "Sanjana", "Akash", "Shaurya", "Sumit", "Deepanjali"};
    QStringList namesColumn5 = {"Romit", "Munni", "Deepak", "Sanju", "Ranjeet", "Rekha"};
    QStringList namesColumn6 = {"Praveen", "Rahul", "Mukesh", "Aryan", "Anurag", "Prakash"};


    for (int row = 0; row < 6; ++row) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(namesColumn1[row]));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(namesColumn2[row]));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(namesColumn3[row]));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(namesColumn4[row]));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(namesColumn5[row]));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(namesColumn6[row]));

    }

    // Connect the search bar signal to the slot
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::search);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search(const QString &text)
{
    QString query = text.toLower();

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
            QTableWidgetItem *item = ui->tableWidget->item(row, column);
            if (item->text().toLower().contains(query)) {
                item->setBackground(Qt::green);  // Highlight in yellow
            } else {
                item->setBackground(Qt::white);  // Remove highlight
            }
        }
    }
}
