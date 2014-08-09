//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heapsort{
public:
	void operator()(std::vector<T> &v)const{
		// Construct heap by inserting
		/*for(int i=1; i<v.size(); i++){
		 insert(v, i);
		 }*/
		
		// Construct heap by partial heaps
		for (int i = (v.size() / 2)-1; i >= 0; i--)
			heapify(v, i, v.size());
		
		// Sort using heap
		for(int i=v.size()-1; i>=0; i--){
			int h=v[0];
			v[0]=v[i];
			v[i]=h;
			heapify(v, 0, i-1);
		}
	}
private:
	void insert(std::vector<T> &v, int i) const{
		int h=v[i];
		while(i!=0 && h > v[(i-1)/2]){
			v[i]=v[(i-1)/2];
			i=(i-1)/2;
		}
		v[i]=h;
	}
	void heapify(std::vector<T> &v, int i, int N) const{
		while((2*i)+1 <= N){
			int j = (2*i)+1;
			if(j < N && v[j] < v[j+1]) j++;
			if(!(v[i] < v[j])) break;
			std::swap(v[i], v[j]);
			i = j;
		}
	}
};

int main(int argc, const char * argv[])
{
	int temp[] = {16,2,77,29, 6, 19, 15, 88};
	vector<int> array (temp, temp + sizeof(temp) / sizeof(int) );
	
	Heapsort<int> heapsort;
	heapsort(array);
	
	cout << "Sorted array is \n";
	for(int i=0; i<array.size(); i++){
		cout<<array[i]<<" ";
	}
	
    return 0;
}

