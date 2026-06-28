#include <iostream>
#include <fstream>

void compressFile(const std::string& inputPath, const std::string& outputPath) {
    // Open input file in binary mode
    std::ifstream inFile(inputPath, std::ios::binary);
    // Open output file in binary mode
    std::ofstream outFile(outputPath, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char currentByte;
    char nextByte;

    // Read the very first byte to kick off the program
    if (inFile.get(currentByte)) {
        unsigned char count = 1;

        // Loop through the rest of the file byte by byte
        while (inFile.get(nextByte)) {
            // If the byte repeats and we haven't hit the 255 cap (max size of a single byte counter)
            if (nextByte == currentByte && count < 255) {
                count++;
            } else {
                // Write the count and the byte to the compressed file
                outFile.put(static_cast<char>(count));
                outFile.put(currentByte);

                // Reset for the new byte pattern
                currentByte = nextByte;
                count = 1;
            }
        }
        // Write the final remaining byte sequence
        outFile.put(static_cast<char>(count));
        outFile.put(currentByte);
    }

    inFile.close();
    outFile.close();
    std::cout << "Compression complete!" << std::endl;
}

int main() {
    compressFile("original.txt", "compressed.rle");
    return 0;
}
