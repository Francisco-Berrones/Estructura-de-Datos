#include "iostream"
using namespace std;
#include "vector"

int main(){
    vector<int> mivector;
    for (int i=0; i<=10; i++){
        mivector.push_front(i);

    }
    for(int i=0; i<=10;i++){
        cout << mivector[i] << " ";
    }
    cout << mivector[3];



    return 0;
}