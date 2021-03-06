#include "AssetManager.hpp"



void AssetManager::LoadTexture(std::string name, std::string fileName) {
    sf::Texture tex;
    if( tex.loadFromFile(fileName) ) {
        tex.setSmooth(true);
        this->_textures[name] = tex;
    }
}
/*void AssetManager::LoadTexture(std::string name, std::string fileName, int xStart, int yStart, int width, int height) {

    sf::Texture tex;
    if( tex.loadFromFile(fileName, sf::IntRect(xStart, yStart, width, height)) ) {
        this->_textures[name] = tex;
    }
}*/

sf::Texture& AssetManager::GetTexture(std::string name) {
    return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName) {

    sf::Font font;
    if( font.loadFromFile(fileName) ) {
        this->_fonts[name] = font;
    }
}

sf::Font& AssetManager::GetFont(std::string name) {
    return this->_fonts.at(name);
}

