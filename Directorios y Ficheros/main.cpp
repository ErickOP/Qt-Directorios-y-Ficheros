#include <QCoreApplication>
#include <iostream>
#include <QDateTime>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc = 0;
    do{
        qDebug() << "\n*** Analisis de un directorio/fichero ***";
        qDebug() << "\n ";
        qDebug() << "\n ";
        qDebug() << "1.Ingrese un path";
        qDebug() << "\n ";
        qDebug() << "2.Salir del programa";
        qDebug() << "\nIngrese una opcion: ";
        std::cin >> opc;

        switch (opc) {

        case 1:
        {
            qDebug()<<"Ingresar un path\n";
            char dire[100];
            QDir directorio;
            QFile Dir;
            QString Nombre;
            QFileInfo ali;
            do{
                std::cin.getline(dire,100);
                QString c = dire;
                directorio = (c);
                QString name = directorio.dirName();
                ali = c;
                if(directorio.exists()){
                    qDebug() << "El path fue encontrado\n";
                    if(ali.isDir()){
                        qDebug() << "El path ingresado es un directorio";
                        QFileInfoList inforPath = directorio.entryInfoList();
                        int tamanioTot = inforPath.size();
                        qDebug() <<"Tamanio total de la carpeta " << tamanioTot;
                        foreach(const QFileInfo &info, inforPath){
                            QString nombres = info.fileName();
                            if ((nombres == ".") || (nombres == ".."))
                                continue;
                            QString tipo = info.path();
                            QString modificacion = info.birthTime().toString();
                            bool sePuedeLeer = info.isReadable();
                            bool esEjecutable = info.isExecutable();
                            QString duenio = info.owner();
                            qDebug() <<"                 **Directorio**               ";
                            qDebug() <<"Nombre:              " << nombres;
                            qDebug() <<"Tipo(directorio o carpeta):                " << tipo;
                            qDebug() <<"Tamaño:              " << tamanioTot;
                            qDebug() <<"Fecha de creacion:   " << modificacion;
                            qDebug() <<"Se puede leer:       " << sePuedeLeer;
                            qDebug() <<"Archivo Ejecutable:       " << esEjecutable;
                            qDebug() <<"Dueño del elemento:               " << duenio;
                        }
                    }
                    if(ali.isFile()){
                        qDebug() <<"El path ingresado es un Archivo";
                        QFileInfo ArchivoInfo = directorio.absolutePath();
                        int tamanio = ArchivoInfo.size();
                        QString nombresA = ArchivoInfo.fileName();
                        if ((nombresA == ".") || (nombresA == ".."))
                            continue;
                        QString tipoA = directorio.absolutePath();
                        QString modificacionA = ArchivoInfo.lastModified().toString();
                        bool sePuedeLeerA = ArchivoInfo.isReadable();
                        bool esEjecutableA = ArchivoInfo.isExecutable();
                        QString duenioA = ArchivoInfo.owner();
                        qDebug() << tamanio;
                        qDebug() <<"                   **Archivo**                   ";
                        qDebug() <<" Nombre:              " << nombresA;
                        qDebug() <<" Tipo(directorio o carpeta):                " << tipoA;
                        qDebug() <<" Fecha de creacion:   " << modificacionA;
                        qDebug() <<" Se puede leer:       " << sePuedeLeerA;
                        qDebug() <<" Archivo Ejecutable:       " << esEjecutableA;
                        qDebug() <<" Dueño del elemento:               " << duenioA;
                    }
                    break;
                }else
                    qDebug() <<"Ingrese un path correcto";
            }while(!directorio.exists()||!(ali.isFile()));
            break;
        }
            break;
        case 2:
        {
             qDebug()<<"Gracias por utilizar el programa";
        }
            break;
        default:
            qDebug() <<"Opcion incorrecta!";
            break;
        }
    }while(opc !=2);
    return a.exec();
}
