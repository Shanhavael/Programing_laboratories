#include <iostream>

#include <string>
#include<fstream>
using namespace std;

string findPesel(string data)
{
    int i=0;
    char pesel[11];
    while ((int)data[i]<48 || (int)data[i]>57)
    {
        i++;
    }
    for (int j=0;j<11;j++)
    {
        pesel[j]=data[i];
        i++;
    }
    return pesel;
}

bool checkPesel(string pesel)
{
    int sum=pesel[0]-'0'+pesel[4]-'0'+pesel[8]-'0'+pesel[10]-'0'+3*(pesel[1]-'0'+pesel[5]-'0'+pesel[9]-'0')+7*(pesel[2]-'0'+pesel[6]-'0')+9*(pesel[3]-'0'+pesel[7]-'0');
    cout<<sum<<endl;
    return sum%10==0;
}



int main()
{
    ofstream file("results.txt");
    if (file.is_open())
    {
        int x=0;
        while(x==0)
        {
            string city,data,pesel;
            cout << "Enter city name" << endl;
            getline(cin, city);
            cout << "Enter name, surname and PESEL"<< endl;
            getline(cin,data);

            pesel = findPesel(data);
            if(checkPesel(pesel))
            {
                file << city << endl << data <<endl;
            }
            else
                {
                    cout<<"Incorect PESEL"<<endl;
                }


            cout << "continue?"<<endl<< "yes enter 0, no enter 1"<<endl;
            cin >> x;
            string a;
            getline(cin,a);
        }

        file.close();
    }
    else cout<< "unable to open file";
    return 0;
}
