#include "Profile.h"
#include <typeinfo>

int main(){
    srand (time(NULL));
    std::stack<Profile> DatingList;
    std::stack<Profile> AcceptedList;

    std::string swipe;
    std::string newline(5, '\n'); 
    std::string FinalChoice;
    int NumProfiles = 0;
    
   
    std::cout<<"Welcome to the Dating Application!"<<'\n'
    <<"How many profiles would you like to view?"<<std::endl;
        
    std::cin>>NumProfiles; 
        
    for(int i = 0; i < NumProfiles; i++){
        Profile Date;
        DatingList.push(Date);
    }

        
   while(DatingList.size() != 0){     
        std::cout<<DatingList.top();

        std::cout<<std::endl;
        
        std::cout<<"Do you like this profile?\nIf so type: \"Yes\""<<std::endl;
        std::cin>>swipe;
        for(auto& x:swipe){
            x = tolower(x);
        }

        if (swipe == "yes"){
            AcceptedList.push(DatingList.top());
        }

        std::cin.clear();
        
        std::cout << newline<<std::endl;

        DatingList.pop();
   }

    std::cout<<"Number of Profiles liked: "<<AcceptedList.size()<<std::endl;
    std::cout<<"Would you like to display all profiles liked ? "<<AcceptedList.size()<<std::endl;

    std::cin.clear();
    std::cin>>FinalChoice;
    for(auto& x:FinalChoice){
            x = tolower(x);
        }

        if (FinalChoice == "yes"){
            std::cout<<"Displaying all liked profiles"<<std::endl;
            while(AcceptedList.size() != 0){
                std::cout<<AcceptedList.top()<<std::endl;
                std::cout<<newline<<std::endl;
                AcceptedList.pop();
            }
        }

    std::cout<<"Thank you for utilizing the dating application!"<<std::endl;
    return 0;
}