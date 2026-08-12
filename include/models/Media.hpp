// src/models/Media.hpp
#pragma once

#include <string>
#include <utility>
#include <vector>
#include "Enums.hpp"

class Media {
    public:
        int id; // database entry id
        int mid; // Used to identify the entry in the database for this media object
        bool isLiked; 
        MediaType type;
        std::vector<std::string> tags; // comments about the media by user

    virtual ~Media() = default;

    Media(int id, int mid, bool isLiked, MediaType type, std::vector<std::string> tags);

    void addTag(std::string tag);

    void removeTag(int idx);

    void addRating(bool rating);
};