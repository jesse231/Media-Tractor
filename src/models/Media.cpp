#include "models/Media.hpp"
#include <glaze/glaze.hpp>
#include <ranges>
#include <stdexcept>

using namespace std;

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

    std::string joined;
    (void)glz::write_json(tags, joined);

    result.push_back("tags: " + joined);

    std::string final_json;
    (void)glz::write_json(result, final_json);
    return final_json;
}

void Media::setId(int mediaId) {
    id = mediaId;
}

void Media::addTag(std::string tag) {
    tags.push_back(tag);
}

void Media::removeTag(int idx) {
    if (idx < 0 || idx >= tags.size()) { 
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