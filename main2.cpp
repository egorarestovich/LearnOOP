#include <iostream>
#include <vector>
#include <ctype.h>


class Class{
private:
    int* data = nullptr;
    int length = 0;
public:
    Class(std::vector<int>& values)
    {
        length = values.size();

        data = new int[length];

        for(int i = 0; i < length; i++)
        {
            data[i] = values[i];
        }
    }

    Class(const Class& other)
    {
        this->length = other.length;

        if(this->data != nullptr)
        {
            delete[] data;
        }

        data = new int [this->length];

        for(int i = 0; i < length; i++)
        {
            this->data[i] = other.data[i];
        }
    }


    Class& operator = (const Class& other)
    {
        this->length = other.length;

        if(this->data != nullptr)
        {
            delete[] data;
        }

        data = new int[this->length];

        for(int i = 0; i < length; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    void print_values()
    {
        for(int i = 0; i < length; i++)
        {
            std::cout << data[i];
        }
        std::cout << '\n';
    }

    ~Class()
    {
        delete[] data;
    }

};

int main(){
    size_t len; std::cin >> len;
    std::vector<int> values(len);
    for(auto& el : values)
    {
        std::cin >> el;
    }

    Class a(values);

    for(auto& el : values)
    {
        std::cin >> el;
    }
    Class b(values);

    a.print_values();
    b.print_values();

    a = b;

    a.print_values();
}
