namespace JUtils
{
    template <class T>
    std::ostream& operator<<(std::ostream& os, Array<T>& array)
    {
        os << "[";
        for (int i = 0; i < array.len(); i++)
        {
            os << array[i];
            if (i < array.len() - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    template<class T>
    Array<T>::Array()
    {
        this->array = (T*) malloc(sizeof(T));
        this->size = 0;
    }

    template<class T>
    T& Array<T>::operator[](int idx)
    {
        return this->array[idx];
    }

    template<class T>
    void Array<T>::operator+=(T item)
    {
        this->append(item);
    }

    template<class T>
    int Array<T>::len()
    {
        return this->size;
    }

    template<class T>
    T& Array<T>::get(int idx)
    {
        return this->array[idx];
    }

    template<class T>
    void Array<T>::append(T item)
    {
        this->array = (T*) realloc(this->array, (this->size++) * sizeof(T));
        this->array[size - 1] = item;
    }

    template<class T>
    T& Array<T>::pop()
    {
        T item = this->get(this->len() - 1);

        T* popped = (T*) malloc(sizeof(T) * this->size--);
        memcpy(popped, this->array, this->size * sizeof(T));
        free(this->array);
        this->array = popped;

        return item;
    }

    template<class T>
    void Array<T>::remove(int idx)
    {
        T* popped = (T*) malloc(sizeof(T) * --this->size);
        memcpy(popped, this->array, idx * sizeof(T));
        for (int i = idx; i < this->size; i++) popped[i] = this->array[i + 1]; // Memcpy didnt work for this idk why
        free(this->array);
        this->array = popped;
    }

}