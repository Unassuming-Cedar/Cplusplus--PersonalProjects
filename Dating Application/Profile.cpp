#include "Profile.h"

Profile::Profile(){
    //Filling profile variables with data
    ReadFile();
    PersonAge = AgePopulator();
    PersonSex = SexPopulator();
    PersonName = NamePopulator();
    PersonOccupation = OccupationPopulator();
    PersonEducation = EducationPopulator();
    LikesProfileArrayPopulator();
    DislikesProfileArrayPopulator();
    DescArrayPopulator();
}

int Profile::AgePopulator(){
    int ageGenerator;

    //Generates Ages between 18 - 47
    ageGenerator = (rand() % MAX) + 18;
   
   return ageGenerator;
}

std::string Profile::SexPopulator(){
    int sexGenerator;
    std::string Sex;
    
    //Generates Male or Female sex
    sexGenerator = (rand() % 2);
    
    if(sexGenerator == true){
        Sex = "Male";
    }else{
        Sex = "Female";
    }
  
   return Sex;
}

void Profile::ReadFile(){
    std::ifstream fileStream;
    int counter = 0;
    
    std::string Likes = " ";
    std::string Dislikes = " ";
    std::string Edu = " ";
    std::string Names = " ";
    std::string Occupation = " ";
    std::string Description = " ";

    
    //Opening File
    fileStream.open("Likes.txt");

    //Reading in From Likes.txt
    while(getline(fileStream,Likes)){
        LikesArr[counter] = Likes;
        counter ++;
    }
    
    //closing file
    fileStream.close();

    //Resetting Counter Amount
    counter = 0;

    //Opening Dislikes.txt
    fileStream.open("Dislikes.txt");

    //Reading in From Dislikes.txt
    while (getline(fileStream,Dislikes)){
        DislikesArr[counter] = Dislikes;
        counter++;
    }

    fileStream.close();

    counter = 0;

    fileStream.open("Edu.txt");

    while (getline(fileStream,Edu)){
        EducationArr[counter] = Edu;
        counter++;
    }

    fileStream.close();
    
    counter = 0;

    //Opening Dislikes.txt
    fileStream.open("Occupation.txt");

    //Reading in From Dislikes.txt
    while (getline(fileStream,Occupation)){
        OccupationArr[counter] = Occupation;
        counter++;
    }

    fileStream.close();

    counter = 0;

    fileStream.open("Names.txt");

    while (getline(fileStream,Names)){
        NamesArr[counter] = Names;
        counter++;
    }
    
    fileStream.close();

    counter = 0;
    
    fileStream.open("Description.txt");

    //Reading in From Dislikes.txt
    while (getline(fileStream,Occupation)){
        DescriptionArr[counter] = Occupation;
        counter++;
    }

    fileStream.close();
}

std::string Profile::NamePopulator(){
    std::string NameFirst;
    std::string NameLast;
    std::string FullName;

    //Generates a first and last name
    int randName = (rand() % MAX);

    NameFirst = NamesArr[randName];

    int randLast = (rand() % MAX);
    NameLast = NamesArr[randLast];

    FullName = NameFirst + " " + NameLast;
    
   return FullName;
}

std::string Profile::OccupationPopulator(){
    std::string Job;

    //Random selects occupation
    int randOccu = (rand() % MAX);

    //Storing Job
    Job = OccupationArr[randOccu];
    
    return Job;

}

std::string Profile::EducationPopulator(){
     std::string Education;

    //Random selects occupation
    int randEdu = (rand() % 6);

    //Storing Job
    Education = EducationArr[randEdu];
    
    return Education;
}

std::string Profile::LikesPopulator(){
     std::string Likes;

    //Random selects occupation
    int randLike = (rand() % MAX);

    //Storing Job
    Likes = LikesArr[randLike];
    
    return Likes;
}

std::string Profile::DescPopulator(){
    std::string Desc;

    int Descselect = (rand() % MAX); 

    Desc = DescriptionArr[Descselect];

    return Desc;
}

void Profile::DescArrayPopulator(){
    for (int i = 0; i < Preferences; i++){
        PersonDesc[i] = DescPopulator();
    }

    return;
}

void Profile::LikesProfileArrayPopulator(){

    for (int i = 0; i < Preferences; i++){
        PersonLikes[i] = LikesPopulator();
    }

    return;
}

void Profile::DislikesProfileArrayPopulator(){

    for (int i = 0; i < Preferences; i++){
        PersonDislikes[i] = DislikesPopulator();
    }

    return;
}

std::string Profile::DislikesPopulator(){
     std::string DisLike;

    //Random selects occupation
    int randDisLike = (rand() % MAX);

    //Storing Job
    DisLike = DislikesArr[randDisLike];
    
    return DisLike;
}

std::ostream &operator<< (std::ostream &output, Profile &P){
    output<<"Name is: "<<P.PersonName<<'\n'
    <<"Sex is: "<<P.PersonSex<<'\n'
    <<"Age is: "<<P.PersonAge<<'\n'
    <<"Job: "<<P.PersonOccupation<<'\n'
    <<"Education: "<<P.PersonEducation<<'\n'
    <<"Description: \n"<<std::endl;

    for (int i = 0; i < Preferences; i++){
        std::cout<<P.PersonDesc[i]<<std::endl;
    }
    
    std::cout<<std::endl;

    std::cout<<"Likes are: \n"<<std::endl;

    for (int i = 0; i < Preferences; i++){
        std::cout<<'\t'<<P.PersonLikes[i]<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"Dislikes are: \n";
    for (int i = 0; i < Preferences; i++){
        std::cout<<'\t'<<P.PersonDislikes[i]<<std::endl;
    }

    return output;
}
