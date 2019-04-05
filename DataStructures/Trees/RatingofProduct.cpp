#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include <random>
#include <time.h>

using namespace std;

class Products
{
public:
    int id;
    double rating;
    Products(int id, double rating)
    {
        this->id = id;
        this->rating = rating;
    }
};

int main()
{
    //creating a random array of products;
    vector<Products> productsList;
    mt19937 mt_rand(time(0));
    uniform_int_distribution<> distr(1, 45);

    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 15; j++){
            productsList.push_back(Products(i,distr(mt_rand)));
        }
    }

    // for(auto x: productsList){
    //     cout<<" Product: "<<x.id<< " Rating: "<<x.rating<<endl;

    // }
    map<int, double> ans;
    map<int, priority_queue<double>> processor;
    for(auto x: productsList)
        processor[x.id].push(x.rating);
    
    for(auto x: processor){
        int cnt = 5;
        double prductScore = 0;
        while(cnt--){
            prductScore+= x.second.top();
            x.second.pop();
        }
        ans[x.first] = prductScore/ 5.0;
    }
    //finding greatest average score for each product

    for(auto x: ans){
        cout<< "Product ID:"<<x.first<<endl;
        cout<<" Max Average Rating: "<<x.second<<endl;
    }

    return 0;
}