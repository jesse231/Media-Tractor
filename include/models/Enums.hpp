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

namespace EnumHelpers {
    std::string mediaTypeToString(MediaType type);

    std::string watchStatusToString(WatchStatus status);

    std::optional<MediaType> stringToMediaType(std::string mediaType);

    std::optional<WatchStatus> stringToWatchStatus(std::string status);
}