#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ctime"
#include"QTime"
#include<iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            game[i][j]=rand()%6+1;
        }
    }
    showwindow();
    //checkgame();
    //clean();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showwindow()
{
    ui->label_26->setNum(20-(presstime/2));

    QString str=QString::number(game[0][0]);
    ui->pushButton->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[0][1]);
    ui->pushButton_2->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[0][2]);
    ui->pushButton_3->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[0][3]);
    ui->pushButton_4->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[0][4]);
    ui->pushButton_5->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[1][0]);
    ui->pushButton_6->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[1][1]);
    ui->pushButton_7->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[1][2]);
    ui->pushButton_8->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[1][3]);
    ui->pushButton_9->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[1][4]);
    ui->pushButton_10->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[2][0]);
    ui->pushButton_11->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[2][1]);
    ui->pushButton_12->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[2][2]);
    ui->pushButton_13->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[2][3]);
    ui->pushButton_14->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[2][4]);
    ui->pushButton_15->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[3][0]);
    ui->pushButton_16->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[3][1]);
    ui->pushButton_17->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[3][2]);
    ui->pushButton_18->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[3][3]);
    ui->pushButton_19->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[3][4]);
    ui->pushButton_20->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[4][0]);
    ui->pushButton_21->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[4][1]);
    ui->pushButton_22->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[4][2]);
    ui->pushButton_23->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[4][3]);
    ui->pushButton_24->setIcon(QIcon(":/candy crush/"+str+".png"));

    str=QString::number(game[4][4]);
    ui->pushButton_25->setIcon(QIcon(":/candy crush/"+str+".png"));


}

void MainWindow::push()
{

    for(i=0;i<5;i++)
    {
        count=0;
        for(j=0;j<5;j++)
        {
            if(game[j][i]!=0)
            {
                check[count][i]=game[j][i];
                count++;
            }
        }
    }
    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
                game[j][i]=check[j][i];
        }
    }
    showwindow();
    delay(500);

    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            if(game[j][i]==0)
                game[j][i]=rand()%6+1;
        }
    }

    showwindow();

}

void MainWindow::delay(int time)
{
    QTime t= QTime::currentTime().addMSecs(time);
    while( QTime::currentTime() < t )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void MainWindow::changed()
{

    if(change[0][1]==change[1][1])
    {
        if(abs(change[0][0]-change[1][0])==1)
        {
            trans=game[(change[1][0])][(change[1][1])];
            game[(change[1][0])][(change[1][1])]=game[(change[0][0])][(change[0][1])];
            game[(change[0][0])][(change[0][1])]=trans;
        }
    }
    if(change[0][0]==change[1][0])
    {
        if(abs(change[0][1]-change[1][1])==1)
        {   trans=game[(change[1][0])][(change[1][1])];
            game[(change[1][0])][(change[1][1])]=game[(change[0][0])][(change[0][1])];
            game[(change[0][0])][(change[0][1])]=trans;
        }
    }


}

void MainWindow::clean()
{
    if(l[0]<2&&k[0]<2)
     {
         if(times==0)
             changed();
         showwindow();
     }
    else
    {
        while(k[0]>2||l[0]>2)
        {

         if(k[0]>2)
         {
             for(i=0;i<k[0];i++)
             {
                 game[(k[2])][(k[3]-i)]=0;
             }
         }
         if(l[0]>2)
         {
             for(i=0;i<l[0];i++)
             {
                 game[(l[2]-i)][(l[3])]=0;
             }
         }
            checkgame();
        }
    showwindow();
    delay(500);
    push();
    showwindow();
    delay(500);
    }

}


void MainWindow::checkgame()
{
    count=0;

    for(int a=0;a<5;a++)
    {
        j=game[a][0]%10;
        k[0]=1;
        for(int b=0;b<5;b++)
        {

        if(j==(game[a][b+1]%10))
        {
            k[0]++;
            k[1]=j;
            k[2]=a;
            k[3]=b+1;
        }
        else
        {
            if(k[0]>2)
                break;

            k[0]=1;
            j=game[a][b+1]%10;
        }

        if(b==3)
            break;

        }
        if(k[0]>2)
            break;
    }

    for(int a=0;a<5;a++)
    {
        i=game[0][a]%10;
        l[0]=1;

        for(int b=0;b<5;b++)
        {

            if(i==(game[b+1][a]%10))
            {
                l[0]++;
                l[1]=i;
                l[2]=b+1;
                l[3]=a;
            }
            else
            {
                if(l[0]>2)
                    break;

                i=game[b+1][a]%10;
                l[0]=1;
            }

        if(b==3)
            break;
        }
        if(l[0]>2)
            break;
    }



}



void MainWindow::on_pushButton_clicked()
{

    change[(presstime%2)][0]=0;
    change[(presstime%2)][1]=0;
    // ui->label->setPixmap(QPixmap(":/candy crush/select.png"));

    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_2_clicked()
{

    change[(presstime%2)][0]=0;
    change[(presstime%2)][1]=1;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_3_clicked()
{

    change[(presstime%2)][0]=0;
    change[(presstime%2)][1]=2;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_4_clicked()
{

    change[(presstime%2)][0]=0;
    change[(presstime%2)][1]=3;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_5_clicked()
{

    change[(presstime%2)][0]=0;
    change[(presstime%2)][1]=4;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_6_clicked()
{

    change[(presstime%2)][0]=1;
    change[(presstime%2)][1]=0;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_7_clicked()
{

    change[(presstime%2)][0]=1;
    change[(presstime%2)][1]=1;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_8_clicked()
{

    change[(presstime%2)][0]=1;
    change[(presstime%2)][1]=2;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_9_clicked()
{

    change[(presstime%2)][0]=1;
    change[(presstime%2)][1]=3;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_10_clicked()
{

    change[(presstime%2)][0]=1;
    change[(presstime%2)][1]=4;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_11_clicked()
{

    change[(presstime%2)][0]=2;
    change[(presstime%2)][1]=0;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_12_clicked()
{

    change[(presstime%2)][0]=2;
    change[(presstime%2)][1]=1;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_13_clicked()
{

    change[(presstime%2)][0]=2;
    change[(presstime%2)][1]=2;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_14_clicked()
{

    change[(presstime%2)][0]=2;
    change[(presstime%2)][1]=3;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_15_clicked()
{

    change[(presstime%2)][0]=2;
    change[(presstime%2)][1]=4;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_16_clicked()
{

    change[(presstime%2)][0]=3;
    change[(presstime%2)][1]=0;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_17_clicked()
{

    change[(presstime%2)][0]=3;
    change[(presstime%2)][1]=1;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_18_clicked()
{

    change[(presstime%2)][0]=3;
    change[(presstime%2)][1]=2;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_19_clicked()
{

    change[(presstime%2)][0]=3;
    change[(presstime%2)][1]=3;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_20_clicked()
{

    change[(presstime%2)][0]=3;
    change[(presstime%2)][1]=4;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_21_clicked()
{

    change[(presstime%2)][0]=4;
    change[(presstime%2)][1]=0;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_22_clicked()
{

    change[(presstime%2)][0]=4;
    change[(presstime%2)][1]=1;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_23_clicked()
{

        change[(presstime%2)][0]=4;
        change[(presstime%2)][1]=2;
        if((presstime%2)==1)
        {
            changed();
            showwindow();
            delay(500);
            times=0;
            checkgame();
            clean();
        }
        else
            presstime++;
}

void MainWindow::on_pushButton_24_clicked()
{

    change[(presstime%2)][0]=4;
    change[(presstime%2)][1]=3;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

void MainWindow::on_pushButton_25_clicked()
{

    change[(presstime%2)][0]=4;
    change[(presstime%2)][1]=4;
    if((presstime%2)==1)
    {
        changed();
        showwindow();
        delay(500);
        times=0;
        checkgame();
        clean();
    }
    else
        presstime++;
}

