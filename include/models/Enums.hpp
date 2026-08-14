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
            case MediaType::Show: return "Show";
            case MediaType::Anime: return "Anime";
            case MediaType::Book: return "Book";
            case MediaType::Game: return "Game";
            default: throw std::invalid_argument("Unknown MediaType");
        }
    }

    inline std::string watchStatusToString(WatchStatus status) {
        switch (status) {
            case WatchStatus::Watchlist: return "Watchlist";
            case WatchStatus::InProgress: return "In Progress";
            case WatchStatus::Completed: return "Completed";
            case WatchStatus::Dropped: return "Dropped";
            default: throw std::invalid_argument("Unknown WatchStatus");
        }
    }

    inline std::optional<MediaType> stringToMediaType(std::string mediaType) {
        if (mediaType == "Movie") {
            return MediaType::Movie;
        }
        else if (mediaType == "Show") {
            return MediaType::Show;
        }
        else if (mediaType == "Anime") {
            return MediaType::Anime;
        }
        else if (mediaType == "Book") {
            return MediaType::Book;
        }
        else if (mediaType == "Game") {
            return MediaType::Game;
        } else {
            return std::nullopt;
        }
    }

    inline std::optional<WatchStatus> stringToWatchStatus(std::string status) {
        if (status == "Watchlist") {
            return WatchStatus::Watchlist;
        }
        else if (status == "In Progress") {
            return WatchStatus::InProgress;
        }
        else if (status == "Completed") {
            return WatchStatus::Completed;
        }
        else if (status == "Dropped") {
            return WatchStatus::Dropped;
        }
        else {
            return std::nullopt;
        }
    }
}