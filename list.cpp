#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
// vector containers
vector <int> vec1, vec2;
// vector iterators
vector <int>::iterator Iter1, Iter2;
int i, j;
// pushing data, constructing vectors
for(i = 0; i <= 5; i++)
vec1.push_back(i);
for(j = 10; j <= 20; j++)
vec2.push_back(j);
// print the data
cout<<"vec1 vector data: ";

for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)
cout<<*Iter1<<" ";
cout<<endl;
cout<<"vec2 vector data: ";

for(Iter2 = vec2.begin(); Iter2 != vec2.end(); Iter2++)
cout<<*Iter2<<" ";
cout<<endl;

// to copy the first 4 elements of vec1 into the middle of vec2
copy(vec1.begin(), vec1.begin() + 4, vec2.begin() + 5);
// print the result
cout<<"vec2 vector with vec1 vector insert data: ";

for(Iter2 = vec2.begin(); Iter2 != vec2.end(); Iter2++)
cout<<*Iter2<<" ";
cout<<endl;
// to shift the elements inserted into vec2 two positions to the left
copy(vec2.begin()+4, vec2.begin() + 7, vec2.begin() + 2);
// print the result
cout<<"vec2 vector with shifted insert data: ";

for(Iter2 = vec2.begin(); Iter2 != vec2.end(); Iter2++)
cout<<*Iter2<<" ";
cout<<endl;

return 0;

}