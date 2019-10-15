/*
Student Name: Fikri Cem
Student Number: Yilmaz
Project Number: 1
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include "Restaurant.h"

using namespace std;

void Restaurant::execute(const vector<string>& operations) {
    for (const string& op : operations){
        cout << "Operation: " << op << "\t";
		/* YOU NEED TO IMPLEMENT THIS PART */
		if(op == "N"){
		    for(Table& tab: tables){
		        if(!tab.isOccupied()){
		            tab.occupy();
                    break;
		        }
		    }
		}
		else if(op == "S"){
		    vector<Table> temp;
		    Table& tb = tables.back();
		    while(tb.isOccupied()){
		        temp.push_back(tb);
		        tables.pop_back();
		        tb = tables.back();
		    }
		    tb.occupy();
		    tables.pop_back();
		    tables.push_back(tb);
		    while(temp.size()!=0){
		        Table &adding = temp.back();
		        adding.occupy();
		        tables.push_back(adding);
		        temp.pop_back();
		    }
		}
		else{
		    int n;
		    n = stoi(op);
		    tables[n-1].empty();
		}

        cout << "State: " << *this << endl;
    }
}

Restaurant::Restaurant(unsigned int N)
	: tables{N}
{
    cout << "-Starting- \tState: " << *this << endl;
}

ostream &operator<<(ostream &out, Restaurant &restaurant) {
    for (Table table : restaurant.tables) {
        out << table.isOccupied();
    }
	return out;
}

