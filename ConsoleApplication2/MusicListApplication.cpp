
#include <thread>
#include <chrono>       

#include <algorithm>    
#include <vector>
#include <string>
#include <iostream>


class Music {

private: 

    std::string id;                                                       // var for store id in previous Music List
    int time;                                                             // var for store time playing, to know how long wait for next select
    std::string name;                                                     // var for store name of playing song

public:

    Music(std::string n, std::string i, int t = 1000) {
        name = n;
        id = i;
        time = t;
    }

    Music() {
        name = "";
        id = "";
        time = 0;
    }

    std::string getName() { return name; }
    std::string getId() { return id; }
    int getTime() { return time; }
};


int main()
{
    int numberOfMusic;                                                      // vareble to store number of Music object 

    std::vector <Music> playList1;
    std::vector <Music>::iterator playListIterator;
    std::vector <std::string> previousMusicList;
    std::vector <std::string>::iterator previousMusicIterator;
    
    srand((unsigned)time(0));                                               //function using current time as seed for pseudo-random number generator 
    int pseudorandomNumber;                                             

    std::cout << "Input int character: ";
    std::cin >> numberOfMusic;                                               //input from keybord number of Music objects

    while (std::cin.fail()) {                                                //work while you put the correct character
        std::cout << "Error, input character must be int!" << std::endl;
        std::cin.clear();                                               
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');  // to ignores the characters equal to maximum size of stream or until a '\n' is encountered
        std::cout << "Input int character: ";
        std::cin >> numberOfMusic;
    }
    

  for(int i=0; i <= numberOfMusic; ++i){                                    //loop for create Music object and put it in the vector
      std::string id = std::to_string(i);
      std::string name = "Music" + std::to_string(i);
  
      Music musicOb =  Music(name,id);
      playList1.push_back(musicOb);  
  }
  

  for (playListIterator = playList1.begin(); playList1.size() != previousMusicList.size();)
  {
      pseudorandomNumber = (rand() % (numberOfMusic+1)) + 0;             //create diffrent sequence of pseudo-random numbers in the range of 0 to numberOfMusic on every program run
      playListIterator = playList1.begin() + pseudorandomNumber;         //set iterator on pseudo-random number

      previousMusicIterator = find(previousMusicList.begin(), previousMusicList.end(), std::to_string(pseudorandomNumber));
                                                                     
      if (previousMusicIterator != previousMusicList.end()) {
      
      }
      else {
        std::cout <<"Now Playing: "<< playListIterator->getName() << std::endl;                 //show the name of current play music
        previousMusicList.push_back(playListIterator->getId());                                 
        std::this_thread::sleep_for(std::chrono::milliseconds(playListIterator->getTime()));    //waits until the music time runs out
      } 
  }

  std::cout << std::endl << "You listened to the entire playlist."<<std::endl;
}


