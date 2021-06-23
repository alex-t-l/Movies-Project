//
//  Store.h
//  MovieProject
//  Store that holds the customers, and movie shelves (in Inventory.)
//  Created by Alex Lai on 3/12/21.
//

#ifndef Store_h
#define Store_h

#include "Customer.h"
#include "HashTable.h"
#include "Inventory.h"
#include "Movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Store {
public:
  Store();

  void fillInventory(const string &fileName);
  void fillStoreWithCustomers(const string &fileName);
  void processTransactions(const string &fileName);

private:
  HashTable<int, Customer *> customers;
  Inventory *movies;
};
#endif /* Store_h */
