#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>     /* abs */
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
void cout_vector(vector<int>vector)
{
    for (int c=0;c<vector.size();c++)
    {
        cout<<vector[c]<<" ";
    }
    cout<<endl;
}

// Algorithm
//void match_making(priority_queue<int>bachelor,vector<int>spinster)
void match_making(vector<int>bachelor,vector<int>spinster,int test_number)
{

    int b = 0;
    int age_difference;
    priority_queue<int,vector<int>,greater<int> > single_bachelors;
    while(!bachelor.empty()) {

        age_difference = 999;
        int best_woman = -1;
        for (int w=0;w<spinster.size();w++)
        {
            if(abs(bachelor[b]-spinster[w]) < age_difference)
            {
                age_difference = abs(bachelor[b]-spinster[w]);
                best_woman = w;
            }
            else
                break;

        }
        if (best_woman == -1)
        {
            cout<<"Single: "<<bachelor[b]<<endl;
            single_bachelors.push(bachelor[b]);
        }

        else
            cout<<"Couple: "<<bachelor[b]<<" and "<<spinster[best_woman]<<endl;
        spinster.erase(remove(spinster.begin(), spinster.end(), spinster[best_woman]), spinster.end());
        bachelor.pop_back();
        b++;
    }
    // Output
    if (single_bachelors.size()>0)
        cout<<"Case "<<test_number<<": "<<single_bachelors.size()<<" "<<single_bachelors.top()<<endl;
    else
        cout<<"Case "<<test_number<<": 0"<<endl;

}

int main()
{

    vector<int> bachelor{ 26,25,2,21,50,22,34,1 };
    vector<int> spinster{ 35,25,23,24,21,60};


    sort(bachelor.begin(), bachelor.end(), greater<int>());
    sort(spinster.begin(), spinster.end(), greater<int>());
    match_making(bachelor,spinster,1);


    // Input
    /*
    string bs,line;
    vector<int> num_persons;
    vector<int> bachelors;
    vector<int> spinsters;
    int t = 0;
    while(true)
    {
        getline(cin,bs); // input number of bachelors and spinsters
        int number;
        stringstream iss( bs );
        while ( iss >> number )
            num_persons.push_back( number );
        if (num_persons[0] == 0 && num_persons[1] == 0)
            break;
        for (int n=0;n<num_persons[0];n++)
        {
            getline(cin,line); // input bachelors
            bachelors.push_back(stoi(line));
        }
        for (int n=0;n<num_persons[1];n++)
        {
            getline(cin,line); // input spinsters
            spinsters.push_back(stoi(line));
        }
        sort(bachelors.begin(), bachelors.end(), greater<int>());
        sort(spinsters.begin(), spinsters.end(), greater<int>());
        match_making(bachelors,spinsters,t+1);
        num_persons = {};
        bachelors = {};
        spinsters = {};
        t ++;
    }
*/
    return 0;
}

