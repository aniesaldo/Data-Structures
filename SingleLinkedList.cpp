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

    List(const List&)=delete;

    List& operator=(const List&)=delete;

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

    void print(){
        Node *temp=head;
        if(head==nullptr)
            Log("List Empty");
        while(temp!=nullptr){
            Log(temp->data);
            temp=temp->nxt;
        }
    }

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
            }
            else{
                //Log("hi");
                Node *findNum=head;
                Node *findNumPrev=head;
                while(findNum->data!=num){
                    findNumPrev=findNum;
                    findNum=findNum->nxt;
                }
                findNumPrev->nxt=findNum->nxt;
                delete findNum;
                findNum=nullptr;
            }
        }
        listSize--;
    }

    size_t size() const{  
        return listSize;    
    }

    bool isEmpty() const{
        return size()==0;
    }

};

int main(){
    List<int> ob(5);
    ob.Add_element_at_end(10);
    ob.Add_element_at_end(20);
    ob.Add_element_at_end(30);
    ob.print();
    Log(ob.size());
    Log(ob.isEmpty());
    ob.remove(30);
    ob.print();
    Log(ob.size());
    Log(ob.isEmpty());
    return 0;
}