#include <iostream>
#include <cstdlib>
#include <ctime>
#include "algorithm.h"

const int totalVotes = 100;

void generateVotes(int arr[], int max) {
    for(int i = 0; i < max; i++) {
        arr[i] = (rand() % 5) + 1;
    }
}

void showVotes(int arr[], int max) {
    for(int i = 0; i < max; i++){
        std::cout << arr[i] << " ";
    }
}

int main() {
    Candidate voteDirectory[] = {
        {"Candidate 1 : Bo Dalton Capistrano", {0}},
        {"Candidate 2 : Cornelius Raymon Agustin", {0}},
        {"Candidate 3 : Deja Jayla Banaga", {0}},
        {"Candidate 4 : Lalla Brielle Yabut", {0}},
        {"Candidate 5 : Franklin Relano Castro", {0}}
    };

    std::cout << "########## List of Candidates ##########" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << voteDirectory[i].name << std::endl;
    }

    std::cout << "########## Peoples Votes ###############" << std::endl;
    srand(static_cast<unsigned int>(time(0)));
    int peoplesVote[totalVotes];
    generateVotes(peoplesVote, totalVotes);
    showVotes(peoplesVote, totalVotes);

    std::cout << "\n########## SORTED Peoples Votes ##########" << std::endl;
    insertionSort(peoplesVote, totalVotes);
    showVotes(peoplesVote, totalVotes);

    std::cout << "\n########## Total Votes per Candidate ##########" << std::endl;
    countVote(peoplesVote, voteDirectory,totalVotes);

    return 0;
}