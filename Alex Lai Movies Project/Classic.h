//
//  Classic.h
//  MovieProject
//  Represents a movie of classic genre, uses dynamic casting.
//  Created by Alex Lai on 3/10/21.
//

#ifndef Classic_h
#define Classic_h
#include "Movie.h"
#include <cassert>

class Classic : public Movie {
public:
  Classic(int stock, string const &director, string const &title,
          const string &majorActorFirstName, const string &majorActorLastName,
          int year, int month)
      : Movie(stock, title, director, year, 'C') {
    this->majorActorFirstName = majorActorFirstName;
    this->majorActorLastName = majorActorLastName;
    this->month = month;
  }

  string getMajorActorFirstName() const { return this->majorActorFirstName; }

  string getMajorActorLastName() const { return this->majorActorLastName; }

  int getMonth() const { return month; }
  ostream &toString(ostream &os) const override {
    os << "Genre/Title: Classic, " + this->getTitle()
       << ", Director: " << this->getDirector()
       << ", Released: " << this->getYear()
       << " Major Actor: " << this->getMajorActorFirstName() << " "
       << this->getMajorActorLastName() << ", "
       << "Stock: " << this->getStock()
       << "  Currently being borrowed: " << this->getBorrowed();
    return os;
  }

  bool equals(Movie *other) const override {
    assert(other != nullptr);
    if (other->getType() != this->getType()) {
      return false;
    }
    auto *that = dynamic_cast<Classic *>(other);
    return this->getDirector() == that->getDirector() &&
           this->getTitle() == that->getTitle() &&
           this->getYear() == that->getYear() &&
           this->month == that->getMonth() &&
           this->getMajorActorFirstName() == that->getMajorActorFirstName() &&
           this->getMajorActorLastName() == that->getMajorActorLastName();
  }

  bool lessThan(Movie *other) const override {
    assert(other != nullptr);
    auto *that = dynamic_cast<Classic *>(other);
    // Lets sort by release year, release month, first name, then last name.
    if (this->getYear() != that->getYear()) {
      return this->getYear() < other->getYear();
    }
    if (this->getMonth() != that->getMonth()) {
      return this->getMonth() < that->getMonth();
    }
    if (this->getMajorActorFirstName() != that->getMajorActorFirstName()) {
      return this->getMajorActorFirstName() < that->getMajorActorFirstName();
    }
    if (this->getMajorActorLastName() != that->getMajorActorLastName()) {
      return this->getMajorActorLastName() < that->getMajorActorLastName();
    }
    return false;
  }

  bool greaterThan(Movie *other) const override {
    assert(other != nullptr);
    auto *that = dynamic_cast<Classic *>(other);
    // Lets sort by release year, release month, first name, then last name.
    if (this->getYear() != that->getYear()) {
      return this->getYear() > other->getYear();
    }
    if (this->getMonth() != that->getMonth()) {
      return this->getMonth() > that->getMonth();
    }
    if (this->getMajorActorFirstName() != that->getMajorActorFirstName()) {
      return this->getMajorActorFirstName() > that->getMajorActorFirstName();
    }
    if (this->getMajorActorLastName() != that->getMajorActorLastName()) {
      return this->getMajorActorLastName() > that->getMajorActorLastName();
    }
    return false;
  }

private:
  string majorActorFirstName;
  string majorActorLastName;
  int month;
};
#endif /* Classic_h */
