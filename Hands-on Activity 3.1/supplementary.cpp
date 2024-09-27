#include<iostream>
#include<utility>
#include<string>

class Node
{
    public:
        std::string data;
        Node *next;
        Node *prev;
};

Node* CURRENT = nullptr;

Node* ADD(Node* track, std::string newSong)
{
    Node* newNode = new Node;
    newNode -> data = newSong;
    newNode -> next = track;
    newNode -> prev = nullptr;

    if (track != nullptr) {
        track -> prev = newNode;
    }
    
    return newNode;
}

Node* NEXT(Node* track)
{
    if (track != nullptr) {
        CURRENT = track -> next;
    }
    return CURRENT;
}

Node* PREVIOUS(Node* track)
{
    if (track != nullptr) {
        CURRENT = track -> prev;
    }
    return CURRENT;
}

Node* REMOVE(Node* track, std::string trackRemove)
{
    Node* temp = track;
    while (temp != nullptr) {
        if (temp -> data == trackRemove) {
            if (temp -> prev != nullptr) {
                temp -> prev -> next = temp -> next;
            } else {
                track = temp -> next;
            }
            if (temp -> next != nullptr) {
                temp -> next -> prev = temp -> prev;
            }
            delete temp;
            return track;
        }
        temp = temp -> next;
    }
    return track;
}

void loopSongs(Node* track)
{
  while(track != nullptr)
  {
    std::cout << track -> data << std::endl;
    track = track -> next;
  }
  std::cout << std::endl;
}

int main()
{
    int x;
    // Playlist
    Node *track1 = new Node;
    Node *track2 = new Node;
    Node *track3 = new Node;
    Node *track4 = new Node;

    track1 -> data = "Electric Feel - by MGMT";
    CURRENT = track1;
    track1 -> next = track2;
    track1 -> prev = nullptr;

    track2 -> data = "Feeling Good - by Michael Buble";
    track2 -> next = track3;
    track2 -> prev = track1;

    track3 -> data = "My Way - by Frank Sinatra";
    track3 -> next = track4;
    track3 -> prev = track2;

    track4 -> data = "Fly Me To The Moon - by Frank Sinatra";
    track4 -> next = nullptr;
    track4 -> prev = track3;

    std::cout << "1 : NEXT | 2 : PREV | 3 : PLAY ALL | 4 : INSERT | 5 : REMOVE | 0 : END PROGRAM" << std::endl;
    std::cin >> x;
    while (x != 0)
    {
        switch(x)
        {
            case 1:
                CURRENT = NEXT(CURRENT);
                std::cout << "Playlist adjusted! Please PLAY ALL the tracks to see the changes," << std::endl;
                break;
            case 2:
                CURRENT = PREVIOUS(CURRENT);
                std::cout << "Playlist adjusted! Please PLAY ALL the tracks to see the changes," << std::endl;
                break;
            case 3:
                loopSongs(CURRENT);
                break;
            case 4:
                {
                    std::string newTrack;
                    std::cout << "Enter a new Track for your spotify playlist! : ";
                    std::cin.ignore();
                    std::getline(std::cin, newTrack);
                    track1 = ADD(track1, newTrack);
                }
                break;
            case 5:
                {
                    std::string removeTrack;
                    std::cout << "Enter a Track to remove from you spotify playlist... : ";
                    std::cin.ignore();
                    std::getline(std::cin, removeTrack);
                    track1 = REMOVE(track1, removeTrack);
                }
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
        std::cout << "1 : NEXT | 2 : PREV | 3 : PLAY ALL | 4 : INSERT | 5 : REMOVE | 0 : END PROGRAM" << std::endl;
        std::cin >> x;
    }
}