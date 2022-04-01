#include <iostream>
#include <cmath>

using namespace std;

struct samkutxedi{
    double a;
    double b;
    double c;
    double angle (int n=0){
        if(!isTriangle())
            return -1;
        switch (n){
            case 0:
                return acos((b*b+c*c-a*a)/(2*b*c) );
            case 1:
                return acos((b*b+a*a-c*c)/(2*b*a));
            default:
                return acos((a*a+c*c-b*b)/(2*a*c));
        }
    }
    void input(){
        cout<<"Choose known triangle sides or angles: \n";
        cout<<"1) 2 sides and 1 angle.\n";
        cout<<"2) 1 side and 2 angles.\n";
        cout<<"3) All 3 triangle sides.\n";
        cout<<"Enter 1, 2 or 3: ";
        int n; cin>>n;
        switch (n) {
            case 1:
                break;
            case 2:
                cout << "Enter the side size: ";

        }
        do{
            cout<<"a="; cin>>a; a=fabs(a);
            cout<<"b="; cin>>b; b=fabs(b);
            cout<<"c="; cin>>c; c=fabs(c);
        }while(!isTriangle());
    }
    void oriGverdi(){
        double Alpha;
        cout<<"Enter a and b sides: ";
        cin>>a>>b;
        cout << "Enter the angle size in radians: ";
        cin >> Alpha;
        char oppositeside = 'a';
        cout << "Which is the opposite side of the angle ";
        do {
            cout << "type a, b or c: ";
            cin >> oppositeside;
        }while(oppositeside!='a' || oppositeside!='b' || oppositeside!='c');
        if (oppositeside == 'a') {
            double Beta = asin((b * sin(Alpha)) / a);
            double Gamma = M_PI - Alpha - Beta;
            c = (b * sin(Gamma) / sin(Alpha));
        }
        if(oppositeside== 'b'){

        }
    }
    double P(){
        return (a+b+c)/2;
    }

    double S(){
        double p=P();
        if(isTriangle()) return sqrt(p * (p - a) * (p - b) * (p - c));
        else return -1;
    }

    bool isTriangle(){
        double p=P();
        if (sqrt(p*(p-a)*(p-b)*(p-c))>0)
            return true;
        else
            return false;
    }

    double mediana(int n=0){
        if(!isTriangle())  return -1;
        switch(n){
            case 0:
                return sqrt(2*(b*b+c*c)-a*a)/2;
            case 1:
                return sqrt(2*(a*a+c*c)-b*b)/2;
            default:
                return sqrt(2*(a*a+b*b)-c*c)/2;
        }
    }

    void display(bool onestrng){
        char sep;
        if(!onestrng)
            sep='\n';
        else	sep='\t';

        cout<<a<<sep
            <<b<<sep
            <<c<<sep
            <<"α = "<<angle(0)<<sep
            <<"ß = "<<angle(1)<<sep
            <<"ɣ = "<<angle(2)<<sep
            <<mediana(0)<<sep
            <<mediana(1)<<sep
            <<mediana(2)<<sep
            <<"P = "<<P()<<sep
            <<"S = "<<S()<<endl;
    }}A;

int main(){
    A.input();
    A.display(true);
}
