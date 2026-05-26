//Itinerary Tickets 
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;
void printItinerary(unordered_map<string,string> tickets){
    //starting point
    unordered_set<string> to;

    for(pair<string,string> ticket:tickets){//from->to
        to.insert(ticket.second);
    }

    string start="";
    for(pair<string,string> ticket:tickets){
        if(to.find(ticket.first)==to.end()){//starting point   //not fount element
            start=ticket.first;
        }
    }

    //plan print
    cout<<start<<"->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"->";
        start=tickets[start];
    }
    cout<<endl;

}

int main(){
    unordered_map<string,string> tickets;//from->to 
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";

    printItinerary(tickets);

   //Mumbai->Delhi->Goa->Chennai->Bengaluru->
   return 0;
}