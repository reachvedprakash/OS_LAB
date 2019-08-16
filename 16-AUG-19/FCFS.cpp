#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    int Arrival[N] , Execution[N] , Service[N] , Waiting[N]  ;
    for( int i = 0 ; i < N ; i++ )
    {
        cin >> Arrival[i];
    }
    for( int i = 0 ; i < N ; i++ )
    {
        cin >> Execution[i];
    }

    Service[0] = 0;
    Waiting[0] = 0;
    for( int i = 1 ; i < N ; i++ )
    {
        if( Arrival[i] <= Service[i-1]+Execution[i] )
        {
            Service[i] = Service[i-1]+Execution[i-1];
            Waiting[i] = Service[i] -  Arrival[i] ;
        }
        else
        {
            Service[i] = Arrival[i];
            Waiting[i] = 0 ;
        }
        
    }


    for(int i =0 ; i < N ; i++)
    {
        cout << i <<  "  Service Tym : " << Service[i] << " Waiting Tym : " << Waiting[i]<< endl;  
    }
    double sum =0 ;
    for(int i =0 ; i < N ; i++ )
    sum+= Waiting[i];

    sum/=N;
    cout << "Average Waiting Tym :" << sum << endl;
        
}