//Linear probing with chaining without replacement.
#include <iostream>
#define MAX 5 //DefiningMax value as 5
#define key 5 //Defining HashKey as 5
using namespace std;
class hashing
{
    int data[MAX], chain[MAX];
    bool flag[MAX];

public:
    hashing();
    void insert();
    void display();
    void search();
    void del();
};
hashing::hashing()
{
    // Initialising the values in an array as default
    for (int i = 0; i < MAX; i++)
    {
        flag[i] = false;
        chain[i] = -1;
        data[i] = -1;
    }
}
void hashing::insert()
{
    int x, loc, i = 0, last = -1;
    cout << "\nEnter Element To be inserted ";
    cin >> x;
    loc = x % key;
    if (flag[loc] == false) // If the found location is empty then directly insert
    {
        data[loc] = x;
        flag[loc] = true;
    }
    else
    {
        while (flag[loc] != false && i < MAX) // Found the empty location to insert
        {
            if (data[loc] % key == x % key && chain[loc] == -1) // maintaining the last count for chaining the same group element
                {
                    last = loc;
                }
            loc = (loc + 1) % key;
            i++;
        }
        if (i == MAX) // If it has reached end of table then return
        {
            cout << "\n Hash Table is Full ";
            return;
        }
        // Inserting the elements in an array
        data[loc] = x;
        flag[loc] = true;
        if (last != -1)
            chain[last] = loc;
    }
}
void hashing::display()
{
    cout << "\nData\tIndex\tChain" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << data[i] << "\t " << i << "\t" << chain[i] << endl;
    }
}
void hashing::search()
{
    int temp, found = 0, ctr = 0;
    cout << "\n Enter Item to be searched : ";
    cin >> temp;
    int loc = temp % key;
    while (data[loc] != temp) // Loops run till it find the elements
    {
        if (chain[loc] == -1) // If at any point chain is -1, then it breaks the loop
        {
            found = 1;
            break;
        }
        else
            loc = chain[loc];
        // Continuing the chain and checking simultaneously
        ctr++;
    }
    cout << "\n Element found in " << ctr << " steps " << endl;
    if (found == 0)
        cout << "\n\tElement Found ";
    else
        cout << "\n\tNot Found ";
}
void hashing::del()
{
    int temp, loc, i = 0, start, found = 0;
    cout << "\nEnter Item to be deleted : ";
    cin >> temp;
    loc = temp % key;
    if (data[loc] == temp) // Checking if the hashed location has that element
    {
        cout << "\n Element " << data[loc] << " deleted " << endl;
        data[loc] = -1;
        flag[loc] = false;
        chain[loc] = -1;
    }
    else
    {
        while (data[loc] != temp && i < MAX) // we find the element using loop
        {
            if (chain[loc] == -1)
            {
                found = 1;
                break;
            }
            else
            {
                start = loc;
                loc = chain[loc];
            }
            while (data[loc] != temp && i < MAX) // we find the element using
                if (chain[loc] == -1)
                {
                    found = 1;
                    break;
                }
            i++;
        }
        if (found == 0)
        // If it is found, we delete and maintain the chain
        {
            cout << "\n Element " << data[loc] << " deleted " << endl;
            chain[start] = chain[loc];
            data[loc] = -11111;
            flag[loc] = false;
            chain[loc] = -1;
        }
        else
            cout << "\n Element Not found " << endl;
    }
}
int main()
{
    hashing obj;
    int choice,n;
    do
    {
        cout<<"\n---------------------------------------------------------------------------";
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit ";
        cout<<"\n---------------------------------------------------------------------------";     
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"\nEnter the number of elements to be inserted: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    obj.insert(); 
                } 
                break;
        
            case 2:
                obj.search();
                break;

            case 3:
                obj.del();
                break;

            case 4:
                obj.display();
                break;
        }
    } while (choice != 5);
}
