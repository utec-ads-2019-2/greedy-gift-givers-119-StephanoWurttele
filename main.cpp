#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class person{
	public:
	string nombre;
	int money=0;
	public:
	person(string temp):nombre(temp){};
};




int main(){
	int NumPeople;
	vector<person> participants;
	string temp;
	int spend,distribute;
	bool flag=false;
	while(cin>>NumPeople){
		if(flag)
			cout<<endl;
		flag=true;
		for(int i=0;i<NumPeople;i++){
			cin>>temp;
			person now(temp);
			participants.push_back(now);
		}
		for(int i=0;i<NumPeople;i++){
			cin>>temp>>spend>>distribute;
			if(distribute==0)
				continue;
			for (int j=0;j<NumPeople;j++){
           			if (participants[j].nombre==temp){
               				participants[j].money-=spend;
					participants[j].money+=spend%distribute;
				}
			}
			for(int j=0;j<distribute;j++){
				cin>>temp;
				if(spend==0)
					continue;
				for (int j=0;j<NumPeople;j++){
           				if (participants[j].nombre==temp){
						participants[j].money+=spend/distribute;
					}
				}
			}
		}
		for(int i=0;i<NumPeople;i++)
			cout<<participants[i].nombre<<" "<<participants[i].money<<endl;
		participants.clear();
	}
	
	return 0;

}
