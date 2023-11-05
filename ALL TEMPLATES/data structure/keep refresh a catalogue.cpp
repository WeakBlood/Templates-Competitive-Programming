#include <iostream> 
#include <unordered_map>
/* this is a very simple example on how to use efficiently an unordered_map*/
std::unordered_map<long long int, int> libro_count;

void aggiungi(long long int id) 
{
     libro_count[id]++;  // we add books of kind id
}

void togli(long long int id) 
{ 
    if(libro_count.find(id) != libro_count.end()) 
    { 
        libro_count[id]--;  // we remove them only if the key exist 
    } 
}

int conta(long long int id) 
{ 
    if(libro_count.find(id) != libro_count.end()) 
    { 
        return libro_count[id];  // we give the number in that key if it exist unless we are going to get an error 
    } 
    return 0; 
}