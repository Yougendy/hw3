#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;  // Stores heap elements
  int m_;  // Number of children per node
  PComparator comp_;  // Comparator function

  void heapifyUp(size_t index);
  void heapifyDown(size_t index);
};

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

// Returns true if the heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
}

// Returns the size of the heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const {
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}

// Pushes an item into the heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data.push_back(item);
  heapifyUp(data.size() - 1);
}

// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(data[0], data.back());
  data.pop_back();
  if (!empty()) {
    heapifyDown(0);
  }
}

// Heapify-up to maintain heap order
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index) {
  if (index == 0) return;
  size_t parent = (index - 1) / m_;
  if (comp_(data[index], data[parent])) {
    std::swap(data[index], data[parent]);
    heapifyUp(parent);
  }
}

// Heapify-down to maintain heap order
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index) {
  size_t best = index;
  for (int i = 1; i <= m_; ++i) {
    size_t child = m_ * index + i;
    if (child < data.size() && comp_(data[child], data[best])) {
      best = child;
    }
  }
  if (best != index) {
    std::swap(data[index], data[best]);
    heapifyDown(best);
  }
}

#endif
