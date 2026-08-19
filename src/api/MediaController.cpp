#include "api/MediaController.hpp"
#include <glaze/glaze.hpp>

MediaController::MediaController(MediaService& mediaService)
    : m_mediaService(mediaService) {}

void MediaController::registerRoutes(crow::SimpleApp& app) {
    
    // GET /api/media
    CROW_ROUTE(app, "/api/media").methods(crow::HTTPMethod::GET)
    ([this](const crow::request& req) {
        try {
            auto allMedia = m_mediaService.getAllMedia();
            
            // Glaze automatically converts the std::vector<models::Media> to a JSON array!
            std::string jsonResponse;
            (void)glz::write_json(allMedia, jsonResponse);

            crow::response res(200, jsonResponse);
            res.add_header("Content-Type", "application/json");
            return res;
            
        } catch (const std::exception& e) {
            return crow::response(500, R"({"error": "Internal Server Error"})");
        }
    });

    // POST /api/media
    CROW_ROUTE(app, "/api/media").methods(crow::HTTPMethod::POST)
    ([this](const crow::request& req) {
        try {
            Media newMedia;
            
            // Glaze automatically parses the JSON string directly into your C++ struct!
            auto parseError = glz::read_json(newMedia, req.body);
            if (parseError) {
                return crow::response(400, R"({"error": "Invalid JSON format"})");
            }

            // Send to Service Layer
            int newId = m_mediaService.addMedia(newMedia);

            // Create a simple success response
            std::string responseBody = R"({"message": "Media added", "id": )" + std::to_string(newId) + "}";
            
            crow::response res(201, responseBody);
            res.add_header("Content-Type", "application/json");
            return res;

        } catch (const std::invalid_argument& e) {
            // Business logic failures
            std::string errorJson = R"({"error": ")" + std::string(e.what()) + R"("})";
            return crow::response(400, errorJson);
        } catch (const std::exception& e) {
            return crow::response(500, R"({"error": "Internal Server Error"})");
        }
    });
}