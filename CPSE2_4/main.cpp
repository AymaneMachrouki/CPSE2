#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>

void Opdracht2(std::vector<char> bible){
    std::cout << "De file bevat " << bible.size() << " characters." << std::endl;
}

void Opdracht3(std::vector<char> bible){
    std::cout << "De file bevat " << std::count(bible.begin(), bible.end(), '\n') << " regels." << std::endl;
}

void Opdracht4(std::vector<char> bible){
    std::cout << "De file bevat " << std::count_if(bible.begin(), bible.end(), isalpha) << " letters." << std::endl;
}

void Opdracht5(std::vector<char> bible){
    std::transform(bible.begin(), bible.end(), bible.begin(), [](char character){return std::tolower(character);});
}

void Opdracht7(std::vector<char> bible, std::map<char, int> letterDictionary){
    std::string alphabet = "abcdefghijklmnopqrstuwvxyz";
    std::map<int, char> map = {};
    std::vector<int> order = {};

    std::cout << std::endl<< "Het aantal individuele letters op alfabetische volgorde:" << std::endl;
    for(char character : alphabet){
        std::cout << "De " << character << " komt " << letterDictionary[character] << " keer voor." << std::endl;
    }

    std::cout << std::endl << "Het aantal individuele letters op volgorde van minst naar meest:" << std::endl;
    for(char character : alphabet){
        map[letterDictionary[character]] = character;
        order.push_back(letterDictionary[character]);
    }
    std::sort(order.begin(), order.end());
    for(int amount : order){
        std::cout << "De " << map[amount] << " komt " << amount << " keer voor." << std::endl;
    }
}

void Opdracht6(std::vector<char> bible){
	std::map<char, int> letterDictionary = {};
    std::string alphabet = "abcdefghijklmnopqrstuwvxyz";

    for(char character : alphabet){
        letterDictionary[character] = std::count(bible.begin(), bible.end(), character);
    }

    Opdracht7(bible, letterDictionary);
}

void Opdracht8(){
    std::map<std::string, int> wordCount;
    std::map<std::string, int> ss;
    std::vector<int> order;
    std::vector<std::string> words;
    std::ifstream file("The King James Bible.txt");

    while(!file.eof()){
        std::string temp;
        std::string word;
        file >> temp;
        if(!temp.empty()){
            for(char character : temp){
                if( isalpha(character) ){
                    word = word + character;
                }
            }
            std::transform(word.begin(), word.end(), word.begin(), [](char character){return std::tolower(character);});
            if(!word.empty()){
                auto o = wordCount.find(word);
                if(o == wordCount.end()){
                    wordCount[word] = 1;
                }
                else{
                    o->second++;
                }
            }
        }
    }

    for(unsigned int i = 0; i < 10; i++){
        int most = 0;
        std::string s;
        for(auto it = wordCount.begin(); it != wordCount.end(); ++it){
            if(it->second > most){
                most = it->second;
                s = it->first;
            }
        }
        ss[s] = most;
        wordCount[s] = 0;
    }

    for(auto const& [key, val] : ss){
        order.push_back(val);
        words.push_back(key);
    }

    std::cout << std::endl << "Dit zijn de 10 meest voorkomende woorden:" << std::endl;
    for(unsigned int i = 0; i < 10; i++){
        int index = std::max_element(order.begin(),order.end()) - order.begin();
        int n = order[index];
        std::string s = words[index];
        order.erase(order.begin() + index);
        words.erase(words.begin() + index);
        std::cout << "Het woord " << s << " komt " << n << " keer voor." << std::endl;
    }
}

int main(){
	std::string filename = "The King James Bible.txt";
	std::ifstream file(filename);

    std::vector<char> bible;
    char character;
    while(file.get(character)){
        bible.push_back(character);
    }

    Opdracht2(bible);
    Opdracht3(bible);
    Opdracht4(bible);
    Opdracht5(bible);
    Opdracht6(bible);
    Opdracht8();

    file.close();
}