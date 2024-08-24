#pragma once

//Including Libraries

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <fStream>

//Upper bound for values
const int MAX  = 30;

//The max amount of Profile choices that will be displayed
const int Preferences = 5;


class Profile{
    public:
    
    //Variables
    int PersonAge;
    std::string PersonSex;

    std::string PersonName;
    std::string PersonOccupation;
    std::string PersonEducation;

    //Array Declarations
    std::string PersonLikes[Preferences];
    std::string PersonDislikes[Preferences];
    std::string PersonDesc[Preferences];

    //Declaring Array for Likes
    std::string LikesArr[MAX];

    std::string LikesProfArray[Preferences];

    std::string DislikesProfArray[Preferences];

    //Declaring Array for Dislikes
    std::string DislikesArr[MAX];

    //Declaring Array for Education
    std::string EducationArr[MAX];

    //Declaring Array for Names
    std::string NamesArr[MAX];

    //Declaring Array for Occupation
    std::string OccupationArr[MAX];

    //Declaring Array for Description
    std::string DescriptionArr[MAX];

    std::string DescriptionArray[Preferences];
    
    //Default Constructor
    Profile();
    
    //Overloaded Constructor
    Profile(int age, bool sex, std::string name,std::string job,
    std::string edu,std::string likes,std::string dislikes);

    //Assigns Age value to profile
    int AgePopulator();

    //Assigns Sex to profile
    std::string SexPopulator();

    //Assigns name to profile
    std::string NamePopulator();

    //Reads in Files
    void ReadFile();
    
    //Assigns Occupation to Profile
    std::string OccupationPopulator();

    //Assigns Education to Profile
    std::string EducationPopulator();
        
    //Populates Likes with things profile likes
    std::string LikesPopulator();

    //Populates description with randomly selected input
    std::string DescPopulator();
    
    //Populates Profile like Array
    void LikesProfileArrayPopulator();

    //Populates Profile Dislike Array
    void DislikesProfileArrayPopulator();

    //Populates Profile description Array
    void DescArrayPopulator();
    
    //Populates Dislikes with things profile dislikes
    std::string DislikesPopulator();

    //Overloaded Insertion Operator
    friend std::ostream &operator<< (std::ostream &output, Profile &P);
};