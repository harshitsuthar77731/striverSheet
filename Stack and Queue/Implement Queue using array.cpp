void MyQueue :: push(int x)
{
    arr[rear] = x;
    rear++;
        // Your Code
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(rear==front)
        return -1;
    int temp = arr[front];
    front++;
    return temp;
        // Your Code       
}
