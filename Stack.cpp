/**
 * @file Stack.cpp
 * @brief This file has a simple implementation of 
 *        generic Stack DataStructure using array 
 *        created using Smart Pointer.
 * @date 2023-09-14
 */

#include <iostream>
#include <memory>
#include <climits> 

class Exception{
    public:
    Exception(){
        std::cout<<"Stack overflow"<<std::endl;;
    }
    Exception(int n){
        std::cout<<"Stack underflow"<<std::endl;
    }
};

template <typename T>
class Stack{
private:
    std::unique_ptr<T[]> mArr{nullptr};
    T mTop{-1};
    static int stackSize;
public:
    explicit Stack(int maxStackSize){
        mArr=std::make_unique<T[]> (maxStackSize);
        Stack<T>::stackSize=maxStackSize;
    }
    int size() const{
        return (mTop+1);
    }
    void push(T pushNum){
        if(++mTop<(Stack<T>::stackSize))
            mArr[mTop]=pushNum;
        else{
            mTop--;
            throw Exception();
        }
    }
    void pop(){
        if(mTop>0){
            mTop--;
        }
        else{
            mTop--;
            mArr[mTop]=INT_MIN;
            throw Exception(1);
        }
    }
    const T& top() const{
        return mArr[mTop]; 
    }
    bool isEmpty(){
        return (mTop==-1);
    }
    int maxSize() const{
        return Stack<T>::stackSize;
    }
    void clear(){
        mTop=-1;
    }
    friend std::ostream& operator<<(std::ostream& o, Stack& ob){
        if(!ob.isEmpty()){
            int i=ob.mTop;
            while(i>=0){
                o << ob.mArr[ob.mTop] << "\n";
            }
            o<<"Stack printed fully";
        }
        else
            o<<"Stack Empty";
        return o;
    }
};
template<typename T>
int Stack<T>::stackSize=0;

int main(){
/**
 * @brief TEST CODE
 * 
 */

    Stack<float> ob(5);
    //Stack<int> ob(5);
    try{    
        ob.push(1.1);
        ob.push(2.2);
        ob.push(3.3);
        ob.push(4.4);
        ob.push(5.5);
        ob.push(6.6);
        ob.push(7.7);
    }catch(Exception& e){
        std::cout<<ob.size()<<std::endl;
        std::cout<<ob.top()<<std::endl;
    }
    try{
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
        std::cout<<ob.top()<<std::endl;
        ob.pop();
    }
    catch(Exception& e){
        std::cout<<ob.size()<<std::endl;
        std::cout<<ob.top()<<std::endl;
        std::cout<<"::::::::"<<std::endl;
    }
    std::cout<<"::::::::"<<std::endl;
    std::cout<<ob<<std::endl;
    try{    
        ob.push(1.1);
        ob.push(2.2);
        ob.push(3.3);
        ob.pop();
    }catch(Exception& e){

    }
    std::cout<<ob.size()<<std::endl;
    std::cout<<ob.top()<<std::endl;
    std::cout<<ob.maxSize()<<std::endl;
    ob.clear();
    std::cout<<"stack cleared and set with lowest possible integer value"<<std::endl;
    std::cout<<ob.top()<<std::endl;
        try{    
        ob.push(1.1);
        ob.push(2.2);
        ob.push(3.3);
        ob.pop();
    }catch(Exception& e){

    }
    std::cout<<ob.size()<<std::endl;
    std::cout<<ob.top()<<std::endl;
    std::cout<<ob.maxSize()<<std::endl;
    return 0;
}