#include "models/Media.hpp"
#include <nlohmann/json.hpp>
#include <ranges>

using namespace std;
using json = nlohmann::json;

Media::Media(int id, int mid, std::optional<bool> rating, WatchStatus status, MediaType type, vector<string> tags) 
    : id(id), mid(mid), rating(rating), status(status), type(type), tags(tags) {}

std::string Media::toString() {
    std::vector<std::string> result;
    result.push_back("id: " + std::to_string(id));
    result.push_back("mid: " + std::to_string(mid));
    if (rating.has_value()) {
        result.push_back("rating: " + std::to_string(rating.value()));
    } else {
        result.push_back("rating: null");
    }
    result.push_back("status: " + EnumHelpers::watchStatusToString(status));
    result.push_back("type: " + EnumHelpers::mediaTypeToString(type));

    std::string joined = ((json) tags).dump();

    result.push_back("tags: " + joined);

    return ((json) result).dump();
}

void Media::addTag(std::string tag) {
    tags.push_back(tag);
}

void Media::removeTag(int idx) {
    if (idx < 0 || idx > tags.size()) {
        throw std::out_of_range("Invalid index: Element does not exist.");
    }
    tags.erase(tags.begin() + idx);
}

void Media::setRating(std::optional<bool> rate) {
    rating = rate;
}

void Media::setStatus(WatchStatus statusUpdate) {
    status = statusUpdate;
}