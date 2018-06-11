/*****************************************
Name:               Axel Yates
Course:             CSCE3110
Assignment:         Program 4 -- Heap
******************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

//Building a Heap Class
class Heap{

    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        Heap()
        {}
        void Insert(int element);
        void Delete(int element);
        void DeleteMin();
        int ExtractMin();
        void DisplayHeap();
        int Size();

};

//Function that returns size of Heap
int Heap::Size(){

    return heap.size();

}
 
//Function to insert an element into Heap
void Heap::Insert(int element){

    heap.push_back(element);
    heapifyup(heap.size() -1);

}

//Function to Delete the Minimum value
void Heap::DeleteMin(){

    if (heap.size() == 0){

        cout<<"Heap is Empty"<<endl;
        return;

    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);

}

//Function that extracts the minimum element
int Heap::ExtractMin(){

    if (heap.size() == 0){
    
        return -1;

    }
    else{

        return heap.front();

    }
}
 
//Function that prints out the heap
void Heap::DisplayHeap(){

    heapifyup(heap.size() -1);
    vector <int>::iterator pos = heap.begin();
    while (pos != heap.end()){

        cout << *pos << " ";
        pos++;

    }
    cout << endl;

}

//Function that deletes an element
void Heap::Delete(int element){

    int i;
    vector <int>::iterator pos = heap.begin();
    for(i = 0; i < heap.size(); i++){

        if(heap.at(i) == element){

            heap.erase(heap.begin() + i);

        }

    }
    heapifyup(heap.size() -1);

}

//Function that returns the left child
int Heap::left(int parent){

    int l = 2 * parent + 1;
    if (l < heap.size()){

        return l;

    }
    else{

        return -1;

    }
}
 
//Function that returns the right child
int Heap::right(int parent){

    int r = 2 * parent + 2;
    if (r < heap.size()){

        return r;

    }
    else{

        return -1;

    }
}
 
//Function that returns the parent
int Heap::parent(int child){

    int p = (child - 1)/2;
    if (child == 0){

        return -1;

    }
    else{

        return p;

    }
}
 
//Function to heapify structure from bottom up
void Heap::heapifyup(int in){

    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]){

        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));

    }

}
 
//Function to heapify structure from top down
void Heap::heapifydown(int in){
 
    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]){

       child = child1;

    }
    if (child > 0 && heap[in] > heap[child]){

        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}
 
int main(){

    Heap h;
    string in;
    int num_to_insert;
    int previous_num;
    int new_num;
    int num_to_delete;

    while(cin >> in){

        if(in == "I"){

            //when a number is to be inserted
            cin >> num_to_insert;
            h.Insert(num_to_insert);

        }
        if(in == "C"){

            //when a number is to be changed
            cin >> previous_num;
            h.Delete(previous_num);
            cin >> new_num;
            h.Insert(new_num);

        }
        if(in == "P"){

            //when the heap is to be printed in postorder
            h.DisplayHeap();

        }
        if(in == "D"){

            //when a number is to be deleted
            cin >> num_to_delete;

        }
    }//end while loop

    return 0;
}
