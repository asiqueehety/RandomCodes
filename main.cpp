
/*Code written by:

ASIQUE EHETASAMUL HAQUE
Roll: 2107096
Dept: Department of Computer Science and Engineering
*/


//PROBLEM: Building Management System
//Classes used:             >Building .         >Flat            >Bill Management           >Welfare

/*
Group 21
Group members:

> Asique Ehetasamul Haque,   2107096
> Rezwan Ahammad Raad,       2107072
> Mustafizur Rahman,         2107058

*/








#include <iostream>

using namespace std;

class bill_manager;
class flat;
class building;
class welfare;

class bill_manager{
    friend class flat;
    friend class building;
    friend class welfare;
    float el;//el = electricity
    float gas=1500.0;
    float water=300.0;
    float hrent;//house rent
public:
    float gen_hrent(){
        hrent= 36000.0;
        return hrent;
    }
    float gen_el(float unit){
        el=unit*7.55;
        return el;
    }
};

class flat{
    friend class bill_manager;
    friend class welfare;
    friend class building;
    int id;
    string tname;//tenant name
    int length;
    int width;
    int room_count;
    float mnt=0;
    int rent=0;
public:
    int getid(){return id;}
    void addTenant(){
        cout<<"\nEnter tenant ID: ";
        cin>>id;
        cout<<"\nEnter tenant name: ";
        cin>>tname;
        cout<<"\nEnter flat length in ft: ";
        cin>>length;
        cout<<"\nEnter flat width in ft: ";
        cin>>width;
        cout<<"\nEnter flat's room count: ";
        cin>>room_count;
    }
    void genbill(bill_manager &billm){
        cout<<"\nHow many units of electricity did tenant use? : ";
        float unit;
        cin>>unit;
        cout<<"\n------------------------------------------------------------------------";
        cout<<"\nMaintenance cost: "<<mnt;
        cout<<"\nElectricity bill: "<<billm.gen_el(unit);
        cout<<"\nGas bill: "<<billm.gas;
        cout<<"\nWater bill: "<<billm.water;
        cout<<"\nHouse rent: "<<billm.gen_hrent();
        rent = mnt + billm.gen_el(unit) + billm.gas + billm.water + billm.gen_hrent();
        cout<<"\n\nTotal rent: "<<rent;
        cout<<"\n------------------------------------------------------------------------";
    }
    void showTenant(){
        cout<<"\n------------------------------------------------------------------------";
        cout<<"\nTenant ID: "<<id;
        cout<<"\nTenant name: "<<tname;
        cout<<"\nApartment length: "<<length<<" ft.";
        cout<<"\nApartment width: "<<width<<" ft.";
        cout<<"\nApartment size: "<<length*width<<" sq. ft.";
        cout<<"\nApartment no. of rooms: "<<room_count;
        cout<<"\n------------------------------------------------------------------------";
    }
    friend prompt();
};

class building{
    friend class flat;
    friend class bill_manager;
    friend class welfare;
    int id;
    int floors;
    int i=0;
    flat *arrflat;
public:
    int getFloors(){
        return floors;
        }
    building(int id,int floors){
        this->id=id;
        this->floors=floors;
        arrflat=new flat[2*floors];
    }
    flat getarrf(int x){
        return arrflat[x];
        }
    void addFlat(){
        cout<<"\nHow many tenants do you want to add? : ";
        int c;
        cin>>c;
        for(int y=0;y<c && i<(2*floors);y++,i++){
            flat abc;
            abc.addTenant();
            arrflat[i]=abc;
            cout<<"\nTENANT ADDED SUCCESSFULLY.\n";
            }
        if(i>=(2*floors)){cout<<"\nBUILDING FULL!\n";}
    }
    friend prompt();
};

class welfare{
    friend flat;
    friend building;
    friend bill_manager;
    string rep;//repair
    string sec;//security
public:
    void wlf(building &bui,int tid){
        int cc;
        cc=0;
        for(int x=0;x<(2*bui.floors);x++){
            if(bui.arrflat[x].id==tid){
                cout<<"\nTo repair ,press 'R': ";
                cout<<"\nTo improve security, press 'S'\n";
                string str;
                cin>>str;
                if(str=="R" || str=="r"){
                    cout<<"\nTo repair appliances, press 1";
                    cout<<"\nTo paint, press 2\n";
                    int in;
                    cin>>in;
                    if(in==1){bui.arrflat[x].mnt+=1000;cout<<"\nRepair done!";}
                    if(in==2){bui.arrflat[x].mnt+=(bui.arrflat[x].length * bui.arrflat[x].width * 10.0);cout<<"\nPaint done!";}
                }
                if(str=="S"||str=="s"){
                    cout<<"\nTo add CCTV Cameras, press 1";
                    cout<<"\nTo add Heat Sensors, press 2\n";
                    int num;
                    cin>>num;
                    if(num==1){
                        cout<<"\nHow many to add? : ";
                        int k;
                        cin>>k;
                        bui.arrflat[x].mnt+=(k*1000);
                        cout<<"\nCCTV Cameras added successfully!\n";
                    }
                    if(num==2){
                        cout<<"\nHow many to add? : ";
                        int k;
                        cin>>k;
                        bui.arrflat[x].mnt+=(k*2000);
                        cout<<"\nHeat sensors added successfully!\n";
                    }
                }
        cc=1;break;}
        }if(cc==0){cout<<"\nTENANT NOT FOUND!\n";}
    }
};

void prompt(building &bui);
void prompt(building &bui){
    while(1){
        cout<<"\nChoose action- \n 1. Add tenant\n 2. Generate bills\n 3. Welfare\n 4. Show tenant details\n\n Press 1/2/3/4: ";
        int in;
        cin>>in;
        if(in==1){
            bui.addFlat();
        }
        if(in==2){
            cout<<"Enter Tenant ID: ";
            int tid,cc;
            cin>>tid;
            cc=0;
            for(int x=0;x<(2*bui.getFloors());x++){
                if(bui.getarrf(x).getid()==tid){
                    bill_manager billm;
                    bui.getarrf(x).genbill(billm);
                    cc=1;
                    break;
                }
            }if(cc!=1){cout<<"\nTENANT NOT FOUND!\n!";}
        }
        if(in==3){
            welfare wlfr;
            cout<<"\nEnter ID of tenant: ";
            int t_id;
            cin>>t_id;
            wlfr.wlf(bui,t_id);
        }
        if(in==4){
            cout<<"Enter Tenant ID: ";
            int id,cc=0;
            cin>>id;
            for(int x=0;x<(2*bui.getFloors());x++){
                if(bui.getarrf(x).getid()==id){
                    bui.getarrf(x).showTenant();
                    cc=1;
                    break;
                }
            }if(cc!=1){cout<<"\nTENANT NOT FOUND!\n!";}
        }
    }
}

int main()
{
    cout<<"\nEnter building ID: ";
    int id;
    cin>>id;
    cout<<"\nEnter number of floors: ";
    int fl;
    cin>>fl;
    building bui(id,fl);

    prompt(bui);

    return 0;
}
