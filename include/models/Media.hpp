// src/models/Media.hpp
#pragma once

#include <string>
#include <utility>
#include <vector>
#include "Enums.hpp"

class Media {
    public:
        int id;
        int mid; // Used to identify the entry in the database for this media object
        std::optional<bool> rating; // media might not have rating
        WatchStatus status;
        MediaType type;
        std::vector<std::string> tags; // comments about the media by user

    virtual ~Media() = default;

    Media(int id, int mid, std::optional<bool> rating, WatchStatus status, MediaType type, std::vector<std::string> tags);

    std::string toString();

    void addTag(std::string tag);

    void removeTag(int idx);

    void setRating(std::optional<bool> rate);

    void setStatus(WatchStatus statusUpdate);
};