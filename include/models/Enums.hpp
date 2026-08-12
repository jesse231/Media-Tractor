#pragma once

#include <string>
#include <stdexcept>

enum class MediaType : int {
    Movie = 1,
    Show = 2,
    Anime = 3,
    Book = 4,
    Game = 5
};

enum class WatchStatus : int {
    Watchlist = 1,
    InProgress = 2,
    Completed = 3,
    Dropped = 4
};

// Helper functions to convert enums to strings.
namespace EnumHelpers {
    
    inline std::string mediaTypeToString(MediaType type) {
        switch (type) {
            case MediaType::Movie: return "Movie";
            case MediaType::Show:  return "Show";
            case MediaType::Anime: return "Anime";
            case MediaType::Book:  return "Book";
            case MediaType::Game:  return "Game";
            default: throw std::invalid_argument("Unknown MediaType");
        }
    }

    inline std::string watchStatusToString(WatchStatus status) {
        switch (status) {
            case WatchStatus::Watchlist:  return "Want to See";
            case WatchStatus::InProgress: return "In Progress";
            case WatchStatus::Completed:  return "Completed";
            case WatchStatus::Dropped:    return "Dropped";
            default: throw std::invalid_argument("Unknown WatchStatus");
        }
    }
}