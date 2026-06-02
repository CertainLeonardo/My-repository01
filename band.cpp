#include <iostream>
#include <string>

int main() {
    std::string bandName;
    std::string bandMembers[3] = {"Kurt Cobain", "Krist Novoselic", "Dave Grohl"};
    std::string bandGenre = "Grunge";
    std::string bandOrigin = "Aberdeen, Washington, USA";
    std::string bandYearsActive = "1987-1994";
    std::string publishedAlbums[3] = {"Bleach", "Nevermind", "In Utero"};
    std::string bandRecordLabel = "Sub Pop Records";
    std::string bandInstruments[3] = {"Vocals/Guitar", "Bass", "Drums"};

    bandName = "Nirvana";
    std::cout << "Band Name: " << bandName << std::endl;
    std::cout << "Band Members: " << bandMembers[0] << ", " << bandMembers[1] << ", " << bandMembers[2] << std::endl;
    std::cout << "Band Genre: " << bandGenre << std::endl;
    std::cout << "Band Origin: " << bandOrigin << std::endl;
    std::cout << "Band Years Active: " << bandYearsActive << std::endl;
    std::cout << "Published Albums: " << publishedAlbums[0] << ", " << publishedAlbums[1] << ", " << publishedAlbums[2] << std::endl;
    std::cout << "Record Label: " << bandRecordLabel << std::endl;
    std::cout << "Instruments: " << bandInstruments[0] << ", " << bandInstruments[1] << ", " << bandInstruments[2] << std::endl;

    return 0;
}