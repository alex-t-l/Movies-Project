//
//  Comedy.h
//  MovieProject
//  Represents a movie of comedy genre.
//  Created by Alex Lai on 3/9/21.
//

#ifndef Comedy_h
#define Comedy_h

#include "Movie.h"

class Comedy : public Movie {
public:
  Comedy(int stock, const string &director, const string &title, int year)
      : Movie(stock, title, director, year, 'F') {}

  ostream &toString(ostream &os) const override {
    os << "Genre/Title: Comedy, " << this->getTitle()
       << ", Director: " << this->getDirector()
       << ", Released: " << this->getYear() << " , Stock: " << this->getStock()
       << " Currently being borrowed: " << this->getBorrowed();
    return os;
    // Some nice sstream code from Geeks4Geeks.
  }

  bool equals(Movie *other) const override {
    return this->type == other->getType() &&
           this->getDirector() == other->getDirector() &&
           this->getTitle() == other->getTitle() &&
           this->getYear() == other->getYear();
  }

  bool lessThan(Movie *other) const override {
    // In comedy, we first sort by title, if the titles are the same..
    if (this->getTitle() != other->getTitle()) {
      return this->getTitle() < other->getTitle();
    }
    // Then we'll instead sort by year.
    if (this->getYear() != other->getYear()) {
      return this->getYear() < other->getYear();
    }
    // If somehow it still doesn't pass, just return false, they're probably the
    // same.
    return false;
  }

  bool greaterThan(Movie *other) const override {
    // In comedy, we first sort by title, if the titles are the same..
    if (this->getTitle() != other->getTitle()) {
      return this->getTitle() > other->getTitle();
    }
    // Then we'll instead sort by year.
    if (this->getYear() != other->getYear()) {
      return this->getYear() > other->getYear();
    }
    // If somehow it still doesn't pass, just return false, they're probably the
    // same.
    return false;
  }
};
#endif /* Comedy_h */
