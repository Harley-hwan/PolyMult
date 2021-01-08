#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class PolyNode    //define data type(structure)
{
public:
   int coef;
   int expo;
   PolyNode* next;
};

class PolyLinkedList //Liked list using node.
{
public:
//    PolyNode *LinkHead;
    vector<PolyNode*> LinkHeads;

    PolyLinkedList()
    {   }
    void addNode2First(int coef, int expo, int n)
    {
        PolyNode *tmp = new PolyNode();
        tmp->coef = coef;
        tmp->expo = expo;

        if(n >= LinkHeads.size()){
            LinkHeads.push_back(tmp);
            tmp->next = NULL;
        }
        else{
            tmp->next = LinkHeads[n];
        }
        
        LinkHeads[n] = tmp;
    }

    void PrintList(int n)
    {

        PolyNode* tmpPoint = LinkHeads[n];

        cout<<"\n Linked List -> ";
        while(tmpPoint->next != NULL)
        {
            cout<<tmpPoint->coef<<","<<tmpPoint->expo <<"->";
            tmpPoint = tmpPoint->next;
        }
        cout<<tmpPoint->coef<<","<<tmpPoint->expo<<endl;
    }
    
    void sum(int n)
    {
        map< int, int > result;

        PolyNode *tmpPoint = LinkHeads[n];

        while(tmpPoint->next != NULL)
        {
            int coef = tmpPoint->coef;
            int expo = tmpPoint->expo;
            
            if(result.count(expo)==0)
            {
                result.insert(make_pair(expo, coef));
            }
            else
            {
                result[expo] += coef;
            }
            
            tmpPoint = tmpPoint->next;
        }
        
        int coef = tmpPoint->coef;
        int expo = tmpPoint->expo;
        
        if(result.count(expo)==0)
        {
            result.insert(make_pair(expo, coef));
        }
        else
        {
            result[expo] += coef;
        }
        
        // result`
        
        vector<pair<int, int> > pairs;
        for (map< int, int >::iterator itr = result.begin(); itr != result.end(); ++itr)
        {
            if(itr->second!=0)
            {
                pairs.push_back(*itr);
            }
        }
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());

        cout << pairs.size() << endl;

        for (vector<pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end(); ++itr){
            cout << itr->second << " " << itr -> first <<"\n"; 
        }
    }

    void polymult(){
        map< int, int > result;
        map< int, int > result2;

        PolyNode *tmpPoint1 = LinkHeads[0];
        PolyNode *tmpPoint2 = LinkHeads[1];

        while(tmpPoint1->next != NULL)
        {
            while(tmpPoint2->next !=NULL){ 
                int coef = tmpPoint1->coef * tmpPoint2->coef;
                int expo = tmpPoint1->expo + tmpPoint2->expo;

                if(result.count(expo)==0)
                {
                    result.insert(make_pair(expo, coef));
                }
                else
                {
                    result[expo] += coef;
                }
                tmpPoint2 = tmpPoint2->next;
            }
            int coef = tmpPoint1->coef * tmpPoint2->coef;
            int expo = tmpPoint1->expo + tmpPoint2->expo;

            if(result.count(expo)==0)
            {
                result.insert(make_pair(expo, coef));
            }
            else
            {
                result[expo] += coef;
            }
            tmpPoint2 = LinkHeads[1];
            tmpPoint1 = tmpPoint1->next;

        }
        while(tmpPoint2->next !=NULL){ 
            int coef = tmpPoint1->coef * tmpPoint2->coef;
            int expo = tmpPoint1->expo + tmpPoint2->expo;

            if(result.count(expo)==0)
            {
                result.insert(make_pair(expo, coef));
            }
            else
            {
                result[expo] += coef;
            }
            tmpPoint2 = tmpPoint2->next;
        }
        int coef = tmpPoint1->coef * tmpPoint2->coef;
        int expo = tmpPoint1->expo + tmpPoint2->expo;

        if(result.count(expo)==0)
        {
            result.insert(make_pair(expo, coef));
        }
        else
        {
            result[expo] += coef;
        }
    
        for(int i = 2; i < LinkHeads.size(); i++){
            for (map< int, int >::iterator itr = result.begin(); itr != result.end(); ++itr)
            {
                tmpPoint2 = LinkHeads[i];
                while(tmpPoint2->next !=NULL){ 
                    int coef = itr->second * tmpPoint2->coef;
                    int expo = itr->first + tmpPoint2->expo;

                    if(result2.count(expo)==0)
                    {
                        result2.insert(make_pair(expo, coef));
                    }
                    else
                    {
                        result2[expo] += coef;
                    }
                    tmpPoint2 = tmpPoint2->next;
                }
                int coef = itr->second * tmpPoint2->coef;
                int expo = itr->first + tmpPoint2->expo;

                if(result2.count(expo)==0)
                {
                    result2.insert(make_pair(expo, coef));
                }
                else
                {
                    result2[expo] += coef;
                }        
            }
            result = result2;
            map< int, int > result3;
            result2 = result3;
        }
        // result
        
        vector<pair<int, int> > pairs;
        for (map< int, int >::iterator itr = result.begin(); itr != result.end(); ++itr)
        {
            if(itr->second!=0)
            {
                pairs.push_back(*itr);
            }
        }
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());

        cout << pairs.size() << endl;


        for (vector<pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end(); ++itr){
            cout << itr->second << " " << itr -> first <<"\n"; 
        }
    }
};

void readFile(PolyLinkedList *polymult, string fName)
{
    int coef, expo, noTerm, N;

    ifstream inFile(fName.data());

    if(inFile.is_open())
    {
        inFile >> N;

        for(int i=0; i<N; i++)
        {
            inFile >> noTerm;

            for(int j=0; j < noTerm; j++)
            {
                inFile >> coef; inFile >> expo;
                polymult->addNode2First(coef, expo, i);
            }
        }  
    }
    inFile.close();
}

void Input(PolyLinkedList *polyadd){
    int coef, expo, noTerm, N;
    cin>>N;

    for(int i=0; i<N; i++)
    {
        cin>>noTerm;

        for(int j=0; j < noTerm; j++)
        {
            cin>>coef; cin>>expo;
            polyadd->addNode2First(coef, expo, i);
        }
    }
}
int main()
{
    PolyLinkedList *a = new PolyLinkedList();

//  readFile(a, "10.inp");
    Input(a);
    a->polymult();
    return 0;
}