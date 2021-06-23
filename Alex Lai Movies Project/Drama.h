//
//  Drama.h
//  MovieProject
//. Represents a movie of drama genre.
//  Created by Alex Lai on 3/10/21.
//

#ifndef Drama_h
#define Drama_h

#include "Movie.h"

class Drama : public Movie {
public:
  Drama(int stock, const string &director, const string &title, int year)
      : Movie(stock, title, director, year, 'D') {}

  ostream &toString(ostream &os) const override {
    os << "Genre/Title: Drama, " + this->getTitle()
       << ", Director: " << this->getDirector()
       << ", Released: " << this->getYear() << ", Stock: " << this->getStock()
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
    // In drama, we first sort by director
    if (this->getDirector() != other->getDirector()) {
      return this->getDirector() < other->getDirector();
    }
    // Then sort by title
    if (this->getTitle() != other->getTitle()) {
      return this->getTitle() < other->getTitle();
    }
    // If somehow it still doesn't pass, just return false, they're probably the
    // same.
    return false;
  }

  bool greaterThan(Movie *other) const override {
    // In drama, we first sort by director
    if (this->getDirector() != other->getDirector()) {
      return this->getDirector() > other->getDirector();
    }
    // Then sort by title
    if (this->getTitle() != other->getTitle()) {
      return this->getTitle() > other->getTitle();
    }
    // If somehow it still doesn't pass, just return false, they're probably the
    // same.
    return false;
  }
};

#endif /* Drama_h */
