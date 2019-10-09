#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{    
    ui->setupUi(this);    
    ui->cargarPartida->setVisible(false);
    ui->nuevaPartida->setVisible(false);
    ui->multijugador->setVisible(false);
    ui->uss->setVisible(false);
    ui->pass->setVisible(false);
    ui->iniciar_2->setVisible(false);
    ui->registro_2->setVisible(false);
    music=new QMediaPlayer;
    music->setMedia(QUrl("qrc:/musica/Música Tema - Game of Thrones.mp3"));
    music->setVolume(5);
    music->play();
}

menu::~menu()
{
    delete ui;
}


void menu::on_iniciar_clicked()
{
    //nos pide iniciar sesion
    ui->uss->clear();
    ui->pass->clear();
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->iniciar_2->setVisible(true);
    ui->iniciar->setVisible(false);
    ui->registro->setVisible(false);

}

void menu::on_registro_clicked()
{
    //nos despliega el menu para crear la cuenta    
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);    
    ui->registro_2->setVisible(true);
    ui->iniciar->setVisible(false);
    ui->registro->setVisible(false);
    ui->iniciar_2->setVisible(false);
}

void menu::on_iniciar_2_clicked()
{
    QFile Iniciando(ui->uss->text());
    qDebug()<< "enntrando en iniciar 2";
    if (!Iniciando.open(QIODevice::ReadOnly | QIODevice::Text))
    {        
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Inicio","Cuenta inexistente, ¿Deseas crear una?",
                                    QMessageBox::Yes | QMessageBox::No);
        if ( reply == QMessageBox::Yes)
        {
            ui->uss->setText("");
            ui->pass->setText("");
            on_registro_clicked();
        }
        if ( reply == QMessageBox::No)
        {
            return;
        }
    }
    else
    {
        QTextStream ini(&Iniciando);
        user_=ini.readLine();
        pass_=ini.readLine();
        if (user_== ui->uss->text() && pass_== ui->pass->text())
        {
            //mostramos el menu de cargar partida, nueva partida, multijugador

            ui->iniciar_2->setVisible(false);
            ui->uss->setVisible(false);
            ui->pass->setVisible(false);
            ui->cargarPartida->setVisible(true);
            ui->nuevaPartida->setVisible(true);
            ui->multijugador->setVisible(true);
        }
    }

}

void menu::on_registro_2_clicked()
{
    if(ui->uss->text()=="" || ui->pass->text()=="") //verifica que el usuario y la contraseña no esten vacios
    {
        QMessageBox::information(this,"Registro","Registro no exitoso, revise bien los campos.");
    }
    else
    {
        QFile creandoCuenta(ui->uss->text());
        if ((!creandoCuenta.open((QIODevice::WriteOnly | QIODevice::Text )) //se abre en modo escritura
             ))
        {
            qDebug () << "error abriendo el archivo de registro";
            return;
        }

        QTextStream out(&creandoCuenta); //abre el archivo que se creo con la cuenta
        out << ui->uss->text(); //escribe el nombre de usuario en el archivo
        out <<endl<<  ui->pass->text()<<endl; // escribe la contraseña en el archivo de texto
        creandoCuenta.close(); //cierra el archivo
        QMessageBox::information(this,"Registro","Registro exitoso.");

        //mostramos el menu de cargar partida, nueva partida, multijugador
        ui->iniciar_2->~QPushButton();
        ui->uss->~QLineEdit();
        ui->pass->~QLineEdit();
        ui->registro_2->setVisible(false);
        ui->cargarPartida->setVisible(true);
        ui->nuevaPartida->setVisible(true);
        ui->multijugador->setVisible(true);
        user_ = ui->uss->text();
        pass_ = ui->pass->text();
    }

}

void menu::on_nuevaPartida_clicked()
{
    qDebug ( ) <<"nueva partida";
    nivel1 * juego;
    juego = new nivel1(user_,pass_);
    juego->show();
    music->stop();
    close();
}

void menu::on_cargarPartida_clicked()
{
    qDebug ( ) <<"cargar partida";
    QMessageBox::information(this,"Menú","En desarrollo");
}

void menu::on_multijugador_clicked()
{
    qDebug ( ) <<"multijugador";
    QMessageBox::information(this,"Menú","En desarrollo");
}
