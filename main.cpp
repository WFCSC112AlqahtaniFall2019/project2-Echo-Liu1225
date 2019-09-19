#include <iostream>
#include <vector>
using namespace std;

/*
 * Echo Liu
 * 2019.09.19
 * Project2
 */
// function declarations
//first declare the mergeSortedLists,
void mergeSortedLists( vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int x = 0;
    int y = left;
    int z = middle + 1;
    tmp.resize(right - left + 1);//resize

    while (y <= middle && z <= right){//using while loop to declare the function
        if(a[y]<a[z]){
            tmp[x] = a[y];
            x ++ ;
            y ++;
        }
        else{
            tmp[x] = a[z];
            x++;
            z++;
        }

    }

    while (y <= middle){
        tmp[x] = a[y];
        x++;
        y++;
    }

    while (z <= right){
        tmp[x] = a[z];
        x++;
        z++;
    }

    for(int p = left, q= 0; p <= right; p++,q++){
        a[p] = tmp[q];
    }
}

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    if(left<right){
        int middle = ( left + right) / 2;
        mergeSort(a,tmp,left, middle);
        mergeSort(a, tmp,middle + 1, right);
        mergeSortedLists(a,tmp,left,middle,right);//recall the mergeSortedLists
    }
}

int main() {
    // get input
    //first get the seed while second get the length
    int seed, length;
    cout << "Please enter seed and length:"<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
// unit test for mergeSortedLists
    /*
    vector<int> test(8);
    test = {5,3,2,6,1,9,7,8};
    vector<int> result(8);
    result = { 1, 2, 3,5, 6, 7,8, 9};
    vector<int> temp(5);
    cout << "Unit Test Start"<<endl;
    cout<< "sort(A)"<< endl;
    cout<< "Base case: if A has length" << length<<", quick return"<< endl;
     cout << "The expected answer is: 1 2 3 5 6 7 8 9"<<endl;
    mergeSortedLists(test,temp,0,test.size() - 1);
    cout<<"The test result is ; " << mergeSortedLists <<endl;

    if(test == result){
        cout << "Test passed" << endl;
    }
    else{
        cout<< "Test failed" <<endl;
    }
    */

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v,t,0,length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */
