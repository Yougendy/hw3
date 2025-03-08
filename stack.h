#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
private:
		std::vector<T> data;
public:
     Stack() = default;
    ~Stack() = default;
    bool empty() const{
			return data.empty(); 
		}
    size_t size() const{
			return data.size(); 
		}
    void push(const T& item){
			data.push_back(item); 
		}
    void pop(){
			if (empty()){
				throw std::underflow_error("Stack is empty");
			}
			data.pop_back(); 
		} // throws std::underflow_error if empty
    const T& top() const{
			if(empty()){
				throw std::underflow_error("Stack is empty");
			}
			return data.back();
		} // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif