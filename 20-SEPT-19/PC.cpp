#include <iostream>
#include <pthread.h>
using namespace std;
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int counter = 0;

void producer()
{
    int nextProduced = 0;
    while (true)
    {
        if (counter == BUFFER_SIZE)
        {
            /* do nothing */
            return;
        }
        // cout << BUFFER_SIZE <<endl;
        // cout << "IN: " << in << "  Out: "<< out << "Counter: " << counter << endl;
        // cout << "The item to produced next: " << endl;
        // cin >> nextProduced;
        nextProduced++;
        buffer[in] = nextProduced;
        in = (in + 1) % BUFFER_SIZE;
        counter++;
        cout << "Producing the item: " << nextProduced << endl;
    }
}

void consumer()
{
    int nextConsumed;
    while (true)
    {
        if(counter == 0)
        {
            return; 
            /* do nothing */
        }
        // cout << "IN: " << in << "  Out: "<< out << endl;
        nextConsumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        counter--;
        cout << "Consuming the item: " << nextConsumed << endl;
    }
}

int main()
{
    producer();
    // cout << "IN: " << in << "  Out: "<< out << endl;
    consumer();
    return 0;
}