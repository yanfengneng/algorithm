#include<iostream>
using namespace std;
typedef struct tagCOMMONTIME
{
    int   year;
    int   month;
    int   day;                        
    int   hour;
    int   minute;
    double   second;
}COMMONTIME;//ͨ��ʱ
typedef COMMONTIME *PCOMMONTIME;  
typedef struct tagTOD
{
    long sn;  //��������������
    double tos;//������С������
}TOD;
typedef TOD *PTOD;
typedef struct
{
    long day; //��������
    TOD tod;  //һ���ڵ�����
}JULIANDAY;//������
typedef JULIANDAY *PJULIANDAY;
typedef struct tagMJULIANDAY
{
    long day;
    TOD  tod;
}MJULIANDAY;//��������
typedef MJULIANDAY *PMJIANDAY;
typedef struct tagTOW
{
    long sn;//����������
    double tos;//��С������
}TOW;
typedef TOW *PTOW;
typedef struct tagGPSTIME
{
    int wn; //����
    TOW tow;//һ���ڵ�����
}GPSTIME;//GPSʱ
typedef GPSTIME *PGPSTIME;
typedef struct tagDOY
{
    unsigned short year;
    unsigned short day;
    TOD tod;    
}DOY;//�����
typedef DOY *PDOY;
double FRAC(double morigin)
{
    return morigin-long(morigin);// ȡС������
}
void CommonTimeToJulianDay(PCOMMONTIME pct,PJULIANDAY pjd) //ͨ��ʱ�������յ�ת��
{
    if(pct->year<1900)
    {
        if(pct->year<80)
        pct->year+=2000;
        else pct->year+=1900;
    }
    double ut=pct->hour + pct->minute/60.0 + pct->second/3600.0;
    if(pct->month<=2)
    {
        pct->year-=1;
        pct->month+=12;
    }
    pjd->day=int(365.25*pct->year)+int(30.6001*(pct->month+1))+pct->day+int(ut/24+1720981.5);
    pjd->tod.sn= ((pct->hour+12)%24)*3600+pct->minute*60+(int)pct->second;//�����������
    pjd->tod.tos=pct->second-(int)pct->second;//���С������
} 
void JulianDayToCommonTime(PJULIANDAY pjd,PCOMMONTIME pct)//�����յ�ͨ��ʱ��ת��
{
    double x=pjd->day+(pjd->tod.sn+pjd->tod.tos)/(60.0*60.0*24);
    int a=int(x+0.5);
    int b=a+1537;
    int c=int((b-122.1)/365.25);
    int d=int(365.25*c);
    int e=int((b-d)/30.6001);
    pct->day=b-d-int(30.6001*e);
    pct->month=e-1-12*int(e/14);
    pct->year=c-4715-int((7+pct->month)/10);
    pct->hour=(pjd->tod.sn/3600+12)%24;
    pct->minute=(pjd->tod.sn%3600)/60;
    pct->second=pjd->tod.sn%60+pjd->tod.tos;
    int N=a%7; 
}
void JulianDayToGPSTime(PJULIANDAY pjd,PGPSTIME pgt)//�����յ�GPSʱ��ת��
{
    double x=pjd->day+(pjd->tod.sn+pjd->tod.tos)/(60.0*60.0*24);
    pgt->wn=int((x-2444244.5)/7);
    pgt->tow.sn=int(((pjd->day-2444244)%7+(pjd->tod.sn/(60.0*60.0*24)-0.5))*86400);
    pgt->tow.tos=pjd->tod.tos;
}
void GPSTimeToJulianDay(PGPSTIME pgt,PJULIANDAY pjd)//GPSʱ�������յ�ת��
{
    pjd->day=int(pgt->wn*7+double(pgt->tow.sn)/86400.0+2444244.5);
    pjd->tod.sn=(pgt->tow.sn+43200)%86400;
    pjd->tod.tos=pgt->tow.tos;
}
void CommonTimeToGPSTime(PCOMMONTIME pct,PGPSTIME pgt)//ͨ��ʱ��GPSʱ��ת��
{
    PJULIANDAY pjd=new JULIANDAY;
    CommonTimeToJulianDay(pct,pjd);
    JulianDayToGPSTime(pjd,pgt);
}
void GPSTimeToCommonTime(PGPSTIME pgt,PCOMMONTIME pct)//GPSʱ��ͨ��ʱ��ת��
{
    PJULIANDAY pjd=new JULIANDAY;
    GPSTimeToJulianDay(pgt,pjd);
    JulianDayToCommonTime(pjd,pct);
}
void CommonTimeToDOY (PCOMMONTIME pct, PDOY pdoy)
{
    PCOMMONTIME pcto=new COMMONTIME;
    pcto->year=pct->year;
    pcto->month=1;
    pcto->day=1;
    pcto->hour=0;
    pcto->minute=0;
    pcto->second=0;

    PJULIANDAY pjdo=new JULIANDAY;

    double JD,JDO;
    CommonTimeToJulianDay(pcto,pjdo);
    JDO=pjdo->day+(pjdo->tod.sn+pjdo->tod.tos)/86400;

    PJULIANDAY pjd=new JULIANDAY;
    CommonTimeToJulianDay(pct,pjd);

    JD=pjd->day+(pjd->tod.sn+pjd->tod.tos)/86400;

    pdoy->day=short(JD-JDO+1);
    pdoy->year=pct->year;

    pdoy->tod.sn=long(pct->hour*3600
        +pct->minute*60+pct->second);
    pdoy->tod.tos=pct->second-int(pct->second);    /*pct->hour*3600
        +pct->minute*60+pct->second-pdoy->tod.sn;*/
}
void DOYToCommonTime (PDOY pdoy, PCOMMONTIME pct)
{
    PCOMMONTIME pcto=new COMMONTIME;
    pcto->year=pdoy->year;
    pcto->month=1;
    pcto->day=1;
    pcto->hour=0;
    pcto->minute=0;
    pcto->second=0;
    PJULIANDAY pjdo=new JULIANDAY;
    double JD,JDO;
    CommonTimeToJulianDay(pcto,pjdo);
    JDO=pjdo->day+(pjdo->tod.sn+pjdo->tod.tos)/86400;
    JD=JDO+pdoy->day+(pdoy->tod.sn+pdoy->tod.tos)/86400-1;
    long a,b,c,d,e;
    a=(long)(JD+0.5);
    b=a+1537;
    c=(long)((b-122.1)/365.25);
    d=(long)(365.25*c);
    e=(long)((b-d)/30.6001);
    pct->day=short(b-d-(long)(30.6001*e)+FRAC(JD+0.5));
    pct->month=short(e-1-12*(long)(e/14));
    pct->year=short(c-4715-(long)((7+pct->month)/10));
    pct->hour=short((pdoy->tod.sn+pdoy->tod.tos)/3600);
    pct->minute=short((pdoy->tod.sn+pdoy->tod.tos
        -pct->hour*3600)/60);
    pct->second=pdoy->tod.sn+pdoy->tod.tos
        -pct->hour*3600-pct->minute*60;
}
void GPSTimeToDOY (PGPSTIME pgt, PDOY pdoy)
{
    PJULIANDAY pjd=new JULIANDAY;
    GPSTimeToJulianDay (pgt, pjd);
    PCOMMONTIME pct=new COMMONTIME;
    JulianDayToCommonTime (pjd,pct);
    CommonTimeToDOY (pct,pdoy);
}
void DOYToGPSTime (PDOY pdoy, PGPSTIME pgt)
{
    PCOMMONTIME pct=new COMMONTIME;
    DOYToCommonTime (pdoy,pct);
    CommonTimeToGPSTime (pct, pgt);
}
void JulianDayToDOY (PJULIANDAY pjd, PDOY pdoy)
{ 
    PCOMMONTIME pct=new COMMONTIME;
    JulianDayToCommonTime (pjd, pct);
    CommonTimeToDOY (pct,pdoy);
}
void DOYToJulianDay (PDOY pdoy, PJULIANDAY pjd)
{
    PCOMMONTIME pct=new COMMONTIME;
    DOYToCommonTime (pdoy,pct);
    CommonTimeToJulianDay(pct,pjd);
}
int main()
{
          PCOMMONTIME pct=new COMMONTIME;
          PJULIANDAY pjd=new JULIANDAY;
          PDOY pdoy=new DOY;
          PGPSTIME pgt= new GPSTIME;
          cin>>pct->year>>pct->month>>pct->day>>pct->hour>>pct->minute>>pct->second;
           cout<<"ת��֮ǰ��ͨ��ʱ������ʱ�䣩��";
           cout<<pct->year<<" "<<pct->month<<" "<<pct->day<<" "<<pct->hour<<":"<<pct->minute<<":"<<pct->second<<endl;
           cout<<endl;
           CommonTimeToJulianDay( pct, pjd);//ͨ��ʱ->�����յ�ת��
           cout<<"ͨ��ʱ->�����յ�ת��:";
           cout<<pjd->day<<"  "<<pjd->tod.sn<<"  "<<pjd->tod.tos<<endl;
           cout<<endl;
           JulianDayToCommonTime( pjd, pct);//������->ͨ��ʱ��ת��
           cout<<"������->ͨ��ʱ��ת��:";
           cout<<pct->year<<" "<<pct->month<<" "<<pct->day<<" "<<pct->hour<<":"<<pct->minute<<":"<<pct->second<<endl;
           cout<<endl;
           JulianDayToGPSTime( pjd, pgt);//������->GPSʱ��ת��
           cout<<"������->GPSʱ��ת��:";
           cout<<pgt->wn<<"  "<<pgt->tow.sn<<"  "<<pgt->tow.tos<<endl;
           cout<<endl;
           GPSTimeToJulianDay( pgt, pjd);//GPSʱ->�����յ�ת��
           cout<<"GPSʱ->�����յ�ת��:";
           cout<<pjd->day<<"  "<<pjd->tod.sn<<"  "<<pjd->tod.tos<<endl;
           cout<<endl;
           CommonTimeToGPSTime( pct, pgt);//ͨ��ʱ->GPSʱ��ת��
           cout<<"ͨ��ʱ->GPSʱ��ת��:";
           cout<<pgt->wn<<"  "<<pgt->tow.sn<<"  "<<pgt->tow.tos<<endl;
           cout<<endl;
           GPSTimeToCommonTime( pgt, pct);//GPSʱ->ͨ��ʱ��ת��
           cout<<"GPSʱ->ͨ��ʱ��ת��:";
              cout<<pct->year<<" "<<pct->month<<" "<<pct->day<<" "<<pct->hour<<":"<<pct->minute<<":"<<pct->second<<endl;
           cout<<endl;
           CommonTimeToDOY ( pct, pdoy);//ͨ��ʱ->�����
           cout<<"ͨ��ʱ->�����:";
           cout<<pdoy->year<<"  "<<pdoy->day<<"  "<<pdoy->tod.sn<<"  "<<pdoy->tod.tos<<endl;
           cout<<endl;
           DOYToCommonTime (pdoy,  pct);//�����->ͨ��ʱ
           cout<<"�����->ͨ��ʱ:";
           cout<<pct->year<<" "<<pct->month<<" "<<pct->day<<" "<<pct->hour<<":"<<pct->minute<<":"<<pct->second<<endl;
           cout<<endl;
           GPSTimeToDOY ( pgt, pdoy);//GPSʱ->�����
           cout<<"GPSʱ->�����:";
           cout<<pdoy->year<<"  "<<pdoy->day<<"  "<<pdoy->tod.sn<<"  "<<pdoy->tod.tos<<endl;
           cout<<endl;
           DOYToGPSTime (pdoy,  pgt);//�����->GPSʱ
           cout<<"�����->GPSʱ:";
           cout<<pgt->wn<<"  "<<pgt->tow.sn<<"  "<<pgt->tow.tos<<endl;
           cout<<endl;
           JulianDayToDOY (pjd, pdoy);//������->�����
           cout<<"������->�����:";
           cout<<pdoy->year<<"  "<<pdoy->day<<"  "<<pdoy->tod.sn<<"  "<<pdoy->tod.tos<<endl;
           cout<<endl;
           DOYToJulianDay ( pdoy, pjd);//�����->������
           cout<<"�����->������:";
           cout<<pjd->day<<"  "<<pjd->tod.sn<<"  "<<pjd->tod.tos<<endl;
           cout<<endl;
           cout<<"��������ת����ԭ�õ���ͨ��ʱ:";
           cout<<pct->year<<" "<<pct->month<<" "<<pct->day<<" "<<pct->hour<<":"<<pct->minute<<":"<<pct->second<<endl;
           cout<<endl;
           system("pause");
}