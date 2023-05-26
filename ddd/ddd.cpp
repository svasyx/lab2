
#define MAX_SIZE 100
#define FU
#include "Node.h"
#include "List.h"

using namespace::std;


int main()
{
    char* buff = new char[255];
    char* nextbuff = new char[255];
    strcpy(buff, "list1");
    strcpy(nextbuff, "list 2 _ 1");
    List list;
    List list2;
    list.SetNew(buff);
    list2.SetNew(nextbuff);
   // list.Print();
    list + list2;
    list.Print();

    cout << "!!!!!!!!!!!!!!" << endl;
    list2 = list;

    list2.Print();
    cout << "!!!!!!!!!!!!!!" << endl;

    cout << (list == list2) << endl;

    list2.SetInput();
    list2.Print();

    return 0;
}


