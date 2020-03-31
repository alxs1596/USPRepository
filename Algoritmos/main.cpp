#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>     /* abs */
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>  // std::begin, std::end

using namespace std;
void cout_vector(vector<int>vector)
{
    for (int c=0;c<vector.size();c++)
    {
        cout<<vector[c]<<" ";
    }
    cout<<endl;
}
int min_value(vector<int>vector)
{
    int min_ = 999;
    for (int i=0;i<vector.size();i++)
    {
        if(vector[i] < min_)
            min_ = vector[i];
    }
    return min_;
}
// Algorithm
//void match_making(priority_queue<int>bachelor,vector<int>spinster)
void match_making(vector<int>bachelor,vector<int>spinster,int case_number)
{
    vector<int> single_bachelors;
    for (int b=0;b<bachelor.size();b++) {
        int senior_bachelor = bachelor[b];
        int age_different = 999;
        int most_similar_spinter = -1;
        for (int s = 0; s < spinster.size(); s++) {
            if (abs(senior_bachelor - spinster[s]) < age_different) {
                age_different = abs(senior_bachelor - spinster[s]);
                most_similar_spinter = s;
                //cout << " Age: " << age_different  <<" s: "<<s<<endl;

            } else {
                // We found the most similar age spinster to a bachelor
                break;
            }
        }
        // We check is there are any sinble bachelor
        if (most_similar_spinter == -1)
        {
            //cout << "Single bachelor: " << bachelor[b]<<endl;
            single_bachelors.push_back(senior_bachelor);
        } else {
            //cout << "Couple: " << bachelor[b] << " and " << spinster[most_similar_spinter] << endl;
        }
        // We remove the elected spinster
        spinster.erase(remove(spinster.begin(), spinster.end(), spinster[most_similar_spinter]), spinster.end());
    }
    if (single_bachelors.size() > 0)
    {
        int min = min_value(single_bachelors);
        cout<<"Case "<<case_number<<": "<<single_bachelors.size()<<" "<<min<<endl;
    } else
        cout<<"Case "<<case_number<<": "<<single_bachelors.size()<<endl;
}

int main()
{


    //vector<int> bachelor{ 26,25,2,21 };
    //vector<int> spinster{ 35,25,23,24};

    /*
    vector<int> spinster{ 30 };
    vector<int> bachelor{ 12,45,1};

    sort(bachelor.begin(), bachelor.end(), greater<int>());
    sort(spinster.begin(), spinster.end(), greater<int>());
    match_making(bachelor,spinster,1);
    */

    // Input

    string bs,line;
    vector<int> num_persons;
    vector<int> bachelors;
    vector<int> spinsters;
    int t = 1;
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
        match_making(bachelors,spinsters,t);
        num_persons = {};
        bachelors = {};
        spinsters = {};
        t ++;
    }

    return 0;
}

