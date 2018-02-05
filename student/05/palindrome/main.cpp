#include <iostream>
#include <string>
bool flag = false;

bool palindrome_recursive(std::string word, int begin, int ending){
    if (word.at(begin) == word.at(ending)){
        if ( begin >= ending)
            return flag;
        else{
            begin++;
            ending--;
            flag = true;
            palindrome_recursive(word, begin, ending);
            return flag;
        }
    }
    else{
        flag = false;
        return flag;
    }
}

int main()
{
    int begin = 0;
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;
    int ending = word.size() - 1;

    if(palindrome_recursive(word, begin, ending)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }

}
