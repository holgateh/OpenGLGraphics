#pragma once
#include <vector>
#include <iostream>
namespace tools
{
    template <class T>
    class CircularQueue
    {
        private:
            unsigned int front, back, occupied;
            const unsigned int SIZE;
            
            std::vector<T> queueData;
        public:
        private:
        public:
            CircularQueue(unsigned int size) : SIZE(size)
            {
                front = -1;
                back = -1;
                occupied = 0;
                queueData = std::vector<T>(SIZE, T(0));
            }

            void push(T item)
            {
                if (!isFull())
                {
                    back = (back + 1) % SIZE;

                    if(front == -1)
                    {
                        front++;
                    }

                    queueData[back] = item;
                    occupied++;
                }
                else
                {
                    std::cout << "Cannot add item to a full queue.\n";
                }
            }
            void pop()
            {
                if((front != -1 && back != -1) && front == back )
                {
                    front = -1;
                    back = -1;
                    occupied--;
                }
                else
                {
                    front = (front + 1) % SIZE;
                    occupied--;
                }
                
            }
            
            T at(unsigned int i)
            {
                if (i < 0 || i >= occupied)
                {
                    throw std::runtime_error("Circular queue .at() index out of range. It must be between 0 and .size()\n");
                }
                return queueData[(front + i) % SIZE];
            }
            
            bool isFull()
            {
                if ((back + 1) % SIZE == front)
                {
                    return true;
                }

                return false;
            }
            
            bool isEmpty()
            {
                if(back == -1 && front == -1)
                {
                    return true;
                }
                
                return false;
            }
            
            unsigned int size()
            {
                return SIZE;
            }
            
            unsigned int occupiedSpace()
            {
                return occupied;
            }

            const std::vector<T>& getArray()
            {
                return queueData;
            }
    };
}