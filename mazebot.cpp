#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct konum{
    int x;
    int y;

};
class player {
private:
    konum pkonum;
    // donemec icin stack kullansan daha iyi olur bir araştır;
    konum *donemecler;
    int playerid;
    int temps;
    char direction;
    char bdirection;
    char *temp[30];
    int sayac;
    int cikis;
    konum yol[900];
public:
  int hamlesayisi; // ilk sayaci ve hamlesayisini dosyadan oku sonra dizileri bu degelere göre dün
    void wtf(){
      if(playerid==1){
    ofstream pkonumf;
    pkonumf.open("pkonum1.txt");
    pkonumf<<pkonum.x<<"\n"<<pkonum.y;
    pkonumf.close();

    ofstream hamlesayisif;
    hamlesayisif.open("hamlesayisi1.txt");
    hamlesayisif<<hamlesayisi;
    hamlesayisif.close();

    ofstream tempsf;
    tempsf.open("temps1.txt");
    tempsf<<temps;
    tempsf.close();

    ofstream directionf;
    directionf.open("direction1.txt");
    directionf<<direction;
    directionf.close();

    ofstream bdirectionf;
    bdirectionf.open("bdirection1.txt");
    bdirectionf<<bdirection;
    bdirectionf.close();

    ofstream sayacf;
    sayacf.open("sayac1.txt");
    sayacf<<sayac;
    sayacf.close();

    ofstream cikisf;
    cikisf.open("cikis1.txt");
    cikisf<<cikis;
    cikisf.close();

    ofstream donemeclerf;
    donemeclerf.open("donemecler1.txt");
    for(int i=0;i<sayac;i++)//tempi sayac -1 e kadar li yaz
    {
    donemeclerf<<(*(donemecler+i)).x<<"\n";
    donemeclerf<<(*(donemecler+i)).y<<"\n";

    }
    donemeclerf.close();

    ofstream tempf;
    tempf.open("temp1.txt");

    for(int i=0;i<sayac-1;i++)//tempi sayac -1 e kadar li yaz
    {
      for(int j=0;j<temps;j++)
      {
        stringstream sc;
        string s;

    sc<<(*((temp[i])+j));
    sc>>s;
    tempf<<s<<"\n";
}
    }
    tempf.close();

    ofstream yolf;
    yolf.open("yol1.txt");
    for(int i=0;i<hamlesayisi;i++)//tempi sayac -1 e kadar li yaz
    {
    donemeclerf<<(yol[i]).x<<"\n";
      donemeclerf<<(yol[i]).y<<"\n";

    }
    yolf.close();
  }
  if(playerid==2){
ofstream pkonumf;
pkonumf.open("pkonum2.txt");
pkonumf<<pkonum.x<<"\n"<<pkonum.y;
pkonumf.close();

ofstream hamlesayisif;
hamlesayisif.open("hamlesayisi2.txt");
hamlesayisif<<hamlesayisi;
hamlesayisif.close();

ofstream tempsf;
tempsf.open("temps2.txt");
tempsf<<temps;
tempsf.close();

ofstream directionf;
directionf.open("direction2.txt");
directionf<<direction;
directionf.close();

ofstream bdirectionf;
bdirectionf.open("bdirection2.txt");
bdirectionf<<bdirection;
bdirectionf.close();

ofstream sayacf;
sayacf.open("sayac2.txt");
sayacf<<sayac;
sayacf.close();

ofstream cikisf;
cikisf.open("cikis2.txt");
cikisf<<cikis;
cikisf.close();

ofstream donemeclerf;
donemeclerf.open("donemecler2.txt");
for(int i=0;i<sayac;i++)//tempi sayac -1 e kadar li yaz
{
donemeclerf<<(*(donemecler+i)).x<<"\n";
donemeclerf<<(*(donemecler+i)).y<<"\n";

}
donemeclerf.close();

ofstream tempf;
tempf.open("temp2.txt");

for(int i=0;i<sayac-1;i++)//tempi sayac -1 e kadar li yaz
{
  for(int j=0;j<temps;j++)
  {
    stringstream sc;
    string s;

sc<<(*((temp[i])+j));
sc>>s;
tempf<<s<<"\n";

}
}
tempf.close();

ofstream yolf;
yolf.open("yol2.txt");
for(int i=0;i<hamlesayisi;i++)//tempi sayac -1 e kadar li yaz
{
donemeclerf<<(yol[i]).x<<"\n";
  donemeclerf<<(yol[i]).y<<"\n";

}
yolf.close();
}

    }

    //Atamalar vb.
    player(int playeridm)
    {
      playerid=playeridm;
      srand(time(NULL));
      temp[0]= (char *) malloc(sizeof(char)*300);
      donemecler= (konum*) malloc(sizeof(konum)*100);
      string ss;
      int sayi;

      if(playerid==1){
      ifstream hamlesayisif;
      hamlesayisif.open("hamlesayisi1.txt");
      getline(hamlesayisif,ss);
      sayi = atoi(ss.c_str());
      if(sayi==0){
      hamlesayisi=0;
      temps=0;
      sayac = 0;
      cikis=0;
      pkonum.x=0;pkonum.y=0;
    }
    else{
      hamlesayisi=sayi;
      hamlesayisif.close();
      ifstream sayacf;
      sayacf.open("sayac1.txt");
      getline(sayacf,ss);
      sayi = atoi(ss.c_str());
      sayac=sayi;
      sayacf.close();

      ifstream cikisf;
      cikisf.open("cikis1.txt");
      getline(cikisf,ss);
      sayi = atoi(ss.c_str());
      cikis=sayi;
      cikisf.close();

      ifstream tempsf;
      tempsf.open("temps1.txt");
      getline(tempsf,ss);
      sayi = atoi(ss.c_str());
      temps=sayi;
      tempsf.close();
      //temps ifstream

      ifstream pkonumf;
      pkonumf.open("pkonum1.txt");
      getline(pkonumf,ss);
      sayi = atoi(ss.c_str());
      pkonum.x=sayi;
      getline(pkonumf,ss);
      sayi = atoi(ss.c_str());
      pkonum.y=sayi;
      pkonumf.close();
      ifstream donemeclerf;
      donemeclerf.open("donemecler1.txt");
      for(int i=0;i<sayac;i++)
      {
        getline(donemeclerf,ss);
        sayi = atoi(ss.c_str());
        (*(donemecler+i)).x=sayi;
        getline(donemeclerf,ss);
        sayi = atoi(ss.c_str());
        (*(donemecler+i)).y=sayi;
      }
      donemeclerf.close();
      ifstream yolf;
      yolf.open("yol1.txt");
      for(int i=0;i<hamlesayisi;i++)
      {
        getline(yolf,ss);
        sayi = atoi(ss.c_str());
        yol[i].x=sayi;
        getline(yolf,ss);
        sayi = atoi(ss.c_str());
        yol[i].y=sayi;
      }
      yolf.close();

      ifstream tempf;
      tempf.open("temp1.txt");
      for(int i=0;i<sayac;i++)
      {
        for(int j=0;j<temps;j++)
        {
          getline(tempf,ss);
          stringstream sc;
          sc <<ss;
          sc>>(*(temp[i]+j));


        }

      }




    }
}

      if(playerid==2){
      ifstream hamlesayisif;
      hamlesayisif.open("hamlesayisi2.txt");
      getline(hamlesayisif,ss);
      sayi = atoi(ss.c_str());
      if(sayi==0){
        hamlesayisi=0;
        temps=0;
        sayac = 0;
        cikis=0;
        pkonum.x=0;pkonum.y=0;
}
else{
  hamlesayisi=sayi;
  hamlesayisif.close();
  ifstream sayacf;
  sayacf.open("sayac2.txt");
  getline(sayacf,ss);
  sayi = atoi(ss.c_str());
  sayac=sayi;
  sayacf.close();

  ifstream cikisf;
  cikisf.open("cikis2.txt");
  getline(cikisf,ss);
  sayi = atoi(ss.c_str());
  cikis=sayi;
  cikisf.close();

  ifstream tempsf;
  tempsf.open("temps2.txt");
  getline(tempsf,ss);
  sayi = atoi(ss.c_str());
  temps=sayi;
  tempsf.close();
  //temps ifstream

  ifstream pkonumf;
  pkonumf.open("pkonum2.txt");
  getline(pkonumf,ss);
  sayi = atoi(ss.c_str());
  pkonum.x=sayi;
  getline(pkonumf,ss);
  sayi = atoi(ss.c_str());
  pkonum.y=sayi;
  pkonumf.close();
  ifstream donemeclerf;
  donemeclerf.open("donemecler2.txt");
  for(int i=0;i<sayac;i++)
  {
    getline(donemeclerf,ss);
    sayi = atoi(ss.c_str());
    (*(donemecler+i)).x=sayi;
    getline(donemeclerf,ss);
    sayi = atoi(ss.c_str());
    (*(donemecler+i)).y=sayi;
  }
  donemeclerf.close();
  ifstream yolf;
  yolf.open("yol2.txt");
  for(int i=0;i<hamlesayisi;i++)
  {
    getline(yolf,ss);
    sayi = atoi(ss.c_str());
    yol[i].x=sayi;
    getline(yolf,ss);
    sayi = atoi(ss.c_str());
    yol[i].y=sayi;
  }
  yolf.close();

  ifstream tempf;
  tempf.open("temp2.txt");
  for(int i=0;i<sayac;i++)
  {
    for(int j=0;j<temps;j++)
    {
      getline(tempf,ss);
      stringstream sc;
      sc <<ss;
      sc>>(*(temp[i]+j));



    }

  }




}




}









    }
    int getcikis()
    {
        return cikis;
    }
    void setdirection(char dir){
        bdirection=direction;
        direction=dir;
    }
    char getdirection()
    {
        return direction;
    }
    void konumata(int x1,int y1)
    {
        pkonum.x=x1;
        pkonum.y=y1;
    }
    void playeridata(int id){

        playerid=id;
    }
    konum  konumual(){
        return pkonum;
    }
    int idal(){
        return playerid;
    }
    konum* donemeclerial(){
        return donemecler;
    }
    void  donemecata(konum donemec,int index)
    {
        (*(donemecler+index))=donemec;
    }
    //Asıl fonksiyonlar
    char hareketolustur(char komut)
    {
        switch (komut){
            case 'l':
            {switch (direction){
                case 'l':
                {
                    return 'd';
                    break;
                }
                case 'r':
                {
                    return 'u';
                    break;
                }
                case 'u':
                {
                    return 'l';
                    break;
                }
                case 'd':
                {
                    return 'r';
                    break;
                }
            }

                break;
            }
            case 'r':
            {
                switch (direction){
                    case 'l':
                    {
                        return 'u';
                        break;
                    }
                    case 'r':
                    {
                        return 'd';
                        break;
                    }
                    case 'u':
                    {
                        return 'r';
                        break;
                    }
                    case 'd':
                    {
                        return 'l';
                        break;
                    }
                }
                break;
            }
            case 'u':
            {switch (direction){
                case 'l':
                {
                    return 'l';
                    break;
                }
                case 'r':
                {
                    return 'r';
                    break;
                }
                case 'u':
                {
                    return 'u';
                    break;
                }
                case 'd':
                {
                    return 'd';
                    break;
                }
            }
                break;
            }
            case 'd':
            {switch (direction){
                case 'l':
                {
                    return 'r';
                    break;
                }
                case 'r':
                {
                    return 'l';
                    break;
                }
                case 'u':
                {
                    return 'd';
                    break;
                }
                case 'd':
                {
                    return 'u';
                    break;
                }
            }
                break;
            }
        }
        return 'a';
    }
    char hareketolustur(char komut,char direc)
    {
        switch (komut){
            case 'l':
            {switch (direc){
                case 'l':
                {
                    return 'd';
                    break;
                }
                case 'r':
                {
                    return 'u';
                    break;
                }
                case 'u':
                {
                    return 'l';
                    break;
                }
                case 'd':
                {
                    return 'r';
                    break;
                }
            }

                break;
            }
            case 'r':
            {
                switch (direc){
                    case 'l':
                    {
                        return 'u';
                        break;
                    }
                    case 'r':
                    {
                        return 'd';
                        break;
                    }
                    case 'u':
                    {
                        return 'r';
                        break;
                    }
                    case 'd':
                    {
                        return 'l';
                        break;
                    }
                }
                break;
            }
            case 'u':
            {switch (direc){
                case 'l':
                {
                    return 'l';
                    break;
                }
                case 'r':
                {
                    return 'r';
                    break;
                }
                case 'u':
                {
                    return 'u';
                    break;
                }
                case 'd':
                {
                    return 'd';
                    break;
                }
            }
                break;
            }
            case 'd':
            {switch (direc){
                case 'l':
                {
                    return 'r';
                    break;
                }
                case 'r':
                {
                    return 'l';
                    break;
                }
                case 'u':
                {
                    return 'd';
                    break;
                }
                case 'd':
                {
                    return 'u';
                    break;
                }
            }
                break;
            }
        }
        return 'a';
    }
    void donemecbuldu(konum yenidonemec){
        (*(donemecler+sayac))=yenidonemec;
        temp[sayac+1]= (char *) malloc(sizeof(char)*300);
        sayac++;
    }
    void hareketet(char komut,int param)
    {
        if(param==0){
          yol[hamlesayisi]=pkonum;
            char hareket=hareketolustur(komut);
            switch (hareket)
            {
                case 'l':{
                    *(temp[sayac])='l';
                    (pkonum.x)--;
                    setdirection('l');
                    break;
                }
                case 'r':{
                    *(temp[sayac])='r';
                    (pkonum.x)++;
                    setdirection('r');
                    break;
                }
                case 'u':{
                    *(temp[sayac])='u';
                    (pkonum.y)++;
                    setdirection('u');
                    break;
                }
                case 'd':{
                    *(temp[sayac])='d';
                    (pkonum.y)--;
                    setdirection('d');
                    break;
                }
            }
            hamlesayisi++;
            temp[sayac]++;
            temps++;
        }
        if(param==1)
        {
            switch (komut) {
                case 'l':
                {
                    (pkonum.x)++;
                    cout<<"RIGHT";
                    setdirection('r');
                    break;
                }
                case 'r':
                {
                    (pkonum.x)--;
                     cout<<"LEFT";
                    setdirection('l');
                    break;
                }
                case 'u':
                {
                    (pkonum.y)--;
                     cout<<"DOWN";
                    setdirection('d');
                    break;
                }
                case 'd':
                {
                    (pkonum.y)++;
                     cout<<"UP";
                    setdirection('u');
                    break;
                }
            }

        }

    }
    //Karar mekanizmasi
    void finddirection(char maze[3][3])
    {
        int l=1;
        int d=1;
        int r=1;
        int u=1;
        for (int i=0;i<3;i++)
        {
            for (int k=0;k<3;k++)
            {
                if((i==0)&&(maze[i][k]=='-'))
                {
                    u=0;
                }
                if((i==2)&&(maze[i][k]=='-'))
                {
                    d=0;
                }
                if((k==0)&&(maze[i][k]=='-'))
                {
                    l=0;
                }
                if((k==2)&&(maze[i][k]=='-'))
                {
                    r=0;
                }
            }

        }
        if(l&&u)
        {
            direction = 'r';
        }
        else if(u&&r)
        {
            direction = 'u';
        }
        else if(r&&d)
        {
            direction = 'l';
        }
        else if(l&&d)
        {
            direction = 'd';
        }
        else {

        }

    }
    void findroute(char maze[3][3])
    { int  icerme =0;
        //you are at [1][1]
        char route[4];
        char froute;
        int rc=0;
        konum rk,lk,uk,dk;
        lk.x=(pkonum.x)-1;
        lk.y=(pkonum.y);
        rk.x=(pkonum.x)+1;
        rk.y=(pkonum.y);
        uk.x=(pkonum.x);
        uk.y=(pkonum.y)+1;
        dk.x=(pkonum.x);
        dk.y=(pkonum.y)-1;
        if(maze[1][0]=='-')
        {     if(hareketolustur(*(temp[sayac]),bdirection)!='r'){
          for (int i=hamlesayisi;i<0;i--)
          {
          if((yol[i].x==lk.x)&&(yol[i].y=lk.y))
            {
              icerme==1;
            }
          }
          if(!icerme){
            route[rc]='l';
            rc++;
          }
        }
icerme =0;
        }
        if(maze[1][2]=='-')
        {     if(hareketolustur(*(temp[sayac]),bdirection)!='l'){
          for (int i=hamlesayisi;i<0;i--)
          {
            if((yol[i].x==rk.x)&&(yol[i].y=rk.y))
            {
              icerme==1;
            }
          }
          if(!icerme){
            route[rc]='r';
            rc++;
          }
        }
icerme =0;
        }
        if(maze[0][1]=='-')
        {
            if(hareketolustur(*(temp[sayac]),bdirection)!='d'){
              for (int i=hamlesayisi;i<0;i--)
              {
        if((yol[i].x==uk.x)&&(yol[i].y=uk.y))
                {
                  icerme==1;
                }
              }
              if(!icerme){
                route[rc]='u';
                rc++;
              }
            }

icerme =0;
        }
        if(maze[2][1]=='-')
        {
            if(hareketolustur(*(temp[sayac]),bdirection)!='u'){
              for (int i=hamlesayisi;i<0;i--)
              {
        if((yol[i].x==dk.x)&&(yol[i].y=dk.y))
                {
                  icerme==1;
                }
              }
              if(!icerme){
                route[rc]='d';
                rc++;
              }
            }
            icerme =0;
        }
        if((maze[1][0]=='c')||(maze[1][2]=='c')||(maze[0][1]=='c')||(maze[2][1]=='c'))
        {
            cikis=1;
        }

        if(rc!=1)
        { if(rc>1)
        {
          int donc=0;
            froute=route[(rand()%(rc+1))];
            switch (froute) {
                case 'r':{
                    cout<<"RIGHT";
                    break;
                }
                case 'l':{
                    cout<<"LEFT";
                    break;
                }
                case 'u':{
                    cout<<"UP";
                    break;
                }
                case 'd':{
                    cout<<"DOWN";
                    break;
                }


            }
            if(((maze[0][0]=='#')||(maze[2][0]=='#'))&&(maze[1][0]=='-'))
            { if(!donc){
                donemecbuldu(pkonum);
                donc++;
              }
            }
            if(((maze[2][0]=='#')||(maze[2][2]=='#'))&&(maze[2][1]=='-'))
            {
              if(!donc){
                  donemecbuldu(pkonum);
                  donc++;
                }
            }
            if(((maze[0][2]=='#')||(maze[2][2]=='#'))&&(maze[1][1]=='-'))
            {
              if(!donc){
                  donemecbuldu(pkonum);
                  donc++;
                }
            }
            if(((maze[0][0]=='#')||(maze[0][2]=='#'))&&(maze[0][1]=='-'))
            {
              if(!donc){
                  donemecbuldu(pkonum);
                  donc++;
                }
            }


            hareketet(froute,0);

        }
            if(rc==0)
            {
                iamstuck();
            }

        }
        else{
            switch (route[0]) {
                case 'r':{
                cout<<"RIGHT";
                    break;
                }
                case 'l':{
                    cout<<"LEFT";
                    break;
                }
                case 'u':{
                    cout<<"UP";
                    break;
                }
                case 'd':{
                    cout<<"DOWN";
                    break;
                }


            }
            hareketet(route[0],0);
        }

    }


    void iamstuck(){
        for(int i=0;!((((*(donemecler+sayac)).x)==pkonum.x)&&(((*(donemecler+sayac)).y)==pkonum.y));i++){
            hareketet((*(temp[sayac]-i)),1);
        }

        free (temp[sayac]);
        sayac--;
    }

};

// []y ekseni [] x ekseni
int main() {
    char maze[3][3];
    int id;
    player player1(1);
    player player2(2);
    //son dönemece geri gidip tüm olası yolları deneyerek yolu bulacaksın ama bu işlemin sonunda gezdiğin labirentin haritasini cikarmayi deneye
    //mesela verilen alandan sol yaptiğinda solda acilan blockugu solan seyin soluna ekle ayni sekilde asagi yukari sag icinde
    cin>>id;


    if(id==1){
        for (int i=0;i<3;i++)
        {
            for (int k=0;k<3;k++)
            {
                cin>>maze[i][k];
            }
        }
        if(player1.hamlesayisi==0)
        {
            player1.finddirection(maze);
        }

        player1.findroute(maze);
        player1.wtf();
    }
    if(id==2){
        for (int i=0;i<3;i++)
        {
            for (int k=0;k<3;k++)
            {
                cin>>maze[i][k];
            }
        }
        if(player2.hamlesayisi==0)
        {
            player2.finddirection(maze);
        }

        player2.findroute(maze);
        player2.wtf();
    }


    return 0;
}
