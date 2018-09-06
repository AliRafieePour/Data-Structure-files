#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class node
{
  public:
    int weight;
    char element;
    bool isleaf;
    node* left_child;
    node* right_child;
};


node* make_a_tree(node* a, node* b)
{
    node* temp=new node;
    temp->isleaf=false;
    temp->weight = a->weight + b->weight;
    temp->left_child=a;
    temp->right_child=b;
    return temp;
}


class MinHeap
{
private:
    vector<node*> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MinHeap(int* array, int length);
    MinHeap(const vector<int>& vector);
    MinHeap();

    int Size()
    {
        return _vector.size();
    }
    void Insert(node* newValue);
    node* GetMin();
    void DeleteMin();
};






//MinHeap::MinHeap(int* array, int length) : _vector(length)
//{
//    for(int i = 0; i < length; ++i)
//    {
//        _vector[i] = array[i];
//    }

//    Heapify();
//}

//MinHeap::MinHeap(const vector<int>& vector) : _vector(vector)
//{
//    Heapify();
//}

MinHeap::MinHeap()
{
}

//void MinHeap::Heapify()
//{
//    int length = _vector.size();
//    for(int i=length-1; i>=0; --i)
//    {
//        BubbleDown(i);
//    }
//}

void MinHeap::Heapify()
{
    int length = _vector.size();
    for(int i=length/2-1; i>=0; --i)
        BubbleDown(i);
}

void MinHeap::BubbleDown(int index)
{
    int length = _vector.size();
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    if(leftChildIndex >= length)
        return; //index is a leaf

    int minIndex = index;

    if(_vector[index]->weight > _vector[leftChildIndex]->weight)
    {
        minIndex = leftChildIndex;
    }

    if((rightChildIndex < length) && (_vector[minIndex]->weight > _vector[rightChildIndex]->weight))
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
        //need to swap
        node* temp = _vector[index];
        _vector[index] = _vector[minIndex];
        _vector[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

void MinHeap::BubbleUp(int index)
{
    if(index == 0)
        return;

    int parentIndex = (index-1)/2;

    if(_vector[parentIndex]->weight > _vector[index]->weight)
    {
        node* temp = _vector[parentIndex];
        _vector[parentIndex] = _vector[index];
        _vector[index] = temp;
        BubbleUp(parentIndex);
    }
}

//void MinHeap::Insert(int newValue)
//{
//    int length = _vector.size();
//    _vector[length] = newValue;
//    BubbleUp(length);
//}

void MinHeap::Insert(node* newValue)
{
    int length = _vector.size();
    _vector.push_back(newValue);
    BubbleUp(length);
}

node* MinHeap::GetMin()
{
    return _vector[0];
}

void MinHeap::DeleteMin()
{
    int length = _vector.size();

    if(length == 0)
    {
        return;
    }

    _vector[0] = _vector[length-1];
    _vector.pop_back();

    BubbleDown(0);
}


vector<int> code;
void print(node* root)
{
    if(root->isleaf==true)
    {
        cout<<root->element<<"  ";
        for (int i=0;i<code.size();++i)
        {
            cout<<code.at(i);
        }
        cout<<endl;
        return;
    }
    if (root->left_child!=NULL)
    {
        code.push_back(1);
        print(root->left_child);
        code.erase(code.begin()+code.size()-1);
    }
    if (root->right_child!=NULL)
    {
        code.push_back(0);
        print(root->right_child);
        code.erase(code.begin()+code.size()-1);
    }
}

int main()
{
    MinHeap MyHeap;
    //ye hip hast ke tosh ye araye darim to on araye hame chi mortab mishe, yaani kafie man biam ye
    //araye bedam be arayash khodesh hipesh mikoneh
    int Vaznha[26];
    for (int i=0;i<26;++i)
    {
        Vaznha[i]=0;
    }
    //inja avval file ro baz mikonam
    //ye string migiram az karbar baraye adresse jaii ke gharare file gharar dashte bashe
    //char Address[1000];
    //cin.getline(Address,1000);
//    ofstream MyFile ("data.txt");
//    MyFile<<"SALAM MAN ALAN DAR DANESHKADEH COMPUTER HASTAM VA DAR HAL ESHGH O HAL MIBASHAM";
//    if (!MyFile)
//    {
//        cout<<"error"<<endl;
//        terminate();
//    }
//    MyFile.close();

    //hala mikham done done karekter haro begiram va beshmaram
    char MyCharecter;
    bool CharSeen[26]; // 26 ta harfe englisi darim, mikham bebinam kollan che karekter haii toye file bode
    for(int i=0;i<26;++i)
    {
        CharSeen[i]=false;
        Vaznha[i]=0;
    }
    ifstream MyFile2 ("data.txt");
    if (!MyFile2)
    {
        cout<<"problem!"<<endl;
        terminate();
    }
    while (MyFile2 >> noskipws >> MyCharecter)
     {
         CharSeen[MyCharecter-65]=1;
         ++Vaznha[MyCharecter-65];
     }
     for (int i=0;i<26;++i)
     {
         if (CharSeen[i]==true)
         {
             node* temp=new node;
             temp->isleaf=true;
             temp->element=i+65; //az kod haye asci estefade kardam va ye rabete beyn andis arraye peyda kardam
             temp->weight=Vaznha[i];
             temp->left_child=NULL;
             temp->right_child=NULL;
             MyHeap.Insert(temp);

         }
     }
     //to marhale ghabl oomadam faghat node hara sakhtam hala to in marhale mikham beram derakht ro besazam
     for (int i=0;i<26;++i)
     {
         if (CharSeen[i]==true)
         {
             if (MyHeap.Size()!=1)
             {
                    //then we are done with our vector harr!
                    //we gotta get out of this loop
                    node* temp; // ye bar migiram node min ro zakhire mikonam
                    temp=MyHeap.GetMin();
                    MyHeap.DeleteMin();
                    node* temp2;// dobareh migiram node min ro zakhire mikonam
                    temp2=MyHeap.GetMin();
                    MyHeap.DeleteMin();
                    node* temp3;// baad miam vazn haye in do ta node ro ba ham jam mokonam va node jadid ro misazam isleaf ro false mikonam
                    temp3=make_a_tree(temp,temp2);
                    MyHeap.Insert(temp3);
             }
             else
             {
                 break;
             }
         }
     }
     print(MyHeap.GetMin());
    return 0;
}
