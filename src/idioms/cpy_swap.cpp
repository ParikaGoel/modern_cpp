// Copy and Swap Idiom

#include <iostream>
#include <algorithm>

class CustomArray{
    public:
        CustomArray(size_t s = 0): 
            _mSize(s), 
            _mArr(_mSize ? new int[_mSize]() : nullptr)
        {}

        CustomArray(const CustomArray& rhs): 
            _mSize(rhs._mSize),
            _mArr(_mSize ? new int[_mSize]() : nullptr)
        {
            std::copy(rhs._mArr, rhs._mArr+_mSize,_mArr);
        }

        // This is usually how assignment operator is implemented
        // CustomArray& operator=(const CustomArray& rhs)
        // {
        //     if (this == &rhs) return *this;

        //     // get the new data ready before we replace the old one
        //     size_t newSize = rhs._mSize;
        //     int* newArr = newSize ? new int[newSize]() : nullptr;
        //     std::copy(rhs._mArr, rhs._mArr+_mSize,newArr);

        //     // replace the old data
        //     delete [] _mArr;
        //     _mSize = newSize;
        //     _mArr = newArr;

        //     return *this;
        // }

        // This implementation is using copy and swap idiom
        // note that here we are accepting argument by value
        // so temporary copy is created when performing assignment
        // and then the swapping occurs with this temporary copy
        CustomArray& operator=(CustomArray rhs)
        {
            swap(*this, rhs);
            return *this;
        }

        ~CustomArray()
        {
            delete [] _mArr;
        }

        friend void swap(CustomArray& arr1, CustomArray& arr2)
        {
            std::swap(arr1._mSize, arr2._mSize);
            std::swap(arr1._mArr, arr2._mArr);
        }

        void print() const{
            std::cout << "Size: " << _mSize << "\n";
            std::cout << "Array Address: " << _mArr << "\n";
        }
    
    private:
        size_t _mSize{0};
        int* _mArr{nullptr};
};


// int main()
// {
//     CustomArray carr(10);
//     carr.print();
//     return 0;
// }