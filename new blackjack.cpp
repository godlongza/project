#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
class card
{
int A = 1;
int J = 10;
int Q = 10;
int K = 10;
public:
    int round=1;
    vector<int> cards;
   
    void allcard();
    void shuffler();
    void showcards();
    int  getcard();
    void drawcard(vector<int> &);
    bool cardempty();
    
};
void card::allcard()
{       
    cards = {A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K,
             A,2,3,4,5,6,7,8,9,10,J,Q,K, 
             A,2,3,4,5,6,7,8,9,10,J,Q,K};
    
           
           
}
void card::shuffler() {
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++) 
    { 
        swap(cards[i], cards[rand() % 52]);
	    cout << " Deck Shuffled!******" << endl;
    }
}
void card::showcards() 
{
	cout << "card:" << endl;
	for (int i=0;i<round;i++)
     {
		cout << this->cards << " ,";
	 }
}
bool card:: cardempty()
{
    return cards.empty();
}
void card:: drawcard(vector<int> &cards)
{
 
            cards.push_back(rand()%52);
            
}
int card::getcard() {
    
	int c= cards.front();
	cards.erase(cards.begin());
	return c;
    s
}