/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 *//*
int res=0;

    for(int g=1; g<=2; g++){
        for(int m=1; m<=2; m++){
            for(int y=2; y<=4; y++){
                if()
            }
        }
    }*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <iostream>
// constraints
#define MAXL 8
using namespace std;
// input data
string date;

int main()
{
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    //assert(1 == scanf("%s", date));
    //strcat(date, "####");
    cin>>date;
    date+="#######";
    int res=0;

    for(int g=1; g<=2; g++)
    {
        for(int m=1; m<=2; m++)
        {
            for(int y=2; y<=4; y++)
            {

                string subday = date.substr(0, g);

              //  cout<<"DAY "<<subday<<endl;
                if(subday.find("#") != string::npos) //se trovato #
                {
                   // cout<<"EXIT #"<<endl;
                    continue;
                }
                //strncpy(subday, date, g);
                int numday = atoi(subday.c_str());
                if(numday < 1 || numday > 31)
                {
                   // cout<<"EXIT NUM"<<endl;
                    continue;
                }


                string submonth = date.substr(g, m);
              //  cout<<"MONTH "<<submonth<<endl;
                if(submonth.find("#") != string::npos)
                {
                   // cout<<"EXIT #"<<endl;
                    continue;
                }
                // strncpy(submonth, date+g, m);
                int nummonth = atoi(submonth.c_str());
                if(nummonth < 1 || nummonth > 12)
                {
                   // cout<<"EXIT NUM"<<endl;
                    continue;
                }


                string subyears = date.substr(g+m, y);
               // cout<<"YEARS "<<subyears<<endl;
                if(subyears.find("#") != string::npos)
                {
                    //cout<<"EXIT #"<<endl;
                    continue;
                }

                if(y>2 && subyears[0]=='0'){
                    continue;
                }
                // strncpy(submonth, date+g, m);
                int numyears = atoi(subyears.c_str());
//                if(numyears < 0 || (numyears > 99 && numyears < 900) || (numyears > 999 && numyears < 1900) || numyears > 1999)
                if (
                    !((numyears >=0 && numyears<=99) ||
                     (numyears >=900 && numyears<=999) ||
                     (numyears >=1900 && numyears<=1999))
                    )
                {
                   // cout<<"EXIT NUM"<<endl;
                    continue;
                }

                if(date[g+m+y]!='#'){
                    //    cout<<"EXIT SPECIAL"<<endl;
                    continue;
                }

                if(nummonth == 4 || nummonth == 6 || nummonth == 9 || nummonth == 11){
                    if(numday==31)
                    {
                      //  cout<<"EXIT LIMIT"<<endl;
                        continue;
                    }
                }

                if(nummonth == 2 && numday > 28){
                      //  cout<<"EXIT LIMIT"<<endl;
                    continue;
                }

                //cout<<"OKK "<<numday<<" "<<nummonth<<" "<<numyears<<endl;
                res++;
            }
        }
    }

    //string a="01";
    //printf("%d\n", atoi(a.c_str())); // change 42 with actual answer
    // date+="####";
    // insert your code here
    // printf("%s\n", date); // change 42 with actual answer
  //  printf("%d\n", atoi("09")); // change 42 with actual answer
    cout<<res<<endl;
    return 0;
}
