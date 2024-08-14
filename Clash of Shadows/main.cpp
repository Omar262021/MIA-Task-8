#include <iostream>
#include<string>
#include<math.h>
using namespace std;

//the common properties
class character{
public:  //Attributes for each character:
    float Health;
    int Energy;
    float shield;

    character(int H=100,int E=500,float sh=0):Health(H),Energy(E),shield(sh){} //constractor

//functions to get the values
    int getHealth(){
      return Health;}

    int getEnergy(){
      return Energy;}

//methods to Calculate the change in energy and health
    int health_damage(int change){
       Health-=change;
       return Health ;}

    int energy_change(int change){
      Energy-=change;
       return Energy ;}

    float get_shield(float save,int new_damage){
      shield=new_damage*save;
      Health+=shield;
      return Health;}

};//the end of the class character



class Batman :public character {
public:
    Batman():character(){}

//Weapons
    void Batarang(){
     energy_change(50);
     health_damage(11);}

    void GrappleGun(){
     energy_change(88);
     health_damage(18);}

    void ExplosiveGel(){
     energy_change(92);
     health_damage(10);}

    void Batclaw(){
     energy_change(120);
     health_damage(20);}

//Shields
     void CapeGlide(){
     energy_change(20);}

     void SmokePellet(){
     energy_change(50);}
};//the end of class Batman




class Joker :public character {
public:
    Joker():character(){}

//Weapons
   void JoyBuzzer(){
     energy_change(40);
     health_damage(8);}

   void LaughingGas(){
     energy_change(56);
     health_damage(13);}

   void AcidFlower(){
     energy_change(100);
     health_damage(22);}

//Shields
   void TrickShield(){
     energy_change(15);}

    void RubberChicken(){
     energy_change(40);}
};//the end of class JOKER


int main()
{
int n=0 , n1=0 , n2=0 , winner=0;

//declaration the objects
Batman attack_B ;
Joker  attack_J ;

int array_use[]={5,3,1,3,8,3,2}; //the number of uses

//declaration the variables
int damage;
float hb=attack_B.getHealth();
int   eb=attack_B.getEnergy();
float hj=attack_J.getHealth();
int   ej=attack_J.getEnergy();

//The beginning of the battle
while(hb>0 && hj>=0 && winner==0 ){

cout<<"choose the batman attack"<<endl;
cout<<"1-Batarang"<<endl<<"2-Grapple Gun"<<endl<<"3-Explosive Gel"<<endl<<"4-Batclaw"<<endl;
cin>>n;

switch (n){   //this block to choose the Weapon for batman
case 1:
    attack_B.Batarang();
    damage=11;
    break;

case 2:

    if(array_use[0]>0){
    attack_B.GrappleGun();
    damage=18;
    array_use[0]--;
    }
    else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
    break;

case 3:

    if(array_use[1]>0){
    attack_B.ExplosiveGel();
    damage=10;
    array_use[1]--;
         }
    else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
    break;


case 4:

    if(array_use[2]>0){
    attack_B.Batclaw();  //can't avoid this Weapon
    array_use[2]--;
   }
     else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
    break;

default:
    cout<<endl<<"the number should be from 1 to 4"<<endl<<"you lose your turn"<<endl;
}//the Batman choose the weapon and attacked the Joker

//if the user choose wrong joker won't defence
if (n!=4 && n>0 && n<5){  //if batman use Bat claw the joker can't avoid this

cout<<endl<<"choose the joker shield"<<endl;
cout<<"1-Trick Shield"<<endl<<"2-Rubber Chicken"<<endl<<"3-i don't need"<<endl;
cin>>n1;

if(n1!=3){

switch (n1){
case 1 :
   attack_B.get_shield(.32,damage); //reduce the damage
   attack_J.TrickShield();         //reduce the energy of joker
    break;

case 2 :

     if(array_use[3]>0){
      attack_B.get_shield(.8,damage);   //reduce the damage
      attack_J.RubberChicken();        //reduce the energy of joker
      array_use[3]--;
     }
     else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
     break;

default :
    cout<<endl<<"the numbers should be from 1 to 3"<<endl<<"you lose your turn"<<endl;
    }
}
}
//print the properties for each character
hj=attack_B.getHealth();
eb=attack_B.getEnergy();
hb=attack_J.getHealth();
ej=attack_J.getEnergy();

cout<<endl<<"the health of Joker :"<<hj<<endl ;
cout<<"the energy of Joker :"<<ej<<endl ;
cout<<endl<<"the health of Batman :"<<hb<<endl ;
cout<<"the energy of Batman :"<<eb<<endl ;


//check the winner
if (hj<=0 || ej<=0){
    cout<<endl <<"The winner is Batman";
    break;
    winner=1;
}
else if(hb<=0 || eb<=0){
    cout<<endl <<"The winner is joker";
    break;
    winner=1;
}

//now it's the joker's turn to attack
cout<<endl<<"choose the joker attack"<<endl;
cout<<"1-Joy Buzzer"<<endl<<"2-Laughing Gas"<<endl<<"3-Acid Flower"<<endl;
cin>>n2;

//choose the joker's attack
switch (n2){
case 1:
    attack_J.JoyBuzzer();
    damage=8;
    break;

case 2:

    if(array_use[4]>0){
      attack_J.LaughingGas();
      damage=13;
      array_use[4]--;
    }
    else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
   break;

case 3:

    if(array_use[5]>0){
      attack_J.AcidFlower();
      damage=22;
      array_use[5]--;
    }
    else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
    break;

default:
    cout<<"the number should be from 1 to 3"<<endl<<"you lose your turn"<<endl;
}

if(n==3)
attack_J.get_shield(.2,damage);

if(n2>0 && n2<5){
//batman try to defence
cout<<endl<<"choose the Batman shield"<<endl;
cout<<"1-Cape Glide"<<endl<<"2-Smoke Pellet"<<endl<<"3-i don't need"<<endl;
cin>>n1;

if(n1!=3){
    switch (n1){
case 1 :
    attack_B.CapeGlide();        //reduce the energy of batman
    attack_J.get_shield(.4,damage); //reduce the damage
    break;

case 2 :

    if(array_use[6]>0){
    attack_B.SmokePellet();       //reduce the energy of batman
    attack_J.get_shield(.9,damage);   //reduce the damage
    array_use[6]--;
    }
    else
        cout<<endl<<"the number of uses of the tool has expired"<<endl;
    break;

default :
    cout<<"the numbers should be from 1 to 3"<<endl<<"you lose your turn"<<endl;
    }
}
}
//print the properties for each character
hb=attack_J.getHealth();
ej=attack_J.getEnergy();
hj=attack_B.getHealth();
eb=attack_B.getEnergy();

cout<<endl<<"the health of Joker :"<<hj<<endl ;
cout<<"the energy of Joker :"<<ej<<endl ;
cout<<endl<<"the health of Batman :"<<hb<<endl ;
cout<<"the energy of Batman :"<<eb<<endl ;

//check the winner
if (hj<=0 || ej<=0){
    cout<<endl <<"The winner is Batman";
    break;
    winner=1;
}
else if (hb<=0 || eb<=0){
    cout<<endl <<"The winner is joker";
    break;
    winner=1;
}}
    return 0;
}

