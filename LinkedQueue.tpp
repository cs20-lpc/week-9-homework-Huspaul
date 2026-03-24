template <typename T>
LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Cannot access back of empty queue");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    this->length = 0;

    Node* curr = copyObj.head;
    while (curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Cannot dequeue from empty queue");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;

    if (isEmpty()) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* n = new Node(elem);

    if (isEmpty()) {
        head = n;
        last = n;
    }
    else {
        last->next = n;
        last = n;
    }

    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Cannot access front of empty queue");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
