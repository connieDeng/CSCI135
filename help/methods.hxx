template <class T>
MyVector<T>::MyVector(T a, T b, T c, T d, T e){
  data[0]=a;
  data[1]=b;
  data[2]=c;
  data[3]=d;
  data[4]=e;
}

template <class T>
void MyVector<T>::printem(){
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// template <class T>
// T* MyVector<T>::get_data(){
//   return data;
// }

template <class T>
void MyVector<T>::insertLocation(int location, T item){
  resize();
  int* result = new int[size];
  bool insert = false;
  for(int i = 0; i < size; i++){
    if(i == location){
      result[i] = item;
      insert = true;
    }else if(insert){
      result[i] = data[i-1];
    }else{
      result[i] = data[i];
    }
  }
  
  data = result;
  return;
}

template <class T>
void MyVector<T>::insertEnd(T item){
  resize();
  data[size - 1] = item;
  return;
}

template <class T>
void MyVector<T>::deleteLocation(int location){
  int* newArr = new int[size - 1];
  bool skipped = false;
  for(int i = 0; i < size; i++){
    if(i == location){
      skipped = true;
    }else if(skipped){
      newArr[i-1] = data[i];
    }else{
      newArr[i] = data[i];
    }
  }

  size = size - 1;
  delete [] data;
  data = newArr; 
  
  return;
}

template <class T>
void MyVector<T>::resize(){
  int* newArr = new int[size+1];
  for(int i = 0; i < size; i++){
    newArr[i] = data[i];
  }

  size = size+1;
  delete [] data;
  data = newArr;
}

