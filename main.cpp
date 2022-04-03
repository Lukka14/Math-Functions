#include <iostream>
#include <cmath>
using namespace std;

struct samkutxedi{
    double a;
    double b;
    double c;

    double Alpha;
    double Beta;
    double Gamma;
    void oriGverdi(){
        double kutxe;
        cout<<"შეიყვანეთ a და b გვერდები: ";
        cin>>a>>b;
        cout << "შეიყვანეთ კუთხის ზომა რადიანებში: ";
        cin >> kutxe;
        string mopirdapireGverdi = "a";
        cout << "რომელია კუთხის მოპირდაპირე გვერდი? ";
        do{
            cout << "შეიყვანეთ a, b ან c: ";
            cin >> mopirdapireGverdi;
        }while(mopirdapireGverdi != "a" && mopirdapireGverdi != "b" && mopirdapireGverdi != "c");
        if (mopirdapireGverdi == "a") {
             Alpha=kutxe;
             Beta = asin((b * sin(Alpha)) / a);
             Gamma = M_PI - Alpha - Beta;
            c = (a * sin(Gamma) / sin(Alpha));
        }
        if(mopirdapireGverdi == "b"){
             Beta=kutxe;
             Alpha = asin((a * sin(Beta)) / b);
             Gamma = M_PI - Beta - Alpha;
             c = (b * sin(Gamma) / sin(Beta));
        }
        if(mopirdapireGverdi == "c") {
            Gamma=kutxe;
            c = sqrt(a * a + b * b - 2 * a * b * cos(kutxe));
            Alpha = asin((a* sin(Gamma))/c);
            Beta = M_PI - Alpha - Gamma;
        }
        isTriangle();
    }

    void oriKutxe(){
        int n;
        double gverdi;
        cout << "შეიყვანეთ გვერდის სიგრძე: ";
        cin>>gverdi;
        cout<<"შეიყვანეთ Alpha და Beta კუთხეები: ";
        cin>>Alpha>>Beta;
        cout<<"რომელია ცნობილი გვერდის პირდაპირ მდებარე კუთხე?\n";
        do{
            cout<<"1) Alpha\n2) Beta\n3) Gamma\n";
            cout<<"აირჩიეთ შესაბამისი ციფრი: ";
            cin>>n;
        }while(n!=1 && n!=2 && n!=3);
        if(n==1){
            a=gverdi;
            Gamma=M_PI-Alpha-Beta;
            c = (a * sin(Gamma) / sin(Alpha));
            b = (a*sin(Beta))/ sin(Alpha);
        }
        if(n==2){
            b=gverdi;
            Gamma=M_PI-Alpha-Beta;
            a = (sin(Alpha)*b)/ sin(Beta);
            c = (b * sin(Gamma) / sin(Beta));
        }
        if(n==3){
            c=gverdi;
            Gamma=M_PI-Alpha-Beta;
            a=(sin(Alpha)*c)/sin(Gamma);
            b=(sin(Beta)*c)/sin(Gamma);
        }
        isTriangle();
    }

    void samiGverdi(){
        cout<<"შეიყვანეთ სამკუთხედის გვერდები: \n";
            cout<<"a="; cin>>a; a=fabs(a);
            cout<<"b="; cin>>b; b=fabs(b);
            cout<<"c="; cin>>c; c=fabs(c);
            isTriangle();
            Alpha= acos((b*b+c*c-a*a)/(2*b*c));
            Beta= acos((a*a+c*c-b*b)/(2*a*c));
            Gamma= acos((b*b+a*a-c*c)/(2*a*b));
    }

    void sheyvana(){
        cout<<"აირჩიეთ რა არის ცნობილი:\n";
        cout<<"1) 2 გვერდი და 1 კუთხე.\n";
        cout<<"2) 1 გვერდი და 2 კუთხე.\n";
        cout<<"3) სამკუთხედის სამივე გვერდი.\n";
        int n;
        do {
            cout << "შეიყვანეთ 1, 2 ან 3: ";
            cin >> n;
        }while(n!=1 && n!=2 && n!=3);
        switch (n) {
            case 1:
                oriGverdi();
                break;
            case 2:
                oriKutxe();
                break;
            case 3:
                samiGverdi();
                break;
        }
    }
    double P(){
        return (a+b+c)/2;
    }

    double S(){
        double p=P();
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double height(double tmp){
        return (2*S())/tmp;
    }

    double chaxazulisS(){
        double r=S()/P();
        return M_PI*r*r;
    }

    double shemoxazulisS(){
        double R=a/(2* sin(Alpha));
        return M_PI*R*R;
    }



    void isTriangle(){
        double p=P();
        if (sqrt(p*(p-a)*(p-b)*(p-c))<=0){
            cout<<"შეყვანილი ინფორმაცია არასწორია, ასეთი სამკუთხედი არ არსებობს. :(";
            exit(-1);
        }
    }

    double mediana(int n=0){
        switch(n){
            case 0:
                return sqrt(2*(b*b+c*c)-a*a)/2.0;
            case 1:
                return sqrt(2*(a*a+c*c)-b*b)/2.0;
            default:
                return sqrt(2*(a*a+b*b)-c*c)/2.0;
        }
    }

    double biseqtrisa(string gverdi="a"){
        if (gverdi == "a") {
            return (2*sqrt(b*c*P()*(P()-a)))/(b+c);
        }
        if(gverdi == "b"){
            return (2*sqrt(a*c*P()*(P()-b)))/(a+c);
        }
        if(gverdi == "c") {
            return (2*sqrt(b*a*P()*(P()-c)))/(b+a);;
        }
    }

    double damrgvaleba(double tmp=0,int x=10){
        return round(tmp*pow(10,x))/(pow(10,x)*1.0);
    }

    void gamotana(bool onestrng){
        char sep;
        if(!onestrng)
            sep='\n';
        else	sep='\t';
        cout<<"a="<<damrgvaleba(a)<<sep
            <<"b="<<damrgvaleba(b)<<sep
            <<"c="<<damrgvaleba(c)<<sep
            <<"α="<<damrgvaleba(Alpha)<<sep
            <<"ß="<<damrgvaleba(Beta)<<sep
            <<"ɣ="<<damrgvaleba(Gamma)<<sep
            <<"m(a)="<<damrgvaleba(mediana(0))<<sep
            <<"m(b)="<<damrgvaleba(mediana(1))<<sep
            <<"m(c)="<<damrgvaleba(mediana(2))<<sep
            <<"h(a)="<<damrgvaleba(height(a))<<sep
            <<"h(b)="<<damrgvaleba(height(b))<<sep
            <<"h(c)="<<damrgvaleba(height(c))<<sep
            <<"B(a)="<<damrgvaleba(biseqtrisa("a"))<<sep
            <<"B(b)="<<damrgvaleba(biseqtrisa("b"))<<sep
            <<"B(c)="<<damrgvaleba(biseqtrisa("c"))<<sep
            <<"P="<<damrgvaleba(2*P())<<sep
            <<"S="<<damrgvaleba(S())<<sep
            <<"area="<<damrgvaleba(chaxazulisS())<<sep
            <<"AREA="<<damrgvaleba(shemoxazulisS())<<sep;

    }}A;

int main(){
    A.sheyvana();
    A.gamotana(true);
}
