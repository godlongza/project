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
   // friend int drawcard();
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
	srand(time(0));
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

/*int drawcard() 
{
    
	int c= cards.front();
	card.erase(cards.begin());
	return c;
    
}*/

int drawcard(vector<int> & cards) 
{
    
	int c= cards.front();
	cards.erase(cards.begin());
	return c;
    
}

class dealer{
	vector<int>hand;
	vector<Player*>playerSet;
	card draws;

public:
	void setPlayerSet(vector<Player*>& playerSet);
	vector<Player*> getPlayerSet();
	void Draw2();
	int CheckHand();
	void draw();

};

void dealer::setPlayerSet(vector<Player*>& playerSet) {
	this->playerSet = playerSet;
}

vector<Player*> dealer::getPlayerSet() {
	return this->playerSet;
}

void dealer::draw() {
	this->hand.push_back(drawcard(draws.cards));
}
void dealer::Draw2() {
	//int collect;
	for(int i=0; i<2; i++){
	//	collect = drawcard(draws.cards);
		hand.push_back(drawcard(draws.cards));
	}

	for (auto p : this->playerSet) {
		p->draw();
		p->draw();
	}
}
int dealer::CheckHand() {
	int sum = 0;
	cout << "Dealer Hand:" << endl;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}