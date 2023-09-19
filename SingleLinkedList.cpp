/**
 * @file SingleLinkedList.cpp
 * @brief This file has the basic impl of Singlylinkedlist
 */

#include <iostream>
#define Log(x) std::cout << x << std::endl;

template<typename T>
class List{
    private:
    class Node{
        public:
        T data;
        Node *nxt;
        };
    Node *head{nullptr};
    size_t listSize{0};

    public:
    List()=default;
    explicit List(T num){
        Add_element_at_end(num);
    }

    /**
     * @brief Delete copy ctor and assignment op overload to
     *        ignore bogus code.
     */
    List(const List&)=delete;
    List& operator=(const List&)=delete;

    /**
     * @brief Add element to the end of the list
     * @param num - Number to be added
     */
    void Add_element_at_end(T num){
        Node *temp=new Node;
        if(head==nullptr){
            temp->data=num;
            temp->nxt=nullptr;
            head=temp;
            listSize++;
        }
        else{
            Node *lastNode=head;
            while(lastNode->nxt!=nullptr){
                lastNode=lastNode->nxt;
            }
            temp->data=num;
            lastNode->nxt=temp;
            temp->nxt=nullptr;
            listSize++;
        }
    }

    /**
     * @brief Prints the whole list
     */
    void print(){
        Node *temp=head;
        if(head==nullptr)
            Log("List Empty");
        while(temp!=nullptr){
            Log(temp->data);
            temp=temp->nxt;
        }
    }

    /**
     * @brief Removes an element from the list
     * 
     * @param num - Number to be removed
     */
    void remove(T num){
        if(isEmpty()){
            Log("List is Empty");
            return;
        }
        else{
            if(head->data==num){
                Node *findNum=head;
                head=head->nxt;
                delete findNum;
                findNum=nullptr;
                listSize--;
            }
            else{
                //Log("Hit BP");
                Node *findNum=head;
                Node *findNumPrev=head;
                while((findNum->data!=num)&&(findNum->nxt!=nullptr)){
                    findNumPrev=findNum;
                    findNum=findNum->nxt;
                }
                if(findNum->data==num){
                    findNumPrev->nxt=findNum->nxt;
                    delete findNum;
                    findNum=nullptr;
                    listSize--;
                }
            }
        }
    }

    /**
     * @brief Returns the element at the given index
     * 
     * @param pos - Index value
     * @return T - Number presetn in the specified index
     */
    T elementAt(int pos){
        int c=0;
        if((pos+1)>listSize){
            Log("Current List size is " << listSize << " which is less than the position entered");
            return -1;
        }
        while(head!=nullptr){
            if(c++==pos){
                return head->data;
            }
            head=head->nxt;
        }
    }

    /**
     * @brief Returns size of the list
     * 
     */
    size_t size() const{  
        return listSize;    
    }

    /**
     * @brief TO check whether the list is empty
     * 
     * @return true - empty
     * @return false - contains elements
     */
    bool isEmpty() const{
        return size()==0;
    }

    /**
     * @brief Deletes whole list
     * 
     */
    void clear(){
        Node* temp;
        while(head!=nullptr){
            temp=head;
            head=head->nxt;
            delete temp;
            temp=nullptr;
        }
        List::listSize=0;
    }

    /**
     * @brief Get the Head object
     * 
     * @return Node* 
     */
    Node* getHead(){
        return head;
    }

    /**
     * @brief Print the list in reverse
     * 
     * @param h - head
     */
    void revPrint(Node *h){
        if(isEmpty()){
            Log("List is Empty, Cant be reversed");
            return;
        }
        if(h->nxt!=nullptr){
            //getchar();
            revPrint(h->nxt);
        }
        Log(h->data);
    }

    /**
     * @brief Reverse the links
     * 
     */
    void revList(){
        Node* cn=head, *pn=NULL, *nn=NULL;
        while(cn!=NULL){
            nn=cn->nxt;//Store next
            cn->nxt = pn;//Reverse current node pointer
            //Move pointers one pos ahead.
            pn = cn;
            cn = nn;
        }
        head = pn;
    }
};

int main(){
    
    /**
     * @brief Test Code
     */
    //List<int> ob(5);
    List<float> ob;
    //List<double> ob(5.5);
    ob.Add_element_at_end(10.1);
    ob.Add_element_at_end(20);
    ob.Add_element_at_end(30.3);
    ob.print();
    ob.revPrint(ob.getHead());
    ob.print();
    ob.revList();
    ob.print();
    Log(ob.size());
    Log(ob.isEmpty());
    ob.remove(30.3);
    ob.print();
    Log(ob.size());
    Log(ob.isEmpty());
    Log(ob.elementAt(3));
    ob.clear();
    Log(ob.elementAt(0));
    Log(ob.isEmpty());

    return 0;
}