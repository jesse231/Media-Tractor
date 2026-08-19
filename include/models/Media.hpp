// src/models/Media.hpp
#pragma once

#include <string>
#include <utility>
#include <vector>
#include <optional>
#include "Enums.hpp"

class Media {
    public:
        int id;
        int mid; // Used to identify the entry in the database for this media object
        std::optional<bool> rating; // media might not have rating
        WatchStatus status;
        MediaType type;
        std::vector<std::string> tags; // comments about the media by user

    std::string toString();

    void setId(int id);

    void addTag(std::string tag);

    void removeTag(int idx);

    void setRating(std::optional<bool> rate);

    void setStatus(WatchStatus statusUpdate);
};