#pragma once
#include <functional>
using namespace std;

template <typename Type>
class Array
{
private:
   Type *data;
   int count;

public:
   ~Array()
   {
      delete[] this->data;
   }
   Array<Type>()
   {
      this->data = new Type[0];
      this->count = 0;
   }
   Array<Type>(Type *data, int count)
   {
      this->data = data;
      this->count = count;
   }
   Type *getData()
   {
      return this->data;
   }
   int getCount()
   {
      return this->count;
   }
   void copy(Type *dest)
   {
      for (int i = 0; i < count; i++)
      {
         dest[i] = this->data[i];
      }
   }
   Array<Type> clone()
   {
      Type *outArr = new Type[count];
      this->copy(outArr);
      return Array<Type>(outArr, count);
   }
   Array<Type> *push(Type element)
   {
      int newCount = count + 1;
      Type *outArr = new Type[newCount];
      if (!this->count || this->count != 0)
      {
         this->copy(outArr);
         //delete[] this->data;
      }
      outArr[count] = element;
      this->data = outArr;
      this->count++;
      return this;
   }
   Array<Type>* pop()
   {
       if (count <= 0) {
           return;
       }
       int newCount = count - 1;
       Type* outArr = new Type[newCount];
       for (int i = 0; i < newCount; i++) 
       {
           outArr[i] = this->data[i];
       }
       delete[] this->data;
       this->count = newCount;
       this->data = outArr;
       return this;
   }
   void filter(function<bool(Type)> f)
   {
      Array<Type> *out = new Array<Type>();
      for (int i = 0; i < count; i++)
      {
         if (f(this->data[i]))
         {
            out->push(this->data[i]);
         }
      }
      delete[] this->data;
      this->count = out->count;
      this->data = new Type[out->getCount()];
      out->copy(this->data);
      delete out;
   }
   void forEach(function<void(Type)> f)
   {
      if (!this->count || this->count == 0)
         return;
      for (int i = 0; i < this->count; i++)
      {
         f(this->data[i]);
      }
   }
   template <typename MapType>
   Array<MapType> *map(function<MapType(Type)> f)
   {
      MapType *outArr = new MapType[this->count];
      Array<MapType> *out = new Array<MapType>(outArr, this->count);
      for (int i = 0; i < this->count; i++)
      {
         out->getData()[i] = f(this->data[i]);
      }
      return out;
   }
   template <typename ReduceType>
   ReduceType reduce(function<ReduceType(ReduceType accumulator, Type currentValue, int currentIndex, Type *srcArray)> f, ReduceType initValue)
   {
      ReduceType value = initValue;
      for (int i = 0; i < this->count; i++)
      {
         value = f(value, this->data[i], i, this->data);
      }
      return value;
   }
};
