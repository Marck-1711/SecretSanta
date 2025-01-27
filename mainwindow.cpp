#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>
#include <QVector>
#include <stdlib.h>
#include "smtpclient.h"
#include "mimemessage.h"
#include "mimetext.h"
#include "emailaddress.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // scroll area
    QWidget *scroll = ui->scrollAreaWidgetContents;
    scroll->setStyleSheet("background-color:#AE0D13; border:none");
    contentLayout = new QVBoxLayout(scroll);
    scroll->setLayout(contentLayout);

    readList();

    // christmas bells image
    QPixmap bells("/home/marco/Documents/MARCO/Projects/example/img/christmas-bell.png");
    ui->bells->setPixmap(bells.scaled(140,140,Qt::KeepAspectRatio));

    // christmas hat image
    QPixmap christmas_hat("/home/marco/Documents/MARCO/Projects/example/img/santa-hat.png");
    ui->christmas_hat->setPixmap(christmas_hat.scaled(140,140,Qt::KeepAspectRatio));

    // Title image
    QPixmap pix("/home/marco/Documents/MARCO/Projects/example/img/logo(1).png");
    ui->titolo->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * READ dati.txt AND WRITE EVERY ROW WITH A NAME AND EMAIL IN A SCROLL AREA ROW
 */

void MainWindow::readList(){
    QFile file("/home/marco/Documents/MARCO/Projects/example/dati.txt");

    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Errore lettura file!";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);
    QString name;
    QString email;
    while(stream.atEnd() == false){
        QStringList fileRow = stream.readLine().split(":");
        name = fileRow[0];
        email = fileRow[1];
        updateScrollArea(name, email);
    }

    file.close();
}

/*
 * BUTTON TO ADD PERSON
 */

void MainWindow::on_pushButton_clicked()
{
    QString nome = ui->form_nome->text();
    QString email = ui->form_email->text();

    if(!nome.isEmpty() && !email.isEmpty()){
        loadFile(nome, email);
        updateScrollArea(nome, email);
    } else{
        ui->errorMsg->setStyleSheet("color:black; background-color:#AE0D13; font-weight:bold; border:none;");
    }
}

/*
 * LOADING OF dati.txt FILE ON SCROLL AREA
 */

void MainWindow::loadFile(QString nome, QString email){

    QFile file("/home/marco/Documents/MARCO/Projects/example/dati.txt");

    if(!file.open(QIODevice::Append)){
        qCritical() << "Errore nell'apertura file!";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);
    if(file.pos() == 0){
        stream << nome << ":" << email;
    } else{
        stream << "\n" << nome << ":" << email;
    }

    file.close();

    ui->form_nome->setText("");
    ui->form_email->setText("");
}

/*
 * ADD A ROW TO SCROLL AREA WITH NAME AND EMAIL FROM PARAMETERS
 */

void MainWindow::updateScrollArea(QString name, QString email){
    QHBoxLayout *rowLayout = new QHBoxLayout();

    // Label for name and email
    QLabel *nameLabel = new QLabel(name);
    nameLabel->setObjectName("nameLabel");
    nameLabel->setStyleSheet("font-size:22px; padding:4px; background-color:white; color:black; border:3px solid black; border-radius:5px;");
    QLabel *emailLabel = new QLabel(email);
    emailLabel->setObjectName("emailLabel");
    emailLabel->setStyleSheet("font-size:22px; padding:4px; background-color:white; color:black; border:3px solid black; border-radius:5px;");

    // button to delete row
    QPushButton *deleteButton = new QPushButton(this);

    QIcon trashIcon(":/img/img/trash-can.png");
    deleteButton->setIcon(trashIcon);
    deleteButton->setToolTip("Elimina questa riga");
    deleteButton->setIconSize(QSize(35, 35)); // set icon dimension
    deleteButton->setFixedSize(40, 40);      // set button dimension

    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        deleteRow(rowLayout->parentWidget());
    });

    // add elements to row layout
    rowLayout->addWidget(nameLabel);
    rowLayout->addWidget(emailLabel);
    rowLayout->addWidget(deleteButton);

    // Create a widget container for row and add to dynamic layout
    QWidget *rowWidget = new QWidget();
    rowWidget->setLayout(rowLayout);
    contentLayout->addWidget(rowWidget);
}

/*
 * DELETE A ROW FROM dati.txt FILE
 */

void MainWindow::deleteRow(QWidget *row){
    QString name = row->findChild<QLabel *>("nameLabel")->text();
    QString email = row->findChild<QLabel *>("emailLabel")->text();

    QFile file("/home/marco/Documents/MARCO/Projects/example/dati.txt");

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qCritical() << "Errore lettura file!";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);
    QString newFile, rowName, rowEmail, currentRow;
    QStringList currentRowList;
    while(!stream.atEnd()){
        currentRow = stream.readLine();
        currentRowList = currentRow.split(':');
        rowName = currentRowList[0];
        rowEmail = currentRowList[1];

        if(!(name == rowName && email == rowEmail)){
            newFile.append(currentRow + '\n');
        }
    }
    newFile.chop(1);
    file.resize(0);
    stream << newFile;

    contentLayout->removeWidget(row);
    row->deleteLater();
}

/*
 * CREATE A VECTOR WITH ASSOCIATES RANDOM INDEXES FOR INDEXES FROM 0 TO DIM-1
 *
 *  EX:  n=6
 *  0 --> 3
 *  1 --> 5
 *  2 --> 4
 *  3 --> 1
 *  4 --> 2
 *  5 --> 0
 */

QVector<int> createCouples(int dim){
    int randomNumber;
    QVector<int> receivers;

    for(int i = 0 ; i < dim ; i ++){
        randomNumber = rand()%dim;
        while(i == randomNumber || receivers.contains(randomNumber)){
            randomNumber = rand()%dim;
        }
        receivers.append(randomNumber);
    }

    return receivers;
}

/*
 * EMAIL SENDING
 */

void MainWindow::on_InviaEmail_clicked()
{
    /*
     * COUPLES CREATION - extract names and emails from dati.txt and associate a receiver to every sender
     */


    QVector<QString> names;
    QVector<QString> emails;
    QVector<int> indexes;
    int len;

    QFile file("/home/marco/Documents/MARCO/Projects/example/dati.txt");

    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Errore lettura file!";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);
    QStringList splittedRow;
    QString row;
    while(!stream.atEnd()){
        row = stream.readLine();
        splittedRow = row.split(':');
        names.append(splittedRow[0]);
        emails.append(splittedRow[1]);
    }

    len = names.length();

    indexes = createCouples(len);

    /*
     * EMAIL SENDING - sending n emails, where n is the number of partecipants
     */

    MimeMessage message;

    EmailAddress sender("marcoiacovelli17@gmail.com", "Marco");
    message.setSender(sender);

    for(int i = 0 ; i < len ; i ++){
        EmailAddress to(emails[i], names[i]);
        message.addRecipient(to);

        message.setSubject("BABBO NATALE SEGRETO");

        MimeText text;

        text.setText("Ciao, il tuo destinatario sarà: " + names[indexes[i]]);

        message.addPart(&text);

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        smtp.connectToHost();
        if(!smtp.waitForReadyConnected()){
            qDebug() << "Errore di connessione all'host!";
        }

        smtp.login("marcoiacovelli17@gmail.com", "mtyx nuky doqi zykv");
        if(!smtp.waitForAuthenticated()){
            qDebug() << "Errore nel login!";
        }

        smtp.sendMail(message);
        if(!smtp.waitForMailSent()){
            qDebug() << "Errore nelll'invio della mail";
        }

        smtp.quit();
    }

}
