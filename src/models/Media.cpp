#include "models/Media.hpp"

using namespace std;

Media::Media(int id, int mid, bool isLiked, MediaType type, vector<string> tags) : id(id), mid(mid), isLiked(isLiked), type(type), tags(tags) {}

void Media::addTag(std::string tag) {
    tags.push_back(tag);
}

void Media::removeTag(int idx) {
    if (idx < 0 || idx > tags.size()) {
        throw std::out_of_range("Invalid index: Element does not exist.");
    }
    tags.erase(tags.begin() + idx);
}

void Media::addRating(bool rating) {
    isLiked = rating;
}