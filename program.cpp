#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song {
    public:
    string name;
    int min, sec;
    
    Song(string n = "", string length = "0:00"){
        name = n;
        sec = stoi(length.substr(length.size()-2));
        min = stoi(length.substr(0, length.size()- 3));
    }
    Song operator+(Song const& s2){
        Song result;
        if( (this->sec + s2.sec) >= 60){
            result.sec = this->sec + s2.sec - 60;
            result.min = this->min + s2.min + 1;
        }
        else{
            result.sec = this->sec + s2.sec;
            result.min = this->min + s2.min;
        }
        return result;
    }
    bool operator>(Song const& s2){
        if(this->min == s2.min) return this->sec > s2.sec;
        return this->min > s2.min;
    }
};

int main(){
    cout << "Welcome to Grant's Cassette maker!\n Please enter track information and press q when done";
    string name;
    string l;
    Song counterSong;
    Song currentSong;
    cout << "\n-----SIDE A-----";
    while(true){
        cout << "Track name (q to finish): ";
        cin.ignore();
        getline(cin, name);
        if(name == "q") break;
        cout << "Track length: ";
        cin >> l;
        currentSong = Song(name, l);
        if((counterSong + currentSong) > Song("", "30:00")){
            cout << "\nSIDE A LENGTH: " << counterSong.min << ":" << counterSong.sec << endl;
            //cout << "\nEMPTY SPACE: " << 30-counterSong.min << ":" << 
            cout << "\n-----SIDE B-----\n";
            counterSong = Song();
        }
        counterSong = counterSong + currentSong;
        //cout << counterSong.min << " " << counterSong.sec << "\n";
        cout << counterSong.min << ":" << counterSong.sec << endl;
    }
    return 1;
    //Add file reading
    //Add error handling for input
    //Add Side b length info
    //add message for if tape is too long
}