/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan, @co-author Alex Lai
 * @date 15 Mar 2021
 */
#include "Classic.h"
#include "Comedy.h"
#include "Customer.h"
#include "Drama.h"
#include "HashTable.h"
#include "Inventory.h"
#include "Movie.h"
#include "Store.h"
#include "Transaction.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void testAllMovies() {
  cout << "Start testAlLMovies" << endl;
  // Comedy tests
  Comedy f(10, "Michael Moore", "Fahrenheit 911", 2001);
  Comedy f2(10, "Michael Moore", "Fahrenheit 911", 2001);
  Comedy f3(15, "Moore Michael", "Fahrenheit 451", 1995);
  assert(f.getStock() == 10);
  assert(f.getDirector() == "Michael Moore");
  assert(f.getTitle() == "Fahrenheit 911");
  assert(f.getYear() == 2001);
  assert(f == f2);
  assert(!(f == f3));
  assert(f > f3);
  assert(f3 < f);
  // Drama tests
  Drama hamilton(3, "Thomas Kail", "Hamilton", 2020);
  Drama d(1, "Steven Caple Jr", "Creed II", 2018);
  d.setStock(213);
  assert(d.getStock() == 213);
  assert(!(hamilton == d));
  assert(d.getDirector() == "Steven Caple Jr");
  assert(d.getTitle() == "Creed II");
  assert(d.getYear() == 2018);
  assert(hamilton > d);
  // Classic tests
  Classic c(3, "Toru Hara", "My Neighbor Totoro", "satsuke", "mei", 1993, 5);
  assert(c.getStock() == 3);
  assert(c.getDirector() == "Toru Hara");
  assert(c.getMajorActorFirstName() == "satsuke");
  assert(c.getMajorActorLastName() == "mei");
  assert(c.getMonth() == 5);
  assert(c.getYear() == 1993);
  Classic shrek(5, "Andrew Adamson", "Shrek", "Shrek", "the Ogre", 2001, 4);
  assert(!(shrek == c));
  assert(shrek == shrek);
  assert(c < shrek);
  assert(shrek > c);
  cout << "End test" << endl;
}

void testHashTable() {
  cout << "Start testHashTable" << endl;
  HashTable<int, string> h;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  string sone = "one";
  string stwo = "two";
  string sthree = "three";
  string sfour = "four";
  h.put(one, sone);
  h.put(two, stwo);
  h.put(three, sthree);
  h.put(four, sfour);
  assert(h.get(one) == "one");
  assert(h.get(two) == "two");
  assert(h.indexOf(one) == 0);
  h.remove(four);
  assert(h.indexOf(four) == -1);
  h.clear();
  assert(h.isEmpty() == true);
  cout << "End testHashTable" << endl;
}

void testCustomers() {
  cout << "Start testCustomers" << endl;
  Customer *c = new Customer("OLD", "BOOMER", 0000);
  c->borrowMovie('C', 1);
  assert(c->getCustomerID() == 0000);
  assert(c->getLastName() == "BOOMER");
  assert(c->getFirstName() == "OLD");
  assert(c->isCurrentlyBorrowing('C', 1) == true);
  c->returnMovie('C', 1);
  assert(c->isCurrentlyBorrowing('C', 1) == false);
  cout << "End testCustomers" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store s;
  s.fillStoreWithCustomers("data4customers.txt");
  s.fillInventory("data4movies.txt");
  s.processTransactions("data4commands.txt");
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void pisanTest() {
  cout << "Start pisanTest" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End pisanTest" << endl;
}
void testAll() {
  testAllMovies();
  testCustomers();
  testHashTable();
  testStoreFinal();
  pisanTest();
}
