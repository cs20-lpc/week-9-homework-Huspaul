template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    maxSize = i;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = maxSize - 1;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) throw string("back: error, queue is empty, cannot access the back");
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    this->length = copyObj.length;
    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) throw string("dequeue: error, queue is empty, cannot dequeue");
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) throw string("enqueue: error, queue is full, cannot enqueue");
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) throw string("front: error, queue is empty, cannot access the front");
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
