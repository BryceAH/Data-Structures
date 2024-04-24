#include <iostream>

using namespace std;

struct node {

    int value; // integer value of each node
    node *next; // pointer that points to the next nodes address

};

class queue{

public:
    queue() {
        front = nullptr; //contructor to indecate that the queue is empty
        rear = nullptr;
    }
    void enqueue(int val){
        node *temp = new node; // new temp node as a place holder to add "val" to the queue
        temp -> value = val;
        temp -> next = nullptr; //becuase it is adding to end of queue it makes the next address null
        if (rear == nullptr) { // if the queue is empty then it makes the front and rear the "temp"
            front = rear = temp;
        } else { // if the node is not empty then the new temp element is added onto the end and the pointer is updated to point to the new element 
            rear->next = temp;
            rear = temp;
        }

    }

    void dequeue(){
        node *temp = front;

        if (front != nullptr) {
            front = front->next; // stores the node in the front to a temparary varible
            cout << "value that was removed: "<< temp -> value << endl;
            cout << "address that was removed: "<< temp << endl << endl;

            delete temp; //deletes the front node
        }
        else {
            front = nullptr; //updates the front to null pointer
            rear = nullptr;  //updates the rear to null pointer
            cout << "There is not enough stuff in the queue to remove" << endl<< endl;
        }
    }
   
    void display() {

        node *temp = front; // makes following while loop start at the front of the queue
        while(temp != nullptr){
            cout <<"Value of current node: "<< temp -> value << endl; //prints the value of the current node
            cout <<"current node address: "<< temp << endl; // gives address of current node
            cout <<"next node address: " << temp -> next << endl << endl; //gives address of next node
            temp = temp -> next; //moves to next node

        }

    }
private:
    node *front;
    node *rear;

};


int main(){
    queue q;
    for (int i = 1; i<=3;i++){ // adds three ints to the linked queue
    q.enqueue(i);
   }

   q.display(); // displays the linked queue

    for (int i = 1; i<=4;i++){ // removes three ints from the queue then one more to show error checking 
        q.dequeue();
    }

    q.enqueue(6); // adds one more to queue to display that you can add more to linked queue

    q.display(); // displays the new added int

    return 0;       
}