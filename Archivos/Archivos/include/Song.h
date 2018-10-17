#ifndef SONG_H
#define SONG_H
#include<ostream>
#include <string>
#include <sstream>
#include <iostream>



using namespace std;

class Song
{
    public:
        Song();
        Song(const string& linea);
        virtual ~Song();
        string getAuthor() const;
        void setAuthor(const string &value);

        void setTitle(const string &value);
        string getTitle()const;

        int getYear()const;
        void setYear(int value);

        unsigned int getDuration() const;
        void setDuration(unsigned int value);

        friend ostream& operator <<(ostream& os, const Song& obj);

    protected:

    private:
        string title;
        string author;
        int year;
        unsigned int duration;
};

#endif // SONG_H
