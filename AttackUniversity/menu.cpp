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
    music->setVolume(30);
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
    //verificamos si los datos que hay en los campos son equivalentes a algun archivo de texto    
     uss=ui->uss->text();
     pass=ui->pass->text();
    QFile archivo(uss);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        //cargamos de forma correcta el archivo por tanto vamos a habilitar la nueva ventana.
        QTextStream read(&archivo);
        QString clave;
        read.readLine();
        clave = read.readLine();
        if( clave == ui->pass->text())
        {
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            nivel = read.readLine();
            qDebug()<< nivel;
            ui->uss->setVisible(false);
            ui->pass->setVisible(false);
            ui->multijugador->setVisible(true);
            ui->cargarPartida->setVisible(true);
            ui->nuevaPartida->setVisible(true);
            ui->iniciar_2->setVisible(false);
            archivo.close();
            music->stop();
        }
        else
        {
            QMessageBox::information(this,"Menú","Error, revise bien los campos.");
        }
    }
    else
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
}

void menu::on_registro_2_clicked()
{
     uss=ui->uss->text();
     pass = ui->pass->text();
    QFile cuenta(uss);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Menú","Cuenta Creada Con Éxito.");
        QTextStream out(&cuenta);
        out << uss<<endl;
        out << pass << endl;
        cuenta.close();
        ui->uss->setVisible(false);
        ui->pass->setVisible(false);
        ui->multijugador->setVisible(true);
        ui->cargarPartida->setVisible(true);
        ui->nuevaPartida->setVisible(true);
        ui->registro_2->setVisible(false);
    }
    else
    {
        QMessageBox::information(this,"Menú","Error, por favor vuelva a intentarlo.");
    }
}

void menu::on_nuevaPartida_clicked()
{
    nivel1 *juego;
    juego = new nivel1(uss,pass,false, 1);
    juego->show();
    close();
}

void menu::on_cargarPartida_clicked()
{
    if( nivel == "1" )
    {
        nivel1 *juego;
        juego = new nivel1(uss,pass,true, 1);
        juego->show();
        close();
    }
    else if ( nivel =="2")
    {
        nivel2 *juego;
        juego = new nivel2(uss,pass,true, 2);
        juego->show();
        close();
    }

}

void menu::on_multijugador_clicked()
{    
    multijugador1 *juego;
    juego = new multijugador1;
    juego->show();
    close();
}
