/*
The problem is:
There are a list of houses, and a list of heaters.
heaters number might be greater or less than house number. 
now you need to design the heaters minimum radius to cover all houses.
E.g houses {1,2,3}, heaters {2}
the answer is 1.
*/

#include "iostream"
#include <vector>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    for (int house : houses)
    {
        vector<int>::iterator pos = lower_bound(heaters.begin(), heaters.end(), house) ;
        //cout<<*(pos-1)<<","<<*pos<<endl;
        int minimumdis = 0;
        if(pos != heaters.end() && pos != heaters.begin())
        {
           minimumdis = abs(house - *pos) < abs(house - *(pos-1)) ?  abs(house - *pos)  : abs(house - *(pos-1));
        }
        else if(pos == heaters.end())
        {
            minimumdis = abs(house - *(pos-1));
        }
        else if (pos == heaters.begin())
        {
            minimumdis = abs(house - *(pos));
         }
         if (minimumdis > radius)
             radius = minimumdis;
     }
     return radius;
};

int main(int argc, char *argv[])
{
    vector<int> houses {1,2,3,4,5};
    vector<int> heaters {1,4};
    int minimus_radius = findRadius(houses, heaters);
    cout<<"The mimum radius of heaters is: "<<minimus_radius<<endl;
    return 0;
}
