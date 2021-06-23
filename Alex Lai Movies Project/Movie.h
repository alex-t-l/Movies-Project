//
//  Movie.h
//  MovieProject
//  Represents a unique movie object, and its stock.
//  Created by Alex Lai on 3/9/21.
//

#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

class Movie {
  friend ostream &operator<<(ostream &os, const Movie &rhs) {
    return rhs.toString(os);
  }

public:
  Movie(int stock, const string &title, const string &director, int year,
        char type) {
    this->stock = stock;
    this->title = title;
    this->director = director;
    this->borrowed = 0;
    this->year = year;
    this->type = type;
  }

  void setDirector(const string &director) { this->director = director; }

  void setTitle(const string &title) { this->title = title; }

  void setYear(int year) { this->year = year; }

  void setStock(int stock) { this->stock = stock; }

  void setBorrowed(int num) { this->borrowed = num; }

  string getDirector() const { return this->director; }

  string getTitle() const { return this->title; }

  int getYear() const { return this->year; }

  int getStock() const { return this->stock; }

  int getBorrowed() const { return this->borrowed; }

  char getType() const { return this->type; }

  // Function for printing out the information about the movie.
  virtual ostream &toString(ostream &os) const = 0;
  bool operator==(Movie &other) const { return equals(&other); }

  bool operator<(Movie &other) const { return lessThan(&other); }

  bool operator>(Movie &other) const { return greaterThan(&other); }

  virtual bool equals(Movie *other) const = 0;
  virtual bool lessThan(Movie *other) const = 0;
  virtual bool greaterThan(Movie *other) const = 0;

protected:
  string director;
  string title;
  int year;
  int stock;
  int borrowed = 0; // How many people are borrowing this movie right now.
  char type;
};

#endif /* Movie_h */
