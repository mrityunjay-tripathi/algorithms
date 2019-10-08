#include<iostream>
using namespace std;

int main()
{
    int e,v;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;

    int adj_matrix[v][v];
    for(int i = 0; i<v; ++i)
    {
        for(int j = 0; j<v; ++j)
        {
            adj_matrix[i][j] = 0;
        }
    }
    cout<<"Enter the edges : ";
    int vi, vj;
    for(int i = 0; i<e; ++i)
    {
        cin>>vi>>vj;
        adj_matrix[vi-1][vj-1] = 1;
    }

    //Print adjacency matrix
    cout<<"The adjacency matrix of given directed graph : \n";
    for(int i = 0; i<v; ++i)
    {
        for(int j = 0; j<v; ++j)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
