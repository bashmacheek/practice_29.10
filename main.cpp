#include <iostream>
#include <cstddef>

struct int_view {
  int_view();
  int_view(int* b, size_t size);
  int_view(int* b, int* e);
  int_view sub_view(size_t start) const;
  int_view end_view(size_t end) const;
  int_view sub_view(size_t start, size_t end) const;

  size_t get_size() const;
  int get(size_t id) const;

  private : 
    int* begin;
    size_t size;
};

int int_view::get(size_t id) const
{
  return begin[id];
}

int_view int_view::sub_view(size_t start) const
{
    if (start > size)
        return int_view();
    return int_view(begin + start, size - start);
}

int_view int_view::end_view(size_t end) const
{
  if (end > size)
    return int_view();
  return int_view(begin, end);
}

int_view int_view::sub_view(size_t start, size_t end) const
{
  if (start > end || end > size)
    return int_view();
  return int_view(begin + start, end - start);
}

int_view::int_view(int* b, size_t s):
    begin(b), size(s)
{}

int_view::int_view(int* b, int* e):
    begin(b), size(e - b)
{}

size_t int_view::get_size() const
{
  return size;
}
int_view::int_view():
  begin(nullptr), size(0) 
  {}

void count(int_view a)
{
}

int main()
{
  int a[10] = {};
  int* c = new int[10];
  int_view a1{c, 10};

  delete[] c;
}
