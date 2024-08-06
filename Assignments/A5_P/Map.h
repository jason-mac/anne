#ifndef MAP_H
#define MAP_H

template <class T> class Map {
private:
  constexpr static unsigned int BASE_CAPACITY = 13;
  unsigned int capacity = BASE_CAPACITY;
  T elements = nullptr;
  unsigned int elementCount = 0;

public:
  unsigned int hash(const T &element) const;
  void insert(const T &element);
  T &search(const T &element) const;
};

#endif
