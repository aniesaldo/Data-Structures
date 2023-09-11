template<typename T>
class MyArray{
    T *ptr{nullptr};
    int arr_size{0};
    public:
    MyArray()=default;
    explicit MyArray(int s){
        if(s!=0){
            this->arr_size=s;
            this->ptr=new T[s]{};
        }
    }
    MyArray(MyArray& source){
        if(!source.isEmpty()){
            this->ptr=new T[source.size()]{};
            for(int i=0;i<source.size();i++){
                this->ptr[i]=source.ptr[i];
            }
            this->arr_size=source.arr_size;
        }
    }
    MyArray(MyArray&& source){
        log("Move Constructor");
        this->ptr=source.ptr;
        this->arr_size=source.arr_size;
        source.ptr=nullptr;
        source.arr_size=0;
    }
    bool isEmpty() const{
        return (this->arr_size==0);
    }
    int size() const{
        return this->arr_size;
    }
    bool isValidIndex(T n) const{
        return (n>=0)&&(n<(this->arr_size));
    }
    T& operator[](int n) const {
        if(!isValidIndex(n)){
            throw std::out_of_range("Outside the limit");
        }
        return this->ptr[n];
    }
    MyArray& operator=(MyArray source){
        swap(*this, source);
        return *this;
    }
    void swap(MyArray& a, MyArray& b) noexcept{
        using std::swap;
        swap(a.ptr,b.ptr);
        swap(a.arr_size,b.arr_size);
    }
    friend std::ostream& operator<<(std::ostream& o, const MyArray& ob){
        for(int i=0;i<ob.size();i++){
            o<<ob[i]<<" ";
        }
        return o;
    }
    ~MyArray(){
        delete[] ptr;
        ptr=nullptr;
    }
};
