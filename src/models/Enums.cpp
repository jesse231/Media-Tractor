#include "models/Enums.hpp"

std::string EnumHelpers::mediaTypeToString(MediaType type) {
    switch (type) {
            case MediaType::Movie: return "Movie";
            case MediaType::Show: return "Show";
            case MediaType::Anime: return "Anime";
            case MediaType::Book: return "Book";
            case MediaType::Game: return "Game";
            default: throw std::invalid_argument("Unknown MediaType");
        }
}

std::string EnumHelpers::watchStatusToString(WatchStatus status) {
    switch (status) {
        case WatchStatus::Watchlist: return "Watchlist";
        case WatchStatus::InProgress: return "In Progress";
        case WatchStatus::Completed: return "Completed";
        case WatchStatus::Dropped: return "Dropped";
        default: throw std::invalid_argument("Unknown WatchStatus");
    }
}

std::optional<MediaType> EnumHelpers::stringToMediaType(std::string mediaType) {
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

std::optional<WatchStatus> EnumHelpers::stringToWatchStatus(std::string status) {
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